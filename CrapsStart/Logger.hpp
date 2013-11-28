/*
 * Logger.hpp
 *
 *  Created on: 26 nov. 2013
 *      Author: David
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>
#include <boost/thread/mutex.hpp>
#include <memory>

class Logger {
    public:
        void log(const std::string& logstring);
        static Logger& getInstance();
        void startOutput();
        void endOutput();
    private:
 	   Logger();              // Constructor? (the {} brackets) are needed here.
        // Dont forget to declare these two. You want to make sure they
        // are unaccessable otherwise you may accidently get copies of
        // your singleton appearing.
 	   Logger(Logger const&);         // Make copycon private
        void operator=(Logger const&); // Don't implement
        boost::mutex lock;
};

#endif /* LOGGER_HPP_ */
