/*
 * Copyright 2025 Comcast Cable Communications Management, LLC
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

#include <getopt.h>
#include "CoreSDKTest.h"

void ShowMenu()
{
    printf("Enter\n"
           "\tI : Get Account Id\n"
           "\tU : Get Account Uid\n"
           "\tM : Get Device Model\n"
           "\tS : Get Device Sku\n"
           "\tA : Handle Advertising methods\n"
           "\tN : Get/Subscribe/Unsubscribe Device Name\n"
           "\tP : Get/Subscribe/Unsubscribe Device Audio Profiles\n"
           "\tR : Get/Subscribe/Unsubscribe Device Screen Resolution\n"
           "\tL : Handle Localization methods\n"
           "\tC : Get/Subscribe/Unsubscribe Closed Caption Settings\n"
           "\tK : Invoke keyboard methods email/password/standard\n"
           "\tV : Handle Profile methods\n"
           "\tT : Handle Authentication methods\n"
           "\tB : Handle Capabilities Method\n"
           "\tE : Handle Metrics methods\n"
           "\tF : Handle Lifecycle methods\n"
           "\tD : Handle SecondScreen methods\n"
           "\tY : Handle Discovery methods\n"
           "\tZ : Parameters Initialization\n"
           "\tQ : Quit\n\n"
          );
}

void ShowPropertyMenu(std::string& module, std::string& property)
{
    printf("%s:%s property options \n"
         "\tG : Get value\n"
         "\tR : Show subscribe/unscribe event menu\n"
         "\tQ : Quit\n", module.c_str(), property.c_str());
}

void ShowProfileMenu()
{
    printf("Options: \n"
         "\tC : Verify ApproveContentRating\n"
         "\tP : Verify ApprovePurchase\n"
         "\tF : Get Flags\n"
         "\tQ : Quit\n");
}

void ShowLocalizationMenu()
{
    printf("Options: \n"
         "\tA: Get additionalInfo\n"
         "\tL: Get LatLon\n"
         "\tP: Get/Subscribe/Unsubscribe Preferred AudioLanguages\n"
         "\tQ : Quit\n");
}

void ShowAuthenticationMenu()
{
    printf("Options: \n"
         "\t Invoke lifecyclesession management sequence from postman before invoking methods\n"
         "\tD : Get Authentication Device\n"
         "\tS : Get Authentication Session\n"
         "\tR : Get Authentication Root\n"
         "\tT : Get Authentication Token\n"
         "\tQ : Quit\n");
}

void ShowCapabilitiesMenu()
{
    printf("Options: \n"
         "\tA : Get Capabilities Available\n"
         "\tG : Get Capabilities Granted\n"
         "\tP : Get Capabilities Permitted\n"
         "\tS : Get Capabilities Supported\n"
         "\tI : Get Capabilities Info\n"
         "\tQ : Quit\n");
}

void ShowAdvertisingMenu()
{
    printf("Options: \n"
         "\tP : Get/Subscribe/Unsubscribe Advertising Policy\n"
         "\tC : Build configuration object for Ad Framework initialization\n"
         "\tD : Get the device advertising device attributes\n"
         "\tQ : Quit\n");
}

void ShowLifecycleMenu()
{
    printf("Options: \n"
         "\tC : Close lifecycle of the app\n"
         "\tB : Subscribe/Unsubscribe Background notification\n"
         "\tF : Subscribe/Unsubscribe Foreground notification\n"
         "\tQ : Quit\n");
}

void ShowMetricsMenu()
{
    printf("Options: \n"
         "\tS : Start Content\n"
         "\tT : Stop Content\n"
         "\tQ : Quit\n");
}

void ShowSecondScreenMenu()
{
    printf("Options: \n"
         "\tD : Get Device Id\n"
         "\tF : Get/Subscribe/Unsubscribe FriendlyName\n"
         "\tP : Get Protocols\n"
         "\tQ : Quit\n");
}

void ShowDiscoveryMenu()
{
    printf("Options: \n"
         "\tS : SignIn\n"
         "\tO : SignOut\n"
         "\tA : ContentAccess\n"
         "\tC : ClearContentAccess\n"
         "\tE : Entitlements\n"
         "\tI : EntityInfo\n"
         "\tP : Policy\n"
         "\tU : PurchasedContent\n"
         "\tN : WatchNext\n"
         "\tL : Launch\n"
#ifdef POLYMORPHICS_REDUCER_METHODS
         "\tW : Watched\n"
         "\tR : WatchedReduced\n"
#endif
         "\tQ : Quit\n");
}

void ShowKeyboardMenu()
{
    printf("Enter\n"
         "\tE : Invoke Email method\n"
         "\tA : Abort Email method\n"
         "\tP : Invoke Password method\n"
         "\tC : Abort Password method\n"
         "\tS : Invoke Standard method\n"
         "\tK : Abort Standard method\n"
         "\tQ : Quit\n");
}

void ShowEventMenu()
{
    printf("Enter\n"
         "\tS : Subscribe Event\n"
         "\tU : Unsubscribe Event\n"
         "\tQ : Quit\n");
}

#define VALUE(string) #string
#define TO_STRING(string) VALUE(string)

#define HandleEventListener(Module, eventFuncName) \
{ \
    int opt; \
    do { \
        getchar(); \
        ShowEventMenu(); \
        printf("Enter option : "); \
        opt = toupper(getchar()); \
        try { \
            switch (opt) { \
            case 'S': { \
                CoreSDKTest::Subscribe##Module##eventFuncName(); \
                break; \
            } \
            case 'U': { \
                CoreSDKTest::Unsubscribe##Module##eventFuncName(); \
                break; \
            } \
            default: \
                break; \
            } \
        } catch (const std::exception &e) { \
            printf("exception thrown: %s\n", e.what()); \
        } \
    } while (opt != 'Q'); \
}


#define HandleProperty(Module, Property) \
{ \
    int opt; \
    do { \
        getchar(); \
        std::string module = TO_STRING(Module); \
        std::string property = TO_STRING(Property); \
        ShowPropertyMenu(module, property); \
        printf("Enter option : "); \
        opt = toupper(getchar()); \
        try { \
            switch (opt) { \
            case 'G': { \
                CoreSDKTest::Get##Module##Property(); \
                break; \
            } \
            case 'R': { \
                HandleEventListener(Module, Property##Changed) \
                break; \
            } \
            default: \
                break; \
            } \
        } catch (const std::exception &e) { \
            printf("exception thrown: %s\n", e.what()); \
        } \
    } while (opt != 'Q'); \
}

void HandleAuthenticationMethod()
{
    int opt;
    do {
        getchar();
        ShowAuthenticationMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'D': {
                CoreSDKTest::GetAuthenticationDevice();
                break;
            }
            case 'S': {
                CoreSDKTest::GetAuthenticationSession();
                break;
            }
            case 'R': {
                CoreSDKTest::GetAuthenticationRoot();
                break;
            }
            case 'T': {
                CoreSDKTest::GetAuthenticationToken();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleCapabilitiesMethod()
{
    int opt;
    do {
        getchar();
        ShowCapabilitiesMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'A': {
                HandleProperty(Capabilities, Available)
                break;
            }
            case 'G': {
                CoreSDKTest::GetCapabilitiesGranted();
                break;
            }
            case 'P': {
                CoreSDKTest::GetCapabilitiesPermitted();
                break;
            }
            case 'S': {
                CoreSDKTest::GetCapabilitiesSupported();
                break;
            }
            case 'I': {
                CoreSDKTest::GetCapabilitiesInfo();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleProfileMethod()
{
    int opt;
    do {
        getchar();
        ShowProfileMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'C': {
                CoreSDKTest::VerifyProfileApproveContentRating(); // Error while testing, need to cross check
                break;
            }
            case 'P': {
                CoreSDKTest::VerifyProfileApprovePurchase(); // Error while testing, need to cross check
                break;
            }
            case 'F': {
                CoreSDKTest::GetProfileFlags();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleLocalizationMethod()
{
    int opt;
    do {
        getchar();
        ShowLocalizationMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'A': {
                CoreSDKTest::GetLocalizationAdditionalInfo();
                break;
            }
            case 'L': {
                CoreSDKTest::GetLocalizationLatlon();
                break;
            }
            case 'P': {
                HandleProperty(Localization, PreferredAudioLanguages)
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleAdvertisingMethod()
{
    int opt;
    do {
        getchar();
        ShowAdvertisingMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'P': {
                HandleProperty(Advertising, Policy)
                break;
            }
            case 'C': {
                CoreSDKTest::BuildAdvertisingConfiguration(); // Error while testing need to check
                break;
            }
            case 'D': {
                CoreSDKTest::GetAdvertisingDeviceAttributes(); // Error while testing need to check
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleLifecycleMethod()
{
    int opt;
    do {
        getchar();
        ShowLifecycleMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'C': {
                CoreSDKTest::LifecycleClose();
                break;
            }
            case 'B': {
                HandleEventListener(Lifecycle, BackgroundNotification)
                break;
            }
            case 'F': {
                HandleEventListener(Lifecycle, ForegroundNotification)
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleMetricsMethod()
{
    int opt;
    do {
        getchar();
        ShowMetricsMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'S': {
                CoreSDKTest::MetricsStartContent();
                break;
            }
            case 'T': {
                CoreSDKTest::MetricsStopContent();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleSecondScreenMethod()
{
    int opt;
    do {
        getchar();
        ShowSecondScreenMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'D': {
                CoreSDKTest::GetSecondScreenDevice();
                break;
            }
            case 'F': {
                HandleProperty(SecondScreen, FriendlyName)
                break;
            }
            case 'P': {
                CoreSDKTest::GetSecondScreenProtocols();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleDiscoveryMethod()
{
    int opt;
    do {
        getchar();
        ShowDiscoveryMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'S': {
                CoreSDKTest::DiscoverySignIn();
                break;
            }
            case 'O': {
                CoreSDKTest::DiscoverySignOut();
                break;
            }
            case 'A': {
                CoreSDKTest::DiscoveryContentAccess();
                break;
            }
            case 'C': {
                CoreSDKTest::DiscoveryClearContentAccess();
                break;
            }
            case 'E': {
                CoreSDKTest::DiscoveryEntitlements();
                break;
            }
            case 'I': {
                CoreSDKTest::DiscoveryEntityInfo();
                break;
            }
            case 'P': {
                CoreSDKTest::DiscoveryPolicy();
                break;
            }
            case 'U': {
                CoreSDKTest::DiscoveryPurchasedContent();
                break;
            }
            case 'N': {
                CoreSDKTest::DiscoveryWatchNext();
                break;
            }
            case 'L': {
                CoreSDKTest::DiscoveryLaunch();
                break;
            }
#ifdef POLYMORPHICS_REDUCER_METHODS
            case 'W': {
                CoreSDKTest::DiscoveryWatched();
                break;
            }
            case 'R': {
                CoreSDKTest::DiscoveryWatchedReduced();
                break;
            }
#endif
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

void HandleKeyboardMethodsInvokation()
{
    int opt;
    do {
        getchar();
        ShowKeyboardMenu();
        printf("Enter option : ");
        opt = toupper(getchar());
        try {
            switch (opt) {
            case 'E': {
                CoreSDKTest::InvokeKeyboardEmail();
                break;
            }
            case 'A': {
                CoreSDKTest::AbortKeyboardEmail();
                break;
            }
            case 'P': {
                CoreSDKTest::InvokeKeyboardPassword();
                break;
            }
            case 'C': {
                CoreSDKTest::AbortKeyboardPassword();
                break;
            }
            case 'S': {
                CoreSDKTest::InvokeKeyboardStandard();
                break;
            }
            case 'K': {
                CoreSDKTest::AbortKeyboardStandard();
                break;
            }
            default:
                break;
            }
        } catch (const std::exception &e) {
            printf("exception thrown: %s\n", e.what());
        }
    } while (opt != 'Q');
}

#define options ":hu:"
int main (int argc, char* argv[])
{
    int c;
    std::string url = "ws://127.0.0.1:9998";
    while ((c = getopt (argc, argv, options)) != -1) {
        switch (c)
        {
            case 'u':
                 url = optarg;
                 break;

            case 'h':
                 printf("./TestFireboltManage -u ws://ip:port\n");
                 exit(1);
        }
    }

    printf("Firebolt Core SDK Test\n");

    CoreSDKTest::CreateFireboltInstance(url);
    int option;
    if (CoreSDKTest::WaitOnConnectionReady() == true) {
       do {
            ShowMenu();
            printf("Enter option : ");
            option = toupper(getchar());
            try {
                switch (option) {
                case 'I' : {
                    CoreSDKTest::GetAccountId(); // Error while running need to cross check
                    break;
                }
                case 'U' : {
                    CoreSDKTest::GetAccountUid(); // Error while running need to cross check
                    break;
                }
                case 'A' : {
                    HandleAdvertisingMethod();
                    break;
                }
                case 'N': {
                    HandleProperty(Device, Name)
                    break;
                }
                case 'M': {
                    CoreSDKTest::GetDeviceModel();
                    break;
                }
                case 'S': {
                    CoreSDKTest::GetDeviceSku();
                    break;
                }
                case 'P': {
                    HandleProperty(Device, Audio)
                    break;
                }
                case 'R': {
                    HandleProperty(Device, ScreenResolution)
                    break;
                }
                case 'L': {
                    HandleLocalizationMethod();
                    break;
                }
                case 'C': {
                    HandleProperty(Accessibility, ClosedCaptionsSettings)
                    break;
                }
                case 'K': {
                    HandleKeyboardMethodsInvokation();
                    break;
                }
                case 'V': {
                    HandleProfileMethod();
                    break;
                }
                case 'T': {
                    HandleAuthenticationMethod();
                    break;
                }
                case 'B': {
                    HandleCapabilitiesMethod();
                    break;
                }
                case 'F': {
                    HandleLifecycleMethod();
                    break;
                }
                case 'E': {
                    HandleMetricsMethod();
                    break;
                }
                case 'D': {
                    HandleSecondScreenMethod();
                    break;
                }
                case 'Y': {
                    HandleDiscoveryMethod();
                    break;
                }
                case 'Z': {
                    CoreSDKTest::ParametersInitialization();
                    break;
                }
                default:
                    break;
                }
            } catch (const std::exception &e) {
                printf("exception thrown: %s\n", e.what());
            }
            getchar(); // Skip white space
        } while (option != 'Q');

    } else {
        printf("Core Test not able to connect with server.... \n");
    }

    CoreSDKTest::DestroyFireboltInstance();

    return 0;
}
