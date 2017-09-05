#ifndef TIMESTAMPSIMULATOR_H
#define TIMESTAMPSIMULATOR_H

#include <string>

#include <QTime>

#include "utils/units.h"

#include "utils/utils_global.h"

class TIMESTAMPSIMULATOR_EXPORT TimeStampSimulator
{
public:
    TimeStampSimulator();
    virtual ~TimeStampSimulator();

    std::string getTimeStamp() const;

    void passTime(units::Time timePassed);
    void resetStartTime();

protected:
    QDateTime start;
    units::Time timePass;
};

#endif // TIMESTAMPSIMULATOR_H
