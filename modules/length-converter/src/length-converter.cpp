// Copyright 2018 Nifadyev Vadim

#include "include/length-converter.h"

double LengthConverter::centimetersToMeters(const double& centimeters) const {
    if (!isCorrect(centimeters)) {
        throw "Error! Invalid argument";
    }
    return centimeters / 100;
}

double LengthConverter::metersToCentimeters(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters * 100;
}

double LengthConverter::metersToKilometers(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 1000;
}

double LengthConverter::kilometersToMeters(const double& kilometers) const {
    if (!isCorrect(kilometers)) {
        throw "Error! Invalid argument";
    }
    return kilometers * 1000;
}

double LengthConverter::kilometersToMiles(const double& kilometers) const {
    if (!isCorrect(kilometers)) {
        throw "Error! Invalid argument";
    }
    return kilometers / 1.609344;
}

double LengthConverter::milesToKilometers(const double& miles) const {
    if (!isCorrect(miles)) {
        throw "Error! Invalid argument";
    }
    return miles * 1.609344;
}

double LengthConverter::footToYards(const double& foot) const {
    if (!isCorrect(foot)) {
        throw "Error! Invalid argument";
    }
    return foot / 3;
}

double LengthConverter::yardsToFoot(const double& yards) const {
    if (!isCorrect(yards)) {
        throw "Error! Invalid argument";
    }
    return yards * 3;
}

double LengthConverter::footToMeters(const double& foot) const {
    if (!isCorrect(foot)) {
        throw "Error! Invalid argument";
    }
    return foot / 0.3048;
}

double LengthConverter::metersToFoot(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters * 0.3048;
}

double LengthConverter::centimetersToInches(const double& centimeters) const {
    if (!isCorrect(centimeters)) {
        throw "Error! Invalid argument";
    }
    return centimeters / 2.54;
}

double LengthConverter::inchesToCentimeters(const double& inches) const {
    if (!isCorrect(inches)) {
        throw "Error! Invalid argument";
    }
    return inches * 2.54;
}

double LengthConverter::metersToNauticalMiles(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 1852;
}

double LengthConverter::nauiticalMilesToMeters
       (const double& nauticalMiles) const {
    if (!isCorrect(nauticalMiles)) {
        throw "Error! Invalid argument";
    }
    return nauticalMiles * 1852;
}

double LengthConverter::kilometersToAstronomicalUnits
       (const double& kilometers) const {
    if (!isCorrect(kilometers)) {
        throw "Error! Invalid argument";
    }
    return kilometers / 149597870.7;
}

double LengthConverter::astronomicalUnitsToKilometers
       (const double& astronomicalUnits) const {
    if (!isCorrect(astronomicalUnits)) {
        throw "Error! Invalid argument";
    }
    return astronomicalUnits * 149597870.7;
}

double LengthConverter::centimetersToSpans(const double& centimeters) const {
    if (!isCorrect(centimeters)) {
        throw "Error! Invalid argument";
    }
    return centimeters / 17.78;
}

double LengthConverter::spansToCentimeters(const double& spans) const {
    if (!isCorrect(spans)) {
        throw "Error! Invalid argument";
    }
    return spans * 17.78;
}

double LengthConverter::spansToVersts(const double& spans) const {
    if (!isCorrect(spans)) {
        throw "Error! Invalid argument";
    }
    return spans / 6000;
}

double LengthConverter::verstsToSpans(const double& versts) const {
    if (!isCorrect(versts)) {
        throw "Error! Invalid argument";
    }
    return versts * 6000;
}

bool LengthConverter::isCorrect(const double& value) const {
    const double eps = 0.01;

    if ((value < 0) || (value < eps && value > -eps)) {
        return false;
    }
    return true;
}

// Additional public methods
double LengthConverter::milesToMeters(const double& miles) const {
    if (!isCorrect(miles)) {
        throw "Error! Invalid argument";
    }
    return miles * 1609.344;
}

double LengthConverter::metersToMiles(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 1609.344;
}

double LengthConverter::yardsToMeters(const double& yards) const {
    if (!isCorrect(yards)) {
        throw "Error! Invalid argument";
    }
    return yards * 9.842519685;
}

double LengthConverter::metersToYards(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 9.842519685;
}

double LengthConverter::inchesToMeters(const double& inches) const {
    if (!isCorrect(inches)) {
        throw "Error! Invalid argument";
    }
    return inches * 0.0254;
}

double LengthConverter::metersToInches(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 0.0254;
}

double LengthConverter::astronomicalUnitsToMeters
       (const double& astronomicalUnits) const {
    if (!isCorrect(astronomicalUnits)) {
        throw "Error! Invalid argument";
    }
    return astronomicalUnits * 149597870700;
}

double LengthConverter::metersToAstronomicalUnits(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 149597870700;
}

double LengthConverter::spansToMeters(const double& spans) const {
    if (!isCorrect(spans)) {
        throw "Error! Invalid argument";
    }
    return spans * 0.1778;
}

double LengthConverter::metersToSpans(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 0.1778;
}

double LengthConverter::verstsToMeters(const double& versts) const {
    if (!isCorrect(versts)) {
        throw "Error! Invalid argument";
    }
    return versts * 1066.8;
}

double LengthConverter::metersToVersts(const double& meters) const {
    if (!isCorrect(meters)) {
        throw "Error! Invalid argument";
    }
    return meters / 1066.8;
}
