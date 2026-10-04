#include <iostream>
using namespace std;

// ======= Conversion Functions =======
int octaltodec(int octal){
	int sum=0, base=1;
	while(octal>0){
		int digit=octal%10;
		sum+=digit*base;
		base*=8;
		octal/=10;
	}
	return sum;
}

int binarytodec(int binary){
	int sum=0, base=1;
	while(binary>0){
		int digit=binary%10;
		sum+=digit*base;
		base*=2;
		binary/=10;
	}
	return sum;
}

int dectooct(int decimal){
	int octal=0, base=1;
	while(decimal>0){
		int rem=decimal%8;
		octal+=rem*base;
		base*=10;
		decimal/=8;
	}
	return octal;
}

int dectobin(int decimal){
	int binary=0, base=1;
	while(decimal>0){
		int rem=decimal%2;
		binary+=rem*base;
		base*=10;
		decimal/=2;
	}
	return binary;
}

int hextodec(string hex){
	int decimal=0;
	for(int i=0;i<hex.length();i++){
		char ch=hex[i];
		int digit;
		if(ch>='0' && ch<='9') digit=ch-'0';
		else if(ch>='A' && ch<='F') digit=ch-'A'+10;
		else if(ch>='a' && ch<='f') digit=ch-'a'+10;
		else{
			cout<<"Invalid hex digit: "<<ch<<endl;
			return -1;
		}
		decimal=decimal*16+digit;
	}
	return decimal;
}

string dectohex(int decimal){
	if(decimal==0) return "0";
	string hex="";
	while(decimal>0){
		int rem=decimal%16;
		char hexDigit = (rem<10) ? rem+'0' : rem-10+'A';
		hex=hexDigit+hex;
		decimal/=16;
	}
	return hex;
}

// ======= MAIN FUNCTION =======
int main(){
	int choice;
	while(true){
		cout<<"\n===== Number System Converter =====\n";
		cout<<"1. Binary to Decimal\n";
		cout<<"2. Octal to Decimal\n";
		cout<<"3. Hexadecimal to Decimal\n";
		cout<<"4. Decimal to Binary\n";
		cout<<"5. Decimal to Octal\n";
		cout<<"6. Decimal to Hexadecimal\n";
		cout<<"7. Binary to Octal\n";
		cout<<"8. Octal to Binary\n";
		cout<<"9. Binary to Hexadecimal\n";
		cout<<"10. Hexadecimal to Binary\n";
		cout<<"11. Octal to Hexadecimal\n";
		cout<<"12. Hexadecimal to Octal\n";
		cout<<"0. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;

		if(choice==0) break;

		int dec, bin, oct;
		string hex;

		switch(choice){
			case 1:
				cout<<"Enter binary number: ";
				cin>>bin;
				cout<<"Decimal: "<<binarytodec(bin)<<endl;
				break;
			case 2:
				cout<<"Enter octal number: ";
				cin>>oct;
				cout<<"Decimal: "<<octaltodec(oct)<<endl;
				break;
			case 3:
				cout<<"Enter hexadecimal number: ";
				cin>>hex;
				cout<<"Decimal: "<<hextodec(hex)<<endl;
				break;
			case 4:
				cout<<"Enter decimal number: ";
				cin>>dec;
				cout<<"Binary: "<<dectobin(dec)<<endl;
				break;
			case 5:
				cout<<"Enter decimal number: ";
				cin>>dec;
				cout<<"Octal: "<<dectooct(dec)<<endl;
				break;
			case 6:
				cout<<"Enter decimal number: ";
				cin>>dec;
				cout<<"Hexadecimal: "<<dectohex(dec)<<endl;
				break;
			case 7:
				cout<<"Enter binary number: ";
				cin>>bin;
				dec=binarytodec(bin);
				cout<<"Octal: "<<dectooct(dec)<<endl;
				break;
			case 8:
				cout<<"Enter octal number: ";
				cin>>oct;
				dec=octaltodec(oct);
				cout<<"Binary: "<<dectobin(dec)<<endl;
				break;
			case 9:
				cout<<"Enter binary number: ";
				cin>>bin;
				dec=binarytodec(bin);
				cout<<"Hexadecimal: "<<dectohex(dec)<<endl;
				break;
			case 10:
				cout<<"Enter hexadecimal number: ";
				cin>>hex;
				dec=hextodec(hex);
				cout<<"Binary: "<<dectobin(dec)<<endl;
				break;
			case 11:
				cout<<"Enter octal number: ";
				cin>>oct;
				dec=octaltodec(oct);
				cout<<"Hexadecimal: "<<dectohex(dec)<<endl;
				break;
			case 12:
				cout<<"Enter hexadecimal number: ";
				cin>>hex;
				dec=hextodec(hex);
				cout<<"Octal: "<<dectooct(dec)<<endl;
				break;
			default:
				cout<<"Invalid choice! Try again.\n";
		}
	}
	cout<<"Program terminated.\n";
	return 0;
}

