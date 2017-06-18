#include "utilsjson.h"

using json = nlohmann::json;

void UtilsJSON::checkPropertiesExists(const std::vector<std::string> & properties, const nlohmann::json & objJSON) throw(std::invalid_argument) {
    for(const std::string & property : properties) {
        if (!hasProperty(property, objJSON)) {
            throw(std::invalid_argument(generateNoPropertyErrorMsg(objJSON, property)));
        }
    }
}

bool UtilsJSON::hasProperty(const std::string & property, const nlohmann::json & objJSON) {
    return (objJSON.find(property) != objJSON.end());
}

std::string UtilsJSON::generateNoPropertyErrorMsg(const nlohmann::json & objJSON, const std::string & property) {
    return jsonObjToStr(objJSON) + "JSON has no property \"" + property + "\"";
}

std::string UtilsJSON::jsonObjToStr(const nlohmann::json & objJSON) {
    std::stringstream stream;
    stream << objJSON;
    return stream.str();
}

units::Volume UtilsJSON::getVolumeUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::Volume vol;
    if (unitsStr.compare(UNITS_VOLUME_L) == 0) {
        vol = units::l;
    } else if (unitsStr.compare(UNITS_VOLUME_ML) == 0) {
        vol = units::ml;
    } else if (unitsStr.compare(UNITS_VOLUME_UL) == 0) {
        vol = units::ul;
    } else if (unitsStr.compare(UNITS_VOLUME_NL) == 0) {
        vol = units::nl;
    } else {
        throw(std::invalid_argument("Unknow volume units \"" + unitsStr + "\""));
    }
    return vol;
}

units::Temperature UtilsJSON::getTemperatureUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::Temperature temp;
    if (unitsStr.compare(UNITS_TEMPERATURE_C) == 0) {
        temp = units::C;
    } else if (unitsStr.compare(UNITS_TEMPERATURE_K) == 0) {
        temp = units::K;
    } else {
        throw(std::invalid_argument("Unknow Temperature units \"" + unitsStr + "\""));
    }
    return temp;
}

units::Frequency UtilsJSON::getFrequencyUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::Frequency freq;
    if (unitsStr.compare(UNITS_FREQUENCY_HZ) == 0) {
        freq = units::Hz;
    } else if (unitsStr.compare(UNITS_FREQUENCY_KHZ) == 0) {
        freq = units::kHz;
    } else if (unitsStr.compare(UNITS_FREQUENCY_KHZ) == 0) {
        freq = units::MHz;
    } else {
        throw(std::invalid_argument("Unknow frequency units \"" + unitsStr + "\""));
    }
    return freq;
}

units::Length UtilsJSON::getLengthUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::Length len;
    if (unitsStr.compare(UNITS_LENGTH_CM) == 0) {
        len = units::cm;
    } else if (unitsStr.compare(UNITS_LENGTH_M) == 0) {
        len = units::m;
    } else if (unitsStr.compare(UNITS_LENGTH_NM) == 0) {
        len = units::nm;
    } else {
        throw(std::invalid_argument("Unknow length units \"" + unitsStr + "\""));
    }
    return len;
}

units::Time UtilsJSON::getTimeUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::Time time;
    if (unitsStr.compare(UNITS_TIME_HR) == 0) {
        time = units::hr;
    } else if (unitsStr.compare(UNITS_TIME_H) == 0) {
        time = units::hr;
    } else if (unitsStr.compare(UNITS_TIME_MINUTE) == 0) {
        time = units::minute;
    } else if (unitsStr.compare(UNITS_TIME_MS) == 0) {
        time = units::ms;
    } else if (unitsStr.compare(UNITS_TIME_S) == 0) {
        time = units::s;
    } else {
        throw(std::invalid_argument("Unknow time units \"" + unitsStr + "\""));
    }
    return time;
}

units::ElectricPotential UtilsJSON::getElectricPotentialUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::ElectricPotential ep;
    if (unitsStr.compare(UNITS_ELECTRICPOTENTIAL_V) == 0) {
        ep = units::V;
    } else {
        throw(std::invalid_argument("Unknow electric potential units \"" + unitsStr + "\""));
    }
    return ep;
}

units::LuminousIntensity UtilsJSON::getLuminousIntensityUnits(const std::string & unitsStr) throw(std::invalid_argument) {
    units::LuminousIntensity ep;
    if (unitsStr.compare(UNITS_LUMINOUS_CD) == 0) {
        ep = units::cd;
    } else {
        throw(std::invalid_argument("Unknow luminous intensity units \"" + unitsStr + "\""));
    }
    return ep;
}
