g++ gen.cpp -o gen.e
g++ brut.cpp -o brut.e
g++ @opcjeCpp main.cpp prev.cpp -o main.e

testSize=100;
pushRate=0.6;
xRange=1000;

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

function leaveHandler(){
    rm -f brut.e gen.e main.e
    exit
}
trap leaveHandler SIGINT

counter=1
while true; do 
    echo -n "$counter: "

    testCase=$(./gen.e <<< "$RANDOM $testSize $pushRate $xRange")

    if [[ $1 = "-v" ]]; then
        valgrind -q --exit-on-first-error=yes --error-exitcode=-1 --log-file=memcheck.log --tool=memcheck --leak-check=yes ./main.e <<< "$testCase" 1>/dev/null
        if [[ $? -eq 0 ]]; then
            echo -e "${GREEN}Sucess.${NC}"
        else
            echo -e "${RED}Failure!${NC} Check memcheck.log"

            leaveHandler
        fi
    else
        brutOut=$(./brut.e <<< "$testCase")
        mainOut=$(./main.e <<< "$testCase")
        diffVal=$(diff <(echo $brutOut) <(echo $mainOut))

        if [[ ! $diffVal ]]; then
            echo -e "${GREEN}Sucess.${NC}"
        else
            echo -e "${RED}Failure!${NC}"
            echo "Test case: "
            echo "$testCase"
            echo "Brut out: $brutOut"
            echo "Your out: $mainOut"
            
            leaveHandler
        fi
    fi

    counter=$((counter+1))
done