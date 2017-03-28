#pragma once

/* Each character on a computer is assigned a unique code and the preferred standard is ASCII 
(American Standard Code for Information Interchange). 
For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, 
then XOR each byte with a given value, taken from a secret key. The advantage 
with the XOR function is that using the same encryption key on the cipher text, 
restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, 
and the key is made up of random bytes. The user would keep the encrypted message 
and the encryption key in different locations, and without both "halves", it is 
impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method 
is to use a password as a key. If the password is shorter than the message, which 
is likely, the key is repeated cyclically throughout the message. The balance for 
this method is using a sufficiently long password key for security, but short 
enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case 
characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file 
containing the encrypted ASCII codes, and the knowledge that the plain text must 
contain common English words, decrypt the message and find the sum of the ASCII 
values in the original text.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void execute_59() {
    std::string line;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;

    std::vector<unsigned char> characters;

    std::ifstream myfile("p059_cipher.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {

            while ((pos = line.find(delimiter)) != std::string::npos) {
                token = line.substr(0, pos);
                characters.push_back((unsigned char)std::stoi(token));
                line.erase(0, pos + delimiter.length());
            }
			
			characters.push_back((unsigned char)std::stoi(line));
		}
        myfile.close();
    }

	for (int k = 0; k < 10; k++) std::cout << (int)characters[characters.size() - 10 + k] << " "; std::cout << std::endl;

	unsigned char pass[3];
	for (int k = 0; k < 3; ++k){

		for (auto c = 'a'; c <= 'z'; ++c){

			int acceptable_c_num = 0;
			for (int i = k; i < characters.size(); i += 3) {

				auto decr_c = (unsigned char)(characters[i] ^ c);
				if ((decr_c >= 'a' && decr_c <= 'z') || decr_c == ' ') {
					++acceptable_c_num;
				}
			}


			if (acceptable_c_num*1. / (characters.size() / 3) * 100 > 90) {
				pass[k] = c;
				std::cout << c << std::endl;
			}
		}
	}

	int sum = 0;
	for (int k = 0; k < characters.size(); k++) {
		std::cout << (unsigned char)(characters[k] ^ pass[k % 3]);
		sum += (unsigned char)(characters[k] ^ pass[k % 3]);
	}
	std::cout << sum <<std::endl;
    
}