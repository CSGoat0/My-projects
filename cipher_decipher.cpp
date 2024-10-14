// Program description: Program that Ciphers and Decipher text using multiple algorithms in C++
// Last Modification Date: 18/03/2024
// Author: Abdelrahman Nabil Hassan, ID: 20230219, Section: 3

#include <bits/stdc++.h>

using namespace std;

// Cipher 0
string a_encrypt(int a, int b, string message);
string a_decrypt(int c, int b, string encryptedmessage);
// To Ensure the Validation of the Values of a and c
bool validation_values(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]))
        {
            return false;
        }
    }
    if (stoi(value) <= 0)
    {
        return false;
    }
    return true;
}
void a_menu(string chosen)
{
    string a, b, c;
    cout << "Please, Enter Values of a, b, and c: ";
    cin >> a >> b >> c;
    while(!validation_values(a) || !validation_values(b) || !validation_values(c))
    {
        cout << "Invalid Input. Please, Enter Positive Integers Only\n";
        cout << "Please, Enter Values of a, b, and c: ";
        cin >> a >> b >> c;
    }
    while(!validation_values(a) ||  !validation_values(c) || ((stoi(a)*stoi(c)) % 26) != 1)
    {
        cout << "please enter Values of (a) and (c) according to this equation: (a x c) % 26 = 1\n";
        cin.ignore();
        cout << "Value (a): ";
        cin >> a;
        cin.ignore();
        cout << "Value (c): ";
        cin >> c;
    }
    string message;
    // Switch To Function According to Chosen from Menu
    if (stoi(chosen) == 1)
    {
        cin.ignore();
        cout << "Please, Enter a Message: ";
        getline(cin, message, '\n');
        cout << "encrypted Message: " << a_encrypt(stoi(a), stoi(b), message) << endl;
    }
    else if (stoi(chosen) == 2) // Decipher a message
    {
        cin.ignore();
        cout << "Please, Enter a encrypted Message: ";
        getline(cin, message, '\n');
        cout << "decrypted Message: " << a_decrypt(stoi(c), stoi(b), message) << endl;
    }
}
// Take Plain Message then encrypt the Message
string a_encrypt(int a, int b, string message)
{
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            if (islower(message[i]))
            {
                encryptedMessage += ((a * (message[i] - 'a') + b) % 26) + 'a';
            }
            else
            {
                encryptedMessage += ((a * (message[i] - 'A') + b) % 26) + 'A';
            }
        }
        else
        {
            encryptedMessage += message[i];
        }
    }
    return encryptedMessage;
}
// Take encrypted Message then decrypt the Message
string a_decrypt(int c, int b, string encryptedmessage)
{
    string decryptedMessage = "";
    for (int i = 0; i < encryptedmessage.length(); i++)
    {
        if (isalpha(encryptedmessage[i]))
        {
            if (islower(encryptedmessage[i]))
            {
                int y = encryptedmessage[i] - 'a';
                int x = (c * (y - b + 26)) % 26;
                decryptedMessage += char(x + 'a');
            }
            else
            {
                int y = encryptedmessage[i] - 'A';
                int x = (c * (y - b + 26)) % 26;
                decryptedMessage += char(x + 'A');
            }
        }
        else
        {
            decryptedMessage += encryptedmessage[i];
        }
    }
    return decryptedMessage;
}

// Cipher 1
string check_validation_text(string text)
{
    string res = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (!isalpha(text[i]))
            continue;
        else
            res += toupper(text[i]);
    }
    if(res.length() < 2)
    {
        return "";
    }
    return res;
}
string encrpytRout(string plainText, int key)
{
    string cipherText = "";
    int columns = key;
    int row = ceil((double)plainText.length() / columns);
    char arr[row][columns];
    int ch = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (ch >= plainText.length())
                arr[i][j] = 'X';
            else
                arr[i][j] = plainText[ch];
            ch++;
        }
    }
    int top = 0, right = columns - 1, left = 0, bottom = row - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = top; i <= bottom; i++)
        {
            cipherText += arr[i][right];
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cipherText += arr[bottom][i];
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cipherText += arr[i][left];
            }
            left++;
        }
        for (int i = left; i <= right; i++)
        {
            cipherText += arr[top][i];
        }
        top++;
    }
    return cipherText;
}
string decrpytRout(string cipherText, int key)
{
    string plainText = "";
    int columns = key;
    int row = ceil((double)cipherText.length() / columns);
    char arr[row][columns];
    int ch = 0;
    int top = 0, right = columns - 1, left = 0, bottom = row - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = cipherText[ch];
            ch++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bottom][i] = cipherText[ch];
                ch++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[i][left] = cipherText[ch];
                ch++;
            }
            left++;
        }
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = cipherText[ch];
            ch++;
        }
        top++;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] != 'X')
            {
                plainText += arr[i][j];
            }
        }
    }
    return plainText;
}
bool check_validation_key(string key, int lenText)
{
    for (int i = 0; i < key.length(); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    if (stoi(key) < 1 || stoi(key) > lenText / 2)
        return false;
    return true;
}
void Route(string mode)
{
    string plainText, key;
    cout << "PLease, Enter a plain Text: ";
    getline(cin, plainText, '\n');
    while (check_validation_text(plainText) == "")
    {
        cout << "Please enter at least two alphabetical characters: ";
        getline(cin, plainText, '\n');
    }
    plainText = check_validation_text(plainText);
    cout << "Please Enter Positive Key Not Greater Than the half length of the plain Text: ";
    cin >> key;
    while (!check_validation_key(key, plainText.length()))
    {
        cout << "Please Enter Positive Key Not Greater Than the half length of the plain Text: ";
        cin >> key;
    }
    cin.ignore();
    if (mode == "1")
        cout << encrpytRout(plainText, stoi(key));
    else
        cout << decrpytRout(plainText, stoi(key));
    cout << endl;
}

// Cipher 2
// Return the Text with only Upper Alphabetical Characters
string formatting(string text)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        // if The Current Character is Alphabetical convert it to upper case
        if (isalpha(text[i]))
        {
            result += toupper(text[i]);
        }
    }
    return result;
}
// Check the valdition of the Key To make sure that is postive integer 1-13
bool check_valid_group(string group)
{
    for (int i = 0; i < group.length(); i++)
    {
        // if Current Character not Digit return false
        if (!isdigit(group[i]))
        {
            return false;
        }
    }
    // conver it to integer then Check if it in range 1-13
    if (stoi(group) > 13 || stoi(group) < 1)
    {
        return false;
    }
    return true;
}
void atbash_cipher(string plainText, int group)
{
    string chipherText = "";
    // Length fo of the Each Segement according to number of group
    int segmentLength = 26 / group;
    for (char ch : plainText)
    {
        // To Check if the current Character in the Segements or not
        bool flage = 0;
        for (int i = 0; i < group; i++)
        {
            char left = 'A' + i * segmentLength;
            char right = left + segmentLength - 1;
            if (ch >= left && ch <= right)
            {
                chipherText += char(right - (ch - left));
                flage = 1;
                break;
            }
        }
        // if the current Character Not in any Segements output it as it is
        if (!flage)
        {
            chipherText += ch;
        }
    }
    cout << chipherText << endl;
}

// Cipher 3
bool Only_Alpha(string keyword)
{
    int length = keyword.length();
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(keyword[i])) {
            return false;
        }
    }
    return true;
}
//to check if the length of the input is more than 80 (Doctor's Obligation)
bool More_Than_80(string word)
{
    if (word.length() > 80) {
        return true;
    }
    return false;
}
//to check if the length of the kew_word is more than 8 (Doctor's Obligation)
bool More_Than_8(string keyword) {
    if (keyword.length() > 8) {
        return true;
    }
    return false;
}
string v_encode(string word, string keyword)
{
    int w_length = word.size();
    string encoded = "";

    //to find the encrypted Message
    for (int i = 0; i < w_length; i++) {
        if (!isalpha(word[i])) {
            encoded.push_back(word[i]);
            continue;
        }

        //Operations of encryption
        int sum = word[i] + keyword[i];
        //'A' = 65
        int op = sum % 26 + 'A';
        encoded.push_back(char(op));
    }
    //final Answer
    return encoded;
}
string v_decypher(string cyphered, string keyword)
{
    int w_length = cyphered.length();
    string new_keyword = "";
    for (int i = 0, j = 0; i < w_length; i++, j++) {
        if (j == keyword.length()) {
            j = 0;
        }
        new_keyword.push_back(keyword[j]);
    }
    keyword = new_keyword;

    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string message = "";
    for (int i = 0; i < w_length; i++)
    {
        if (!isalpha(cyphered[i]))
        {
            message.push_back(cyphered[i]);
            continue;
        }
        int diff = cyphered[i] - 'A';
        for (char ch : alphabets)
        {
            if ((ch + keyword[i]) % 26 == diff)
            {
                message.push_back(ch);
            }
        }
    }
    return message;
}
// "1" for cipher and "2" for decipher
void vignere(string choose)
{
    cout << "Please enter the de/cyphered Message: \n";
    string word, keyword;
    getline(cin, word);

    while (More_Than_80(word)) {
        cout << "Invalid Input, the de/cyphered Message should be restricted to 80 Characters.\n";
        cout << "Please try again!\n";
        cout << "Enter The Message: \n";
        getline(cin, word);
    }

    cout << "Please enter the Key_Word: \n";
    getline(cin, keyword);
    int w_length = word.length();

    while (Only_Alpha(keyword) == false) {
        cout << "Invalid Input, Key_Word should only contain Alphabets.\n";
        cout << "Please try again!\n";
        cout << "Enter the Key_Word: \n";
        getline(cin, keyword);
    }

    while (More_Than_8(keyword)) {
        cout << "Invalid Input, the Key_word should be restricted to 8 Characters.\n";
        cout << "Please try again!\n";
        cout << "Enter the Key_Word: \n";
        getline(cin, keyword);
    }

    //to switch message to uppercase characters
    for (int i = 0; i < w_length; i++) {
        if (!isalpha(word[i])) {
            continue;
        }
        word[i] = toupper(word[i]);
    }

    //to switch key_word to upper case characters
    for (int i = 0; i < keyword.length(); i++) {
        keyword[i] = toupper(keyword[i]);
    }

    //to find repeated key_word
    string new_keyword = "";
    for (int i = 0, j = 0; i < w_length; i++, j++) {
        if (j == keyword.length()) {
            j = 0;
        }
        new_keyword.push_back(keyword[j]);
    }

    //to use "Keyword" instead of "New_keyword"
    keyword = new_keyword;

    string ans;

    if (choose == "1")
    {
        ans = v_encode(word, keyword);
    }
    else
    {
        ans = v_decypher(word, keyword);
    }

    cout << "The de/cyphered is: " << ans << endl;
}

// Cipher 4
void baconian_encode()
{
    cout << "Please, enter a word to encode: \n";

    string word;
    getline(cin, word);

    int size = word.length();
    for (int i = 0; i < size; i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
        }
        word[i] = toupper(word[i]);
    }

    vector <string> vec;

    for (int i = 0; i < size; i++)
    {
        if (word[i] == 'A')
        {
            vec.push_back("aaaaa");
            vec.push_back(" ");
        }
        else if (isspace(word[i]))
        {
            vec.push_back(" ");
            vec.push_back(" ");
        }
        else if (word[i] == 'B')
        {
            vec.push_back("aaaab");
            vec.push_back(" ");
        }
        else if (word[i] == 'C')
        {
            vec.push_back("aaaba");
            vec.push_back(" ");
        }
        else if (word[i] == 'D')
        {
            vec.push_back("aaabb");
            vec.push_back(" ");
        }
        else if (word[i] == 'E')
        {
            vec.push_back("aabaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'F')
        {
            vec.push_back("aabab");
            vec.push_back(" ");
        }
        else if (word[i] == 'G')
        {
            vec.push_back("aabba");
            vec.push_back(" ");
        }
        else if (word[i] == 'H')
        {
            vec.push_back("aabbb");
            vec.push_back(" ");
        }
        else if (word[i] == 'I')
        {
            vec.push_back("abaaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'J')
        {
            vec.push_back("abaab");
            vec.push_back(" ");
        }
        else if (word[i] == 'K')
        {
            vec.push_back("ababa");
            vec.push_back(" ");
        }
        else if (word[i] == 'L')
        {
            vec.push_back("ababb");
            vec.push_back(" ");
        }
        else if (word[i] == 'M')
        {
            vec.push_back("abbaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'N')
        {
            vec.push_back("abbab");
            vec.push_back(" ");
        }
        else if (word[i] == 'O')
        {
            vec.push_back("abbba");
            vec.push_back(" ");
        }
        else if (word[i] == 'P')
        {
            vec.push_back("abbbb");
            vec.push_back(" ");
        }
        else if (word[i] == 'Q')
        {
            vec.push_back("baaaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'R')
        {
            vec.push_back("baaab");
            vec.push_back(" ");
        }
        else if (word[i] == 'S')
        {
            vec.push_back("baaba");
            vec.push_back(" ");
        }
        else if (word[i] == 'T')
        {
            vec.push_back("baabb");
            vec.push_back(" ");
        }
        else if (word[i] == 'U')
        {
            vec.push_back("babaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'V')
        {
            vec.push_back("babab");
            vec.push_back(" ");
        }
        else if (word[i] == 'W')
        {
            vec.push_back("babba");
            vec.push_back(" ");
        }
        else if (word[i] == 'X')
        {
            vec.push_back("babbb");
            vec.push_back(" ");
        }
        else if (word[i] == 'Y')
        {
            vec.push_back("bbaaa");
            vec.push_back(" ");
        }
        else if (word[i] == 'Z')
        {
            vec.push_back("bbaab");
            vec.push_back(" ");
        }
        else
        {
            continue;
        }
    }

    int veclength = vec.size();

    for (int i = 0; i < veclength; i++)
    {
        cout << vec[i];
    }
    cout << endl;
}
void baconian_decode()
{
    cout << "Please enter a word to decode: \n";
    string ciphered;
    getline(cin, ciphered);

    int size = ciphered.length();

    string newcipher = "";
    for (int i = 0; i < size; i++) {
        if (ciphered[i] == 'a' || ciphered[i] == 'A' || ciphered[i] == '0')
        {
            ciphered[i] = 'a';
        }
        else if (ciphered[i] == 'b' || ciphered[i] == 'B' || ciphered[i] == '1')
        {
            ciphered[i] = 'b';
        }
        if (isspace(ciphered[i]))
        {
            newcipher.push_back(ciphered[i]);
            continue;
        }
        if (!isalpha(ciphered[i]) || ciphered[i] != 'a' && ciphered[i] != 'b')
        {
            continue;
        }
        newcipher.push_back(ciphered[i]);
    }
    ciphered = newcipher;
    size = ciphered.length();

    string answer = "";

    for (int i = 0; i < size; i += 5)
    {
        string cont = "";
        if (ciphered[i] == ' ' && ciphered[i + 1] == ' ' && ciphered[i + 2] == ' ')
        {
            answer.push_back(' ');
            i += 3;
        }
        else if (ciphered[i] == ' ')
        {
            i++;
        }

        for (int j = i; j < 5 + i; j++)
        {
            if (j >= ciphered.length()) { continue; }
            cont.push_back(ciphered[j]);
        }

        if (cont == "aaaaa")
        {
            answer.push_back('A');
        }
        else if (cont == "aaaab")
        {
            answer.push_back('B');
        }
        else if (cont == "aaaba")
        {
            answer.push_back('C');
        }
        else if (cont == "aaabb")
        {
            answer.push_back('D');
        }
        else if (cont == "aabaa")
        {
            answer.push_back('E');
        }
        else if (cont == "aabab")
        {
            answer.push_back('F');
        }
        else if (cont == "aabba")
        {
            answer.push_back('G');
        }
        else if (cont == "aabbb")
        {
            answer.push_back('H');
        }
        else if (cont == "abaaa")
        {
            answer.push_back('I');
        }
        else if (cont == "abaab")
        {
            answer.push_back('J');
        }
        else if (cont == "ababa")
        {
            answer.push_back('K');
        }
        else if (cont == "ababb")
        {
            answer.push_back('L');
        }
        else if (cont == "abbaa")
        {
            answer.push_back('M');
        }
        else if (cont == "abbab")
        {
            answer.push_back('N');
        }
        else if (cont == "abbba")
        {
            answer.push_back('O');
        }
        else if (cont == "abbbb")
        {
            answer.push_back('P');
        }
        else if (cont == "baaaa")
        {
            answer.push_back('Q');
        }
        else if (cont == "baaab")
        {
            answer.push_back('R');
        }
        else if (cont == "baaba")
        {
            answer.push_back('S');
        }
        else if (cont == "baabb")
        {
            answer.push_back('T');
        }
        else if (cont == "babaa")
        {
            answer.push_back('U');
        }
        else if (cont == "babab")
        {
            answer.push_back('V');
        }
        else if (cont == "babba")
        {
            answer.push_back('W');
        }
        else if (cont == "babbb")
        {
            answer.push_back('X');
        }
        else if (cont == "bbaaa")
        {
            answer.push_back('Y');
        }
        else if (cont == "bbaab")
        {
            answer.push_back('Z');
        }
    }
    cout << answer << endl;;
}

// Cipher 5
void polybius_square_cipher(){
    // Key
    string key;
    cout << "Enter a key from (1-5) at any order and non-repeating numbers" << endl;
    getline(cin, key);
    // Check validation of the key
    while (true) {
        while (key.length() != 5) {
            cout << "Enter a valid key!" << endl;
            getline(cin, key);
        }
        if (key.length() == 5) {
            // Check key contains (1-5) at any order
            char separated_key[5];
            for (int i = 0; i < 5; ++i) {
                separated_key[i] = key[i];
            }
            sort(separated_key, separated_key + 5);
            if (separated_key[0] == '1' and separated_key[1] == '2' and separated_key[2] == '3' and separated_key[3] == '4' and separated_key[4] == '5') {
                break;
            }
            key = "";
        }
    }
    // message the user wants to cipher
    cout << "Please enter message" << endl;
    string message, modified_message;
    getline(cin, message);
    // modify message so it contains alphabetic characters and spaces
    for (int i = 0; i < message.length(); ++i) {
        // alphabetic characters
        if (isalpha(message[i])){

            modified_message.push_back((char) tolower(message[i]));
        }
            // spaces
        else if (isspace(message[i])){
            modified_message.push_back(' ');
        }
    }
    // array mimics the polybius square index 0 is 'a' and so on (without j)
    int polybius_square_numbers[25] = {}, index = 0;
    // Set numbers in the array
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            polybius_square_numbers[index++] = ((int) key[i] - '0') * 10 + (int) key[j] - '0';
        }
    }
    // Turn characters into numbers of polybius square and removes j
    // Turn character into an index for the square
    string ciphered_message;
    for (int i = 0; i < modified_message.length(); ++i) {
        if (isspace(modified_message[i])) {
            ciphered_message.push_back(' ');
        } else {
            int location;
            if (modified_message[i] > 'i') {
                location = modified_message[i] - 'a' - 1;
            } else {
                location = modified_message[i] - 'a';
            }
            ciphered_message += to_string(polybius_square_numbers[location]);
        }
    }
    // Display Ciphered message
    cout << "Cipher text: " << ciphered_message << endl;
}
void polybius_square_decipher(){
    // Key
    string key;
    cout << "Enter a key from (1-5) at any order and non-repeating numbers" << endl;
    getline(cin, key);
    // Check validation of the key
    while (true) {
        while (key.length() != 5) {
            cout << "Enter a valid key!" << endl;
            getline(cin, key);
        }
        if (key.length() == 5) {
            // Check key contains (1-5) at any order
            char separated_key[5];
            for (int i = 0; i < 5; ++i) {
                separated_key[i] = key[i];
            }
            sort(separated_key, separated_key + 5);
            if (separated_key[0] == '1' and separated_key[1] == '2' and separated_key[2] == '3' and separated_key[3] == '4' and separated_key[4] == '5') {
                break;
            }
            key = "";
        }
    }
    // array mimics the polybius square index 0 is 'a' and so on (without j)
    int polybius_square_numbers[25] = {}, index = 0;
    // Set numbers in the array
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            polybius_square_numbers[index++] = ((int) key[i] - '0') * 10 + (int) key[j] - '0';
        }
    }
    cout << "Please enter cipher text" << endl;
    string cipher_text, plain_text;
    getline(cin, cipher_text);
    // Check that input is valid
    // turn every two adjacent numbers into an index and turn it into a letter
    bool is_found = false;
    for (int i = 0; i < cipher_text.length(); ++i) {
        if (isspace(cipher_text[i])) {
            plain_text.push_back(' ');
        } else {
            // Validate input
            if ( !(isdigit(cipher_text[i]) and isdigit(cipher_text[i+1])) ){
                is_found = false;
                break;
            }
            int two_numbers = (cipher_text[i] - '0') * 10 + cipher_text[i+1] - '0';
            i++;
            // Validate input
            if ((two_numbers / 10 > 5) or (two_numbers / 10 < 1) or (two_numbers % 10 > 5) or (two_numbers % 10 < 1)){
                is_found = false;
                break;
            }
            // Turn numbers to letters
            for (int j = 0; j < 25; ++j) {
                if (two_numbers == polybius_square_numbers[j]) {
                    is_found = true;
                    if (j > 8) {
                        plain_text.push_back((char) ('a' + j + 1));
                    } else {
                        plain_text.push_back((char) ('a' + j));
                    }
                    break;
                }
            }
        }
    }
    // Display Plain text if it's valid
    if (is_found)
        cout << "Plain text: " << plain_text << endl;
    else
        cout << "Cipher Text is wrong!" << endl;
}

// Cipher 6
void simple_substitution_cipher(){
    // Key of letters
    string key;
    cout << "Please enter a key of 5 letters and they must be unique" << endl;
    getline(cin, key);
    // Check if the key is valid
    while (true) {
        while (key.length() != 5) {
            cout << "Wrong key" << endl;
            getline(cin, key);
        }
        // turn key into small letters
        for (int i = 0; i < 5; ++i) {
            key[i] = (char) tolower(key[i]);
        }
        char separated_key[5];
        bool valid_input = true;
        // separate key into chars and check if it's letters
        for (int i = 0; i < 5; ++i) {
            if (isalpha(key[i])) {
                separated_key[i] = key[i];
            } else {
                valid_input = false;
                break;
            }
        }
        // check if letters is unique
        sort(separated_key, separated_key + 5);
        for (int i = 0; i < 4; ++i) {
            if (separated_key[i] == separated_key[i+1]){
                valid_input = false;
                break;
            }
        }
        if (valid_input) {
            break;
        }
        key = "";
    }
    // Array index 0 is 'a' and index 25 is 'z'
    // The first five letters are filled with the key letters and the rest are
    // filled with the rest letters with an order
    char substitution[26] {key[0], key[1], key[2], key[3], key[4]};
    int index = 5;
    // if place is empty fill it with the next letter in alphabet if the letter is not taken
    for (int i = 0; i < 26; ++i) {
        bool exists = false;
        for (int j = 0; j < 5; ++j) {
            if ('a' + i == key[j]){
                exists = true;
                break;
            }
        }
        if (!exists) {
            substitution[index++] =(char) ('a' + i);
        }
    }
    // take input from user
    cout << "Please enter plain text" << endl;
    string plain_text, cipher_text;
    // loops if input is empty
    while (true) {
        getline(cin, plain_text);
        if (plain_text.empty()) {
            cout << "Please input something" << endl;
        } else {
            break;
        }
    }
    // turn letter in the plain text to an index for the substitution array
    // where 'a' is 0 and 'z' is 25 and get that letter from the substitution array
    for (int i = 0; i < plain_text.length(); ++i) {
        if (isalpha(plain_text[i])){
            cipher_text.push_back(substitution[tolower(plain_text[i]) - 'a']);
        } else {
            cipher_text.push_back(plain_text[i]);
        }
    }
    // Display cipher
    cout << "Cipher text: " << cipher_text << endl;
}
void simple_substitution_decipher(){
    // Key of letters
    string key;
    cout << "Please enter the key of five unique letters" << endl;
    getline(cin, key);
    // Check if the key is valid
    while (true) {
        while (key.length() != 5) {
            cout << "Wrong key" << endl;
            getline(cin, key);
        }
        // turn key into small letters
        for (int i = 0; i < 5; ++i) {
            key[i] = (char) tolower(key[i]);
        }
        char separated_key[5];
        bool valid_input = true;
        // separate key into chars and check if it's letters
        for (int i = 0; i < 5; ++i) {
            if (isalpha(key[i])) {
                separated_key[i] = key[i];
            } else {
                valid_input = false;
                break;
            }
        }
        // check if letters is unique
        sort(separated_key, separated_key + 5);
        for (int i = 0; i < 4; ++i) {
            if (separated_key[i] == separated_key[i+1]){
                valid_input = false;
                break;
            }
        }
        if (valid_input) {
            break;
        }
        key = "";
    }
    // initialize substitution array
    char substitution[26] = {};
    int value = 0;
    // turn every letter in the key into an index place for every one a letter from 'a' to 'e' in order
    for (int i = 0; i < 5; ++i) {
        substitution[key[i] - 'a'] = (char) ('a' + i);
    }
    // check if place in the array is empty and fill the rest with letters in order
    for (int i = 0; i < 26; ++i) {
        if (substitution[i] == '\0') {
            substitution[i] = (char) ('f' + value);
            value++;
        }
    }
    // take cipher
    cout << "Please enter cipher text" << endl;
    string plain_text, cipher_text;
    // loops if input is empty
    while (true) {
        getline(cin, cipher_text);
        if (cipher_text.empty()) {
            cout << "Please input something" << endl;
        } else {
            break;
        }
    }
    // turn letter in the plain text to an index for the substitution array
    for (int i = 0; i < cipher_text.length(); ++i) {
        if (isalpha(cipher_text[i])){
            plain_text.push_back(substitution[tolower(cipher_text[i]) - 'a']);
        } else {
            plain_text.push_back(cipher_text[i]);
        }
    }
    // Display plain text
    cout << "Plain text: " << plain_text << endl;
}

// Cipher 7
// Converts Text to Morse code
void morse_encoder(){
    bool flag = true;
    // Loops if input is wrong
    while (flag) {
        flag = false;
        string text, morse;
        // Takes input from user
        cout << "Please enter text" << endl;
        getline(cin, text);
        // makes sure user entered an input
        if (text.empty()) {
            cout << "Error: Please enter something!" << endl;
            flag = true;
            continue;
        }
        // Loops for every character
        for (char i: text) {
            // If alphabet character exists converts it to morse (contains known alphabet in english only)
            if (isalpha(i)) {
                i = char(tolower(i));
                if (i == 'a')
                    morse += ".-";
                else if (i == 'b')
                    morse += "-...";
                else if (i == 'c')
                    morse += "-.-.";
                else if (i == 'd')
                    morse += "-..";
                else if (i == 'e')
                    morse.push_back('.');
                else if (i == 'f')
                    morse += "..-.";
                else if (i == 'g')
                    morse += "--.";
                else if (i == 'h')
                    morse += "....";
                else if (i == 'i')
                    morse += "..";
                else if (i == 'j')
                    morse += ".---";
                else if (i == 'k')
                    morse += "-.-";
                else if (i == 'l')
                    morse += ".-..";
                else if (i == 'm')
                    morse += "--";
                else if (i == 'n')
                    morse += "-.";
                else if (i == 'o')
                    morse += "---";
                else if (i == 'p')
                    morse += ".--.";
                else if (i == 'q')
                    morse += "--.-";
                else if (i == 'r')
                    morse += ".-.";
                else if (i == 's')
                    morse += "...";
                else if (i == 't')
                    morse.push_back('-');
                else if (i == 'u')
                    morse += "..-";
                else if (i == 'v')
                    morse += "...-";
                else if (i == 'w')
                    morse += ".--";
                else if (i == 'x')
                    morse += "-..-";
                else if (i == 'y')
                    morse += "-.--";
                else if (i == 'z')
                    morse += "--..";
                else {
                    cout << "Unknown character \'" << i << "\', Please try again!" << endl;
                    flag = true;
                    break;
                }
                // if there is a space adds a space (between words
            } else if (isspace(i)) {
                morse.push_back(' ');
            }
                // if it is a digit converts it to Morse code
            else if (isdigit(i)) {
                if (i < 53) {
                    for (int j = 48; j < i; ++j) {
                        morse.push_back('.');
                    }
                    for (int j = 0; j < 53 - i; ++j) {
                        morse.push_back('-');
                    }
                } else {
                    for (int j = 53; j < i; ++j) {
                        morse.push_back('-');
                    }
                    for (int j = 0; j < 58 - i; ++j) {
                        morse.push_back('.');
                    }
                }
                // If it is a known symbol in morse
            } else {
                if (i == '&')
                    morse += ".-...";
                else if (i == '\'')
                    morse += ".----.";
                else if (i == '@')
                    morse += ".--.-.";
                else if (i == ')')
                    morse += "-.--.-";
                else if (i == '(')
                    morse += "-.--.";
                else if (i == ':')
                    morse += "---...";
                else if (i == ',')
                    morse += "--..--";
                else if (i == '=')
                    morse += "-...-";
                else if (i == '!')
                    morse += "-.-.--";
                else if (i == '.')
                    morse += ".-.-.-";
                else if (i == '-')
                    morse += "-....-";
                else if (i == '+')
                    morse += ".-.-.";
                else if (i == '\"')
                    morse += ".-..-.";
                else if (i == '?')
                    morse += "..--..";
                else if (i == '/')
                    morse += "-..-.";
                else if (i == ';')
                    morse += "-.-.-.";
                else {
                    // For Unknown characters as '$'
                    cout << "Unknown character \'" << i << "\', Please try again!" << endl;
                    flag = true;
                    break;
                }
            }
            // adds space for each character in morse
            morse.push_back(' ');
        }
        // if there is an error, it won't print morse code
        if(not flag)
            cout << "The Code is: " << morse << endl;
    }
}
// Converts Morse code to readable Text
// Note: there is no capital letters
void morse_decoder(){
    bool flag = true;
    // Loops if input is wrong
    while (flag) {
        flag = false;
        // part is for every part in morse code
        string code, text, part;
        // Takes morse code form user
        cout << "Please enter morse code" << endl;
        getline(cin, code);
        // Make sure the input isn't empty
        if (code.empty()) {
            cout << "Error: Please enter something!" << endl;
            flag = true;
            continue;
        }
        // Adds space at the end to solve a bug
        if (code[code.size() - 1] != ' ')
            code.push_back(' ');
        // Loops for every Code in Morse code
        bool mini_flag = false;
        for (char i : code) {
            // Creates words till a space is found in variable Part
            if (i == '.' or i == '-') {
                part.push_back(i);
                mini_flag = false;
            } else if (isspace(i)) {
                // Space
                if (part.empty()) {
                    if (mini_flag) {
                        text.push_back(' ');
                        mini_flag = false;
                    }
                    else
                        mini_flag = true;
                }
                    // Alphabet
                else if (part == ".-")
                    text.push_back('a');
                else if (part == "-...")
                    text.push_back('b');
                else if (part == "-.-.")
                    text.push_back('c');
                else if (part == "-..")
                    text.push_back('d');
                else if (part == ".")
                    text.push_back('e');
                else if (part == "..-.")
                    text.push_back('f');
                else if (part == "--.")
                    text.push_back('g');
                else if (part == "....")
                    text.push_back('h');
                else if (part == "..")
                    text.push_back('i');
                else if (part == ".---")
                    text.push_back('j');
                else if (part == "-.-")
                    text.push_back('k');
                else if (part == ".-..")
                    text.push_back('l');
                else if (part == "--")
                    text.push_back('m');
                else if (part == "-.")
                    text.push_back('n');
                else if (part == "---")
                    text.push_back('o');
                else if (part == ".--.")
                    text.push_back('p');
                else if (part == "--.-")
                    text.push_back('q');
                else if (part == ".-.")
                    text.push_back('r');
                else if (part == "...")
                    text.push_back('s');
                else if (part == "-")
                    text.push_back('t');
                else if (part == "..-")
                    text.push_back('u');
                else if (part == "...-")
                    text.push_back('v');
                else if (part == ".--")
                    text.push_back('w');
                else if (part == "-..-")
                    text.push_back('x');
                else if (part == "-.--")
                    text.push_back('y');
                else if (part == "--..")
                    text.push_back('z');
                    // Numbers
                else if (part == "-----")
                    text.push_back('0');
                else if (part == ".----")
                    text.push_back('1');
                else if (part == "..---")
                    text.push_back('2');
                else if (part == "...--")
                    text.push_back('3');
                else if (part == "....-")
                    text.push_back('4');
                else if (part == ".....")
                    text.push_back('5');
                else if (part == "-....")
                    text.push_back('6');
                else if (part == "--...")
                    text.push_back('7');
                else if (part == "---..")
                    text.push_back('8');
                else if (part == "----.")
                    text.push_back('9');
                    // Symbols
                else if (part == ".-...")
                    text.push_back('&');
                else if (part == ".----.")
                    text.push_back('\'');
                else if (part == ".--.-.")
                    text.push_back('@');
                else if (part == "-.--.-")
                    text.push_back(')');
                else if (part == "-.--.")
                    text.push_back('(');
                else if (part == "---...")
                    text.push_back(':');
                else if (part == "-.-.-.")
                    text.push_back(';');
                else if (part == "--..--")
                    text.push_back(',');
                else if (part == "-...-")
                    text.push_back('=');
                else if (part == ".-.-.-")
                    text.push_back('.');
                else if (part == "-....-")
                    text.push_back('-');
                else if (part == ".-.-.")
                    text.push_back('+');
                else if (part == ".-..-.")
                    text.push_back('\"');
                else if (part == "..--..")
                    text.push_back('?');
                else if (part == "-..-.")
                    text.push_back('/');
                else if (part == "-.-.--")
                    text.push_back('!');
                else {
                    // If it is wrong morse code
                    cout << "Wrong input!" << endl;
                    flag = true;
                    break;
                }
                // Resets part after every character
                part = "";
            } else {
                // If it is wrong  morse code
                cout << "Wrong input!" << endl;
                flag = true;
                break;
            }
        }
        // if there is an error, it won't text
        if (not flag)
            cout << "The message is: " << text << endl;
    }
}

// Cipher 8
// Check the validation of the Key to check if it contains only Alphabetical
bool checkValidationKey(string key)
{
    for(char ch: key)
    {
        if(!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}
// Check the validation of the  ciphertextHex
bool checkValidationHexa(string ciphertextHex)
{
    for(char ch: ciphertextHex)
    {
        // check If any character is not a valid hexadecimal
        if(!isxdigit(ch))
        {
            return false;
        }
    }
    return true;
}
// Decrypt the cypher hexadecimal to plain Text
void xorDecrypt(string ciphertextHex, string key)
{
    string plaintext;
    // vector to store ascii value of the bytes
    vector<int> ciphertextAscii;
    // loop over each two byte of hexa
    for (int i = 0; i < ciphertextHex.length(); i += 2)
    {
        // convert each two hexa bytes to ascii value
        // stoi function to make sure that the two bytes of the hexa is base 16
        int ascii = std::stoi(ciphertextHex.substr(i, 2), nullptr, 16);
        // Push the ascii value to the vector
        ciphertextAscii.push_back(ascii);
    }
    // loop over all ascii values then convert these values to his Characters
    for (int i = 0; i < ciphertextAscii.size(); i++)
    {
        // XOR  ascii values of vector with  ascii values of key
        // then convert the result to his Characters
        plaintext += char(ciphertextAscii[i] ^ key[i % key.length()]);
    }
    cout << "Plain text: " << plaintext << endl;
    return;
}
void xorEncrypt(string plaintext, string key)
{
    string ciphertext = "";
    string cipherHexa = "";
    // Loop on each Character of plain text
    for (int i = 0; i < plaintext.length(); i++)
    {
        // XOR  ascii values of plain Text with  ascii values of key
        int asciiValue = plaintext[i] ^ key[i % key.length()];
        // Make Stream Object to Store the Hexa Values of the asciiValue
        stringstream streamObj;
        // convert ascii values to hexa and ensure that it always two bytes
        streamObj << hex << setw(2) << setfill('0') << asciiValue;
        // convert to string then append it to cipherHexa
        cipherHexa += streamObj.str();
        // XOR  ascii values of plain Text with  ascii values of key then convert it to char
        ciphertext += plaintext[i] ^ key[i % key.length()];
    }
    cout << "Cipher Text: " << ciphertext << endl;
    cout << "Cipher Hexa: " << cipherHexa << endl;
    return;
}

// Cipher 9
// Function to decode a message encoded using the rail fence cipher
void decoded_rail_fence() {
    string word;
    cout << "PLease, enter a word to decode: \n";

    //to accept spaces
    getline(cin, word);

    int length = word.size();

    //to save the word without spaces in it
    string only_alpha = "";

    //to remove spaces
    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            only_alpha.push_back(word[i]);
        }
    }

    //to change the unwanted word in "word with the wanted one
    word = only_alpha;

    //to get the new length after removing the spaces
    length = word.size();

    //to slice the word
    string first_row = "";
    string second_row = "";
    string third_row = "";

    /*in the following loops, i divided the word into three raws, the fist contain first quarter, the second contain the half after the first quarter
    and the last contain the last contain the last quarter (1/4 + 1/2 + 1/4 = 1)*/

    //to handel all possible cases of slicing
    if (length % 4 == 0 && length != 4) {

        for (int i = 0; i < length / 4; i++) {
            first_row.push_back(word[i]);
        }

        for (int i = length / 4; i < (3 * length) / 4; i++) {
            second_row.push_back(word[i]);
        }

        for (int i = (3 * length) / 4; i < length; i++) {
            third_row.push_back(word[i]);
        }
    }

        //to handel all possible cases of slicing
    else if (length % 2 == 0 && length != 4) {

        for (int i = 0; i < length / 4 + 1; i++) {
            first_row.push_back(word[i]);
        }

        for (int i = length / 4 + 1; i < (3 * length) / 4 + 1; i++) {
            second_row.push_back(word[i]);
        }

        for (int i = (3 * length) / 4 + 1; i < length; i++) {
            third_row.push_back(word[i]);
        }
    }

    //to handel all possible cases of slicing
    if ((length - 3) % 4 == 0) {
        for (int i = 0; i < length / 4 + 1; i++) {
            first_row.push_back(word[i]);
        }

        for (int i = length / 4 + 1; i < (3 * length) / 4; i++) {
            second_row.push_back(word[i]);
        }

        for (int i = (3 * length) / 4; i < length; i++) {
            third_row.push_back(word[i]);
        }
    }

    //to handel all possible cases of slicing
    if ((length - 3) % 4 != 0 && length % 2 != 0) {
        for (int i = 0; i < length / 4 + 1; i++) {
            first_row.push_back(word[i]);
        }

        for (int i = length / 4 + 1; i < (3 * length) / 4 + 1; i++) {
            second_row.push_back(word[i]);
        }

        for (int i = (3 * length) / 4 + 1; i < length; i++) {
            third_row.push_back(word[i]);
        }
    }

    //to handel all possible cases of slicing
    if (length == 4) {
        first_row.push_back(word[0]);
        second_row = second_row + word[1] + word[2];
        third_row.push_back(word[3]);
    }

    //to handel all possible cases of slicing
    if (length == 1) {
        cout << word[0] << endl;
        return;
    }

    string new_word = "";
    int n = 0;
    for (int i = 0; i < length; i++) {
        if (i < first_row.length()) {
            new_word.push_back(first_row[i]);
        }
        if (i + n < second_row.length()) {
            new_word.push_back(second_row[i + n]);
        }
        n++;
        if (i < third_row.length()) {
            new_word.push_back(third_row[i]);
        }
        if (i + n < second_row.length()) {
            new_word.push_back(second_row[i + n]);
        }
    }
    cout << "The decrypted word is: " << new_word << endl;
}
// function to perform word encryption
/*this function is made using real examples of  Rail - fence Cipher
and how the encryption actually work, which means it's a fixed sequence (I really tried hard to discover it using a lot of examples :] )*/
string reshape(string word)
{
    int length = word.size();
    string new_word = "";

    for (int i = 0; i < length; i = i + 4)
    {
        //to avoid string overflow
        if (i >= length)
        {
            break;
        }
        new_word.push_back(word[i]);
    }
    for (int i = 1; i < length; i = i + 2)
    {
        //to avoid string overflow
        if (i >= length)
        {
            break;
        }
        new_word.push_back(word[i]);
    }
    for (int i = 2; i < length; i = i + 4)
    {
        new_word.push_back(word[i]);
    }
    return new_word;
}
void encoded_rail_fence() {
    string word;

    cout <<  "Enter text you want to cipher" << endl;

    //to include the spaces of input in the string
    getline(cin, word);

    //this variable is to add the new string in it
    string new_word = "";

    int length = word.size();

    for (int i = 0; i < length; i++)
    {
        //to skip spaces in the new word
        if (isalpha(word[i]))
        {
            //to convert all letters to small ones
            word[i] = char(tolower(word[i]));
            new_word.push_back(word[i]);
        }
    }

    //to encrypt the new word and save it in "word" variable
    word = reshape(new_word);

    length = word.size();

    // Display Text before cipher

    // First row
    for (int i = 0; i < length; i++) {
        cout << new_word[i];
        int n_max_dots = 0;
        while (n_max_dots < 3 and i < length - 1) {
            cout << '.';
            n_max_dots++;
            i++;
        }
    }
    // Second row
    cout << endl << '.';
    for (int i = 1; i < length; i++) {
        cout << new_word[i];
        int n_max_dots = 0;
        while (n_max_dots < 1 and i < length - 1) {
            cout << '.';
            n_max_dots++;
            i++;
        }
    }
    // Third row
    cout << endl << "..";
    for (int i = 2; i < length; i++) {
        cout << new_word[i];
        int n_max_dots = 0;
        while (n_max_dots < 3 and i < length - 1) {
            cout << '.';
            n_max_dots++;
            i++;
        }
    }

    // Display encrypted text
    cout  << endl << "The encrypted word is: " << word << endl;
}


int main() {
    while (true) {
        cout << "Ahlan ya user ya habibi." << endl;
        cout << "What do you like to do today?" << endl;
        cout << "1- Cipher a message" << endl;
        cout << "2- Decipher a message" << endl;
        cout << "3- End" << endl;
        string mode;
        cin >> mode;
        string option;
        if (mode == "1") {
            while (true) {
                cout << "Which Cipher do you like to choose?" << endl;
                cout << "0- Affine Cipher" << endl;
                cout << "1- Route Cipher" << endl;
                cout << "2- Atbash Cipher" << endl;
                cout << "3- Vignere Cipher" << endl;
                cout << "4- Baconian Cipher" << endl;
                cout << "5- Simple Substitution Cipher." << endl;
                cout << "6- Polybius Square Cipher" << endl;
                cout << "7- Morse code" << endl;
                cout << "8- XOR Cipher" << endl;
                cout << "9- Rail-fence Cipher" << endl;
                cout << "10- Return" << endl;
                cin >> option;
                cin.ignore();
                if (option == "0") {
                    a_menu(mode);
                    break;
                } else if (option == "1") {
                    Route(mode);
                    break;
                } else if (option == "2") {
                    string plainText;
                    cout << "Please, Enter a Plain Text: ";
                    getline(cin, plainText, '\n');
                    string group;
                    cout << "Please, Enter a Number of Group(1-13): ";
                    cin >> group;
                    while (!check_valid_group(group))
                    {
                        cout << "Please, Enter a Number of Group(1-13): ";
                        cin >> group;
                    }
                    plainText = formatting(plainText);
                    atbash_cipher(plainText, stoi(group));
                    cin.ignore();
                    cout << endl;
                    break;
                } else if (option == "3") {
                    vignere(mode);
                    break;
                } else if (option == "4") {
                    baconian_encode();
                    break;
                } else if (option == "5") {
                    simple_substitution_cipher();
                    break;
                } else if (option == "6") {
                    polybius_square_cipher();
                    break;
                } else if (option == "7") {
                    morse_encoder();
                    break;
                } else if (option == "8") {
                    cout << "Please Enter a plain Text: ";
                    string plainText, key;
                    getline(cin, plainText, '\n');
                    cout << "Please Enter a Secret key: ";
                    getline(cin, key, '\n');
                    while(!checkValidationKey(key))
                    {
                        cout << "Invalid input Please enter Alphabetical characters only: ";
                        getline(cin, key, '\n');
                    }
                    xorEncrypt(plainText, key);
                    break;
                } else if (option == "9") {
                    encoded_rail_fence();
                    break;
                } else if (option == "10") {
                    cout << endl;
                    break;
                }
            }
            if (option != "10") {
                cout << endl << "Press Enter to Return...";
                cin.ignore();
                cout << endl;
            }
        } else if (mode == "2") {
            while (true) {
                cout << "Which Decipher do you like to choose?" << endl;
                cout << "0- Affine Cipher" << endl;
                cout << "1- Route Cipher" << endl;
                cout << "2- Atbash Cipher" << endl;
                cout << "3- Vignere Cipher" << endl;
                cout << "4- Baconian Cipher" << endl;
                cout << "5- Simple Substitution Cipher." << endl;
                cout << "6- Polybius Square Cipher" << endl;
                cout << "7- Morse code" << endl;
                cout << "8- XOR Cipher" << endl;
                cout << "9- Rail-fence Cipher" << endl;
                cout << "10- Return" << endl;
                cin >> option;
                cin.ignore();
                if (option == "0") {
                    a_menu(mode);
                    break;
                } else if (option == "1") {
                    Route(mode);
                    break;
                } else if (option == "2") {
                    string plainText;
                    cout << "Please, Enter a Plain Text: ";
                    getline(cin, plainText, '\n');
                    string group;
                    cout << "Please, Enter a Number of Group(1-13): ";
                    cin >> group;
                    while (!check_valid_group(group))
                    {
                        cout << "Please, Enter a Number of Group(1-13): ";
                        cin >> group;
                    }
                    plainText = formatting(plainText);
                    atbash_cipher(plainText, stoi(group));
                    cin.ignore();
                    cout << endl;
                    break;
                } else if (option == "3") {
                    vignere(mode);
                    break;
                } else if (option == "4") {
                    baconian_decode();
                    break;
                } else if (option == "5") {
                    simple_substitution_decipher();
                    break;
                } else if (option == "6") {
                    polybius_square_decipher();
                    break;
                } else if (option == "7") {
                    morse_decoder();
                    break;
                } else if (option == "8") {
                    cout << "Please Enter a Cipher Text: ";
                    string cipherText, key;
                    getline(cin, cipherText, '\n');
                    while(!checkValidationHexa(cipherText))
                    {
                        cout << "Invalid input Please enter valid hexadecimal digit only: ";
                        getline(cin, cipherText, '\n');
                    }
                    cout << "Please Enter a Secret key: ";
                    getline(cin, key, '\n');
                    while(!checkValidationKey(key))
                    {
                        cout << "Invalid input Please enter Alphabetical characters only: ";
                        getline(cin, key, '\n');
                    }
                    xorDecrypt(cipherText, key);
                    break;
                } else if (option == "9") {
                    decoded_rail_fence();
                    break;
                } else if (option == "10") {
                    break;
                }
            }
            if (option != "10") {
                cout << endl << "Press Enter to Return...";
                cin.ignore();
                cout << endl;
            }
        } else if (mode == "3") {
            break;
        }
    }
    return 0;
}
