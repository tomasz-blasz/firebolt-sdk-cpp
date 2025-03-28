/*
 * Copyright 2023 Comcast Cable Communications Management, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "unit.h"

class SecondScreenTest : public ::testing::Test
{
protected:
    JsonEngine *jsonEngine;
    Firebolt::Error error = Firebolt::Error::None;

    void SetUp() override
    {
        jsonEngine = new JsonEngine();
    }

    void TearDown() override
    {
        delete jsonEngine;
    }
};

TEST_F(SecondScreenTest, FriendlyName)
{
	nlohmann::json_abi_v3_11_3::json expectedValue = nlohmann::json::parse(jsonEngine->get_value("SecondScreen.friendlyName"));

    auto actualValue = Firebolt::IFireboltAccessor::Instance().SecondScreenInterface().friendlyName(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve friendlyName from Secondscreen.friendlyName() method";
    EXPECT_EQ(actualValue, expectedValue);
}

TEST_F(SecondScreenTest, Device)
{
    nlohmann::json_abi_v3_11_3::json expectedValue = nlohmann::json::parse(jsonEngine->get_value("SecondScreen.device"));

    auto actualValue = Firebolt::IFireboltAccessor::Instance().SecondScreenInterface().device(std::nullopt, &error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve device from Secondscreen.device() method";
    EXPECT_EQ(actualValue, expectedValue);
}

TEST_F(SecondScreenTest, Protocols)
{
    std::string jsonString = jsonEngine->get_value("SecondScreen.protocols");

    // Check if the JSON string is empty
    ASSERT_FALSE(jsonString.empty()) << "JSON string for Secondscreen.protocols is empty";

    nlohmann::json expectedValues;
    try {
        expectedValues = nlohmann::json::parse(jsonString);
    } catch (const nlohmann::json::parse_error& e) {
        FAIL() << "Failed to parse JSON string: " << e.what();
    }

    Firebolt::Types::BooleanMap actualValues = Firebolt::IFireboltAccessor::Instance().SecondScreenInterface().protocols(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve protocols from Secondscreen.protocols() method";
    EXPECT_EQ(actualValues, expectedValues);
}
