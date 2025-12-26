# CaesarCipherTool
A simple Caesar Cipher encryption and auto-decryption tool written in C.  
It can encrypt text files with a key and automatically decrypt files by guessing the key based on common English words.



## 🔧 Features
- Encrypt text files using a shift key
- Auto-decrypt Caesar cipher encrypted files
- Command-line interface with menu
- Lightweight and easy to use
- ⚠️ **Educational project for learning C and basic cryptography (not intended for professional use)**

## How to Compile
gcc CaesarCipherTool.c -o Caesar
## How to Run
./Caesar


## Menu Options
    Encrypt a file

   - Input the file to encrypt and the output file name

   - Enter a numeric key (any number; the program will use key % 26)

    Auto-decrypt a file

   - Input the encrypted file and the output file name

   - The program will try all possible keys and choose the most likely text
    Exit 

   - Exit the program
   

    
## Usage/Examples
    
       Encrypt a file

 - Menu: choose 1

 - Enter input filename: message.txt

 - Enter output filename: encrypted.txt

 - Enter encryption key: 3

       Auto-decrypt a file

 - Menu: choose 2

 - Enter input filename: encrypted.txt

 - Enter output filename: decrypted.txt



## Author

- Sh1RoZoneX(https://github.com/Sh1RoZoneX)