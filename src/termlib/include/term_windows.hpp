#ifndef __TERM_WINDOWS_H__
#define __TERM_WINDOWS_H__

#include <ncurses.h>
#include <vector>

// Class the main windows
class TERM_WINDOW
{
public:
    // Basic constructor
    TERM_WINDOW(int height, int width, int pos_y, int pos_x);
    // Constructor with color
    TERM_WINDOW(int height, int width, int pos_y, int pos_x, chtype colors);
    // Virtual destructor
    virtual ~TERM_WINDOW();
    // Function for adding a color scheme
    void set_colors(chtype colors);
    // This function is an analog refresh() for two windows (main and background)
    virtual void update();
    // Clear the text in the main subwindow (wclear)
    virtual void clear();
    // Print the text in the main subwindow (wprintw)
    virtual void print(std::string const& text);
    // Print the text in the main subwindow (mvwprintw)
    void print(int x, int y, std::string const& text);
    // Get the main subwindow width and height
    void get_width_and_height(int& width, int& height);
    // Return a pointer to the main subwindow
    WINDOW* get_main();
private:
    WINDOW* main;       // This is the main subwindow
    WINDOW* background; // and its background window
};


// Class of main text window
class MAIN_TEXT_WINDOW : public TERM_WINDOW
{
public:
    // Constructors
    MAIN_TEXT_WINDOW(int height, int width, int pos_y, int pos_x) : 
        TERM_WINDOW(height, width, pos_y, pos_x) {}
    MAIN_TEXT_WINDOW(int height, int width, int pos_y, int pos_x, chtype colors) :
        TERM_WINDOW(height, width, pos_y, pos_x, colors) {}
    // Destructor
    ~MAIN_TEXT_WINDOW() { clear(); }
    
    // Update the main text page
    void update_page();
    // Erase all main text variables
    void clear() override;
    // Print the text in the main text window
    void print(std::string const& text) override;
    // Set/Get current page
    int &set_current_page() { return current_page; }
    // Return the number of pages
    int get_num_pages() const { return num_pages; }
    // Return the number of characters
    int get_num_chr() const { return num_chr; }
private:
    std::vector<std::string> text_buffer;   // Pointer to the main text buffer
    int num_pages = 0;        // Number of pages in the text
    int current_page = 0;     // Current page number
    int num_chr = 0;          // Number of characters in the text
};


#endif
