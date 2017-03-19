/*********************************************
 * Author: Juan Du
 * Date: 2017/02/09
 * Description: utility menu function 
*********************************************/
#include "menu.hpp"
#include "input.hpp"
#include <iostream>
#include <string>


void Menu::displayMenu()
{
  std::cout<<"Welcome to the Dungeons & Snake game!"<< std::endl;
  std::cout<<"Press the number associated with the menu"<< std::endl;
  std::cout<<"1. Display game instruction. " <<std::endl; 
  std::cout<<"2: Start the game. "<<std::endl; 
  std::cout<<"0: Exit" <<std::endl; 
  
}

char Menu::getChoice()
{
  char choice;
  readChar(choice);
  while ((choice<'1' || choice > '2') && choice !='0')
  {
    std::cout<<"Invalid input. Please enter again."<<std::endl;
    readChar(choice);
  }
  return choice;
}
