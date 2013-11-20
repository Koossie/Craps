#ifndef GAMECONTEXT_HPP_
#define GAMECONTEXT_HPP_

#include "Config.hpp"
#include <utility>
#include "Context.hpp"
#include "Dice.hpp"



class GameContext : public Context
{
	public:
		GameContext(const std::string& aTableName = "One");
		void play();

		std::string getTableName() const {return tableName;}
		std::pair<Dice,Dice> getDices() {
			       return std::make_pair(dice1,dice2);
				}
		unsigned char getScore() const {return dice1.getValue() + dice2.getValue();}
		int getInitialThrow() const;
		void setInitialThrow(const int aRoll);

	protected:
		void throwDices();

	private:
		std::string tableName;
		Dice dice1;
		Dice dice2;
		int initialThrow;
};

#endif // GAMECONTEXT_HPP_
