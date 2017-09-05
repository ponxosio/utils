#include "timestampsimulator.h"

TimeStampSimulator::TimeStampSimulator()
{
    this->start = QDateTime::currentDateTime();
    this->timePass = 0 * units::s;
}

TimeStampSimulator::~TimeStampSimulator()
{

}

std::string TimeStampSimulator::getTimeStamp() const {
    QDateTime now = start.addMSecs(timePass.to(units::ms));
    return now.toString("dd hh:mm:ss").toStdString();
}

void TimeStampSimulator::passTime(units::Time timePassed) {
    this->timePass += timePassed;
}

void TimeStampSimulator::resetStartTime() {
    this->start = QDateTime::currentDateTime();
}
