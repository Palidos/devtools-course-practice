// Copyright 2018 Bederdinov Daniil

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/hypothec_calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class HypothecCalculatorAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    HypothecCalculatorApp app_;
    string output_;
};

TEST_F(HypothecCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a hypothec calculator application\\..*");
}

TEST_F(HypothecCalculatorAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2", "7"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(HypothecCalculatorAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"aa", "bb", "cc", "dd"};

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(HypothecCalculatorAppTest, Can_Detect_Float_Overflow) {
    vector<string> args = {"99999999999999999999", "99999999999999999999",
        "99999999999999999999", "99999999999999999999"};

        Act(args);

        Assert("Wrong format or value is out of range");
}

TEST_F(HypothecCalculatorAppTest, Can_Print_Result) {
    vector<string> args = {"1000", "1", "6", "10"};

    Act(args);

    Assert("1029");
}
