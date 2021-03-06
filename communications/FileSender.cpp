/*
 * FileSender.cpp
 *
 *  Created on: 15 de may. de 2016
 *      Author: angel
 */

#include "FileSender.h"

FileSender::FileSender() {
    this->inputName = "";
    this->outputName = "";
}

FileSender::FileSender(const std::string& outputName, const std::string& inputName, std::shared_ptr<TimeStampSimulator> timestampManager) :
	CommandSender()
{
	this->inputName = inputName;
	this->outputName = outputName;

    this->timestampManager = timestampManager;
}

FileSender::~FileSender() {
	disconnect();
}

unsigned long FileSender::sendString(const char* str) {
    if (outFile.is_open()) {
        semaphore.lock();

        std::string timeStamp = "";
        if (timestampManager != NULL) {
            timeStamp = timestampManager->getTimeStamp();
        } else {
            QDateTime now = QDateTime::currentDateTime();
            timeStamp = now.toString("dd hh:mm:ss").toStdString();
        }

        outFile << timeStamp << ". " << str << "\n";
        outFile.flush();

        semaphore.unlock();
	} else {
		throw(std::ios_base::failure("the connection must be opened first"));
	}
    return 1;
}

std::string FileSender::receiveString() throw (std::ios_base::failure) {
	return readUntil('\n');
}

std::string FileSender::readUntil(char endCharacter) throw (std::ios_base::failure) {
    std::string line;
	if (inFile.is_open()) {
        semaphore.lock();

		bool finded = false;
		char c;

		do {
			std::string temp;
			inFile.get(c);
			if (inFile.eof()) {
				inFile.clear();
				inFile.seekg(0, inFile.beg);
                                finded = !line.empty();
			} else {
				temp += c;
				if (c == endCharacter) {
					finded = true;
				} else if (temp.find_first_not_of(
						"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_")
						== std::string::npos) {
					line += c;
				}
			}
		} while (!finded);

        semaphore.unlock();
	} else {
		throw(std::ios_base::failure("the connection must be opened first"));
	}
	return line;
}

void FileSender::disconnect() {
	if (outFile.is_open()) {
        outFile.flush();
        outFile.close();
	}
	if (inFile.is_open()) {
		inFile.close();
	}
}

void FileSender::connect() throw (std::ios_base::failure) {
	if (!outFile.is_open()) {
		outFile.open(outputName.c_str());
	} else {
		throw(std::ios_base::failure("the file " + outputName + " is already opened"));
	}
	if (!inFile.is_open()) {
		inFile.open(inputName.c_str());
	} else {
		throw(std::ios_base::failure(
				"the file " + inputName + " is already opened"));
	}

    if (timestampManager != NULL) {
        timestampManager->resetStartTime();
    }
}
