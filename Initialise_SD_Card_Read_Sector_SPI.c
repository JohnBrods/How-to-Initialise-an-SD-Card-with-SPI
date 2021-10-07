                                                    /*Anyone is free to copy, modify, publish, use, compile or
                                                    distribute this software, either in source code form or as a compiled
                                                    binary, for non-commercial use only. (i.e. YOU MAY NOT SELL IT)
                                                    John B 07/10/2021

                                                    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
                                                    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
                                                    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
                                                    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
                                                    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
                                                    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
                                                    OTHER DEALINGS IN THE SOFTWARE.*/
                                                    //Initialise an SD Card with SPI(2 Gig used) FAT16 or FAT32
                                                    //Read SD Card Boot Sector or any other
                                                    //I Would Like A Mention If You Demo It.
                                                    //Like All My C Files, It Has My Own 'write Number' Function, It's Fast :)
                                                    //To Donate A Coffee, See Link In Youtube Where You Found This File, Thank You.


//GLCD FontName : San_Diego36x46
//GLCD FontSize : 36 x 46

const unsigned short Number_Fontlarge[] = {

   0x00,0xF0,0xF9,0x00,0x00,0x00,0xFC,0xF9,0x03,0x00,0x00,0xFF,0xF9,0x0F,0x00,0x80,0xFF,0xF0,0x1F,0x00,0xC0,0x7F,0xE0,0x3F,0x00,0xC0,0x3F,0xC0,0x3F,0x00,
   0xE0,0x3F,0xC0,0x7F,0x00,0xF0,0x3F,0xC0,0xFF,0x00,0xF0,0x3F,0xC0,0xFF,0x00,0xF8,0x3F,0xC0,0xFF,0x01,0xF8,0x3F,0xC0,0xFF,0x01,0xF8,0x3F,0xC0,0xFF,0x01,
   0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,
   0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,
   0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,
   0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xFC,0x3F,0xC0,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x01,0xF8,0x3F,0xC0,0xFF,0x01,
   0xF8,0x3F,0xC0,0xFF,0x01,0xF0,0x3F,0xC0,0xFF,0x00,0xF0,0x3F,0xC0,0xFF,0x00,0xE0,0x3F,0xC0,0x7F,0x00,0xC0,0x3F,0xC0,0x3F,0x00,0xC0,0x7F,0xE0,0x3F,0x00,
   0x80,0xFF,0xF0,0x1F,0x00,0x00,0xFF,0xF9,0x0F,0x00,0x00,0xFC,0xF9,0x03,0x00,0x00,0xF0,0xF9,0x00,0x00, // Code for char num 48
   0x00,0x00,0x78,0x00,0x00,0x00,0xC0,0x7F,0x00,0x00,0x00,0xFF,0x7F,0x00,0x00,0x80,0xFF,0x7F,0x00,0x00,0x80,0xFF,0x7F,0x00,0x00,0x80,0xFF,0x7F,0x00,0x00,
   0x00,0xFE,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,
   0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,
   0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,
   0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,
   0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,
   0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xF8,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x07,0x00,
   0x80,0xFF,0xFF,0x0F,0x00,0x80,0xFF,0xFF,0x0F,0x00,0x80,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00, // Code for char num 49
   0x00,0x7C,0xFC,0x00,0x00,0x80,0x7F,0xFC,0x07,0x00,0xE0,0x7F,0xFC,0x0F,0x00,0xF0,0x1F,0xF0,0x3F,0x00,0xF8,0x07,0xE0,0x7F,0x00,0xFC,0x0F,0xE0,0xFF,0x00,
   0xFC,0x1F,0xE0,0xFF,0x00,0xFE,0x3F,0xE0,0xFF,0x01,0xFE,0x3F,0xE0,0xFF,0x01,0xFE,0x3F,0xE0,0xFF,0x03,0xFE,0x3F,0xE0,0xFF,0x03,0xFE,0x3F,0xE0,0xFF,0x03,
   0xFE,0x3F,0xE0,0xFF,0x03,0xFC,0x1F,0xE0,0xFF,0x03,0xFC,0x1F,0xE0,0xFF,0x03,0xF8,0x0F,0xE0,0xFF,0x03,0xE0,0x03,0xF0,0xFF,0x03,0x00,0x00,0xF0,0xFF,0x01,
   0x00,0x00,0xF8,0xFF,0x01,0x00,0x00,0xF8,0xFF,0x01,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0xFE,0x7F,0x00,0x00,0x00,0xFF,0x3F,0x00,0x00,0x80,0xFF,0x1F,0x00,
   0x00,0xE0,0xFF,0x0F,0x00,0x00,0xF0,0xFF,0x01,0x00,0x00,0xF8,0x7F,0x00,0x00,0x00,0xFC,0x0F,0x00,0x00,0x00,0xFE,0x01,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,
   0x00,0x1F,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0xFF,0x01,0x80,0x07,0xC0,0xFF,0x3F,0xC0,0x07,
   0xF0,0xFF,0xFF,0xFF,0x07,0xF8,0xFF,0xFF,0xFF,0x07,0xF8,0xFF,0xFF,0xFF,0x03,0xFC,0xFF,0xFF,0xFF,0x03,0xFC,0xFF,0xFF,0xFF,0x03,0xFE,0xFF,0xFF,0xFF,0x01,
   0x7E,0xF0,0xFF,0xFF,0x00,0x1E,0x80,0xFF,0x7F,0x00,0x0E,0x00,0xFE,0x3F,0x00,0x00,0x00,0xF0,0x0F,0x00, // Code for char num 50
   0x00,0x7C,0xFC,0x00,0x00,0x00,0x7F,0xFC,0x07,0x00,0xC0,0x7F,0xFC,0x1F,0x00,0xE0,0x1F,0xF8,0x3F,0x00,0xF0,0x0F,0xE0,0x7F,0x00,0xF8,0x1F,0xE0,0xFF,0x00,
   0xF8,0x3F,0xC0,0xFF,0x01,0xFC,0x3F,0xC0,0xFF,0x01,0xFC,0x7F,0xC0,0xFF,0x03,0xFC,0x7F,0xC0,0xFF,0x03,0xFC,0x7F,0xC0,0xFF,0x03,0xFC,0x7F,0xC0,0xFF,0x03,
   0xFC,0x7F,0xC0,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x03,0xF0,0x1F,0xC0,0xFF,0x01,0xC0,0x07,0xC0,0xFF,0x01,0x00,0x00,0xC0,0xFF,0x00,
   0x00,0x00,0xE0,0xFF,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xFE,0x3F,0x00,0x00,0x80,0xFF,0x0F,0x00,0x00,0x80,0xFF,0x07,0x00,0x00,0x80,0xFF,0x1F,0x00,
   0x00,0x00,0xF8,0x7F,0x00,0x00,0x00,0xE0,0xFF,0x00,0x00,0x00,0xC0,0xFF,0x01,0x00,0x00,0xC0,0xFF,0x01,0x00,0x00,0xC0,0xFF,0x03,0xE0,0x03,0xC0,0xFF,0x03,
   0xF8,0x0F,0xC0,0xFF,0x07,0xFC,0x1F,0xC0,0xFF,0x07,0xFC,0x1F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,
   0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x1F,0xC0,0xFF,0x03,0xFC,0x1F,0xC0,0xFF,0x03,0xFC,0x0F,0xE0,0xFF,0x01,0xF8,0x07,0xE0,0xFF,0x00,
   0xF0,0x1F,0xF8,0x7F,0x00,0xE0,0x7F,0xFC,0x3F,0x00,0x80,0x7F,0xFC,0x0F,0x00,0x00,0x7C,0xFC,0x00,0x00, // Code for char num 51
   0x00,0x00,0x80,0x0F,0x00,0x00,0x00,0xC0,0x0F,0x00,0x00,0x00,0xE0,0x0F,0x00,0x00,0x00,0xF0,0x0F,0x00,0x00,0x00,0xF0,0x0F,0x00,0x00,0x00,0xF8,0x0F,0x00,
   0x00,0x00,0xFC,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,
   0x00,0x20,0xFE,0x0F,0x00,0x00,0x20,0xFE,0x0F,0x00,0x00,0x30,0xFE,0x0F,0x00,0x00,0x38,0xFE,0x0F,0x00,0x00,0x3C,0xFE,0x0F,0x00,0x00,0x3C,0xFE,0x0F,0x00,
   0x00,0x1E,0xFE,0x0F,0x00,0x00,0x1F,0xFE,0x0F,0x00,0x00,0x0F,0xFE,0x0F,0x00,0x80,0x07,0xFE,0x0F,0x00,0xC0,0x03,0xFE,0x0F,0x00,0xE0,0x03,0xFE,0x0F,0x00,
   0xE0,0x01,0xFE,0x0F,0x00,0xF0,0x00,0xFE,0x0F,0x00,0x78,0x00,0xFE,0x0F,0x00,0x7C,0x00,0xFE,0x0F,0x00,0x3C,0x00,0xFE,0x0F,0x00,0x1E,0x00,0xFE,0x0F,0x00,
   0xFF,0x3F,0xFE,0xFF,0x03,0xFF,0x3F,0xFE,0xFF,0x03,0xFF,0x3F,0xFE,0xFF,0x03,0xFF,0x3F,0xFE,0xFF,0x03,0xFE,0x3F,0xFE,0xFF,0x03,0x00,0x00,0xFE,0x0F,0x00,
   0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0xC0,0xFF,0x7F,0x00,
   0x00,0xF0,0xFF,0xFF,0x01,0x00,0xF0,0xFF,0xFF,0x01,0x00,0xF0,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00, // Code for char num 52
   0x00,0x00,0x00,0x00,0x00,0xF0,0x7F,0x00,0x70,0x00,0xF0,0xFF,0xFF,0x7F,0x00,0xF0,0xFF,0xFF,0x7F,0x00,0xF0,0xFF,0xFF,0x7F,0x00,0xF0,0xFF,0xFF,0x7F,0x00,
   0xF0,0xFF,0xFF,0x3F,0x00,0xF0,0xFF,0xFF,0x1F,0x00,0xF0,0xFF,0xFF,0x0F,0x00,0xF0,0xFF,0xFF,0x03,0x00,0xF0,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x38,0x38,0x3E,0x00,0x00,
   0x38,0x3E,0xFE,0x01,0x00,0xB8,0x3F,0xFE,0x0F,0x00,0xF8,0x3F,0xFE,0x1F,0x00,0xF8,0x07,0xF8,0x3F,0x00,0xF8,0x01,0xE0,0x7F,0x00,0xF8,0x00,0xE0,0xFF,0x00,
   0x78,0x00,0xC0,0xFF,0x01,0x38,0x00,0xC0,0xFF,0x03,0x00,0x00,0xC0,0xFF,0x03,0x00,0x00,0xC0,0xFF,0x03,0x00,0x00,0xC0,0xFF,0x07,0xC0,0x01,0xC0,0xFF,0x07,
   0xF0,0x0F,0xC0,0xFF,0x07,0xF8,0x1F,0xC0,0xFF,0x07,0xFC,0x1F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,
   0xFE,0x3F,0xC0,0xFF,0x03,0xFE,0x3F,0xC0,0xFF,0x03,0xFE,0x1F,0xC0,0xFF,0x01,0xFC,0x1F,0xC0,0xFF,0x01,0xFC,0x0F,0xE0,0xFF,0x00,0xF8,0x07,0xE0,0x7F,0x00,
   0xF0,0x0F,0xF8,0x3F,0x00,0xE0,0x3F,0xFE,0x0F,0x00,0x80,0x3F,0xFE,0x03,0x00,0x00,0x3E,0x7E,0x00,0x00, // Code for char num 53
   0x00,0xF8,0xF8,0x00,0x00,0x00,0xFE,0xF8,0x07,0x00,0x00,0xFF,0xF8,0x1F,0x00,0xC0,0x7F,0xE0,0x3F,0x00,0xE0,0x3F,0xC0,0x7F,0x00,0xE0,0x1F,0xE0,0xFF,0x00,
   0xF0,0x1F,0xE0,0xFF,0x00,0xF8,0x1F,0xF0,0xFF,0x01,0xF8,0x1F,0xF0,0xFF,0x01,0xFC,0x1F,0xF0,0xFF,0x01,0xFC,0x1F,0xF0,0xFF,0x01,0xFC,0x1F,0xF0,0xFF,0x01,
   0xFE,0x1F,0xF0,0xFF,0x01,0xFE,0x1F,0xE0,0xFF,0x00,0xFE,0x1F,0xC0,0x7F,0x00,0xFE,0x1F,0x80,0x3F,0x00,0xFF,0x1F,0x00,0x0E,0x00,0xFF,0x1F,0x00,0x00,0x00,
   0xFF,0x1F,0x00,0x00,0x00,0xFF,0x1F,0xF8,0x07,0x00,0xFF,0x1F,0xFF,0x1F,0x00,0xFF,0x9F,0xFF,0x7F,0x00,0xFF,0x1F,0xFF,0xFF,0x00,0xFF,0x1F,0xF0,0xFF,0x01,
   0xFF,0x1F,0xC0,0xFF,0x03,0xFF,0x1F,0xC0,0xFF,0x07,0xFF,0x1F,0x80,0xFF,0x07,0xFF,0x1F,0x80,0xFF,0x07,0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,
   0xFE,0x1F,0x80,0xFF,0x0F,0xFE,0x1F,0x80,0xFF,0x0F,0xFE,0x1F,0x80,0xFF,0x0F,0xFE,0x1F,0x80,0xFF,0x0F,0xFC,0x1F,0x80,0xFF,0x0F,0xFC,0x1F,0x80,0xFF,0x0F,
   0xFC,0x1F,0x80,0xFF,0x07,0xF8,0x1F,0x80,0xFF,0x07,0xF8,0x1F,0x80,0xFF,0x07,0xF0,0x1F,0x80,0xFF,0x03,0xE0,0x1F,0x80,0xFF,0x01,0xE0,0x3F,0xC0,0xFF,0x00,
   0xC0,0x7F,0xF0,0x7F,0x00,0x00,0xFF,0xF8,0x3F,0x00,0x00,0xFE,0xF8,0x0F,0x00,0x00,0xF8,0xF8,0x01,0x00, // Code for char num 54
   0x00,0xF8,0x01,0x00,0x00,0x1C,0xFE,0x1F,0x00,0x07,0x9C,0xFF,0x7F,0x80,0x07,0xDC,0xFF,0xFF,0xC3,0x07,0xFE,0xFF,0xFF,0xFF,0x07,0xFE,0xFF,0xFF,0xFF,0x07,
   0xFE,0xFF,0xFF,0xFF,0x03,0xFE,0xFF,0xFF,0xFF,0x03,0xFE,0xFF,0xFF,0xFF,0x01,0x3E,0xF8,0xFF,0xFF,0x01,0x1E,0xC0,0xFF,0xFF,0x00,0x1E,0x00,0xFE,0x3F,0x00,
   0x1E,0x00,0xE0,0x0F,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0xC0,0x0F,0x00,0x00,0x00,0xE0,0x07,0x00,
   0x00,0x00,0xF0,0x03,0x00,0x00,0x00,0xF8,0x03,0x00,0x00,0x00,0xFC,0x01,0x00,0x00,0x00,0xFE,0x01,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x80,0xFF,0x00,0x00,
   0x00,0xC0,0x7F,0x00,0x00,0x00,0xC0,0x7F,0x00,0x00,0x00,0xE0,0x7F,0x00,0x00,0x00,0xF0,0x3F,0x00,0x00,0x00,0xF0,0x3F,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,
   0x00,0xF8,0x3F,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,0x00,0xFC,0x3F,0x00,0x00,0x00,0xFC,0x3F,0x00,0x00,0x00,0xFC,0x7F,0x00,0x00,0x00,0xFC,0x7F,0x00,0x00,
   0x00,0xFC,0x7F,0x00,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0xF8,0xFF,0x00,0x00,
   0x00,0xF8,0x7F,0x00,0x00,0x00,0xF0,0x7F,0x00,0x00,0x00,0xE0,0x3F,0x00,0x00,0x00,0xC0,0x0F,0x00,0x00, // Code for char num 55
   0x00,0xF8,0xF9,0x01,0x00,0x00,0xFF,0xF9,0x0F,0x00,0xC0,0xFF,0xF9,0x3F,0x00,0xE0,0x7F,0xE0,0x7F,0x00,0xF0,0x3F,0xC0,0xFF,0x00,0xF8,0x1F,0x80,0xFF,0x01,
   0xFC,0x1F,0x80,0xFF,0x03,0xFC,0x1F,0x80,0xFF,0x03,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,
   0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFC,0x1F,0x80,0xFF,0x03,0xFC,0x1F,0x80,0xFF,0x03,0xF8,0x1F,0x80,0xFF,0x01,
   0xF8,0x1F,0x80,0xFF,0x01,0xF0,0x3F,0xC0,0xFF,0x00,0xE0,0xFF,0xF9,0x7F,0x00,0x80,0xFF,0xF9,0x1F,0x00,0x00,0xFF,0xF9,0x0F,0x00,0xC0,0xFF,0xF9,0x3F,0x00,
   0xF0,0x3F,0xC0,0xFF,0x00,0xF8,0x1F,0x80,0xFF,0x01,0xFC,0x1F,0x80,0xFF,0x03,0xFC,0x1F,0x80,0xFF,0x03,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,
   0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,0xFF,0x1F,0x80,0xFF,0x0F,
   0xFF,0x1F,0x80,0xFF,0x0F,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFE,0x1F,0x80,0xFF,0x07,0xFC,0x1F,0x80,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x01,
   0xF0,0x7F,0xE0,0xFF,0x00,0xE0,0xFF,0xF9,0x7F,0x00,0x80,0xFF,0xF9,0x1F,0x00,0x00,0xFC,0xF9,0x03,0x00, // Code for char num 56
   0x00,0xF8,0xF8,0x00,0x00,0x00,0xFF,0xF8,0x03,0x00,0xC0,0xFF,0xF8,0x07,0x00,0xE0,0x7F,0xF0,0x1F,0x00,0xF0,0x3F,0xE0,0x3F,0x00,0xF8,0x1F,0xC0,0x3F,0x00,
   0xFC,0x1F,0xC0,0x7F,0x00,0xFC,0x1F,0xC0,0xFF,0x00,0xFE,0x1F,0xC0,0xFF,0x00,0xFE,0x1F,0xC0,0xFF,0x01,0xFF,0x1F,0xC0,0xFF,0x01,0xFF,0x1F,0xC0,0xFF,0x01,
   0xFF,0x1F,0xC0,0xFF,0x03,0xFF,0x1F,0xC0,0xFF,0x03,0xFF,0x1F,0xC0,0xFF,0x03,0xFF,0x1F,0xC0,0xFF,0x03,0xFF,0x1F,0xC0,0xFF,0x07,0xFF,0x1F,0xC0,0xFF,0x07,
   0xFF,0x1F,0xC0,0xFF,0x07,0xFE,0x1F,0xC0,0xFF,0x07,0xFE,0x1F,0xC0,0xFF,0x07,0xFE,0x3F,0xC0,0xFF,0x07,0xFC,0x7F,0xC0,0xFF,0x07,0xF8,0xFF,0xC7,0xFF,0x07,
   0xF0,0xFF,0xCF,0xFF,0x07,0xE0,0xFF,0xCF,0xFF,0x07,0xC0,0xFF,0xC7,0xFF,0x07,0x00,0xFE,0xC0,0xFF,0x07,0x00,0x00,0xC0,0xFF,0x07,0x00,0x00,0xC0,0xFF,0x07,
   0xC0,0x07,0xC0,0xFF,0x03,0xF0,0x1F,0xC0,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x03,0xF8,0x3F,0xC0,0xFF,0x03,0xFC,0x7F,0xC0,0xFF,0x01,0xFC,0x7F,0xC0,0xFF,0x01,
   0xFC,0x7F,0xC0,0xFF,0x01,0xFC,0x7F,0xC0,0xFF,0x00,0xFC,0x7F,0xC0,0xFF,0x00,0xFC,0x3F,0xC0,0x7F,0x00,0xF8,0x3F,0xC0,0x3F,0x00,0xF0,0x1F,0xE0,0x3F,0x00,
   0xF0,0x3F,0xF0,0x1F,0x00,0xC0,0xFF,0xF8,0x07,0x00,0x80,0xFF,0xF8,0x03,0x00,0x00,0xFC,0xF8,0x00,0x00 // Code for char num 57
        };

/*const unsigned char Number_Font_Start = 0;
const unsigned char Number_Font_Length_Bytes = 230;
const unsigned char Number_Font_Width = 40;      // full bytes of pixels   8,16,24,32,40 etc
const unsigned char Number_Font_Height = 46;     //San Diego MEDIUM
const unsigned char Number_Font_Spacing = 2;*/



//GLCD FontName : Academy_Engraved_LET22x25
//GLCD FontSize : 22 x 25

const unsigned short Number_Font[] = {

   0x80,0x3F,0x00,0xE0,0xE0,0x00,0x50,0xC0,0x01,0x28,0x40,0x03,0x34,0x80,0x06,0x34,0x80,0x04,0x12,0x00,0x0D,0x1A,0x00,0x0D,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x19,0x00,0x19,0x1A,0x00,0x09,0x12,0x00,0x0D,0x34,0x80,0x0C,0x34,0x80,0x06,0x28,0x80,0x03,0x70,0x40,0x01,0xE0,0xA0,0x00,0xC0,0x7F,0x00, // Code for char num 48
   0x00,0x1C,0x00,0xE0,0x13,0x00,0x80,0x11,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x12,0x00,0x00,0x32,0x00,0x00,0x61,0x00,0xE0,0xFF,0x01, // Code for char num 49
   0x80,0x3F,0x00,0xC0,0xD0,0x00,0xE0,0xA0,0x01,0xD0,0x20,0x03,0xD0,0x40,0x03,0x50,0x40,0x02,0x60,0x40,0x02,0x00,0x40,0x03,0x00,0x20,0x03,0x00,0x20,0x03,0x00,0x90,0x01,0x00,0xD0,0x00,0x00,0x68,0x00,0x00,0x34,0x00,0x00,0x1C,0x00,0x00,0x0E,0x00,0x00,0x03,0x00,0x80,0x01,0x00,0x80,0x00,0x04,0x40,0x00,0x06,0x20,0x00,0x03,0xF0,0xFF,0x03,0xF0,0x3F,0x03,0x08,0x00,0x03,0xF8,0xFF,0x01, // Code for char num 50
   0xC0,0x3F,0x00,0x70,0x48,0x00,0x50,0xD0,0x00,0x48,0x90,0x01,0x68,0x90,0x01,0x30,0x90,0x01,0x00,0x90,0x01,0x00,0x90,0x00,0x00,0xC8,0x00,0x00,0x68,0x00,0x00,0x36,0x00,0x80,0xE9,0x00,0x00,0xC6,0x01,0x00,0x98,0x01,0x00,0x20,0x03,0x00,0x40,0x02,0x00,0x40,0x02,0x00,0x80,0x02,0x00,0x80,0x02,0x10,0x80,0x02,0x28,0x80,0x02,0x28,0x40,0x01,0x28,0xC0,0x00,0x70,0x60,0x00,0xE0,0x3F,0x00, // Code for char num 51
   0x00,0x60,0x00,0x00,0x50,0x00,0x00,0x48,0x00,0x00,0x48,0x00,0x00,0x4C,0x00,0x00,0x4A,0x00,0x00,0x49,0x00,0x00,0x49,0x00,0x80,0x48,0x00,0x40,0x48,0x00,0x20,0x48,0x00,0x20,0x48,0x00,0x10,0x48,0x08,0x08,0x48,0x08,0x04,0x48,0x06,0xFC,0xCF,0x07,0x02,0x48,0x06,0xFE,0xCF,0x07,0x00,0x48,0x00,0x00,0x48,0x00,0x00,0x48,0x00,0x00,0x48,0x00,0x00,0xC8,0x00,0x00,0x84,0x01,0x80,0xFF,0x07, // Code for char num 52
   0x80,0xFF,0x03,0x40,0x00,0x01,0xC0,0xFF,0x01,0xC0,0xFF,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0xE0,0x07,0x00,0x90,0x3F,0x00,0x10,0x78,0x00,0xF0,0xC0,0x00,0x00,0x87,0x01,0x00,0x18,0x03,0x00,0x20,0x02,0x00,0x40,0x06,0x00,0x40,0x06,0x00,0x80,0x06,0x00,0x80,0x06,0x30,0x80,0x02,0x28,0x80,0x02,0x28,0x40,0x01,0x68,0xC0,0x01,0x70,0xF0,0x00,0xE0,0x3F,0x00, // Code for char num 53
   0x00,0xFE,0x00,0x80,0x47,0x03,0x40,0x83,0x02,0xA0,0x81,0x06,0x90,0x80,0x06,0xD0,0x00,0x01,0xC8,0x00,0x00,0x48,0x00,0x00,0x64,0x00,0x00,0x64,0x18,0x00,0x64,0xFF,0x00,0xE4,0x20,0x03,0x64,0x40,0x06,0x64,0x80,0x06,0x64,0x80,0x0C,0x64,0x80,0x0C,0x64,0x80,0x0C,0x64,0x80,0x0C,0x64,0x80,0x0C,0x68,0x80,0x0C,0x68,0x80,0x06,0xD0,0x80,0x06,0xE0,0x40,0x03,0xC0,0xC1,0x01,0x80,0xFF,0x00, // Code for char num 54
   0xE0,0xFF,0x07,0x20,0x00,0x06,0x10,0xFF,0x03,0xF0,0xFF,0x03,0x30,0x00,0x01,0x10,0x80,0x00,0x08,0x80,0x00,0x00,0x40,0x00,0x00,0x60,0x00,0x00,0x30,0x00,0x00,0x28,0x00,0x00,0x28,0x00,0x00,0x14,0x00,0x00,0x14,0x00,0x00,0x12,0x00,0x00,0x1A,0x00,0x00,0x1A,0x00,0x00,0x19,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x80,0x0C,0x00,0x80,0x0C,0x00,0x80,0x0C,0x00,0x80,0x0F,0x00, // Code for char num 55
   0x00,0x7F,0x00,0xC0,0xC0,0x00,0x60,0x80,0x01,0x50,0x00,0x03,0x30,0x00,0x03,0x50,0x00,0x03,0x50,0x00,0x03,0xD0,0x00,0x03,0x90,0x01,0x01,0x20,0x87,0x00,0x20,0x7C,0x00,0xC0,0xF0,0x00,0x80,0xC3,0x01,0x60,0x0C,0x03,0x30,0x30,0x06,0x28,0xC0,0x04,0x14,0x00,0x0D,0x14,0x00,0x09,0x14,0x00,0x0A,0x14,0x00,0x0A,0x14,0x00,0x06,0x38,0x00,0x05,0x28,0x00,0x03,0xF0,0x80,0x01,0xC0,0x7F,0x00, // Code for char num 56
   0x80,0x3F,0x00,0xE0,0xE0,0x00,0x50,0xA0,0x01,0x68,0x40,0x03,0x28,0x40,0x02,0x24,0x80,0x06,0x24,0x80,0x04,0x24,0x80,0x0C,0x24,0x80,0x0C,0x64,0x80,0x0C,0x64,0x80,0x0C,0x64,0x80,0x0C,0xC8,0x80,0x0C,0x90,0x81,0x0C,0x20,0xE3,0x0C,0xC0,0x9F,0x0C,0x00,0x80,0x0C,0x00,0x80,0x04,0x00,0x80,0x06,0x00,0x40,0x06,0x60,0x40,0x03,0xD0,0x40,0x01,0xD0,0xA0,0x01,0x90,0xD0,0x00,0xE0,0x3F,0x00 // Code for char num 57
        };



const unsigned char Number_Font_Start = 0;
const unsigned char Number_Font_Length_Bytes = 75;
const unsigned char Number_Font_Width = 24;      // full bytes of pixels   8,16,24,32,40 etc
const unsigned char Number_Font_Height = 25;     //Academy_Engraved_LET16x20
const unsigned char Number_Font_Spacing = 2;


#define Black_Out         Write_Data_SSD1963(0b0000000000000000);
#define Brown_Out         Write_Data_SSD1963(0b1111101000000000);
#define Red_Out           Write_Data_SSD1963(0b1111100000000000);
#define Orange_Out        Write_Data_SSD1963(0b1111001110000000);
#define Yellow_Out        Write_Data_SSD1963(0b1111111111100000);
#define Green_Out         Write_Data_SSD1963(0b0000011111100000);
#define Blue_Out          Write_Data_SSD1963(0b0000000000010111);
#define Violet_Out        Write_Data_SSD1963(0b1111000000011111);
#define Olive_Out         Write_Data_SSD1963(0b0011100111100011);
#define White_Out         Write_Data_SSD1963(0xFFFF);
#define Magenta_Out       Write_Data_SSD1963(0b1111100100001101);
#define Lime_Out          Write_Data_SSD1963(0b0111011111101100);
#define Baby_Powder_Out   Write_Data_SSD1963(0b1110111010001111);
#define Cyan_Out          Write_Data_SSD1963(0b0000011111111111);
#define Lavenderblush_Out Write_Data_SSD1963(0b1111101111000111);
#define Beige_Out         Write_Data_SSD1963(0b1011110000000000);


const unsigned char Black = 0;
const unsigned char Brown = 1;
const unsigned char Red = 2;
const unsigned char Orange = 3;
const unsigned char Yellow = 4;
const unsigned char Green = 5;
const unsigned char Blue = 6;
const unsigned char Violet = 7;
const unsigned char Olive = 8;
const unsigned char White = 9;
const unsigned char Magenta = 10;
const unsigned char Lime = 11;
const unsigned char Baby_Powder = 12;
const unsigned char Cyan = 13;
const unsigned char Lavenderblush = 14;
const unsigned char Beige = 15;

sbit SRAM_CS at LATJ4_Bit;
sbit SRAM_CS_Direction at TRISJ4_bit;

unsigned char TFT_DataPort at LATE;
unsigned char TFT_DataPort_Direction at TRISE;  //TRISE is lower PMD 0>7

sbit TFT_RST at LATB11_Bit; //RESET

sbit TFT_RS  at LATG12_BIT;  //TRD1/SQID1/RG12 PIN140

sbit TFT_CS  at LATG15_BIT;       //NEW 252 EFH

sbit TFT_RD  at LATC4_bit;  //PMRD  READ   EBIOE/AN19/RPC4/PMRD/RC4 PIN 13

sbit TFT_WR  at LATC3_bit;  //PMWR  WRITE  EBIWE/AN20/RPC3/PMWR/RC3 PIN 12

sbit TFT_RST_Direction at TRISB11_bit;    //RESET

sbit TFT_RS_Direction  at TRISG12_BIT;    //PIN 140 RG12

sbit TFT_CS_Direction  at TRISG15_BIT;      //NEW 252 EFH

sbit TFT_RD_Direction  at TRISC4_bit;    //PMRD  READ

sbit TFT_WR_Direction  at TRISC3_bit;    //PMWR  WRITE  EBIWE/AN20/RPC3/PMWR/RC3

sbit Mmc_Chip_Select            at LATE8_bit;
sbit Mmc_Chip_Select_Direction at TRISE8_bit;


void Set_Index(unsigned char index) {
  TFT_RS = 0;
  PMDOUT = index;
  while(PMMODE & 0x8000); //Busy bit
}

void Write_Command(unsigned char command ) {
  TFT_RS = 1;
  PMDOUT = command;
  while(PMMODE & 0x8000); //Busy bit
}

void Write_Data(unsigned int _data) {
  TFT_RS = 1;
  PMDOUT = _data;
  while(PMMODE & 0x8000); //Busy bit
}

void Write_Command_SSD1963(unsigned char Command) {
  TFT_RS = 0;  //RS = 0 NOT DATA  D/C = 0
  PMDOUT = Command;
  while(PMMODE & 0x8000); //Busy bit
}


void Write_Data_SSD1963(unsigned int _data) {
  TFT_RS = 1;   //RS = 1 = DATA   D/C = 1
  PMDOUT = _data;
  while(PMMODE & 0x8000); //Busy bit
}

void Init_16Bit_PMP() {

  PMMODE = 0;
  PMCONBits.DUALBUF = 1;   //DUAL BUFFER FOR IN AND OUT
  PMMODEbits.MODE = 2;     // Master 2     slave =1
  PMMODEbits.WAITB = 1;    //WAITB<1:0>: Data Setup before a Read/Write Strobe Wait States bits(1) 11 = Data wait of 4 TPB; multiplexed address phase of 4 TPB  10 = Data wait of 3 TPB; multiplexed address phase of 3 TPB 01 = Data wait of 2 TPB; multiplexed address phase of 2 TPB 00 = Data wait of 1 TPB; multiplexed address phase of 1 TPB (default)
  PMMODEbits.WAITM = 3;    //1111 = Wait of 16 TPB --0001 = Wait of 2 TPB-- 0000 = Wait of 1 TPB (default)STROBE PULSE WIDTH
  PMMODEbits.WAITE = 1;   //bit 1-0WAITE<1:0>: Data Hold After Read/Write Strobe Wait States bits(1)

  PMMODEbits.MODE16 = 1;   // 1 = 16-bit mode: a read or write to the data register invokes a single 16-bit transfer   For read operations  11 = Wait of 3 TPB  00 = Wait of 0 TPB (default)
  PMCONbits.CSF = 0;      //chip select bit
  PMCONbits.PTRDEN = 1;   //READ STROBE
  PMCONbits.PTWREN = 1;   //WRITE STROBE
  PMCONbits.PMPEN = 1;    //PMP ENABLE
  TFT_Set_Active(Set_Index,Write_Command,Write_Data);
}

void TFT_Set_DBC_SSD1963_BACKLIGHT(char value2) {  //PAGE54
  TFT_CS = 0;
  TFT_Set_Index_Ptr(0xBE);
  TFT_Write_Command_Ptr(0x06);
  TFT_Write_Command_Ptr(value2);
  TFT_Write_Command_Ptr(0x01); // PWM CONTROLLED BY DBC
  TFT_Write_Command_Ptr(0xFF); //MAX
  TFT_Write_Command_Ptr(0x00); //MIN
  TFT_Write_Command_Ptr(0x01);
  TFT_CS = 1;
}



void TFT_SET_MODE_SSD1963_5_Inch(){  // & newer 7"            Page 84 for timing


      TFT_CS_Direction = 0;
      TFT_RST_Direction = 0;
      TFT_RD_Direction = 0;
      TFT_WR_Direction = 0;
      TFT_RST = 0;
      Delay_ms(10);
      TFT_RST = 1;
      Delay_ms(10);
      TFT_RD = 1;
      TFT_WR = 1;

       TFT_CS = 0;

      TFT_Set_Index_Ptr(0x01);     //Software Reset
      Delay_ms(10);                //The Host Processor Must Wait 5ms Before Sending Any New Commands

      TFT_Set_Index_Ptr(0xE2);        // SET PLL
      TFT_Write_Command_Ptr(0x22);    // MULTIPLIER 10 MHz BASE CLOCK x 36 = 360  08/07/21
      TFT_Write_Command_Ptr(0x02);    // DIVIDES BY THIS NUMBER + 1 DIVIDE BY 3 = 120 MHz
      TFT_Write_Command_Ptr(17);      // DUMMY   08/07/21 WAS 0X04

      TFT_Set_Index_Ptr(0xE0);
      TFT_Write_Command_Ptr(0x01); // START PLL   BIT ZERO
      Delay_ms(50);               // Wait 100ms for the PLL to Lock 08/07/21
      TFT_Set_Index_Ptr(0xE0);
      TFT_Write_Command_Ptr(0x03); // BIT 1 = USE PLL AS OUTPUT BIT ZERO = ENABLE PLL 08/07/21

      TFT_Set_Index_Ptr(0x26);       // Set Gamma Curve
      TFT_Write_Command_Ptr(0x01);   // Gamma curve selection =0
    //TFT_Write_Command_Ptr(0x02);   // Gamma curve selection =1
    //TFT_Write_Command_Ptr(0x04);   // Gamma curve selection =2
    //TFT_Write_Command_Ptr(0x08);   // Gamma curve selection =3

      TFT_Set_Index_Ptr(0x0B);       //SET SCAN MODE
      TFT_Write_Command_Ptr(0x00);   //SET TFT MODE   top to bottom, left to right normal etc

      TFT_Set_Index_Ptr(0x0A);
      TFT_Write_Command_Ptr(0x1C);   //Power Mode

      TFT_Set_Index_Ptr(0xF0);       // Set Pixel Data Interface
      TFT_Write_Command_Ptr(0x03);   // 16-bit (565 format)   011 16-bit (565 format)

      TFT_Set_Index_Ptr(0x38);     //Exit Idle Mode

      TFT_Set_Index_Ptr(0x13);     //Enter Normal Mode;

      TFT_Set_Index_Ptr(0xBC);     //Set Post Proc
      TFT_Write_Command_Ptr(0x4D); //40 Set the contrast value     4D == 77  127 decimal is max    4D FOR CHINA DISPLAY
      TFT_Write_Command_Ptr(150);  //80 Set the brightness value   80 == 128 160 decimal is about max  85 FOR CHINA DISPLAY 08/07/21
      TFT_Write_Command_Ptr(0x60); //40 Set the saturation value   40 ==  64  127 decimal is max!  zero is black & white 6E FOR CHINA DISPLAY
      TFT_Write_Command_Ptr(0x01); //1 Enable the postprocessor


      TFT_Set_Index_Ptr(0xB0);          //SET LCD MODE   SIZE !!  08/07/21
      TFT_Write_Command_Ptr(32);        //Bit 5 Is 24 Bit Colour On TFT Panel All Active Low Pulses  MIDAS TFT PANEL IS 24 BIT
      TFT_Write_Command_Ptr(0);         //BIT 6 & 5TFT MODE NOT SERIAL
      TFT_Write_Command_Ptr(0x03);      //03 SET horizontal size=800+1 HightByte   !!!!!!!!!!!!
      TFT_Write_Command_Ptr(0x21);      //SET horizontal size=800+1 LowByte
      TFT_Write_Command_Ptr(0x01);      //SET vertical size=480+1 HightByte
      TFT_Write_Command_Ptr(0xE0);      //SET vertical size=480+1 LowByte
      TFT_Write_Command_Ptr(0x00);      //Even line RGB sequence / Odd line RGB sequence RGB

      // Set LSHIFT freq (DCLK from PLL)
      //  Typical DCLK for TM070RBH10 is 29.23MHz  NEW ==  Dot Data ClockD CLK - 33.26 - MHz  for 5" <<<<<<<<<<
      // 33.30 = 120 * (LCDC_FPR + 1) / 2^20
      // 5.3 (million) times  2^20  divide  120 = 46312    // y over x   on calculator

      TFT_Set_Index_Ptr(0xe6);       // pixel clock frequency  08/07/21
      TFT_Write_Command_Ptr(0x05);   // >>>LCD_FPR = 349526
      TFT_Write_Command_Ptr(0x55);   //40,000,076 Hz   40 MHz  349 526    08/07/21
      TFT_Write_Command_Ptr(0x00);


      /////////////////////////HORIZONTAL PERIOD BELOW /////  08/07/21  ///////////////////////////////////////

      TFT_Set_Index_Ptr(0xB4);          // Set Horizontal Period   MIN 862 TYPICAL 1056 MAX 1200
      TFT_Write_Command_Ptr(0x03);      // High byte of horizontal total period (display + non-display)   900 = 0X384
      TFT_Write_Command_Ptr(0x84);      // Low byte of the horizontal total period (display + non-display) 900
      TFT_Write_Command_Ptr(0x00);      // High byte of the non-display period between the start of the horizontal sync (LLINE) signal and the first display data. TOO LOW CAPTURE WONT WORK
      TFT_Write_Command_Ptr(68);        // 8 JULY 2021 MIN BLANKING SPEC IS 62 Low byte of the non-display period between the start of the horizontal sync (LLINE) signal and the first display data
      TFT_Write_Command_Ptr(8);         // Set the vertical sync pulse width
      TFT_Write_Command_Ptr(0x00);      // SET Hsync pulse start position
      TFT_Write_Command_Ptr(0x00);
      TFT_Write_Command_Ptr(0x00);      //SET Hsync pulse subpixel start position  //

      /////////////////////  08/07/21  //// VERTICAL PERIOD BELOW ////////////

      TFT_Set_Index_Ptr(0xB6);          //Set Vertical Period Set Vertical Period MIN = 510 TYPICAL = 525 MAX = 650  08/07/21
      TFT_Write_Command_Ptr(0x02);      // High byte of the vertical total (display + non-display) period in lines
      TFT_Write_Command_Ptr(0x12);      // Low byte INCREASES SYNC TIME AND BACK PORCH  (530) 480 + 40 +  10
      TFT_Write_Command_Ptr(0x00);      // 00
      TFT_Write_Command_Ptr(40);        //The non-display period in lines between the start of the frame and the first display data in line.
      TFT_Write_Command_Ptr(6);         //Set the vertical sync pulse width (LFRAME) in lines. TFT DOES NOT REQUIRE A SYNC PULSE
      TFT_Write_Command_Ptr(0x00);      //SET Vsync pulse start position  08/07/21
      TFT_Write_Command_Ptr(0x00);


      TFT_Set_Index_Ptr(0x36);          //Set Vertical Period
      TFT_Write_Command_Ptr(0b00000000);        //   BIT 7 = 0 Top to bottom, pages transferred from SP (Start Page) to EP (End Page).
                                                //   BIT 6 0 Left to right, columns transferred from SC (Start Column) to EC (End Column).
                                                //   BIT 5 0 Normal mode
                                                //   BIT 4 0 LCD refresh from top line to bottom line.
                                                //   BIT 3 0 RGB
                                                //   BIT 2 0 LCD refresh from left side to right side
                                                //   BIT 1 0 Normal
                                                //   BIT 0 0 Normal

      TFT_Set_Index_Ptr(0x29);       //SET display on     ************
       TFT_CS = 1;
}

static void Init_MCU() {

   ANSELA = 0;
   ANSELB = 0;
   ANSELC = 0;
   ANSELD = 0;
   ANSELE = 0;
   ANSELF = 0;
   ANSELG = 0;
   ANSELH = 0;
   ANSELJ = 0;

   TRISA = 0;
   TRISB = 0;
   TRISC = 0;
   TRISD = 0;
   TRISE = 0;
   TRISF = 0;
   TRISG = 0;
   TRISH = 0;
   TRISJ = 0;
   TRISK = 0;

   SRAM_CS_Direction = 0;


   TRISD14_Bit = 1;
   SDI3R  = 0b1011; // = RPD14      PAGE 251     RD14 = SDI3    SPI3
   RPB10R = 0b0111; // = SDO3       PAGE 254     RB10 = SD03    SPI3

   PORTA=0;PORTB=0;PORTC=0;PORTD=0;PORTE=0;PORTF=0;PORTG=0; PORTH=0; PORTJ=0;  PORTK=0;

   TRISA14_Bit = 1;
   INT3R = 0b1101; // = RPA14   clock in pin RA14

   JTAGEN_bit = 0;
}



////////////////////////////////////////////////////////////////////////////////    �little-endian�   Least Significant Number first !!  //////////////////////////////////////

//Offset |   Size    | Description           Implementing File I/O Functions Using Microchip�s Memory Disk Drive File System Library  AN1045
//  00h  |   3 Bytes | Jump Code + NOP
//  03h  |   8 Bytes | OEM Name
//  0Bh  |   1 Word  | Bytes per Sector ------we expect 64 0x0B to 0x0C Table shows 00 02 put 0x02 into calculator and add 2 zeros
//  0Dh  |   1 Byte  | Sectors per Cluster
//  0Eh  |   1 Word  | Start sector for FAT1 also known as Reserved Sectors
//  10h  |   1 Byte  | Number of Copies of FAT
//  11h  |   1 Word  | Number of Root Directory Entries 0x11 & 0x12
//  13h  |   1 Word  | Number of Sectors in Partition Smaller than 32MB
//  15h  |   1 Byte  | Media Descriptor (F8h for Hard Disks)
//  16h  |   1 Word  | Sectors per FAT
//  18h  |   1 Word  | Sectors per Cluster   //Sectors per Track
//  1Ah  |   1 Word  | Number of Heads
//  1Ch  |   1 DWord | Number of Hidden Sectors in Partition
//  20h  |   1 DWord | Number of Sectors in Partition
//  24h  |   1 Word  | Logical Drive Number of Partition
//  26h  |   1 Byte  | Extended Signature (29h)
//  27h  |   1 DWord | Serial Number of Partition
//  2Bh  |  11 Bytes | Volume Name of Partition
//  36h  |   8 Bytes | FAT Name (FAT16)
//  3Eh  | 448 Bytes | Executable Code
//  1FEh |   2 Bytes | Executable Marker (55h AAh)

////////////////////////////////////////////////////////////////////////////////////


unsigned char  SectorBuffer[512];                 // FOR BOOT SECTOR
unsigned long  First_File_Allocation_Table_at;    // Sector number of first FAT


//   Offset  |  Size     |  Description        Implementing File I/O Functions Using Microchip�s Memory Disk Drive File System Library  AN1045
//      00h  |  8 Bytes  |  Filename(1).
//      08h  |  3 bytes  |  File Extension.   //10  == zero
//      0Bh  |  1 Byte   |  File Attributes.
//      0Ch  |  1 Byte   |  Reserved.
//      0Dh  |  1 Byte   |  File Creation Time (ms portion).
//      0Eh  |  2 Bytes  |  File Creation Time (hours, minutes and seconds).
//      10h  |  2 bytes  |  File Creation Date.
//      12h  |  2 Bytes  |  Last Access Date.
//      14h  |  2 Bytes  |  Extended Address-Index.
//      16h  |  2 Bytes  |  Last Update Time (hours, minutes and seconds).
//      18h  |  2 Bytes  |  Last Update Date.
//      1Ah  |  2 Bytes  |  First Cluster of the File.
//      1Ch  |  4 Bytes  |  File Size. 4 bytes

unsigned char   Boot_Sector = 0;   // Sector number of Boot Record
unsigned long   Root_Directory;  // Sector number of Root Directory
unsigned int    First_File_Allocation_Table; // Sector number of first FAT
unsigned int    Bytes_Per_Sector;
unsigned int    Sectors_Per_Cluster; //Sectors per Track
unsigned int    Start_Sector_for_FAT1;   //  Also known as Reserved_Sectors;  0Eh
unsigned short  Number_of_File_Allocation_Tables;
unsigned int    Number_of_Root_Directory_Entries;   // Number of Root Directory Entries
unsigned int    Sectors_Per_FAT;    //Sectors per FAT
unsigned long   Number_of_Sectors;
unsigned long   Number_Of_Hidden_Sectors;
unsigned char   byte_String[4];
unsigned char   int_String[7];
unsigned char   Long_String[14];
unsigned long   sector;
unsigned long   sectorb0;
unsigned long   sectorb1;
unsigned long   sectorb2;
unsigned long   sectorb3;
unsigned long   Cluster_Size;  //int x int = long



unsigned int Background_Colour;

Clear_Screen_SSD1963(unsigned int Colour){

     unsigned long i;
     TFT_CS = 0;
     Background_Colour = 0x00 | Colour;

     Write_Command_SSD1963(0x2A); //Set Column Address 800
     Write_Data_SSD1963(0x00);
     Write_Data_SSD1963(0x00);
     Write_Data_SSD1963(0x03);
     Write_Data_SSD1963(0x20);

     Write_Command_SSD1963(0x2B); //Set Row Address 480
     Write_Data_SSD1963(0);
     Write_Data_SSD1963(0);
     Write_Data_SSD1963(0x1);
     Write_Data_SSD1963(0xE0);

     Write_Command_SSD1963(0x2C);   // Write Memory Start, 0x2C

    switch (Colour)  {

     case 0:     for(i=0;i<384480;i++){
                 Black_Out;
                 } break;
     case 1:     for(i=0;i<384480;i++){
                 Brown_Out;
                 } break;
     case 2:     for(i=0;i<384480;i++){
                 Red_Out;
                 } break;
     case 3:     for(i=0;i<384480;i++){
                 Orange_Out;
                 } break;
     case 4:     for(i=0;i<384480;i++){
                 Yellow_Out;
                 } break;
     case 5:     for(i=0;i<384480;i++){
                 Green_Out;
                 } break;
     case 6:     for(i=0;i<384480;i++){
                 Blue_Out;
                 } break;
     case 7:     for(i=0;i<384480;i++){
                 Violet_Out;
                 } break;
     case 8:     for(i=0;i<384480;i++){
                 Olive_Out;
                 } break;
     case 9:     for(i=0;i<384480;i++){
                 White_Out;
                 } break;
     case 10:    for(i=0;i<384480;i++){
                 Magenta_Out;
                 } break;
     case 11:    for(i=0;i<384480;i++){
                 Lime_Out;
                 } break;
     case 12:    for(i=0;i<384480;i++){
                 Baby_Powder_Out;
                 } break;
     case 13:    for(i=0;i<384480;i++){
                 Cyan_Out;
                 } break;
     case 14:    for(i=0;i<384480;i++){
                 Lavenderblush_Out;
                 } break;
     case 15:    for(i=0;i<384480;i++){
                 Beige_Out;
                 } break;
     default:    for(i=0;i<384480;i++){
                 Write_Data_SSD1963(Colour);
                 } break;
    }

    TFT_CS = 1;
    return Background_Colour;
}


unsigned int Pixel;
void Get_Pixel_Colour(unsigned int Colour){

      switch (Colour)  {

     case 0:     Pixel = 0x00;
                 break;
     case 1:     Pixel = 0b1111101000000000;
                 break;
     case 2:     Pixel = 0b1111000000000000;
                 break;
     case 3:     Pixel = 0b1111001110000000;
                 break;
     case 4:     Pixel = 0b1111111111100000;
                 break;
     case 5:     Pixel = 0b0000001100000000;
                 break;
     case 6:     Pixel = 0b0000000000010111;
                 break;
     case 7:     Pixel = 0b1111000000011111;
                 break;
     case 8:     Pixel = 0b0011100111100011;
                 break;
     case 9:     Pixel = 0b1111111111111111;
                 break;
     case 10:    Pixel = 0b1111100100001101;
                 break;
     case 11:    Pixel = 0b0110011111100000;
                 break;
     case 12:    Pixel = 0b1110111010001111;
                 break;
     case 13:    Pixel = 0b0000011111111111;
                 break;
     case 14:    Pixel = 0b1111101111000111;
                 break;
     case 15:    Pixel = 0b1011110000000000;
                 break;
     default:    Pixel = Colour;
                 break;
    }

    switch (Background_Colour)  {

     case 0:     Background_Colour = 0x00;
                 break;
     case 1:     Background_Colour = 0b1111101000000000;
                 break;
     case 2:     Background_Colour = 0b1111000000000000;
                 break;
     case 3:     Background_Colour = 0b1111001110000000;
                 break;
     case 4:     Background_Colour = 0b1111111111100000;
                 break;
     case 5:     Background_Colour = 0b0000001100000000;
                 break;
     case 6:     Background_Colour = 0b0000000000010111;
                 break;
     case 7:     Background_Colour = 0b1111000000011111;
                 break;
     case 8:     Background_Colour = 0b0011100111100011;
                 break;
     case 9:     Background_Colour = 0b1111111111111111;
                 break;
     case 10:    Background_Colour = 0b1111100100001101;
                 break;
     case 11:    Background_Colour = 0b0110011111100000;
                 break;
     case 12:    Background_Colour = 0b1110111010001111;
                 break;
     case 13:    Background_Colour = 0b0000011111111111;
                 break;
     case 14:    Background_Colour = 0b1111101111000111;
                 break;
     case 15:    Background_Colour = 0b1011110000000000;
                 break;
     default:    break;
    }
}

void Set_Display_Numbers_SSD1963(unsigned int X_Position, unsigned int Y_Position){

     unsigned int Set_Start_Column = 0x00 | X_Position;
     unsigned int Set_Start_Row = 0x00 | Y_position;

     unsigned int Set_End_Column = Set_Start_Column + Number_Font_width-1; //(bytes -1 bit) 8 pixels = 1 byte, 16 pixels = 2 bytes
     unsigned int Set_End_Row = Set_Start_Row + Number_font_height;

     TFT_CS = 0;
     Write_Command_SSD1963(0x2A);               //Set Start Column               D/C = 0;
     Write_Data_SSD1963(Set_Start_column>>8);   //Start column number high byte  D/C = 1;
     Write_Data_SSD1963(Set_Start_column);      //Start column number low byte   D/C = 1;
     Write_Data_SSD1963(Set_End_Column>>8);     //End column number high byte    D/C = 1;
     Write_Data_SSD1963(Set_End_Column);        //End column number low byte     D/C = 1;

     Write_Command_SSD1963(0x2B);             //SET ROW ADDRESS                  D/C = 0;
     Write_Data_SSD1963(Set_Start_Row>>8);    //Start page(row)number high byte  D/C = 1;
     Write_Data_SSD1963(Set_Start_Row);       //Start page (row) number low byte D/C = 1;
     Write_Data_SSD1963(0x01);                //End page (row) number high byte  D/C = 1;
     Write_Data_SSD1963(0xE0);                //End page (row) number low byte   D/C = 1;

     Write_Command_SSD1963(0x2C);   //WRITE MEMORY START                         D/C = 0;

     TFT_CS = 1;
}

void Write_Number_Nine(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*9; jj<Number_Font_Length_Bytes*10; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Eight(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*8; jj<Number_Font_Length_Bytes*9; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }

     TFT_CS = 1;
}

void Write_Number_Seven(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*7; jj<Number_Font_Length_Bytes*8; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Six(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*6; jj<Number_Font_Length_Bytes*7; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Five(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*5; jj<Number_Font_Length_Bytes*6; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Four(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*4; jj<Number_Font_Length_Bytes*5; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Three(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*3; jj<Number_Font_Length_Bytes*4; jj++){    //Number Three

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Two(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*2; jj<Number_Font_Length_Bytes*3; jj++){    //Number Two

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){

          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_One(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x=0;
     static unsigned char dataout=0;
     static unsigned int i=1;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);

     TFT_CS = 0;

      for (jj=Number_Font_Length_Bytes*1; jj<Number_Font_Length_Bytes*2; jj++){    //Number One

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){
          Write_Data_SSD1963(Pixel);
         } else  { Write_Data_SSD1963(Background_Colour);  }// Space

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}




void Write_Number_Zero(unsigned int X_Position, unsigned int Y_Position, unsigned int Colour){
     static unsigned char x = 0;
     static unsigned char dataout = 0;
     static unsigned int i = 1;
     static unsigned int jj = 0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);
     TFT_CS = 0;

      for (jj=Number_Font_Start; jj<Number_Font_Length_Bytes*1; jj++){    //Number One

         for (x=0; x<8; x++){

          dataout = Number_Font[jj] &i;

         if (dataout){
          Write_Data_SSD1963(Pixel);

         } else { Write_Data_SSD1963(Background_Colour);  }

          i=i<<1;

          if (i>128){
               i=1;}
         }
     }
     TFT_CS = 1;
}

void Write_Number_Space(unsigned int X_Position, unsigned int Y_Position){
     static unsigned int Colour;
     static unsigned int jj=0;

     Get_Pixel_Colour(Colour);
     Set_Display_Numbers_SSD1963(X_Position,Y_Position);
     TFT_CS = 0;

     for (jj=0; jj<Number_Font_Length_Bytes*8; jj++){    //Space

       Write_Data_SSD1963(Background_Colour);
     }
      TFT_CS = 1;
}

   unsigned char DoneOne   = 1;
   unsigned char DoneTwo   = 1;
   unsigned char DoneThree = 1;
   unsigned char DoneFour  = 1;
   unsigned char DoneFive  = 1;
   unsigned char DoneSix   = 1;
   unsigned char DoneSeven = 1;
   unsigned char DoneEight = 1;
   unsigned char DoneNine  = 1;
   unsigned char ValidEight = 0, ValidSeven = 0, ValidSix = 0, ValidFive = 0, ValidFour = 0, ValidThree = 0, ValidTwo = 0, ValidOne = 0, ValidZero = 0;

void Write_Number(unsigned long num,unsigned int X_Position,unsigned int Y_Position, unsigned char Font_Colour) {

   unsigned int Font_Width;
   unsigned int units_start;
   unsigned int tens_start;
   unsigned int hundreds_start;
   unsigned int thousands_start;
   unsigned int ten_thousands_start;
   unsigned int hundred_thousands_start;
   unsigned int million_start;
   unsigned int ten_million_start;
   unsigned int hundred_million_start;
   unsigned int Billion_Start;
   unsigned char Colour;
   static unsigned char numberstring[14];
   Colour = 0x00 | Font_Colour;
   Font_Width = Number_Font_Width + Number_Font_Spacing;

    if (num <=9){
        units_start = X_Position;   }

   if (num >=10 && num<=99){
       DoneOne = 0;
       ValidEight = 1;
       units_start = X_Position +Font_Width*1;
       tens_start= X_Position;
      }

    if (num >=100 && num<=999){
       DoneTwo = 0;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position + Font_Width *2;
       tens_start = X_Position + Font_Width*1;
       hundreds_start = X_Position;
      }

      if (num >=1000 && num<=9999){             //thousand
       DoneThree = 0;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position +Font_Width *3;
       tens_start = X_Position + Font_Width *2;
       hundreds_start = X_Position + Font_Width*1;
       thousands_start = X_Position;
       }

       if (num >=10000 && num<=99999){            //ten thousand to 99 thousand
       DoneFour = 0;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position + Font_Width *4;
       tens_start = X_Position +Font_Width *3;
       hundreds_start = X_Position + Font_Width *2;
       thousands_start = X_Position + Font_Width*1;
       ten_thousands_start = X_Position;
       }

       if (num >=100000 && num<=999999){         //100 thousand  to 999 thousand
       DoneFive = 0;
       ValidFour = 1;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position + Font_Width *5;
       tens_start = X_Position + Font_Width *4;
       hundreds_start = X_Position + Font_Width *3;
       thousands_start = X_Position+ Font_Width *2;
       ten_thousands_start = X_Position + Font_Width*1;
       hundred_thousands_start = X_Position;
       }

       if (num >=1000000 && num<=9999999){         // 1 million  to 9'999'999
       DoneSix = 0;
       ValidThree = 1;
       ValidFour = 1;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position+ Font_Width *6;
       tens_start = X_Position + Font_Width *5;
       hundreds_start = X_Position +Font_Width *4;
       thousands_start = X_Position+ Font_Width *3;
       ten_thousands_start = X_Position+ Font_Width *2;
       hundred_thousands_start = X_Position+ Font_Width*1;
       million_start = X_Position;
       }

       if (num >=10000000 && num<=99999999){       //ten million to 99 million
       DoneSeven = 0;
       ValidTwo = 1;
       ValidThree = 1;
       ValidFour = 1;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position+ Font_Width *7;
       tens_start = X_Position + Font_Width *6;
       hundreds_start = X_Position + Font_Width *5;
       thousands_start = X_Position+ Font_Width *4;
       ten_thousands_start = X_Position+ Font_Width *3;
       hundred_thousands_start = X_Position+ Font_Width *2;
       million_start = X_Position+ Font_Width*1;
       ten_million_start = X_position;
       }

       if (num >=100000000 && num<=999999999){       //humdred million
       DoneEight = 0;
       ValidOne = 1;
       ValidTwo = 1;
       ValidThree = 1;
       ValidFour = 1;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position+ Font_Width *8;
       tens_start = X_Position + Font_Width *7;
       hundreds_start = X_Position + Font_Width *6;
       thousands_start = X_Position+ Font_Width *5;
       ten_thousands_start = X_Position+ Font_Width *4;
       hundred_thousands_start = X_Position+ Font_Width *3;
       million_start = X_Position+ Font_Width*2;
       ten_million_start = X_position+Font_Width;
       hundred_million_start = X_Position;
       }

       if (num >=1000000000 && num<=4294967295){      //Billion  A Long Will Only Count Up To 4 Billion 4'294'967'295
       DoneNine = 0;
       ValidZero = 1;
       ValidOne = 1;
       ValidTwo = 1;
       ValidThree = 1;
       ValidFour = 1;
       ValidFive = 1;
       ValidSix = 1;
       ValidSeven = 1;
       ValidEight = 1;
       units_start = X_Position + Font_Width *9;
       tens_start = X_Position + Font_Width *8;
       hundreds_start = X_Position + Font_Width *7;
       thousands_start = X_Position+ Font_Width *6;
       ten_thousands_start = X_Position+ Font_Width *5;
       hundred_thousands_start = X_Position+ Font_Width *4;
       million_start = X_Position+ Font_Width*3;
       ten_million_start = X_position+Font_Width*2;
       hundred_million_start = X_Position+Font_Width;
       Billion_Start = X_Position;
       }
       LongWordTostr(num,numberstring);     // Converts input unsigned long integer number to a string

       if (num<10 && DoneOne !=1){               //Clears The Tens Position Once
        Write_Number_Space(X_Position + Font_Width,Y_Position);
        DoneOne = 1;
        ValidEight = 0;
       }

      if (num<100 && DoneTwo !=1){             //Clears The Hundreds Position Once
        Write_Number_Space(X_Position + Font_Width *2,Y_Position);
        DoneTwo = 1;
        ValidSeven = 0;
       }

       if (num<1000 && DoneThree !=1){             //Clears The Thousands Position Once
        Write_Number_Space(X_Position + Font_Width *3,Y_Position);
        DoneThree = 1;
        ValidSix = 0;
       }

       if (num<10000 && DoneFour !=1){           //Clears The ten Thousands Position Once
        Write_Number_Space(X_Position + Font_Width *4,Y_Position);
        DoneFour = 1;
        ValidFive = 0;
       }

       if (num<100000 && DoneFive !=1){        //Clears The hundred Thousands Position Once
         Write_Number_Space(X_Position + Font_Width *5,Y_Position);
         DoneFive = 1;
         ValidFour = 0;
        }

       if (num<1000000 && DoneSix !=1){     //Clears The million Position Once
         Write_Number_Space(X_Position + Font_Width *6,Y_Position);
         DoneSix = 1;
         ValidThree = 0;
        }

        if (num<10000000 && DoneSeven !=1){     //Clears Ten million Position Once
         Write_Number_Space(X_Position + Font_Width *7,Y_Position);
         DoneSeven = 1;
         ValidTwo = 0;
        }

        if (num<100000000 && DoneEight !=1){     //Clears Hundred million Position Once
          Write_Number_Space(X_Position + Font_Width *8,Y_Position);
          DoneEight = 1;
          ValidOne = 0;
         }

        if (num<1000000000 && DoneNine !=1){     //Clears Billion Position Once
          Write_Number_Space(X_Position + Font_Width *9,Y_Position);
          DoneNine = 1;
          ValidZero = 0;
         }

    switch (numberstring[9])  {  //units position

     case 48:    X_Position = units_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = units_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = units_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = units_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = units_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = units_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = units_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = units_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = units_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = units_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }

  if (ValidEight){
     switch (numberstring[8])  { //tens position

     case 48:    X_Position = tens_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = tens_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = tens_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = tens_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = tens_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = tens_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = tens_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = tens_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = tens_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = tens_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

    if (ValidSeven){
     switch (numberstring[7])  {   //hundreds position

     case 48:    X_Position = hundreds_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = hundreds_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = hundreds_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = hundreds_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = hundreds_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = hundreds_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = hundreds_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = hundreds_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = hundreds_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = hundreds_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    } }

    if (ValidSix){
     switch (numberstring[6])  {   //thousands position

     case 48:    X_Position = thousands_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = thousands_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = thousands_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = thousands_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = thousands_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = thousands_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = thousands_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = thousands_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = thousands_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = thousands_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

    if (ValidFive){
     switch (numberstring[5])  {   //ten thousands position

     case 48:    X_Position = ten_thousands_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = ten_thousands_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = ten_thousands_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = ten_thousands_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = ten_thousands_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = ten_thousands_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = ten_thousands_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = ten_thousands_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = ten_thousands_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = ten_thousands_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

    if (ValidFour){
     switch (numberstring[4])  {   //hundred thousands position

     case 48:    X_Position = hundred_thousands_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = hundred_thousands_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = hundred_thousands_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = hundred_thousands_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = hundred_thousands_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = hundred_thousands_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = hundred_thousands_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = hundred_thousands_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = hundred_thousands_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = hundred_thousands_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

     if (ValidThree){
     switch (numberstring[3])  {   //1 million position

     case 48:    X_Position = million_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = million_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = million_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = million_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = million_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = million_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = million_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = million_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = million_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = million_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

      if (ValidTwo){
     switch (numberstring[2])  {   //10 million position

     case 48:    X_Position = ten_million_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = ten_million_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = ten_million_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = ten_million_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = ten_million_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = ten_million_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = ten_million_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = ten_million_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = ten_million_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = ten_million_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

      if (ValidOne){
     switch (numberstring[1])  {   //100 million position

     case 48:    X_Position = hundred_million_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = hundred_million_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = hundred_million_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = hundred_million_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = hundred_million_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = hundred_million_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = hundred_million_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = hundred_million_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = hundred_million_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = hundred_million_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}

    if (ValidZero){
     switch (numberstring[0])  {   //Billion position

     case 48:    X_Position = billion_start;
                 Write_Number_Zero(X_Position,Y_Position, Colour);
                 break;
     case 49:    X_Position = billion_start;
                 Write_Number_One(X_Position,Y_Position, Colour);
                 break;
     case 50:    X_Position = billion_start;
                 Write_Number_Two(X_Position,Y_Position, Colour);
                 break;
     case 51:    X_Position = billion_start;
                 Write_Number_Three(X_Position,Y_Position, Colour);
                 break;
     case 52:    X_Position = billion_start;
                 Write_Number_Four(X_Position,Y_Position, Colour);
                 break;
     case 53:    X_Position = billion_start;
                 Write_Number_Five(X_Position,Y_Position, Colour);
                 break;
     case 54:    X_Position = billion_start;
                 Write_Number_Six(X_Position,Y_Position, Colour);
                 break;
     case 55:    X_Position = billion_start;
                 Write_Number_Seven(X_Position,Y_Position, Colour);
                 break;
     case 56:    X_Position = billion_start;
                 Write_Number_Eight(X_Position,Y_Position, Colour);
                 break;
     case 57:    X_Position = billion_start;
                 Write_Number_Nine(X_Position,Y_Position, Colour);
                 break;
     default:    break;
    }}
}


void Set_Bus_Speeds(){

      /* unlock system for clock configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    //000 = 1x divider  001 = 2x divider 010 = 3x divider  010 = 3x divider  011 = 4x divider  100 = 5x divider  101 = 6x divider  110 = 10x divider  111 = 12x divider

    // PB1DIV
    // Peripheral Bus 1 cannot be turned off, so there's no need to turn it on
    PB1DIVbits.PBDIV = 1; // Peripheral Bus 1 Clock Divisor Control (PBCLK1 is SYSCLK divided by 2)

    // PB2DIV
    PB2DIVbits.ON = 1; // Peripheral Bus 2 Output Clock Enable (Output clock is enabled)
    PB2DIVbits.PBDIV = 1; // Peripheral Bus 2 Clock Divisor Control (PBCLK2 is SYSCLK divided by 2)  Peripheral Bus 2 Clock drives i2C, spi, PMP

    // PB3DIV
    PB3DIVbits.ON = 1; // Peripheral Bus 3 Output Clock Enable (Output clock is enabled)
    PB3DIVbits.PBDIV = 1; // Peripheral Bus 3 Clock Divisor Control (PBCLK3 is SYSCLK divided by 2)

    // PB4DIV
    PB4DIVbits.ON = 1; // Peripheral Bus 4 Output Clock Enable (Output clock is enabled)
    while (!PB4DIVbits.PBDIVRDY); // Wait until it is ready to write to
    PB4DIVbits.PBDIV = 1; // Peripheral Bus 4 Clock Divisor Control (PBCLK4 is SYSCLK divided by 1)        //four drives ports

    // PB5DIV
    PB5DIVbits.ON = 1; // Peripheral Bus 5 Output Clock Enable (Output clock is enabled)
    PB5DIVbits.PBDIV = 1; // Peripheral Bus 5 Clock Divisor Control (PBCLK5 is SYSCLK divided by 2)

    // PB7DIV
    PB7DIVbits.ON = 1; // Peripheral Bus 7 Output Clock Enable (Output clock is enabled)
    PB7DIVbits.PBDIV = 1; // Peripheral Bus 7 Clock Divisor Control (PBCLK7 is SYSCLK divided by 1)

    // PB8DIV
    PB8DIVbits.ON = 1; // Peripheral Bus 8 Output Clock Enable (Output clock is enabled)
    PB8DIVbits.PBDIV = 1; // Peripheral Bus 8 Clock Divisor Control (PBCLK8 is SYSCLK divided by 2)

    // PRECON - Set up prefetch
    PRECONbits.PFMSECEN = 0; // Flash SEC Interrupt Enable (Do not generate an interrupt when the PFMSEC bit is set)
    PRECONbits.PREFEN = 0b11; // Predictive Prefetch Enable (Enable predictive prefetch for any address)  bit 5-4 PREFEN<1:0>: Predictive Prefetch Enable bits
    PRECONbits.PFMWS = 0b10; // PFM Access Time Defined in Terms of SYSCLK Wait States (Two wait states)
    CFGCONbits.ECCCON = 3;

    SYSKEY = 0x00;

}

void initSPI(void)                               //bus speed = 112'000'000
{                                               //divide by 280 = clock of 400 kHz
    SPI3_Init_Advanced(_SPI_MASTER, _SPI_8_BIT, 280, _SPI_SS_DISABLE, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_HIGH, _SPI_ACTIVE_2_IDLE);
  //  SPI3_Init_Advanced(_SPI_MASTER, _SPI_8_BIT, 280, _SPI_SS_DISABLE, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_HIGH, _SPI_IDLE_2_ACTIVE);
}

void initFastSPI(void)
{
    SPI3_Init_Advanced(_SPI_MASTER, _SPI_8_BIT, 8, _SPI_SS_DISABLE, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_HIGH, _SPI_ACTIVE_2_IDLE);
}


/* Definitions for MMC/SDC command */
#define CMD0   (64 + 0)                    // Software Reset Command  ZERO  HEX 40
#define CMD1   (64 + 1)                    // SEND_OP_COND
#define ACMD41 (64 + 41)                   // SEND_OP_COND (SDC)
#define CMD8   (64 + 8)                    // Command  8  Version Check
#define CMD9   (64 + 9)                    // SEND_CSD
#define CMD10  (64 + 10)                   // SEND_CID
#define CMD12  (64 + 12)                   // STOP_TRANSMISSION
#define ACMD13 (64 + 13)                   // SD_STATUS (SDC)
#define CMD16  (64 + 16)                   // SET_BLOCK LENGTH
#define CMD17  (64 + 17)                   // READ_SINGLE_BLOCK
#define CMD18  (64 + 18)                   // READ_MULTIPLE_BLOCK
#define CMD23  (64 + 23)                   // SET_BLOCK_COUNT
#define ACMD23 (64 + 23)                   // SET_WR_BLK_ERASE_COUNT (SDC)
#define CMD24  (64 + 24)                   // WRITE_BLOCK
#define CMD25  (64 + 25)                   // WRITE_MULTIPLE_BLOCK
#define CMD41  (64 + 41)                   // SEND_OP_COND (ACMD)
#define CMD55  (64 + 55)                   // APP_CMD
#define CMD58  (64 + 58)                   // READ_OCR

void main(){

       //THIS C FILE WILL INITIALISE AN SD CARD WITHOUT A LIBRARY. JOHN B 07/10/21
       //IT WILL ALSO READ ANY SECTOR.
       //SIMPLE SPI  (Simple he says lol).


      unsigned int x = 0;
      unsigned char dataBuffer[512];
      unsigned int sdcardbuffer_X_position = 30;
      unsigned int sdcardbuffer_Y_position = 30;
      unsigned char loop;
      unsigned char startloop;
      unsigned char loop1;
      unsigned char loopa;
      unsigned char loop2;
      unsigned char loop3;
      unsigned char loop4;
      unsigned char loop5;
      unsigned char loop6;
      unsigned char looplast;
      unsigned char Complete;
      unsigned char Finished = 0;
      unsigned char end;

      unsigned char dummybuffer = 255;

      unsigned char File_Type = 3;    // fat32 = 4     fat16 = 3

      LATB10_bit = 1;
      LATB14_bit = 1;
      
      Set_Bus_Speeds();
      Init_MCU();
      PRISS = 0x76543210;

      Init_16Bit_PMP();

      TFT_Init_SSD1963(800,480);
      TFT_SET_MODE_SSD1963_5_Inch();
      TFT_Set_DBC_SSD1963_BACKLIGHT(210);
      
      Clear_Screen_SSD1963(Blue);

      LATB10_bit = 1;     // RB10 = SERIAL DATA OUT SPI3
      LATB14_bit = 1;     // RB14 = CLOCK SPI 3
      initSPI();

      Clear_Screen_SSD1963(Yellow);


       Clear_Screen_SSD1963(Blue);
       Delay_ms(200); //TIME FOR SD CARD

       Mmc_Chip_Select = 1;               // EVERY COMMAND HAS A CONSTANT LENGTH OF 6 BYTES.
                                          // COMMAND = 1 BYTE.
                                          // FOLLOWED BY A SET OF FOUR BYTES WHICH ARE KNOWN AS THE ARGUMENTS.
                                          // THESE ARGUMENTS USUALLY CONTAIN THE ADDRESS OF A DATA OR THE LENGTH OF A BLOCK.
                                          // THE LAST BYTE IS THE CRC (CYCLIC REDUNDANCY CHECK) BYTE.
                                          // FOR SOME COMMANDS LIKE CMD0, THE CRC IS 0X95 AND IN MOST CASES, A 0XFF IS SENT.

                                          // 64 = Software Reset Command Zero - Should Return a 1 Meaning The Card Is In An Idle State
                                          // 65 = Initiate Initialisation Process - Should Return a 0 Meaning Everything is Clear & Card Not in Idle State.
                                          // CMD0, CMD1, ACMD41, CMD58 and CMD59 will be accepted when the card is in its idle state.



     for (x=0; x<10; x++){    // DUMMY CLOCKS  74 ARE REQUIRED.
      SPI3_Write(0xff);
      }
               loopa:

      Mmc_Chip_Select = 0;

      SPI3_Write(CMD0);  //Software Reset Command  ZERO  HEX 40
      SPI3_Write(0x00);
      SPI3_Write(0x00);
      SPI3_Write(0x00);
      SPI3_Write(0x00);
      SPI3_Write(0x95);       //0x95 Is Checksum For Software Reset

      SPI3_Write(0xFF);      // COMMAND RESPONSE TIME (NCR).
      Mmc_Chip_Select = 1;
      // SPI3_Write(0xFF);      // COMMAND RESPONSE TIME (NCR).

      Mmc_Chip_Select =0;
      dataBuffer[0] = SPI3_Read(dummybuffer);  // Response R1 with LSB Set To 1
      Mmc_Chip_Select = 1;


      Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,White);
      Write_Number(0,sdcardbuffer_X_position+250,sdcardbuffer_Y_position,Black);
      Delay_ms(400);
      Clear_Screen_SSD1963(Blue);

      goto loop2;


     //  TFT_Set_Font(Tahoma25x27,CL_BLACK,FO_HORIZONTAL);
     //Clear_Screen_SSD1963(Black);

       //SPI3_Write(0xFF);
       //SPI3_Write(0xFF);       //Dummy Writes Need To Be Written
       Mmc_Chip_Select = 0;

       SPI3_Write(CMD1);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x87);      // Checksum

       SPI3_Write(0xFF);   // Command Response Time (NCR).
       Mmc_Chip_Select =1;
       SPI3_Write(0xFF);   // Command Response Time (NCR). Adding This Gives A Zero On First Byte Out In Next Step
       Mmc_Chip_Select =0;

       dataBuffer[x] = SPI3_Read(dummybuffer);

       Mmc_Chip_Select = 1;

       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Lime);
       Write_Number(1,sdcardbuffer_X_position+250,sdcardbuffer_Y_position,White);
       Delay_ms(600);


        loop2:  //--------

       Clear_Screen_SSD1963(Blue);

      // SPI3_Write(0xFF);
      // SPI3_Write(0xFF);       //DUMMY WRITES NEED TO BE WRITTEN I READ. NO THEY DO NOT NEED TO BE WRITTEN !
       Mmc_Chip_Select = 0;

       SPI3_Write(CMD8);  //Command  8  Version Check
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x01);
       SPI3_Write(0xAA);
       SPI3_Write(0x87);   // Checksum

       SPI3_Write(0xFF);   // Command Response Time (NCR). <<<<<<<WEEKS OF WORK FOR THIS LITTLE SHIT<<<<<<<<<AT LEAST ONE NCR INSIDE THE CHIP SELECT<<<<<<<<<<<<
       Mmc_Chip_Select =1;
       SPI3_Write(0xFF);   // Command Response Time (NCR).

       Mmc_Chip_Select =0;

       for (x=0; x<6; x++){
         dataBuffer[x] = SPI3_Read(dummybuffer);
        }
       Mmc_Chip_Select = 1;

       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,White);
       Write_Number(dataBuffer[1],sdcardbuffer_X_position,sdcardbuffer_Y_position+30,White);
       Write_Number(dataBuffer[2],sdcardbuffer_X_position,sdcardbuffer_Y_position+60,White);
       Write_Number(dataBuffer[3],sdcardbuffer_X_position,sdcardbuffer_Y_position+90,White);
       Write_Number(8,sdcardbuffer_X_position+250,sdcardbuffer_Y_position,Black);
       Delay_ms(800);

         if (dataBuffer[0] == 0){ // THIS HAS TAKEN MONTHS OF WORK TO GET HERE.
             Clear_Screen_SSD1963(Yellow);
             initFastSPI();
             goto loop3;
           }

           loop3:
         // goto loop4;
  //-----------------------------------------------------------------------------------------------------------------------
       Clear_Screen_SSD1963(Lavenderblush);


       Mmc_Chip_Select = 0;

       SPI3_Write(CMD55);  //     PAGE 59 OF SD CARD ASSOCIATION STATES THAT COMMAND 55 SHALL ALWAYS PRECEDE AMCD41
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x87);   // Checksum

       SPI3_Write(0xFF);    // Command Response Time (NCR).
       Mmc_Chip_Select = 1;
       SPI3_Write(0XFF);   // Command Response Time (NCR).

       Mmc_Chip_Select = 0;
       dataBuffer[0] = SPI3_Read(dummybuffer);
       Mmc_Chip_Select = 1;

       sdcardbuffer_Y_position = 30;
       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,White);
       Write_Number(55,sdcardbuffer_X_position+250,sdcardbuffer_Y_position,Black);

       Delay_ms(600);

        loop4:
       Clear_Screen_SSD1963(Lavenderblush);


       Mmc_Chip_Select = 0;

       SPI3_Write(CMD41);  //Command 41    SPI3_Write(0x69);  //Command 41      SPI3_Write(105);  ==Command 41      SPI3_Write(119); == Command 55    SPI3_Write(122);  ==Command 58
       SPI3_Write(0x40);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x87);   // Checksum

       SPI3_Write(0XFF);   // Command Response Time (NCR).
       Mmc_Chip_Select = 1;

       Mmc_Chip_Select = 0;
       dataBuffer[0] = SPI3_Read(dummybuffer);
       Mmc_Chip_Select = 1;

       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
       Write_Number(41,sdcardbuffer_X_position+250,sdcardbuffer_Y_position,Black);
       Delay_ms(600);

         if (dataBuffer[0] == 0){
           goto loop5;
         }else { goto loop3; }       //GOING TO START OF CMD41 AND LOOPING WILL GIVE YOU A 5


   //-----------------------------------------------------------------------------------------------------------------------------
       loop5:

       Clear_Screen_SSD1963(Lavenderblush);
       sdcardbuffer_X_position = 30;
       sdcardbuffer_Y_position = 30;
      // SPI3_Write(0xff);
      // SPI3_Write(0xff);       //Dummy Writes Need To Be Written
       Mmc_Chip_Select = 0;

       SPI3_Write(CMD58);  //Command 58          read block
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0xFF);      // Checksum

       SPI3_Write(0xFF);     // Command Response Time (NCR).
       Mmc_Chip_Select = 1;
       SPI3_Write(0xFF);     // Command Response Time (NCR).

       Mmc_Chip_Select = 0;

       for (x=0; x<5; x++){
         dataBuffer[x] = SPI3_Read(dummybuffer);
        }
       Mmc_Chip_Select = 1;          //  The Lower 12 Bits In The Return Value = 0x1AA Mean That The Card Is Sdc V2 And Can Work At A Voltage Range Of Between 2.7 To 3.6

       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
       Write_Number(dataBuffer[1],sdcardbuffer_X_position,sdcardbuffer_Y_position+30,Black);
       Write_Number(dataBuffer[2],sdcardbuffer_X_position,sdcardbuffer_Y_position+60,Black);
       Write_Number(dataBuffer[3],sdcardbuffer_X_position,sdcardbuffer_Y_position+90,Black);
       Write_Number(58,sdcardbuffer_X_position+200,sdcardbuffer_Y_position,Black);

       Delay_ms(600);
              //----------------------------------------------------------------------------------------------
       loop6:

       Clear_Screen_SSD1963(Violet);

       Mmc_Chip_Select = 0;

       SPI3_Write(CMD16);  //Command 16          read block
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x02);
       SPI3_Write(0x00);
       SPI3_Write(0x87);      // Checksum

       SPI3_Write(0xFF);     // Command Response Time (NCR).
       Mmc_Chip_Select = 1;
       //SPI3_Write(0xFF);     // Command Response Time (NCR).  THIS STOPS THE CODE----------------------------------------

       Mmc_Chip_Select = 0;
       dataBuffer[0] = SPI3_Read(dummybuffer);
       Mmc_Chip_Select = 1;

       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
       Write_Number(16,sdcardbuffer_X_position+200,sdcardbuffer_Y_position,Black);

        Delay_ms(800);

        if (dataBuffer[0] !=0){

        goto loop6;   }

        looplast:

       Clear_Screen_SSD1963(Lavenderblush);

       Clear_Screen_SSD1963(Cyan);
       sdcardbuffer_X_position = 30;
       sdcardbuffer_Y_position = 30;

       //SPI3_Write(0xff);
       //SPI3_Write(0xff);       //Dummy Writes Need To Be Written
       Mmc_Chip_Select = 0;

       SPI3_Write(CMD17);  //Command 17          read block
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x87);      // Checksum

       SPI3_Write(0xFF);     // Command Response Time (NCR).
       Mmc_Chip_Select = 1;
      // SPI3_Write(0xFF);     // Command Response Time (NCR).

       Mmc_Chip_Select = 0;
       dataBuffer[0] = SPI3_Read(dummybuffer);
       Mmc_Chip_Select = 1;


       Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
       Write_Number(17,sdcardbuffer_X_position+200,sdcardbuffer_Y_position,Red);

        Delay_ms(500);

        if (dataBuffer[0] !=0){
         Clear_Screen_SSD1963(Red);
         goto looplast;   }


        Mmc_Chip_Select = 0;

       for (x=0; x<516; x++){
         dataBuffer[x] = SPI3_Read(255);
        }
       Mmc_Chip_Select = 1;


       if (dataBuffer[86] ==70){
        Write_Number(dataBuffer[86],sdcardbuffer_X_position,sdcardbuffer_Y_position+30,Red);
        Write_Number(dataBuffer[87],sdcardbuffer_X_position,sdcardbuffer_Y_position+60,Red);
        Write_Number(dataBuffer[88],sdcardbuffer_X_position,sdcardbuffer_Y_position+90,Red);
        Write_Number(dataBuffer[89],sdcardbuffer_X_position,sdcardbuffer_Y_position+120,Red);
        Write_Number(dataBuffer[90],sdcardbuffer_X_position,sdcardbuffer_Y_position+150,Red);
        File_Type = 4;
        Delay_ms(700); }


         sdcardbuffer_X_position = 55;
         sdcardbuffer_Y_position = 30;

        if (dataBuffer[57] ==70){
        Write_Number(dataBuffer[57],sdcardbuffer_X_position,sdcardbuffer_Y_position+150,Violet);
        Write_Number(dataBuffer[58],sdcardbuffer_X_position,sdcardbuffer_Y_position+180,Violet);
        Write_Number(dataBuffer[59],sdcardbuffer_X_position,sdcardbuffer_Y_position+210,Violet);
        Write_Number(dataBuffer[60],sdcardbuffer_X_position,sdcardbuffer_Y_position+240,Violet);
        Write_Number(dataBuffer[61],sdcardbuffer_X_position,sdcardbuffer_Y_position+270,Violet);
        File_Type = 3;
        Delay_ms(700);  }


       sdcardbuffer_X_position = 3;
       sdcardbuffer_Y_position = 30;

         for (x=416; x<512 + File_Type; x++, sdcardbuffer_Y_position +=30 ){
         Write_Number(dataBuffer[x],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
         if (sdcardbuffer_Y_position>=440){
         sdcardbuffer_Y_position = 30;
         sdcardbuffer_X_position += 100; }
         Delay_ms(50);
        }

          Delay_ms(800);

            if (Finished==1){
             goto end;
            }

  //---------------------------------------------------------------------------------------------------------------------------------------------------*/

       Complete:

       Clear_Screen_SSD1963(Yellow);
       sdcardbuffer_X_position = 30;
       sdcardbuffer_Y_position = 30;

       LATJ4_Bit = 1;   //MEMORY CHIP SELECT C/E - CHIP ENABLE INPUT  PIN 6 SRAM   EBICS0/RJ4
       SRAM_CS = 1;
       LATJ12_BIT = 0;  //LOW BYTE  L/B
       LATJ10_BIT = 0;  //HIGH BYTE  U/B
       LATC3_BIT = 1;   //WRITE PIN PMWR WRITE PIN ON PIC PIN 12 PIN 17 ON SRAM W/E
       LATC4_BIT = 1;   //O/E MEMORY OUTPUT ENABLE PIN 41 PMRD PMP READ PIN 13 ON PIC  EBIOE/AN19/RPC4/PMRD/RC4*/


     //---------------------------------------------------------------------------------------------------------------------
       sdcardbuffer_X_position = 3;
       sdcardbuffer_Y_position = 30;

        for (x=File_Type; x<100; x++, sdcardbuffer_Y_position +=30 ){
         Write_Number(dataBuffer[x],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
         if (sdcardbuffer_Y_position>=440){
         sdcardbuffer_Y_position = 30;
         sdcardbuffer_X_position += 100; }
         Delay_ms(50);
        }

        Clear_Screen_SSD1963(Yellow);
        sdcardbuffer_X_position = 30;
       sdcardbuffer_Y_position = 30;

       Mmc_Chip_Select = 0;

       SPI3_Write(CMD58);  //Command 58          read block
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0x00);
       SPI3_Write(0xFD);      // Checksum
       
       SPI3_Write(0xFF);     // Command Response Time (NCR).
       Mmc_Chip_Select = 1;

       SPI3_Write(0xFF);     // Command Response Time (NCR).

       Mmc_Chip_Select = 0;


       for (x=0; x<512 + File_Type; x++){
         dataBuffer[x] = SPI3_Read(dummybuffer);
        }
       Mmc_Chip_Select = 1;

            Write_Number(dataBuffer[0],sdcardbuffer_X_position,sdcardbuffer_Y_position,Black);
            Write_Number(dataBuffer[1],sdcardbuffer_X_position,sdcardbuffer_Y_position+30,Black);
             Write_Number(dataBuffer[2],sdcardbuffer_X_position,sdcardbuffer_Y_position+60,Black);
              Write_Number(dataBuffer[3],sdcardbuffer_X_position,sdcardbuffer_Y_position+90,Black);
               Write_Number(58,sdcardbuffer_X_position+200,sdcardbuffer_Y_position,Black);

        Delay_ms(600);

               Finished = 1;

               goto loop6;    //   E9 00 00 53 59 53 54 45 4D 49 44 00 02 80 30 02


      end:


                                      //       SET BLOCK READ LENGTH NEXT
                                      //       STARTS WITH HEX 50
                                      //       THEN ADDRESS IS 512
                                      //       00000000
                                      //       00000000
                                      //       00000010
                                      //       00000000
                                      //       CRC
                                      //       COMMAND TO WTITE IS HEX 58
                                      //       ADDRESS = SECTOR NUMBER
                                      //       00000000
                                      //       00000000
                                      //       00000000
                                      //       00000000
                                      //       CRC
                                      //       WRITE COMMAND TO SAT NEXT IS DATA = HEX 0XFE

 while(1){

}
}
