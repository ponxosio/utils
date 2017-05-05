/*
 * AutoEnumerate.h
 *
 *  Created on: 7 de abr. de 2016
 *      Author: angel
 */

#ifndef SRC_UTIL_AUTOENUMERATE_H_
#define SRC_UTIL_AUTOENUMERATE_H_

#include "utils/utils_global.h"

/**
 * Class that generates a natural sequence of integer numbers, as an autoenumerate type of a bbdd.
 */
class AUTOENUMERATE_EXPORT AutoEnumerate {
public:
    /**
     * @brief AutoEnumerate creates a new serie starting from 0
     */
	AutoEnumerate();
    /**
     * @brief AutoEnumerate creates a new serie equal to a particular one.
     * @param e serie to be copied.
     */
    AutoEnumerate(const AutoEnumerate & e);
    /**
     * @brief ~AutoEnumerate destoys the object
     */
	virtual ~AutoEnumerate();

	/**
	 * Return the actual value
	 * @return the actual value
	 */
    int getValue() const;
	/**
	 * Return the actual value and advance the sequence
	 * @return the actual value
	 */
	int getNextValue();
	/**
	 * advance the sequence to next number
	 */
	void nextNumber();
	/**
	 * Reset the sequence to the start.
	 */
	void reset();
    /**
     * @brief reset the sequence and sets the initial value to a particular one.
     * @param initialValue value to start the sequence from.
     */
    void reset(int initialValue);
protected:
    /**
     * @brief actualValue the actual value of the serie
     */
	int actualValue;
};

#endif /* SRC_UTIL_AUTOENUMERATE_H_ */
