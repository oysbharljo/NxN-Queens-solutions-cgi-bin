#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include "qclass.hpp"

void readQueryString(char []);

int main()
{
   // variable declarations
   int n = 0;
   char card[80];
   std::string buf;

   std::cout << "Content-Type:text/html;charset=UTF-8\n\n";
   readQueryString(card);
   // perform preliminary html emission chores
   std::cout << "<!DOCTYPE HTML>" << std::endl;
   std::cout << "<head>" << std::endl;
   std::cout << "<meta charset=\"utf-8\">" << std::endl;
   std::cout << "<title>Sputnik</title>" << std::endl;
   std::cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << std::endl;
   // std::cout << "<link rel=\"stylesheet\" media=\"all\" type=\"text/css\" href=\"/includes/style.css\"/>" << std::endl;
   std::cout << "<link rel=\"stylesheet\" media=\"all\" type=\"text/css\" href=\"/includes/chessboard.css\"/>" << std::endl;
   std::cout << "</head>" << std::endl;
   std::cout << "<body>" << std::endl;
   std::cout << "<header><p>cgi-bin C++ nxn queens solutions</p></header>" << std::endl;
   std::cout << "<p><a href=\"/index.php\">Home</a> | <a href=\"/cgi-bin/nqueens.cgi?step1\">Back</a></p>" << std::endl;
   // initial pass - print the form
   if (strcmp(card, "step1") == 0) {
      std::cout << "<form action=\"nqueens.cgi?step2\" method=\"post\">";
      std::cout << "<div>enter dimenions of n x n chess board (4 - 10)</div>" << std::endl;
      std::cout << "<div><input type=\"text\" name=\"N\" size=\"2\" value=\"\"></div>" << std::endl;
      std::cout << "<p> </p>" << std::endl;
      std::cout << "<input type=\"submit\" value=\"SUBMIT\"></form>" << std::endl;
   }
   else {
      std::getline(std::cin, buf);
      std::stringstream ss;
      ss << buf;
      ss.ignore(80, '=');
      if (ss.good())
         ss >> n;
      else
         return 1;
      if (n < 4 || n > 10) {
         std::cout << "<p>I'm sorry Dave, I'm afraid I can't do that.</p>" << std::endl;
         std::cout << "</body>" << std::endl;
         std::cout << "</html>" << std::endl;
         return 1;
      }
      queens_on_board composer(n);    // constructor
      // place queens on n x n board
      composer.place_queens(0);
      std::cout << "<p>" << composer.get_total() << " solutions computed</p>" << std::endl;
   }
   std::cout << "<p><a href=\"/index.php\">Home</a> | <a href=\"/cgi-bin/nqueens.cgi?step1\">Back</a></p>" << std::endl;
   std::cout << "<footer><p>CopyLeft 2017 Josh Roybal - All Wrongs Reserved</p></footer>" << std::endl;
   std::cout << "</body>" << std::endl;
   std::cout << "</html>" << std::endl;
   return 0;
}

// get the step of the process
void readQueryString(char card[])
{
    strcpy(card, getenv("QUERY_STRING"));
}
