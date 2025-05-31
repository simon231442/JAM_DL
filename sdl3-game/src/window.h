typedef struct {
    void* pixelAddress; // Address of the pixel data
    int width;         // Width of the window
    int height;        // Height of the window
    int endianess;     // Endianness of the pixel data
} WindowInfo;

int createWindow(WindowInfo* windowInfo);
void closeWindow(WindowInfo* windowInfo);