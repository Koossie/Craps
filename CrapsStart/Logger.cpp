/*
 * Logger.cpp
 *
 *  Created on: 26 nov. 2013
 *      Author: David
 */

#include "Logger.hpp"
#include <string>
#include <iostream>


Logger::Logger() {}

Logger& Logger::getInstance() {
	static Logger instance; // Guaranteed to be destroyed.
	// Instantiated on first use.
	return instance;
}

void Logger::log( const std::string& tekst) {
	std::cout << tekst << std::endl;
}

void Logger::startOutput() {
	lock.lock();
}

void Logger::endOutput() {
	lock.unlock();
}
