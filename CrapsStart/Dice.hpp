#ifndef DICE_HPP_
#define DICE_HPP_

#include "Config.hpp"
#include <iostream>

/**
 *
 */
class Dice
{
	public:
		/**
		 * Default constructor
		 */
		Dice();
		/**
		 * If aValue is not in the range [1...6] an exception is thrown.
		 *
		 * @param aValue
		 */
		Dice( unsigned long aValue);

		/**
		 * Copy constructor
		 *
		 * @param aDice
		 */
		Dice( const Dice& aDice);
		/**
		 * Destructor
		 */
		virtual ~Dice();

		/**
		 * Comparison operator
		 *
		 * @param aDice
		 * @return true if getValue() == aDice.getValue(), false otherwise
		 */
		bool operator==( const Dice& aDice) const;
		/**
		 * Assignment operator
		 *
		 * @param aDice
		 * @return
		 */
		Dice& operator=( const Dice& aDice);
		/**
		 *
		 */
		unsigned long getValue() const;
		/**
		 * If aValue is not in the range [1...6] an exception is thrown.
		 * The value of this Dice remains unchanged
		 *
		 * @param aValue
		 */
		void setValue( unsigned long aValue);
		/**
		 * See http://www.cplusplus.com/doc/tutorial/inheritance/
		 * for more info.
		 */
		friend std::ostream& operator<<( 	std::ostream& os,
											const Dice& aDice);

	private:
		unsigned long value;

};
// Dice

std::ostream& operator<<( 	std::ostream& os,
							const Dice& aDice);

#endif // DICE_HPP_
