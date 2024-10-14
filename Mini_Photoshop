// Author: Abdelrahman Nabil Hassan
// Project: Mini Photoshop

#include <bits/stdc++.h>
#include "Lib/Image_Class.h"

#define PI 3.14159265358979323846

using namespace std;

// Get color for user in RGB requires a clean buffer
// Print a message if needed
void get_color(int color[3], string message = "") {
    while (true) {
        if (!message.empty()){
            cout << message << endl;
        }
        cout << "Choose a color!" << endl;
        cout << "1- White" << endl << "2- Black" << endl << "3- Red" << endl ;
        cout << "4- Green" << endl << "5- Blue" << endl << "6- Custom color (RGB)" << endl;
        string option;
        getline(cin, option);
        if (option == "1") {
            color[0] = 255;
            color[1] = 255;
            color[2] = 255;
        } else if (option == "2") {
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
        } else if (option == "3") {
            color[0] = 255;
            color[1] = 0;
            color[2] = 0;
        } else if (option == "4") {
            color[0] = 0;
            color[1] = 255;
            color[2] = 0;
        } else if (option == "5") {
            color[0] = 0;
            color[1] = 0;
            color[2] = 255;
        } else if (option == "6") {
            while (true) {
                cout << "Enter (RGB) number followed by a space (Ex:255 255 255)" << endl;
                getline(cin, option);
                if (regex_match(option, regex(R"(\d+ \d+ \d+)"))) {
                    option.push_back(' ');
                    int index = 0;
                    string part;
                    for (int i = 0; i < option.length(); ++i) {
                        if (isdigit(option[i])) {
                            part.push_back(option[i]);
                        } else {
                            int number = stoi(part);
                            part = "";
                            if (number > 255 or number < 0) {
                                cout << "Invalid (RGB) number!" << endl;
                                break;
                            } else {
                                color[index++] = number;
                            }
                        }
                    }
                    if (index == 3) {
                        break;
                    }
                } else {
                    cout << "Invalid input!" << endl;
                }
            }
        } else {
            cout << "Wrong input!" << endl;
            continue;
        }
        break;
    }
}


// check If the input are Digits
bool checkValidation(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '.' && i > 0)
            continue;
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

// Gets filename if it exists
Image get_file()
{
    while (true)
    {
        try
        {
            string filename;
            cout << "Enter image name: ";
            getline(cin, filename);
            // check the existence of file by opening it
            // if it doesn't exist throw an error
            Image image(filename);
            return image;
        }
            // Handles the error
        catch (const invalid_argument &wh)
        {
            cerr << wh.what() << endl;
        }
    }
}

// give a new valid name
void create_new_file(Image &image)
{
    while (true)
    {
        try
        {
            string filename;
            cout << "Enter new image name to store new image ";
            cout << "and specify extension .jpg, .bmp, .png, .tga:" << endl;
            getline(cin, filename);
            // check validation of file by creating it
            // if it can't create throw an error
            image.saveImage(filename);
            break;
        }
            // Handles the error
        catch (const invalid_argument &wh)
        {
            cerr << wh.what() << endl;
        }
    }
}

// Grayscale function
Image gray_scale(Image image)
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Initialize average
            unsigned short int avg = 0;
            // get pixel values
            for (int k = 0; k < 3; ++k)
            {
                avg += image(i, j, k);
            }
            // Calculate average
            avg /= 3;
            // Set all channels (RGB) to the average value
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = avg;
            }
        }
    }
    return image;
}

// Black And White Function
Image blackWhite(Image img)
{
    // Loop on every Pixel and change their color
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < img.channels; k++)
            {
                avg += img(i, j, k);
            }
            // Calculate the average of All RGB Channels
            avg /= 3;
            // if the Average value brighter
            if (avg >= 128)
            {
                // Set all RGB Channels to the white
                img.setPixel(i, j, 0, 255);
                img.setPixel(i, j, 1, 255);
                img.setPixel(i, j, 2, 255);
            }
            else
            {
                // Set all RGB Channels to the Black
                img.setPixel(i, j, 0, 0);
                img.setPixel(i, j, 1, 0);
                img.setPixel(i, j, 2, 0);
            }
        }
    }
    return img;
}

// Invert Image color
Image invert_image_color(Image image)
{
    // Loop for pixel place
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Loop for channel
            for (int k = 0; k < 3; ++k)
            {
                image.setPixel(i, j, k, 255 - image(i, j, k));
            }
        }
    }
    return image;
}

// Flip Image Vertically or Horizontally
Image flipImage(Image img)
{
    // make image clone to store the Flipped Image
    Image flippedImage(img.width, img.height);
    cout << "Please choose whether you want to flip the image vertically or horizontally\n";
    cout << "1- Horizontally" << endl;
    cout << "2- Vertically" << endl;
    cout << "Choose: ";
    string option;
    getline(cin, option);
    while(option != "1" && option != "2")
    {
        cout << "INVALID INPUT. Please\n";
        cout << "Please choose whether you want to flip the image vertically or horizontally\n";
        cout << "1- Horizontally" << endl;
        cout << "2- Vertically" << endl;
        cout << "Choose: ";
        getline(cin, option);
    }
    // Loop on every Pixel and change their position
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < img.channels; k++)
            {

                if (option == "1") // Flip the image Horizontally
                    flippedImage(i, j, k) = img(img.width - i - 1, j, k);
                else if (option == "2") // Flip the image Vertically
                    flippedImage(i, j, k) = img(i, img.height - j - 1, k);
            }
        }
    }
    return flippedImage;
}

// Function to rotate the image by 90, 180 or 270 degrees
Image rotate_image(Image old_image)
{
    Image new_image(old_image.width, old_image.height);
    string option;
    // Display menu
    while (true)
    {
        cout << "Rotate Image:" << endl;
        cout << "1- Rotate by 90 degrees clock-wise" << endl;
        cout << "2- Rotate by 180 degrees clock-wise" << endl;
        cout << "3- Rotate by 270 degrees clock-wise" << endl;
        getline(cin, option);
        if (option == "1" or option == "3")
        {
            // Fix dimensions when rotated
            new_image.height = old_image.width;
            new_image.width = old_image.height;
        }
        else if (option == "2")
        {
            break;
        }
        else
        {
            cout << "Wrong option!" << endl
                 << endl;
            continue;
        }
        break;
    }
    // Rotate Image to right
    if (option == "1")
    {
        for (int i = 0; i < old_image.width; ++i)
        {
            for (int j = 0; j < old_image.height; ++j)
            {
                new_image(old_image.height - 1 - j, i, 0) = old_image(i, j, 0);
                new_image(old_image.height - 1 - j, i, 1) = old_image(i, j, 1);
                new_image(old_image.height - 1 - j, i, 2) = old_image(i, j, 2);
            }
        }
    }
        // Rotate image to left
    else if (option == "3")
    {
        for (int i = 0; i < old_image.width; ++i)
        {
            for (int j = 0; j < old_image.height; ++j)
            {
                new_image(j, old_image.width - 1 - i, 0) = old_image(i, j, 0);
                new_image(j, old_image.width - 1 - i, 1) = old_image(i, j, 1);
                new_image(j, old_image.width - 1 - i, 2) = old_image(i, j, 2);
            }
        }
    }
        // Rotate image upside down
    else
    {
        for (int i = 0; i < old_image.width; ++i)
        {
            for (int j = 0; j < old_image.height; ++j)
            {
                new_image(old_image.width - 1 - i, old_image.height - 1 - j, 0) = old_image(i, j, 0);
                new_image(old_image.width - 1 - i, old_image.height - 1 - j, 1) = old_image(i, j, 1);
                new_image(old_image.width - 1 - i, old_image.height - 1 - j, 2) = old_image(i, j, 2);
            }
        }
    }
    return new_image;
}

// Crop Images
Image cropImage(Image img)
{
    // The Starting Point(X,Y) To Crop At
    string X, Y;
    cout << "Please, Enter The Starting Point(X,Y) To Crop At\n";
    cout << "X: ";
    getline(cin, X);
    // Check if the input is only digits
    while (!checkValidation(X))
    {
        cout << "Please, Enter Positive Number Only: ";
        getline(cin, X);
    }
    while (stod(X) > img.width || stod(X) < 0)
    {
        cout << "Please, Enter Positive Number less than or equal " << img.width << ": ";
        getline(cin, X);
    }
    cout << "Y: ";
    getline(cin, Y);
    // Check if the input is only digits
    while (!checkValidation(Y))
    {
        cout << "Please, Enter Positive Number Only: ";
        getline(cin, Y);
    }
    // Check The Boundary of the Image
    while (stod(Y) > img.height || stod(Y) < 0)
    {
        cout << "Please, Enter Positive Number less than or equal " << img.height << ": ";
        getline(cin, Y);
    }
    // The Dimensions Of The Area to cut
    string W, H;
    cout << "Please, Enter The Dimensions Of The Area to cut\n";
    cout << "Width: ";
    getline(cin, W);
    // Check if the input is only digits
    while (!checkValidation(W))
    {
        cout << "Please, Enter Positive Number Only: ";
        getline(cin, W);
    }
    while (stod(W) + stod(X) > img.width || stod(W) < 0)
    {
        cout << "Please, Enter Positive Number less than or equal " << img.width << ": ";
        getline(cin, W);
    }
    cout << "Height: ";
    getline(cin, H);
    // Check if the input is only digits
    while (!checkValidation(H))
    {
        cout << "Please, Enter Positive Number Only: ";
        getline(cin, H);
    }
    // Check The Boundary of the Image
    while (stod(H) + stod(Y) > img.height || stod(H) < 0)
    {
        cout << "Please, Enter Positive Number less than or equal " << img.height << ": ";
        getline(cin, H);
    }
    // To Store the Cropped Image in it
    Image croppedImage(stoi(W), stoi(H));
    for (int i = 0; i < stoi(W); i++)
    {
        for (int j = 0; j < stoi(H); j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                croppedImage(i, j, k) = img(i + stoi(Y), j + stoi(X), k);
            }
        }
    }
    return croppedImage;
}

// Resize the Image
Image resizeImage(Image img)
{
    cout << "Choose an Option to enter the new dimensions to resize the image\n";
    string option;
    // To Store the New Width and height after the calculation
    int newWidth, newHeight;
    while (true)
    {
        cout << "1 - Dimension(WxH)\n2 - Aspect Ratio(WxH)\n";
        cout << "Choose: ";
        cin >> option;
        if (option == "1")
        {
            cout << "Enter the new dimensions of resize image\n";
            cout << "Width: ";
            cin >> newWidth;
            cout << "Enter the new dimensions of resize image\n";
            cout << "Height: ";
            cin >> newHeight;
        }
        else if (option == "2")
        {
            string aspectRatio;
            // To Make sure the input in the right form
            regex pattern(R"((\d+)(?:/[1-9]+)?)");
            cout << "Enter Aspect Ratio (numerator/denominator): ";
            cin >> aspectRatio;
            while (!regex_match(aspectRatio, pattern))
            {
                cout << "INVALID, Enter Aspect Ratio (numerator/denominator): ";
                cin >> aspectRatio;
            }
            // Calculate the ratio in decimal
            double ratio = (aspectRatio[0] - '0') / (aspectRatio.length() > 1 ? aspectRatio[2] - '0' : 1.0);
            // Calculate the New Width and height based on the ratio
            newWidth = int(img.width * ratio);
            newHeight = int(img.height * ratio);
        }
        else
        {
            cout << "Please, Enter the Correct Choice\n";
            continue;
        }
        break;
    }
    // Make Image according to New Width and height
    Image resizedImage(newWidth, newHeight);
    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < newHeight; j++)
        {
            // Copy pixel from original image to resized image
            for (int k = 0; k < img.channels; k++)
            {
                // Apply Nearest Neighbor Method
                int oldX = round(i * img.width / newWidth);
                int oldY = round(j * img.height / newHeight);
                resizedImage(i, j, k) = img(oldX, oldY, k);
            }
        }
    }
    cin.ignore();
    return resizedImage;
}

Image blur_image(Image image) {
    Image blurred(image.width, image.height);
    int blur_intensity;
    // Take blur intensity from user
    while (true) {
        cout << "Insert Blur intensity (Positive integer): ";
        string input;
        getline(cin, input);
        try {
            blur_intensity = stoi(input);
            if (blur_intensity > 0) {
                break;
            } else {
                cout << "the number is non-positive integer!" << endl;
            }
        } catch (const invalid_argument& wh) {
            cout << "Input is not an integer!" << endl;
        }
    }
    // Make sure intensity is odd
    if (blur_intensity % 2 == 0) {
        blur_intensity -= 1;
    }
    if (blur_intensity == 1) {
        return image;
    }
    // Add extra edges, so it works on all (will be removed later)
    int border_length = blur_intensity / 2;
    int new_row = image.width + blur_intensity, new_column = image.height + blur_intensity;
    for (int k = 0; k < 3; ++k) {
        // Create 2d Pointer instead of an array because of large size
        unsigned long long** prefix_sum = new unsigned long long *[new_row];
        for (int i = 0; i < new_row; ++i) {
            prefix_sum[i] = new unsigned long long [new_column];
        }
        // Fill the upper and left edges
        for (int i = 0; i < new_row; ++i) {
            prefix_sum[i][0] = 0;
        }
        for (int j = 0; j < new_column; ++j) {
            prefix_sum[0][j] = 0;
        }
        // Fill the upper left block
        for (int i = 1; i <= border_length; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + image(0, 0 , k) + prefix_sum[i - 1][j];
            }
        }
        // Fill the upper and left edges
        for (int i = 1; i <= border_length; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + prefix_sum[i][j - 1] +
                                   image(0, j - border_length - 1, k);
            }
        }
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + prefix_sum[i][j - 1] +
                                   image(i - border_length - 1, 0, k);
            }
        }
        // Fill the upper right block
        for (int i = 1; i <= border_length; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] =
                        prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] + image(0, image.height - 1, k);
            }
        }
        // Fill the down left block
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] =
                        prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] + image(image.width - 1, 0, k);
            }
        }
        // Fill inside
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - border_length - 1, j - border_length - 1, k);
            }
        }
        // Fill the right edge
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - border_length - 1, 0, k);
            }
        }
        // Fill the downside
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(image.width - 1, j - border_length - 1, k);
            }
        }
        // Fill the down right block
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(image.width - 1, image.height - 1, k);
            }
        }
        // Assign blurred
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                blurred(i, j, k) = int(
                        (prefix_sum[blur_intensity + i][j + blur_intensity] - prefix_sum[blur_intensity + i][j] -
                         prefix_sum[i][blur_intensity + j] + prefix_sum[i][j]) / (blur_intensity * blur_intensity));
            }
        }
        // Delete Pointer
        for (int i = 0; i < new_row; ++i) {
            delete[] prefix_sum[i];
        }
        delete[] prefix_sum;
    }
    return blurred;
}

// Applying Oil Painting Effect
Image oilPaintingEffect(Image img)
{
    // I set it as a constant for the purpose of testing the code
    // Number of intensity levels for binning pixel intensities
    const int INTENSITY_LEVELS = 20;
    // control the level of detail in the oil painting effect
    const int radius = 5;

    Image outputImage(img.width, img.height);
    for (int x = 0; x < img.width; x++)
    {
        for (int y = 0; y < img.height; y++)
        {
            // arrays to store counts and averages of RGB values for each intensity level
            int intensityCount[INTENSITY_LEVELS] = {0};
            int averageR[INTENSITY_LEVELS] = {0};
            int averageG[INTENSITY_LEVELS] = {0};
            int averageB[INTENSITY_LEVELS] = {0};
            int curMax = 0;
            int maxIndex = 0;
            // Iterate over neighboring pixels within the radius
            // To Ensure to be in the Boundary
            for (int i = max(0, x - radius); i <= min(img.width - 1, x + radius); i++)
            {
                for (int j = max(0, y - radius); j <= min(img.height - 1, y + radius); j++)
                {
                    // Calculate intensity and update counters and averages
                    int r = img(i, j, 0);
                    int g = img(i, j, 1);
                    int b = img(i, j, 2);
                    int curIntensity = int((r + g + b) / 3.0 * INTENSITY_LEVELS / 255.0);
                    intensityCount[curIntensity]++;
                    averageR[curIntensity] += r;
                    averageG[curIntensity] += g;
                    averageB[curIntensity] += b;
                }
            }
            // Find the most frequent intensity level
            for (int i = 0; i < INTENSITY_LEVELS; ++i)
            {
                if (intensityCount[i] > curMax)
                {
                    curMax = intensityCount[i];
                    maxIndex = i;
                }
            }
            // Calculate final RGB values based on the most frequent intensity level
            int finalR = averageR[maxIndex] / curMax;
            int finalG = averageG[maxIndex] / curMax;
            int finalB = averageB[maxIndex] / curMax;
            outputImage.setPixel(x, y, 0, finalR);
            outputImage.setPixel(x, y, 1, finalG);
            outputImage.setPixel(x, y, 2, finalB);
        }
    }

    return outputImage;
}

// Add frame around the image
Image add_frame(Image old_image){
    int border_size;
    string frame;
    while (true) {
        cout << "Choose a frame!" << endl;
        cout << "1- frame1" << endl << "2- frame2" << endl;
        getline(cin, frame);
        if(frame == "1" or frame == "2") {
            break;
        } else {
            cout << "invalid input" << endl;
        }
    }
    // Take the size of the border
    while (true) {
        cout << "Enter border size (leave empty for automatic):";
        string string1;
        getline(cin, string1);
        if (string1.empty()) {
            if (old_image.height > old_image.width) {
                border_size = int (0.1618 * old_image.width * 0.25);
            } else {
                border_size = int (0.1618 * old_image.height * 0.25);
            }
            break;
        } else {
            try {
                border_size = stoi(string1);
                break;
            } catch (const invalid_argument&) {
                cerr << "Invalid input" << endl;
            }
        }
    }
    int color[3] = {};
    // Take a color
    if (frame == "1") {
        get_color(color);
    } else {
        // In case if the user chooses the fancy frame
        get_color(color, "First Color!");
    }
    Image image(old_image.width + border_size * 2, old_image.height + border_size * 2);
    // For the top side
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the left side
    for (int i = 0; i < border_size; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the right side
    for (int i = image.width - border_size; i < image.width; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the bottom side
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = image.height - border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }

    // Fill photo inside frame
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = border_size; j < image.height - border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, old_image(i - border_size, j - border_size, k));
            }
        }
    }

    // For fancy frame
    if (frame == "2") {
        int space = border_size / 7, square_end = int (border_size / 2.4167), thickness = border_size / 29;
        get_color(color, "Second color!");
        // small square up left
        for (int i = space; i <= square_end; ++i) {
            for (int j = space; j <= square_end; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // small square down left
        for (int i = space; i <= square_end; ++i) {
            for (int j = image.height - square_end - 1; j < image.height - space; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // small square up right
        for (int i = image.width - square_end - 1; i < image.width - space; ++i) {
            for (int j = space; j <= square_end; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // small square down right
        for (int i = image.width - square_end - 1; i < image.width - space; ++i) {
            for (int j = image.height - square_end - 1; j < image.height - space; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // From square to square

        // thin line up
        for (int i = square_end + 1; i < image.width - (square_end + 1); ++i) {
            for (int j = square_end + 1; j <= square_end + thickness ; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // thin line down
        for (int i = square_end + 1; i < image.width - (square_end + thickness); ++i) {
            for (int j = image.height - square_end - thickness - 1; j < image.height - square_end - 1; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // thin line left
        for (int i = square_end + 1; i <= square_end + thickness; ++i) {
            for (int j = square_end + 1; j < image.height - square_end - 1; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // thin line right
        for (int i = image.width - square_end - thickness - 1; i < image.width - square_end - 1; ++i) {
            for (int j = square_end + 1; j < image.height - square_end - 1; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // thin out-line

        // Upper
        for (int i = border_size * 6 / 7; i < image.width - border_size * 6 / 7; ++i) {
            for (int j = border_size * 6 / 7; j < border_size * 6 / 7 + thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Lower
        for (int i = border_size * 6 / 7; i < image.width - border_size * 6 / 7; ++i) {
            for (int j = image.height - border_size * 6 / 7 - thickness; j < image.height - border_size * 6 / 7; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Left
        for (int i = border_size * 6 / 7; i < border_size * 6 / 7 + thickness; ++i) {
            for (int j = border_size * 6 / 7; j < image.height - border_size * 6 / 7; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Right
        for (int i = image.width - (border_size * 6 / 7 + thickness); i < image.width - border_size * 6 / 7; ++i) {
            for (int j = border_size * 6 / 7; j < image.height - border_size * 6 / 7; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // Thick frame

        int line_limit = 2 * square_end - space + 2;

        // Middle up
        for (int i = line_limit; i < image.width - line_limit; ++i) {
            for (int j = space; j < space + 2 * thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Corner up left
        // Horizontal
        for (int i = space; i < line_limit + 2 * thickness; ++i) {
            for (int j = line_limit; j < line_limit + 2 * thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Vertical
        for (int i = line_limit; i < line_limit + thickness * 2; ++i) {
            for (int j = space; j < line_limit + 2 * thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Corner up right
        // Horizontal
        for (int i = image.width - line_limit - 2 * thickness; i < image.width - space; ++i) {
            for (int j = line_limit; j < line_limit + 2 * thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Vertical
        for (int i = image.width - line_limit - thickness * 2; i < image.width - line_limit; ++i) {
            for (int j = space; j < line_limit + 2 * thickness; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // Left
        for (int i = space; i < space + thickness * 2; ++i) {
            for (int j = line_limit; j < image.height - line_limit; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Right
        for (int i = image.width - space - 2 * thickness; i < image.width - space; ++i) {
            for (int j = line_limit; j < image.height - line_limit; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // Corner down left
        // Horizontal
        for (int i = space; i < line_limit + 2 * thickness; ++i) {
            for (int j = image.height - line_limit - 2 * thickness; j < image.height - line_limit; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Vertical
        for (int i = line_limit; i < line_limit + thickness * 2; ++i) {
            for (int j = image.height - line_limit - 2 * thickness; j < image.height - space; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Corner down right()
        // Horizontal
        for (int i = image.width - line_limit - 2 * thickness; i < image.width - space; ++i) {
            for (int j = image.height - line_limit - 2 * thickness; j < image.height - line_limit; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
        // Vertical
        for (int i = image.width - line_limit - 2 * thickness; i < image.width - line_limit; ++i) {
            for (int j = image.height - line_limit - 2 * thickness; j < image.height - space; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }

        // Down
        for (int i = line_limit; i < image.width - line_limit; ++i) {
            for (int j = image.height - space - 2 * thickness; j < image.height - space; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, color[k]);
                }
            }
        }
    }
    return image;
}

// infrared Effect function
Image infraRed(Image image)
{
    Image outputImage(image.width, image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            outputImage.setPixel(i, j, 0, 230);
            for (int k = 1; k < 3; ++k)
            {
                outputImage.setPixel(i, j, k, 255 - image(i, j, k));
            }
        }
    }
    return outputImage;
}

// skew the image by the given angle
Image skew(Image image) {
    int angle;
    // Take angle from user
    while (true) {
        try {
            cout << "Enter angle of skewness to the vertical axis (-89 to 89): ";
            string string_angle;
            getline(cin, string_angle);
            angle = stoi(string_angle);
            if (angle > -90 and angle < 90) {
                break;
            } else {
                cout << "Invalid angle!" << endl;
            }
        } catch (const invalid_argument &) {
            cout << "Enter a proper number!" << endl;
        }
    }
    if (angle < 0) {
        int start[image.height];
        for (int i = 0; i < image.height; ++i) {
            start[i] = int (i / tan((90 + angle) * PI / 180));
        }
        Image skewed(image.width + start[image.height - 1], image.height);
        for (int i = 0; i < skewed.width; ++i) {
            for (int j = 0; j < skewed.height; ++j) {
                if (start[j] > i) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else if (i > image.width + start[j]) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = image(i - start[j], j, k);
                    }
                }
            }
        }
        return skewed;
    } else if (angle > 0) {
        int start[image.height];
        for (int i = 0; i < image.height; ++i) {
            start[i] = int (i / tan((90 - angle) * PI / 180));
        } Image skewed(image.width + start[image.height - 1], image.height);
        for (int i = 0; i < skewed.width; ++i) {
            for (int j = 0; j < skewed.height; ++j) {
                if (start[image.height - j - 1] > i) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else if (i > image.width + start[image.height - j - 1]) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = image(i - start[image.height - j - 1], j, k);
                    }
                }
            }
        }
        return skewed;
    } else {
        return image;
    }
}

Image tv_effect(Image image) {
    // Function to simulate bright and dark lines in tv (CRT)
    // it's recommended to see this function on a graphing program
    auto function = [](double x, const double c = 0.9, const int maximum = 1){ while (x > maximum) {x--;} return exp( 0.5 * (0.5 - x) * (x - 0.5) / (c * c));};
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Take a random integer
            int x = rand() % 31;
            for (int k = 0; k < 3; ++k) {
                // if row index is even, subtracts the random variable
                // and if it is odd, adds the random number
                if (j % 2) {
                    if (image.getPixel(i, j, k) + x > 255) {
                        image(i, j, k) = 255;
                    } else {
                        image(i, j, k) += x;
                    }
                } else {
                    if (image.getPixel(i, j, k) - x < 0) {
                        image(i, j, k) = 0;
                    } else {
                        image(i, j, k) -= x;
                    }
                }
                // apply Function
                image(i, j, k) = int(image(i, j, k) * function(0.2 * j));
            }
        }
    }
    return image;
}

// Extra 1
Image hue(const Image& image, bool random = false, float hue_shift = 0) {
    if (random) {
        srand(unsigned (time(nullptr)));
        hue_shift = (float) (rand() % 360);
    }
    // limit shift from 0 to 360
    while (hue_shift > 360) {
        hue_shift -= 361;
    }
    while (hue_shift < 0) {
        hue_shift += 361;
    }

    if (hue_shift == 0){
        return image;
    } else {
        Image shifted_image(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                // RGB to HSV
                float r_ratio = (float) image(i, j, 0) / 255.0f, g_ratio = (float) image(i, j, 1) / 255.0f, b_ratio = (float) image(i, j, 2) / 255.0f;
                // Calculate (V)alue
                float V = max(max(r_ratio, g_ratio), b_ratio);
                float difference = V - min(min(r_ratio, g_ratio), b_ratio), H = 60, S = 0;
                // Calculate (H)ue
                if (difference == 0) {
                    H = 0;
                } else if (V == r_ratio) {
                    H *= fmod((g_ratio - b_ratio) / difference, 6.0f);
                } else if (V == g_ratio) {
                    H *= (b_ratio - r_ratio) / difference + 2;
                } else {
                    H *= (r_ratio - g_ratio) / difference + 4;
                }
                // Calculate (S)aturation
                if (V != 0) {
                    S = difference / V;
                }

                // Hue after shift
                if (H + hue_shift > 360) {
                    H = H + hue_shift - 361;
                } else {
                    H += hue_shift;
                }

                // HSV to RGB
                float C = V * S, M = V - C, X = (float) (C * (1 - abs(fmod(H / 60, 2) - 1)));
                if (H < 60) {
                    r_ratio = C;
                    g_ratio = X;
                    b_ratio = 0;
                } else if (H < 120) {
                    r_ratio = X;
                    g_ratio = C;
                    b_ratio = 0;
                } else if (H < 180) {
                    r_ratio = 0;
                    g_ratio = C;
                    b_ratio = X;
                } else if (H < 240) {
                    r_ratio = 0;
                    g_ratio = X;
                    b_ratio = C;
                } else if (H < 300) {
                    r_ratio = X;
                    g_ratio = 0;
                    b_ratio = C;
                } else {
                    r_ratio = C;
                    g_ratio = 0;
                    b_ratio = X;
                }
                int new_R = int ((r_ratio + M) * 255), new_G = int ((g_ratio + M) * 255), new_B = int ((b_ratio + M) * 255);
                // Set new RGB
                shifted_image.setPixel(i, j, 0, new_R);
                shifted_image.setPixel(i, j, 1, new_G);
                shifted_image.setPixel(i, j, 2, new_B);
            }
        }
        return shifted_image;
    }
}

// Extra 2
Image pixelate(const Image& image, int intensity = 2) {
    if (intensity < 1) {
        intensity = 1;
    }
    if (intensity == 1) {
        return image;
    }
    int new_row = image.width / intensity, new_column = image.height / intensity;
    Image pixelated(new_row, new_column);
    for (int k = 0; k < 3; ++k) {
        // Create 2d Pointer instead of an array because of large size
        // The (+1) is for the line of Zeros
        unsigned long long** prefix_sum = new unsigned long long *[image.width + 1];
        for (int i = 0; i < image.width + 1; ++i) {
            prefix_sum[i] = new unsigned long long [image.height + 1];
        }
        // Fill upper and left edges with 0
        for (int i = 0; i < image.width + 1; ++i) {
            prefix_sum[i][0] = 0;
        }
        for (int j = 0; j < image.height + 1; ++j) {
            prefix_sum[0][j] = 0;
        }
        // Fill inside
        for (int i = 1; i < image.width + 1; ++i) {
            for (int j = 1; j < image.height + 1; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - 1, j - 1, k);
            }
        }
        // Assign pixelated
        for (int i = 0; i < new_row; ++i) {
            for (int j = 0; j < new_column; ++j) {
                pixelated(i, j, k) = (prefix_sum[(i+1) * intensity][(j+1) * intensity]
                                      + prefix_sum[i * intensity][j * intensity]
                                      - prefix_sum[i * intensity][(j+1) * intensity]
                                      - prefix_sum[(i+1) * intensity][j * intensity]) / (intensity * intensity);
            }
        }
        // Delete Pointer
        for (int i = 0; i < new_row; ++i) {
            delete[] prefix_sum[i];
        }
        delete[] prefix_sum;
    }
    return pixelated;
}


bool valid_factor(string factor)
{
    if (factor[factor.length() - 1] == '.' || factor[0] == '.')
    {
        return false;
    }

    int counter = 0;
    for (int i = 0; i < factor.length(); i++)
    {
        if (factor[i] == '.')
            counter++;
    }

    if (counter > 1)
    {
        return false;
    }

    for (int i = 0; i < factor.length(); i++)
    {
        if ((!isdigit(factor[i]) && factor[i] != '.'))
        {
            return false;
        }
    }

    if (stod(factor) < 0)
        return false;

    return true;
}

Image Brightness(const Image& image) {
    Image new_image(image.width, image.height);
    double bright_factor;
    string num;
    cout << "Please enter the brightness factor\n";
    getline(cin, num);

    while (!valid_factor(num))
    {
        cout << "Invalid input, try again!\n";
        getline(cin, num);
    }

    bright_factor = stod(num);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int brightness = image(i, j, k) * bright_factor;
                if (brightness > 255)
                {
                    brightness = 255;
                }
                new_image(i, j, k) = brightness;
            }
        }
    }
    return new_image;
}

Image Purble(const Image& image) {
    Image purble_image(image.width, image.height);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0) * 1.2;
            int blue = image(i, j, 2) * 1.2;
            int green = image(i, j, 1) * 0.8;
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            purble_image(i, j, 0) = red;
            purble_image(i, j, 2) = blue;
            purble_image(i, j, 1) = green;
        }
    }
    return purble_image;
}

Image Sunlight(Image image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int brightness = image(i, j, k) * 0.8;
                image(i, j, k) = brightness;
            }
        }
    }

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int red = image(i, j, 0) * 1.5;
            int green = image(i, j, 1) * 1.4;
            int blue = image(i, j, 2) * 1;
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;
        }
    }
    return image;
}


Image Edge_detction(Image image) {
    image = blackWhite(image);
    Image Final(image.width, image.height);

    //sobel matrix for X_axis and Y_axis
    int matX[3][3] = { {-1 , 0 , 1} , {2 , 0 , -2} , {-1 , 0 , 1} };
    int matY[3][3] = { {1 , 2 , 1} , {0 , 0 , 0} , {-1 , -2 , -1} };

    for (int i = 1; i < image.height - 1; i++)
    {
        for (int j = 1; j < image.width - 1; j++)
        {
            long long sumX = 0;
            long long sumY = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    //sobel gradient X and Y
                    sumX += image(j + l, i + k, 0) * matX[k + 1][l + 1];
                    sumY += image(j + l, i + k, 0) * matY[k + 1][l + 1];
                }
            }
            //gradient magnitude
            long mag = sqrt(sumX * sumX + sumY * sumY);
            Final(j, i, 0) = (mag > 128) ? 0 : 255;
            Final(j, i, 1) = Final(j, i, 0);
            Final(j, i, 2) = Final(j, i, 0);
        }
    }
    return Final;
}



bool check_validation(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '.' && i > 0)
            continue;
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

// Crop Images
Image crop_image(Image img, string X, string Y, string W = "", string H = "")
{
    if (!(X == "0" && Y == "0"))
    {
        // The Starting Point(X,Y) To Crop At
        cout << "Please, Enter The Starting Point(X,Y) To Crop At\n";
        cout << "X: ";
        cin >> X;
        // Check if the input is only digits
        while (!check_validation(X))
        {
            cout << "Please, Enter Positive Number Only: ";
            cin >> X;
        }
        while (stod(X) > img.width || stod(X) < 0)
        {
            cout << "Please, Enter Positive Number less than or equal " << img.width << ": ";
            cin >> X;
        }
        cout << "Y: ";
        cin >> Y;
        // Check if the input is only digits
        while (!check_validation(Y))
        {
            cout << "Please, Enter Positive Number Only: ";
            cin >> Y;
        }
        // Check The Boundary of Image
        while (stod(Y) > img.height || stod(Y) < 0)
        {
            cout << "Please, Enter Positive Number less than or equal " << img.height << ": ";
            cin >> Y;
        }
    }
    if (W == "0" && H == "0")
    {
        // The Dimensions Of The Area to cut
        cout << "Please, Enter The Dimensions Of The Area to cut\n";
        cout << "Width: ";
        cin >> W;
        // Check if the input is only digits
        while (!check_validation(W))
        {
            cout << "Please, Enter Positive Number Only: ";
            cin >> W;
        }
        while (stod(W) + stod(X) > img.width || stod(W) < 0)
        {
            cout << "Please, Enter Positive Number less than or equal " << img.width << ": ";
            cin >> W;
        }
        cout << "Height: ";
        cin >> H;
        // Check if the input is only digits
        while (!check_validation(H))
        {
            cout << "Please, Enter Positive Number Only: ";
            cin >> H;
        }
        // Check The Boundary of the Image
        while (stod(H) + stod(Y) > img.height || stod(H) < 0)
        {
            cout << "Please, Enter Positive Number less than or equal " << img.height << ": ";
            cin >> H;
        }
    }
    // To Store the Cropped Image in it
    Image croppedImage(stoi(W), stoi(H));
    for (int i = 0; i < stoi(W); i++)
    {
        for (int j = 0; j < stoi(H); j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                croppedImage(i, j, k) = img(i + stoi(Y), j + stoi(X), k);
            }
        }
    }
    return croppedImage;
}

// Resize the Image
Image resize_image(Image img, string newWidth = "", string newHeight = "")
{
    cout << "Choose an Option to enter the new dimensions to resize the image\n";
    string option;
    // To Store the New Width and height after the calculation
    if (newWidth == "" && newHeight == "")
    {

        while (true)
        {
            cout << "1 - Dimension(WxH)\n2 - Aspect Ratio(WxH)\n";
            cout << "Choose: ";
            cin >> option;
            if (option == "1")
            {
                cout << "Enter the new dimensions of resize image\n";
                cout << "Width: ";
                cin >> newWidth;
                cout << "Enter the new dimensions of resize image\n";
                cout << "Height: ";
                cin >> newHeight;
            }
            else if (option == "2")
            {
                string aspectRatio;
                // To Make sure the input in the right form
                regex pattern(R"((\d+)(?:/[1-9]+)?)");
                cout << "Enter Aspect Ratio (numerator/denominator): ";
                cin >> aspectRatio;
                while (!regex_match(aspectRatio, pattern))
                {
                    cout << "INVALID, Enter Aspect Ratio (numerator/denominator): ";
                    cin >> aspectRatio;
                }
                // Calculate the ratio in decimal
                double ratio = (aspectRatio[0] - '0') / (aspectRatio.length() > 1 ? aspectRatio[2] - '0' : 1.0);
                // Calculate the New Width and height based on a ratio
                newWidth = int(img.width * ratio);
                newHeight = int(img.height * ratio);
            }
            else
            {
                cout << "Please, Enter the Correct Choice\n";
                continue;
            }
            break;
        }
    }

    // Make Image according to New Width and height
    Image resizedImage(stoi(newWidth), stoi(newHeight));
    for (int i = 0; i < stoi(newWidth); i++)
    {
        for (int j = 0; j < stoi(newHeight); j++)
        {
            // Copy pixel from original image to resized image
            for (int k = 0; k < img.channels; k++)
            {
                // Apply Nearest Neighbor Method
                int oldX = round(i * img.width / stoi(newWidth));
                int oldY = round(j * img.height / stoi(newHeight));
                resizedImage(i, j, k) = img(oldX, oldY, k);
            }
        }
    }
    return resizedImage;
}

Image merge(Image image1){
    string filename1, filename2;
    cout << "Please enter the second photo" << endl;
    Image image2 = get_file();

    cout << "Please choose one option: \n";
    cout << "1- Resize both Images?\n";
    cout << "2- Merge the common area of smaller Image?\n";
    string answer;
    cin >> answer;

    while (answer != "1" && answer != "2")
    {
        cout << "Invalid Input, please try again\n";
        cin >> answer;
    }
    if (answer == "1")
    {
        int newW = max(image1.width, image2.width);
        int newH = max(image1.height, image2.height);
        // use the function of resize on both image1 and image2
        image1 = resize_image(image1, to_string(newW),to_string(newH));
        image2 = resize_image(image2, to_string(newW),to_string(newH));
    }
    else
    {
        int newW = min(image1.width, image2.width);
        int newH = min(image1.height, image2.height);
        image1 = crop_image(image1, "0", "0", to_string(newW), to_string(newH));
        image2 = crop_image(image2, "0", "0", to_string(newW), to_string(newH));
    }

    for (int i = 0; i < image2.width; i++)
    {
        for (int j = 0; j < image2.height; j++)
        {
            image2(i, j, 0) = (image1(i, j, 0) + image2(i, j, 0)) / 2;
            image2(i, j, 1) = (image1(i, j, 1) + image2(i, j, 1)) / 2;
            image2(i, j, 2) = (image1(i, j, 2) + image2(i, j, 2)) / 2;
        }
    }
    cin.ignore();
    return image2;
}

// Main Menu
int main()
{
    while (true) {
        static bool second_menu = false;
        static string option;
        static Image input_image;
        // Display menu to user
        cout << "Welcome to our baby photoshop" << endl;
        if (!second_menu) {
            cout << "1- Insert new image" << endl;
            cout << "2- Exit" << endl;
            getline(cin, option);
            if (option == "1") {
                input_image = get_file();
                second_menu = true;
            } else if (option == "2") {
                break;
            } else {
                cout << "Wrong Input!" << endl;
                continue;
            }
        } else {
            cout << "1- Insert new image" << endl;
            cout << "2- Continue with current image" << endl;
            cout << "3- Exit" << endl;
            getline(cin, option);
            if (option == "1") {
                input_image = get_file();
            } else if (option == "2") {}
            else if (option == "3") {
                break;
            } else {
                cout << "Wrong Input!" << endl;
                continue;
            }
        }
        while (true) {
            cout << "Welcome to our baby photoshop" << endl;
            cout << "1- Gray scale" << endl;
            cout << "2- Black&White" << endl;
            cout << "3- Invert Color Image" << endl;
            cout << "4- Merge Images" << endl;
            cout << "5- Flip Image" << endl;
            cout << "6- Rotate Image" << endl;
            cout << "7- Darken or Lighten image" << endl;
            cout << "8- Crop image" << endl;
            cout << "9- Add frame" << endl;
            cout << "10- Detect image edges" << endl;
            cout << "11- Resize image" << endl;
            cout << "12- Blur image" << endl;
            cout << "13- Natural sunlight effect" << endl;
            cout << "14- Oil Painting effect" << endl;
            cout << "15- TV effect" << endl;
            cout << "16- Night effect" << endl;
            cout << "17- Infrared effect" << endl;
            cout << "18- Skew Image" << endl;
            cout << "19- Manipulate Hue" << endl;
            cout << "20- Pixelate Image" << endl;
            cout << "21- Return" << endl;
            getline(cin, option);
            static Image output_image;
            if (option == "1") {
                output_image = gray_scale(input_image);
            } else if (option == "2") {
                output_image = blackWhite(input_image);
            } else if (option == "3") {
                output_image = invert_image_color(input_image);
            } else if (option == "4") {
                output_image = merge(input_image);
            } else if (option == "5") {
                output_image = flipImage(input_image);
            } else if (option == "6") {
                output_image = rotate_image(input_image);
            } else if (option == "7") {
                output_image = Brightness(input_image);
            } else if (option == "8") {
                output_image = cropImage(input_image);
            } else if (option == "9") {
                output_image = add_frame(input_image);
            } else if (option == "10") {
                output_image = Edge_detction(input_image);
            } else if (option == "11") {
                output_image = resizeImage(input_image);
            } else if (option == "12") {
                output_image = blur_image(input_image);
            } else if (option == "13") {
                output_image = Sunlight(input_image);
            } else if (option == "14") {
                output_image = oilPaintingEffect(input_image);
            } else if (option == "15") {
                output_image = tv_effect(input_image);
            } else if (option == "16") {
                output_image = Purble(input_image);
            } else if (option == "17") {
                output_image = infraRed(input_image);
            } else if (option == "18") {
                output_image = skew(input_image);
            } else if (option == "19") {
                string intense;
                int intensity;
                while (true) {
                    try {
                        cout << "Please enter Hue shift!" << endl;
                        cout << "Enter 0 for random" << endl;
                        getline(cin, intense);
                        intensity = stoi(intense);
                        break;
                    } catch (const invalid_argument&) {
                        cout << "Please enter a number!" << endl;
                    }
                }
                if (intensity == 0) {
                    output_image = hue(input_image, true);
                } else {
                    output_image = hue(input_image, false, intensity);
                }
            } else if (option == "20") {
                string intense;
                int intensity;
                while (true) {
                    try {
                        cout << "Please enter Pixelate intensity: ";
                        getline(cin, intense);
                        intensity = stoi(intense);
                        if (intensity >= 0) {
                            break;
                        }
                        cout << "Please enter a positive number!" << endl;
                    } catch (const invalid_argument&) {
                        cout << "Please enter a number!" << endl;
                    }
                }
                output_image = pixelate(input_image, intensity);
            } else if (option == "21") {
                break;
            } else {
                cout << "Wrong input!" << endl;
                continue;
            }
            create_new_file(output_image);
        }
    }
    return 0;
}
