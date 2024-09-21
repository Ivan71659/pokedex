#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::vector <std::string> split_line (std::string line) {
  std::vector <std::string> line_split;
  std::stringstream ss (line);
  std::string phrase;
  while (std::getline (ss, phrase, ',')) {
    phrase.erase (0, phrase.find_first_not_of (" \t\n\r"));
    phrase.erase (phrase.find_last_not_of (" \t\n\r") + 1);
    line_split.push_back (phrase);
  }
  return line_split;
}

int main () { 
  vector <string> list;

  std::ifstream apot;
  apot.open ("pokedex.txt");

  string linegetter;
  while(getline (apot , linegetter)){
    list.push_back (linegetter);
  }
  
  while(true){
    int choices;
    cout << "\n1. Display Full Pokedex\n2. Search Pokemon\n3. Add Pokemon\n4. Update Pokemon\n5. Delete pokemon\n6. Exit\n\n";
    cin >> choices;
    
    if(choices == 1){
      for(int i = 0; i < list.size(); i++) {
        vector <string> line = split_line (list [i]);
        
        string name = line[0];
        string type = line[1];
        string hp = line[2];
        string attack = line[3];
        string defense = line[4];
        string speed = line[5];
  
        cout << "Name: " << name << " Type: " << type << " HP: " << hp << " Attack: " << attack << " Defense: " << defense << " Speed: " << speed << "\n";
      }

      cout << "\n";
    }
    
    if(choices == 2){
      string search;
      cout << "Enter the name of the Pokemon: ";
      cin >> search;
      std::ifstream searcher;
      searcher.open ("pokedex.txt");
  
      string name2;
      for (int i = 0; i < list.size (); i++) {
        vector <string> line = split_line (list [i]);
  
        string name = line[0];
        string type = line[1];
        string hp = line[2];
        string attack = line[3];
        string defense = line[4];
        string speed = line[5];
  
  
        if(search == name){
          cout << "\nName: " << name << " Type: " << type << " HP: " << hp << " Attack: " << attack << " Defense: " << defense << " Speed: " << speed << "\n";
        }
      }

      cout << "\n";
    }
    
    if(choices == 3){
      string maker;
      cout << "enter the name of the pokemon: ";
      cin >> maker;
      
      string maker1;
      cout << "enter the type of the pokemon: ";
      cin >> maker1;
      
      string maker2;
      cout << "enter the hp of the pokemon: ";
      cin >> maker2;
  
      string maker3;
      cout << "enter the attack of the pokemon: ";
      cin >> maker3;
      
      string maker4;
      cout << "enter the defense of the pokemon: ";
      cin >> maker4;
  
      string maker5;
      cout << "enter the speed of the pokemon: ";
      cin >> maker5;
      
      string pokemon = maker + "," + maker1 + "," + maker2 + "," + maker3 + "," + maker4 + "," + maker5;
      list.push_back(pokemon);
  
      std::ofstream add;
      add.open("pokedex.txt");
      
      for(int i = 0; i < list.size(); i++){
        add<< list[i] << "\n";
      }
      
      add.close ();
    }
    
    if(choices == 4){
      string ask;
      std::cout << "which pokemon would you like to update?";
      cin >> ask;
      
      int ask2;
      std::cout << "what would you like to update.\n1.type\n2.HP\n3.speed\n4.defense\n5.attack\n6.name";
      cin >> ask2;
  
      string type;
      string hp;
      string speed;
      string defense;
      string attack;
      string name;
      
      if(ask2 == 1){
        std::cout << "what would you like to change the type to: ";
        cin >> type;
      }
      else if(ask2 == 2){
        std::cout << "what would you like to change the HP to: ";
        cin >> hp;
      }
      else if(ask2 == 3){
        std::cout << "what would you like to change the speed to: ";
        cin >> speed;
      }
      else if(ask2 == 4){
        std::cout << "what would you like to change the defense to: ";
        cin >> defense;
      }
      else if(ask2 == 5){
        std::cout << "what would you like to change the attack to: ";
        cin >> attack;
      }
      else if(ask2 == 6){
        std::cout << "what would you like to change the name to: ";
        cin >> name;
      }
  
      for(int i = 0; i < list.size(); i++){
        vector <string> line = split_line (list [i]);
  
        if (line [0] == ask) {
          if(ask2 == 1){
            line[1] = type;
          }
          else if(ask2 == 2){
            line[2] = hp;
          }
          else if(ask2 == 3){
            line[5] = speed;
          }
          else if(ask2 == 4){
            line[4] = defense;
          }
          else if(ask2 == 5){
            line[3] = attack;
          }
          else if(ask2 == 6){
            line[0] = name;
          }
          string newline = line[0] +"," + line[1] + "," + line[2] + "," + line[3] + "," + line[4] + "," + line[5];
          list [i] = newline;
        }
      }
    }
    
    if(choices == 5){
      string ask3;
      std::cout << "what would you like to delete ";
      cin >> ask3;
  
      for(int i = 0; i < list.size(); i++){
        vector <string> line = split_line (list [i]);
        if(line[0] == ask3){
          list.erase(list.begin () + i);
          std::cout << line[0] << " has been deleted \n";
          break;
        }
      }
  
      std::ofstream add;
      add.open("pokedex.txt");
  
      for(int i = 0; i < list.size(); i++){
        add<< list[i] << "\n";
      }
  
      add.close ();
    }
    
    if(choices == 6){
      break;
    }
  }

}
