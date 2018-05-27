// Copyright 2018 Nifadyev Vadim

#include <gtest/gtest.h>
#include "include/length-converter.h"

TEST(LengthConverter, Can_Create_Length_Converter) {
    // Act & Assert
    ASSERT_NO_THROW(LengthConverter converter);
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Meters) {
    // Arrange
    double centimeters = 1524;
    double expectedResult = 15.24;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToMeters(centimeters),
                     expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Centimeters_To_Meters) {
    // Arrange
    double centimeters = -1524;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToMeters(centimeters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Centimeters_To_Meters) {
    // Arrange
    double centimeters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToMeters(centimeters));
}

TEST(LengthConverter, Can_Convert_Meters_To_Centimeters) {
    // Arrange
    double meters = 21.56;
    double expectedResult = 2156;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToCentimeters(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Centimeters) {
    // Arrange
    double meters = -24141;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToCentimeters(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Centimeters) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToCentimeters(meters));
}

TEST(LengthConverter, Can_Convert_Meters_To_Kilometers) {
    // Arrange
    double meters = 678901;
    double expectedResult = 678.901;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToKilometers(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Kilometers) {
    // Arrange
    double meters = -9003;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToKilometers(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Kilometers) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToKilometers(meters));
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Meters) {
    // Arrange
    double kilometers = 0.48122;
    double expectedResult = 481.22;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToMeters(kilometers), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Kilometers_To_Meters) {
    // Arrange
    double kilometers = -3;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToMeters(kilometers));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Kilometers_To_Meters) {
    // Arrange
    double kilometers = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToMeters(kilometers));
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Miles) {
    // Arrange
    double kilometers = 59.002;
    double expectedResult = 36.662143084387175;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToMiles(kilometers), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Kilometers_To_Miles) {
    // Arrange
    double kilometers = -12;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToMiles(kilometers));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Kilometers_To_Miles) {
    // Arrange
    double kilometers = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToMiles(kilometers));
}

TEST(LengthConverter, Can_Convert_Miles_To_Kilometers) {
    // Arrange
    double miles = 190.12;
    double expectedResult = 305.96848128;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.milesToKilometers(miles), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Miles_To_Kilometers) {
    // Arrange
    double miles = -6753;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.milesToKilometers(miles));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Miles_To_Kilometers) {
    // Arrange
    double miles = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.milesToKilometers(miles));
}

TEST(LengthConverter, Can_Convert_Foot_To_Yards) {
    // Arrange
    double foot = 8769123.055;
    double expectedResult = 2923041.0183333331;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.footToYards(foot), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Foot_To_Yards) {
    // Arrange
    double foot = -31;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.footToYards(foot));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Foot_To_Yards) {
    // Arrange
    double foot = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.footToYards(foot));
}

TEST(LengthConverter, Can_Convert_Yards_To_Foot) {
    // Arrange
    double yards = 34.99124;
    double expectedResult = 104.97372;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.yardsToFoot(yards), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Yards_To_Foot) {
    // Arrange
    double yards = -3330123.04124;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.yardsToFoot(yards));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Yards_To_Foot) {
    // Arrange
    double yards = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.yardsToFoot(yards));
}

TEST(LengthConverter, Can_Convert_Foot_To_Meters) {
    // Arrange
    double foot = 4011.001;
    double expectedResult = 13159.452099737533;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.footToMeters(foot), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Foot_To_Meters) {
    // Arrange
    double foot = -1.9914;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.footToMeters(foot));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Foot_To_Meters) {
    // Arrange
    double foot = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.footToMeters(foot));
}

TEST(LengthConverter, Can_Convert_Meters_To_Foot) {
    // Arrange
    double meters = 12.333167;
    double expectedResult = 3.7591493016;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToFoot(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Foot) {
    // Arrange
    double meters = -99.003;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToFoot(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Foot) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToFoot(meters));
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Inches) {
    // Arrange
    double centimeters = 11902.34;
    double expectedResult = 4685.9606299212601;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToInches(centimeters),
                     expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Centimeters_To_Inches) {
    // Arrange
    double centimeters = -408.2146;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToInches(centimeters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Centimeters_To_Inches) {
    // Arrange
    double centimeters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToInches(centimeters));
}

TEST(LengthConverter, Can_Convert_Inches_To_Centimeters) {
    // Arrange
    double inches = 674.53;
    double expectedResult = 1713.3062;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.inchesToCentimeters(inches), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Inches_To_Centimeters) {
    // Arrange
    double inches = -1.77904124;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.inchesToCentimeters(inches));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Inches_To_Centimeters) {
    // Arrange
    double inches = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.inchesToCentimeters(inches));
}

TEST(LengthConverter, Can_Convert_Meters_To_Nautical_Miles) {
    // Arrange
    double meters = 32875.1211;
    double expectedResult = 17.751145302375807;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToNauticalMiles(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Try_To_Convert_Negative_Value_From_Meters_To_Nautical_Miles) {
    // Arrange
    double meters = -789.135;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToNauticalMiles(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Nautical_Miles) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToNauticalMiles(meters));
}

TEST(LengthConverter, Can_Convert_Nautical_Miles_To_Meters) {
    // Arrange
    double nauticalMiles = 3.00061;
    double expectedResult = 5557.12972;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.nauiticalMilesToMeters(nauticalMiles),
                     expectedResult);
}

TEST(LengthConverter,
    Throw_When_Try_To_Convert_Negative_Value_From_Nautical_Miles_To_Meters) {
    // Arrange
    double nauticalMiles = -202;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.nauiticalMilesToMeters(nauticalMiles));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Nautical_Miles_To_Meters) {
    // Arrange
    double nauticalMiles = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.nauiticalMilesToMeters(nauticalMiles));
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Astronomical_Units) {
    // Arrange
    double kilometers = 8754875672001;
    double expectedResult = 58522.729174119195;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToAstronomicalUnits(kilometers),
                     expectedResult);
}

TEST(LengthConverter,
    Throw_When_Convert_Negative_Value_From_Kilometers_To_Astronomical_Units) {
    // Arrange
    double kilometers = -5.2441;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToAstronomicalUnits(kilometers));
}

TEST(LengthConverter,
    Throw_When_Convert_Zero_Value_From_Kilometers_To_Astronomical_Units) {
    // Arrange
    double kilometers = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.kilometersToAstronomicalUnits(kilometers));
}

TEST(LengthConverter, Can_Convert_Astronomical_Units_To_Kilometers) {
    // Arrange
    double astronomicalUnits = 2.1046;
    double expectedResult = 314843678.67522;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.astronomicalUnitsToKilometers(astronomicalUnits)
                     , expectedResult);
}

TEST(LengthConverter,
    Throw_When_Convert_Negative_Value_From_Astronomical_Units_To_Kilometers) {
    // Arrange
    double astroUnits = -1.0012441;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.astronomicalUnitsToKilometers(astroUnits));
}

TEST(LengthConverter,
    Throw_When_Convert_Zero_Value_From_Astronomical_Units_To_Kilometers) {
    // Arrange
    double astroUnits = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.astronomicalUnitsToKilometers(astroUnits));
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Spans) {
    // Arrange
    double centimeters = 5901.9;
    double expectedResult = 331.94038245219343;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToSpans(centimeters),
                     expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Centimeters_To_Spans) {
    // Arrange
    double centimeters = -76585.12125;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToSpans(centimeters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Centimeters_To_Spans) {
    // Arrange
    double centimeters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.centimetersToSpans(centimeters));
}

TEST(LengthConverter, Can_Convert_Spans_To_Centimeters) {
    // Arrange
    double spans = 712.014;
    double expectedResult = 12659.60892;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.spansToCentimeters(spans), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Spans_To_Centimeters) {
    // Arrange
    double spans = -9805235.124;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToCentimeters(spans));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Spans_To_Centimeters) {
    // Arrange
    double spans = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToCentimeters(spans));
}

TEST(LengthConverter, Can_Convert_Spans_To_Versts) {
    // Arrange
    double spans = 38001.7125;
    double expectedResult = 6.33361875;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.spansToVersts(spans), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Spans_To_Versts) {
    // Arrange
    double spans = -64.1;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToVersts(spans));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Spans_To_Versts) {
    // Arrange
    double spans = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToVersts(spans));
}

TEST(LengthConverter, Can_Convert_Versts_To_Spans) {
    // Arrange
    double versts = 14.077;
    double expectedResult = 84462;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.verstsToSpans(versts), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Versts_To_Spans) {
    // Arrange
    double versts = -879873.12;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.verstsToSpans(versts));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Versts_To_Spans) {
    // Arrange
    double versts = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.verstsToSpans(versts));
}

TEST(LengthConverter, Can_Convert_Miles_To_Meters) {
    // Arrange
    double miles = 22.013;
    double expectedResult = 35426.489472;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.milesToMeters(miles), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Miles_To_Meters) {
    // Arrange
    double miles = -0.21312489;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.milesToMeters(miles));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Miles_To_Meters) {
    // Arrange
    double miles = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.milesToMeters(miles));
}

TEST(LengthConverter, Can_Convert_Meters_To_Miles) {
    // Arrange
    double meters = 579867.114;
    double expectedResult = 360.31271996540198;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToMiles(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Miles) {
    // Arrange
    double meters = -100074.02;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToMiles(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Miles) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToMiles(meters));
}

TEST(LengthConverter, Can_Convert_Yards_To_Meters) {
    // Arrange
    double yards = 90123.9;
    double expectedResult = 887046.25983897143;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.yardsToMeters(yards), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Yards_To_Meters) {
    // Arrange
    double yards = -987412.8;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.yardsToMeters(yards));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Yards_To_Meters) {
    // Arrange
    double yards = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.yardsToMeters(yards));
}

TEST(LengthConverter, Can_Convert_Meters_To_Yards) {
    // Arrange
    double meters = 8227.7;
    double expectedResult = 835.93432000334383;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToYards(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Yards) {
    // Arrange
    double meters = -79.774;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToYards(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Yards) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToYards(meters));
}

TEST(LengthConverter, Can_Convert_Inches_To_Meters) {
    // Arrange
    double inches = 6514412.1;
    double expectedResult = 165466.06734;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.inchesToMeters(inches), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Inches_To_Meters) {
    // Arrange
    double inches = -773.124;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.inchesToMeters(inches));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Inches_To_Meters) {
    // Arrange
    double inches = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.inchesToMeters(inches));
}

TEST(LengthConverter, Can_Convert_Meters_To_Inches) {
    // Arrange
    double meters = 8547.901;
    double expectedResult = 336531.535433071;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToInches(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Inches) {
    // Arrange
    double meters = -6848;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToInches(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Inches) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToInches(meters));
}

TEST(LengthConverter, Can_Convert_Astronomical_Units_To_Meters) {
    // Arrange
    double astronomicalUnits = 0.42352623;
    double expectedResult = 63358622193.598461;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.astronomicalUnitsToMeters(astronomicalUnits),
                    expectedResult);
}

TEST(LengthConverter,
    Throw_When_Converting_Negative_Value_From_Astronomical_Units_To_Meters) {
    // Arrange
    double astronomicalUnits = -0.0034213;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.astronomicalUnitsToMeters(astronomicalUnits));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Astronomical_Units_To_Meters) {
    // Arrange
    double astronomicalUnits = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.astronomicalUnitsToMeters(astronomicalUnits));
}

TEST(LengthConverter, Can_Convert_Meters_To_Astronomical_Units) {
    // Arrange
    double meters = 745745982395.1;
    double expectedResult = 4.985003990401716;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToAstronomicalUnits(meters),
                    expectedResult);
}

TEST(LengthConverter,
    Throw_When_Converting_Negative_Value_From_Meters_To_Astronomical_Units) {
    // Arrange
    double meters = -890471204.12;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToAstronomicalUnits(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Astronomical_Units) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToAstronomicalUnits(meters));
}

TEST(LengthConverter, Can_Convert_Spans_To_Meters) {
    // Arrange
    double spans = 9670346.23;
    double expectedResult = 1719387.559694;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.spansToMeters(spans), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Spans_To_Meters) {
    // Arrange
    double spans = -3593.041240;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToMeters(spans));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Spans_To_Meters) {
    // Arrange
    double spans = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.spansToMeters(spans));
}

TEST(LengthConverter, Can_Convert_Meters_To_Spans) {
    // Arrange
    double meters = 890412.7;
    double expectedResult = 5007945.44431946;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToSpans(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Spans) {
    // Arrange
    double meters = -801241;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToSpans(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Spans) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToSpans(meters));
}

TEST(LengthConverter, Can_Convert_Versts_To_Meters) {
    // Arrange
    double versts = 856.041;
    double expectedResult = 913224.5388;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.verstsToMeters(versts), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Versts_To_Meters) {
    // Arrange
    double versts = -41240.12;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.verstsToMeters(versts));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Versts_To_Meters) {
    // Arrange
    double versts = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.verstsToMeters(versts));
}

TEST(LengthConverter, Can_Convert_Meters_To_Versts) {
    // Arrange
    double meters = 890481.067;
    double expectedResult = 834.721660104987;
    LengthConverter converter;

    // Act & Assert
    EXPECT_DOUBLE_EQ(converter.metersToVersts(meters), expectedResult);
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Negative_Value_From_Meters_To_Versts) {
    // Arrange
    double meters = -1402;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToVersts(meters));
}

TEST(LengthConverter,
    Throw_When_Trying_To_Convert_Zero_Value_From_Meters_To_Versts) {
    // Arrange
    double meters = 0;
    LengthConverter converter;

    // Act & Assert
    ASSERT_ANY_THROW(converter.metersToVersts(meters));
}
