#ifndef MULTIUNITSWRAPPER_H
#define MULTIUNITSWRAPPER_H

#include <memory>
#include <stdexcept>

#include "utils/electrophoresisresult.h"
#include "utils/units.h"

class MultiUnitsWrapper
{
public:
    typedef enum UnitsType_ {
        no_units,
        length,
        volume,
        time,
        temperature,
        luminous_intensity,
        volumetric_flow,
        frequency,
        electrophoresis_result
    } UnitsType;

    MultiUnitsWrapper(){
        electrophoresisResult = NULL;
    }
    virtual ~MultiUnitsWrapper(){}

    inline void setNoUnits(double value) {
        unitsType = no_units;
        lengthUnit = value * units::m;
    }
    inline void setLength(units::Length l) {
        unitsType = length;
        lengthUnit = l;
    }
    inline void setVolume(units::Volume v) {
        unitsType = volume;
        volumeUnits = v;
    }
    inline void setTime(units::Time t) {
        unitsType = time;
        timeUnits = t;
    }
    inline void setTemperature(units::Temperature t) {
        unitsType = temperature;
        temperatureUnits = t;
    }
    inline void setLuminousIntensity(units::LuminousIntensity li) {
        unitsType = luminous_intensity;
        luminosityIntensityUnits = li;
    }
    inline void setVolumetricFlow(units::Volumetric_Flow vf) {
        unitsType = volumetric_flow;
        volumetricFlowUnits = vf;
    }
    inline void setFrequency(units::Frequency f) {
        unitsType = frequency;
        frequencyUnits = f;
    }
    inline void setElectrophoresisResult(std::shared_ptr<ElectrophoresisResult> er) {
        unitsType = electrophoresis_result;
        electrophoresisResult = er;
    }

    inline double getNoUnits() throw(std::invalid_argument) {
        if (unitsType == no_units) {
            return lengthUnit();
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap  no untis value"));
        }
    }
    inline units::Length getLength() throw(std::invalid_argument) {
        if (unitsType == length) {
            return lengthUnit;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap Length untis"));
        }
    }
    inline units::Volume getVolume() throw(std::invalid_argument) {
        if (unitsType == volume) {
            return volumeUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap Volume untis"));
        }
    }
    inline units::Time getTime() throw(std::invalid_argument) {
        if (unitsType == time) {
            return timeUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap Time untis"));
        }
    }
    inline units::Temperature getTemperature() throw(std::invalid_argument) {
        if (unitsType == temperature) {
            return temperatureUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap Temperature untis"));
        }
    }
    inline units::LuminousIntensity getLuminousIntensity() throw(std::invalid_argument) {
        if (unitsType == luminous_intensity) {
            return luminosityIntensityUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap LuminousIntensity untis"));
        }
    }
    inline units::Volumetric_Flow getVolumetricFlow() throw(std::invalid_argument) {
        if (unitsType == volumetric_flow) {
            return volumetricFlowUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap VolumetricFlow untis"));
        }
    }
    inline units::Frequency getFrequency() throw(std::invalid_argument) {
        if (unitsType == frequency) {
            return frequencyUnits;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap Frequency untis"));
        }
    }

    inline std::shared_ptr<ElectrophoresisResult> getElectrophoresisResult() throw(std::invalid_argument) {
        if (unitsType == electrophoresis_result) {
            return electrophoresisResult;
        } else {
            throw(std::invalid_argument("this unitswrapper does not wrap ElectrophoresisResults untis"));
        }
    }

protected:
    UnitsType unitsType;

    units::Length lengthUnit;
    units::Volume volumeUnits;
    units::Time timeUnits;
    units::Temperature temperatureUnits;
    units::LuminousIntensity luminosityIntensityUnits;
    units::Volumetric_Flow volumetricFlowUnits;
    units::Frequency frequencyUnits;

    std::shared_ptr<ElectrophoresisResult> electrophoresisResult;
};

#endif // MULTIUNITSWRAPPER_H
