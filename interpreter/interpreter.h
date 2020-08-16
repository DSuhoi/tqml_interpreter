#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include <map>
#include <vector>
#include <regex>


// Text link to the next text part
class TextLink {
private:
	// Pointer to the file name string
	char *fileName;
	// Pointer to the answer string
	char *textAnswer;
	// Link to the next text part
	int linkNumber;
public:
	// Empty constructor
	TextLink();
	// Main constructor
	TextLink(int _link, const char *_answer, const char *_file);
	// Destructor
	~TextLink();
	// Return the pointer to the file name (char array)
	char *GetFileName();
	// Return the pointer to the answer (char array)
	char *GetAnswer();
	// Return the link to the next text part
	int GetLink();
};

// Class for parsing text data
class RegexParser {
private:
	// Regular expression for parsing file text
	static const char FILE_TEXT_REGEX[];
	static const char LINKS_TEXT_REGEX[];
	static const char LINK_REGEX[];
	
	// Private constructor
	RegexParser() {}
public:
	// Parsing the file text (Return an array with text parts) (false - OK, true - ERROR)
	static bool ParseFile(char *fileText, std::map<int, char*> &textParts);
	// Return the pointer to the text links from the text part
	static bool ParseLinks(char *part, std::vector<TextLink*> &vectLinks);
	// Return the pointer to the main text
	static char *ParseText(int link = 0);
};


// TQML interpreter class
class Interpreter {
private:
	std::vector<TextLink> vectLinks;
	// Map to the text parts and its link
	std::map<int, char*> textParts;

public:
	// Constructor and Destructor
	Interpreter();
	~Interpreter();
	
	
};



#endif