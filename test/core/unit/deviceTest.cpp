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

class DeviceTest : public ::testing::Test
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

TEST_F(DeviceTest, Id)
{

    auto actual_value = jsonEngine->get_value("Device.id");

    auto id = Firebolt::IFireboltAccessor::Instance().DeviceInterface().id(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve id from Device.id() method";
    EXPECT_EQ(id, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Distributor)
{

    auto actual_value = jsonEngine->get_value("Device.distributor");

    auto distributor = Firebolt::IFireboltAccessor::Instance().DeviceInterface().distributor(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve distributor from Device.distributor() method";
    EXPECT_EQ(distributor, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Platform)
{

    auto actual_value = jsonEngine->get_value("Device.platform");

    auto platform = Firebolt::IFireboltAccessor::Instance().DeviceInterface().platform(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve platform from Device.platform() method";
    EXPECT_EQ(platform, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Uid)
{

    auto actual_value = jsonEngine->get_value("Device.uid");

    auto uid = Firebolt::IFireboltAccessor::Instance().DeviceInterface().uid(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve uid from Device.uid() method";
    EXPECT_EQ(uid, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Type)
{

    auto actual_value = jsonEngine->get_value("Device.type");

    auto type = Firebolt::IFireboltAccessor::Instance().DeviceInterface().type(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve type from Device.type() method";
    EXPECT_EQ(type, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Model)
{

    auto actual_value = jsonEngine->get_value("Device.model");

    auto model = Firebolt::IFireboltAccessor::Instance().DeviceInterface().model(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve model from Device.model() method";
    EXPECT_EQ(model, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Sku)
{

    auto actual_value = jsonEngine->get_value("Device.sku");

    auto sku = Firebolt::IFireboltAccessor::Instance().DeviceInterface().sku(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve sku from Device.sku() method";
    EXPECT_EQ(sku, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, TestDeviceMake)
{

    auto actual_value = jsonEngine->get_value("Device.make");

    auto make = Firebolt::IFireboltAccessor::Instance().DeviceInterface().make(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve make from Device.make() method";
    EXPECT_EQ(make, REMOVE_QUOTES(actual_value));
}

TEST_F(DeviceTest, Hdcp)
{
    Firebolt::Error error = Firebolt::Error::None;

    // Parsing expected JSON values into a BooleanMap
    nlohmann::json expectedJson = nlohmann::json::parse(jsonEngine->get_value("Device.hdcp"));
    Firebolt::Types::BooleanMap expectedValues;

    for (auto it = expectedJson.begin(); it != expectedJson.end(); ++it)
    {
        expectedValues[it.key()] = it.value().get<bool>();
    }

    // Getting the actual value from the DeviceInterface
    Firebolt::Device::HDCPVersionMap hdcpMap = Firebolt::IFireboltAccessor::Instance().DeviceInterface().hdcp(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve hdcp from Device.hdcp() method";

    // Convert HDCPVersionMap to BooleanMap for comparison
    Firebolt::Types::BooleanMap actualValues;
    actualValues["hdcp1.4"] = hdcpMap.hdcp1_4;
    actualValues["hdcp2.2"] = hdcpMap.hdcp2_2;

    EXPECT_EQ(actualValues, expectedValues);
}

TEST_F(DeviceTest, Hdr)
{
    Firebolt::Error error = Firebolt::Error::None;

    // Parsing expected JSON values into a BooleanMap
    nlohmann::json expectedJson = nlohmann::json::parse(jsonEngine->get_value("Device.hdr"));
    Firebolt::Types::BooleanMap expectedValues;

    for (auto it = expectedJson.begin(); it != expectedJson.end(); ++it)
    {
        expectedValues[it.key()] = it.value().get<bool>();
    }

    // Getting the actual value from the DeviceInterface
    Firebolt::Device::HDRFormatMap hdrMap = Firebolt::IFireboltAccessor::Instance().DeviceInterface().hdr(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve hdr from Device.hdr() method";

    // Convert HDRFormatMap to BooleanMap for comparison
    Firebolt::Types::BooleanMap actualValues;
    actualValues["hdr10"] = hdrMap.hdr10;
    actualValues["hdr10Plus"] = hdrMap.hdr10Plus;
    actualValues["dolbyVision"] = hdrMap.dolbyVision;
    actualValues["hlg"] = hdrMap.hlg;

    EXPECT_EQ(actualValues, expectedValues);
}

TEST_F(DeviceTest, Audio)
{ 
    nlohmann::json expectedValues = nlohmann::json::parse(jsonEngine->get_value("Device.audio"));

    // Getting the actual value from the DeviceInterface
    const Firebolt::Device::AudioProfiles audio = Firebolt::IFireboltAccessor::Instance().DeviceInterface().audio(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve audio from Device.audio() method";
    EXPECT_EQ(audio.stereo, expectedValues["stereo"]);
    EXPECT_EQ(audio.dolbyDigital5_1, expectedValues["dolbyDigital5.1"]);
    EXPECT_EQ(audio.dolbyDigital5_1_plus, expectedValues["dolbyDigital5.1+"]);
    EXPECT_EQ(audio.dolbyAtmos, expectedValues["dolbyAtmos"]);
}


std::string networkTypeToString(Firebolt::Device::NetworkType type) {
    switch (type) {
        case Firebolt::Device::NetworkType::WIFI:
            return "wifi";
        case Firebolt::Device::NetworkType::ETHERNET:
            return "ethernet";
        case Firebolt::Device::NetworkType::HYBRID:
            return "hybrid";
        default:
            return "";
    }
}

std::string networkStateToString(Firebolt::Device::NetworkState state) {
    switch (state) {
        case Firebolt::Device::NetworkState::CONNECTED:
            return "connected";
        case Firebolt::Device::NetworkState::DISCONNECTED:
            return "disconnected";
        default:
            return "";
    }
}

TEST_F(DeviceTest, Network)
{
    nlohmann::json expectedValues = nlohmann::json::parse(jsonEngine->get_value("Device.network"));

    // Getting the actual value from the DeviceInterface
    Firebolt::Device::NetworkInfoResult network = Firebolt::IFireboltAccessor::Instance().DeviceInterface().network(&error);

    // Perform the assertions
    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve network from Device.network() method";
    EXPECT_EQ(networkStateToString(network.state), expectedValues["state"]);
    EXPECT_EQ(networkTypeToString(network.type), expectedValues["type"]);
}

TEST_F(DeviceTest, ScreenResolution)
{

    // Parse expected JSON values
    nlohmann::json expectedJson;
    try
    {
        std::string jsonString = jsonEngine->get_value("Device.screenResolution");
        expectedJson = nlohmann::json::parse(jsonString);
    }
    catch (const nlohmann::json::exception &e)
    {
        FAIL() << "Failed to parse JSON: " << e.what();
    }

    // Validate that expectedJson is an array and has the required number of elements
    if (!expectedJson.is_array())
    {
        FAIL() << "Expected JSON is not an array: " << expectedJson.dump(4);
    }

    // Getting the actual value from the DeviceInterface
    Firebolt::Error error = Firebolt::Error::None;
    using Resolution = std::pair<int32_t, int32_t>;
    Resolution screenResolution = Firebolt::IFireboltAccessor::Instance().DeviceInterface().screenResolution(&error);

    // Perform the assertions
    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve screenResolution from Device.screenResolution() method";
    EXPECT_EQ(std::to_string(screenResolution.first) + "x" + std::to_string(screenResolution.second), expectedJson.get<std::string>());
}

TEST_F(DeviceTest, VideoResolution)
{

    // Parse expected JSON values
    nlohmann::json expectedJson;
    try
    {
        std::string jsonString = jsonEngine->get_value("Device.videoResolution");
        expectedJson = nlohmann::json::parse(jsonString);
    }
    catch (const nlohmann::json::exception &e)
    {
        FAIL() << "Failed to parse JSON: " << e.what();
    }

    // Validate that expectedJson is an array and has the required number of elements
    if (!expectedJson.is_array())
    {
        FAIL() << "Expected JSON is not an array: " << expectedJson.dump(4);
    }


    // Getting the actual value from the DeviceInterface
    Firebolt::Error error = Firebolt::Error::None;
    using Resolution = std::pair<int32_t, int32_t>;
    Resolution videoResolution = Firebolt::IFireboltAccessor::Instance().DeviceInterface().videoResolution(&error);

    // Perform the assertions
    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve videoResolution from Device.videoResolution() method";
    EXPECT_EQ(std::to_string(videoResolution.first) + "x" + std::to_string(videoResolution.second), expectedJson.get<std::string>());
}

TEST_F(DeviceTest, Name)
{

    auto actual_value = jsonEngine->get_value("Device.name");

    auto name = Firebolt::IFireboltAccessor::Instance().DeviceInterface().name(&error);

    EXPECT_EQ(error, Firebolt::Error::None) << "Failed to retrieve name from Device.name() method";
    EXPECT_EQ(name, REMOVE_QUOTES(actual_value));
}
