#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//*************************************
//  isValidUppercaseStateCode
//*************************************
// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.
bool isValidUppercaseStateCode(string stateCode) {
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MA.MD.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

bool isValidPollString(string pollData) {
    string stateForecast = "";

    for (int i = 0; i < pollData.length(); i++) {
        if (pollData[i] == ',' || i == pollData.length() - 1) { //separated by comma or end
            if (i == pollData.length() - 1) { //if at end you still need last character
                stateForecast += pollData[i];
            }

            if (stateForecast == "") { //if double comma
                cerr << stateForecast << endl;
                cerr << "double comma" << endl;
                return false;
            }

            //check if its a state
            string upCaseState = "";
            upCaseState.push_back(toupper(stateForecast[0]));
            upCaseState.push_back(toupper(stateForecast[1]));
            if (!isValidUppercaseStateCode(upCaseState)) {
                cerr << upCaseState << endl;
                cerr << "not valid state code" << endl;;
                return false;
            }

            //if it is state check if valid results
            for (int j = 2; j < stateForecast.length(); j++) { //is a valid string
                if (isdigit(stateForecast[j])) {
                    j++; // increment to keep checking
                    if (j > stateForecast.length() - 1) { //if it gets out of bounds, 1 digit at end
                        cerr << stateForecast << endl;
                        cerr << "just a digit at end" << endl;
                        return false;
                    }

                    if (isdigit(stateForecast[j])) { //if 2 digit
                        j++;
                        if (j > stateForecast.length() - 1) { //if it gets out of bounds, 2 digits at end
                            cerr << stateForecast << endl;
                            cerr << "just 2 digits at end" << endl;
                            return false;
                        }   

                        if (!isalpha(stateForecast[j])) { //if 2 digit, party code must come after or else false
                            cerr << stateForecast << endl;
                            cerr << "no party code after 2 digits" << endl;
                            return false;
                        }
                    } else if (!isalpha(stateForecast[j])) { //if 1 digit and then either code or not code, if not a code its false
                        cerr << stateForecast << endl;
                        cerr << "1 digit then no code" << endl;
                        return false;
                    }
                } else {
                    cerr << stateForecast << endl;
                    cerr << "not a digit after state code" << endl;
                    return false;
                }
            }

            stateForecast = ""; //reset it
            continue; //to avoid adding comma
        }
        stateForecast += pollData[i];
    }

    return true;
}

int countSeats(string pollData, char party, int& seatCount) {
    if (!isValidPollString(pollData)) {
        return 1;
    } if (!isalpha(party)) {
        return 2;
    } else {
        seatCount = 0;
        string stateForecast = "";

        for (int i = 0; i < pollData.length(); i++) {
            if (pollData[i] == ',' || i == pollData.length() - 1) { //separated by comma or end
                if (i == pollData.length() - 1) { //if at end you still need last character
                    stateForecast += pollData[i];
                }

                for (int j = 2; j < stateForecast.length(); j++) {
                    int firstInt = stateForecast[j] - '0';
                    j++; //increment to check next character

                    if (isalpha(stateForecast[j])) { //1 number 1 letter
                        if (toupper(party) == toupper(stateForecast[j])) { //if party matches the letter
                            seatCount += firstInt;
                        }
                    } else { //2 number 1 letter
                        int secondInt = stateForecast[j] - '0';
                        int total = firstInt * 10 + secondInt; //take first number in 10s digit and second number in 1s digit
                        j++;

                        if (toupper(party) == toupper(stateForecast[j])) { //if party matches the letter
                            seatCount += total;
                        }
                    }
                }

                stateForecast = ""; //reset it
                continue; //to avoid adding comma
            }
            stateForecast += pollData[i];
        }
        return 0;
    }
}

int main() {
    if (isValidPollString("CA34D12R2I,nV9R,vt,Ny3r9I13D")) //test a normal chain
		cerr << "Passed test 1: isValidPollString(\"CA34D12R2I,nV9R,vt,Ny3r9I13D\")" << endl;
    int seats = -999;
    if (countSeats("CA34D12R2I,nV9R,vt,Ny3r9I13D", 'd', seats) == 0  &&  seats == 47) //tests countseats on a valid pollString
		cerr << "Passed test 1: countSeats(\"CA34D12R2I,nV9R,vt,Ny3r9I13D\", 'd', seats)" << endl;
    if (isValidPollString("")) //test an empty string
		cerr << "Passed test 2: isValidPollString(\"\")" << endl;
    if (isValidPollString("cA")) //tests a state code
        cerr << "Passed test 3: isValidPollString(\"cA\")" << endl;
    if (!isValidPollString("CA34D12R2I, nV9R,vt,Ny3r9I13D")) //space in poll string
		cerr << "Passed test 4: !isValidPollString(\"CA34D12R2I, nV9R,vt,Ny3r9I13D\")" << endl;
    if (!isValidPollString(",CA34D12R2I,nV9R,vt,Ny3r9I13D")) //comma in beginning
		cerr << "Passed test 5: !isValidPollString(\",CA34D12R2I,nV9R,vt,Ny3r9I13D\")" << endl;
    if (!isValidPollString("CA34D12R2I,nV9R,vt,Ny3r9I13D,")) //comma in end
		cerr << "Passed test 6: !isValidPollString(\"CA34D12R2I,nV9R,vt,Ny3r9I13D,\")" << endl;
    if (!isValidPollString("ZT5D,NY9R16D1I,VT,ne3r00D")) //incorrect state code
		cerr << "Passed test 7: !isValidPollString(\"ZT5D,NY9R16D1I,VT,ne3r00D\")" << endl;
    if (!isValidPollString("ZT512")) //incorrect state code
		cerr << "Passed test 8: !isValidPollString(\"ZT512\")" << endl;
    if (!isValidPollString("Cablahblah")) //nonsense string that starts with state code
		cerr << "Passed test 9: !isValidPollString(\"Cablahblah\")" << endl;
    if (!isValidPollString("blahblah")) //nonsense string
		cerr << "Passed test 10: !isValidPollString(\"blahblah\")" << endl;
    if (!isValidPollString("Ca1bb")) //extra letter
		cerr << "Passed test 11: !isValidPollString(\"Ca1bb\")" << endl;
    if (!isValidPollString("12")) //random number
        cerr << "Passed test 12: !isValidPollString(\"12\")" << endl;
}