#include "jsonutils.h"
#include <QDebug>
#include <QDateTime>


bool headingdone = false;

const QString jsonLogPattern = "Debug{";
//const QString header = "failedAt,functionTestResult_common_isTestPass,functionTestResult_common_lastState,functionTestResult_functionTest_coverClosed,functionTestResult_functionTest_magnetStat1,functionTestResult_functionTest_magnetStat2,functionTestResult_functionTest_neutralCurrentOff,functionTestResult_functionTest_neutralCurrentOn,functionTestResult_functionTest_phaseCurrentOff,functionTestResult_functionTest_phaseCurrentOn,functionTestResult_functionTest_pushButton,functionTestResult_pcbNumber_pcbNumber,functionTestResult_rtc_rtcDriftSecond,functionTestResult_vi_neutralCurrent,functionTestResult_vi_phaseCurrent,functionTestResult_vi_voltage,highCurrentTestResult_common_isTestPass,highCurrentTestResult_common_lastState,highCurrentTestResult_cumulativeEnergy,highCurrentTestResult_meterEnergyWH,highCurrentTestResult_neutralEnergy,highCurrentTestResult_neutralReactiveEnergy,highCurrentTestResult_neutralWattHour,highCurrentTestResult_phaseEnergy,highCurrentTestResult_phaseReactiveEnergy,highCurrentTestResult_phaseWattHour,highCurrentTestResult_startingCumlativeEnergy,highCurrentTestResult_testCurrent,highCurrentTestResult_testVoltage,highCurrentTestResult_timeMS,hvTestResult_isTestPass,hvTestResult_lastState,laserEngraveResult_loaNumber,laserEngraveResult_mfgDate,laserEngraveResult_serialNumber,lowCurrentTestResult_common_isTestPass,lowCurrentTestResult_common_lastState,lowCurrentTestResult_cumulativeEnergy,lowCurrentTestResult_meterEnergyWH,lowCurrentTestResult_neutralEnergy,lowCurrentTestResult_neutralReactiveEnergy,lowCurrentTestResult_neutralWattHour,lowCurrentTestResult_phaseEnergy,lowCurrentTestResult_phaseReactiveEnergy,lowCurrentTestResult_phaseWattHour,lowCurrentTestResult_startingCumlativeEnergy,lowCurrentTestResult_testCurrent,lowCurrentTestResult_testVoltage,lowCurrentTestResult_timeMS,megarTestResult_isTestPass,megarTestResult_lastState,meterFinalSerialNumber,meterTmpSerialNumber,neutralCalibration_isTestPass,neutralCalibration_lastState,nicSyncTestResult_channelAddrss,nicSyncTestResult_common_isTestPass,nicSyncTestResult_common_lastState,nicSyncTestResult_dlmsLastState,nicSyncTestResult_isDLMSPass,nicSyncTestResult_meterMemoryNumber,nicSyncTestResult_meterNumberPrint,nicSyncTestResult_netowrkAddress,nicSyncTestResult_rfKey,phaseCalibration_isTestPass,phaseCalibration_lastState,startingCurrentTestResult_common_isTestPass,startingCurrentTestResult_common_lastState,startingCurrentTestResult_cumulativeEnergy,startingCurrentTestResult_meterEnergyWH,startingCurrentTestResult_neutralEnergy,startingCurrentTestResult_neutralReactiveEnergy,startingCurrentTestResult_neutralWattHour,startingCurrentTestResult_phaseEnergy,startingCurrentTestResult_phaseReactiveEnergy,startingCurrentTestResult_phaseWattHour,startingCurrentTestResult_startingCumlativeEnergy,startingCurrentTestResult_testCurrent,startingCurrentTestResult_testVoltage,startingCurrentTestResult_timeMS\n"
const QString header = "failedAt,meterTmpSerialNumber,pcbNumber,meterMemoryNumber,meterFinalSerialNumber,meterFeedDelay,cycleTime,Date ,Time, "
                        "FT_startTestTime,FT_endTestTime,FT_timeDuration,"
                        "FT_isTestPass,FT_lastState,FT_coverClosed,FT_magnet1,FT_magnet2,FT_Relay_neutralOff,FT_Relay_neutralOn,FT_Relay_phaseOff,FT_Relay_phaseOn,FTpushButton,FTrtcDriftSecond,HVTestResult,IRTestResult,"
                        "PHC_startTestTime,PHC_endTestTime,PHC_timeDuration,"
                        "PHCisTestPass,PHClastState,PHCtestDuration,PHCerrorDetails,"
                        "NEC_startTestTime,NEC_endTestTime,NEC_timeDuration,"
                        "NECisTestPass,NEClastState,NECtestDuration,NECerrorDetails,"
                        "SC_startTestTime,SC_endTestTime,SC_timeDuration,"
                        "SCisTestPass,SClastState,SCphaseWattHour,SCneutralWattHour,SCphaseEnergy(KVAH),SCneutralEnergy(KVAH),SCphaseReactiveEnergy,SCneutralReactiveEnergy,SCcumulativeEnergy,SCtheoryEnergy,SCpowerWH,SCtestDuration,"
                        "E1startTestTime,E1endTestTime,E1timeDuration,"
                        "E1isTestPass,E1lastState,E1phaseWattHour,E1_phase_error,E1neutralWattHour,E1_neutral_error,E1phaseEnergy(KVAH),E1neutralEnergy(KVAH),E1phaseReactiveEnergy,E1neutralReactiveEnergy,E1cumulativeEnergy,E1theoryEnergy,E1powerWH,E1testDuration,E1ErrorDetails,"
                        "E2startTestTime,E2endTestTime,E2timeDuration,"
                        "E2isTestPass,E2lastState,E2phaseWattHour,E2_phase_error,E2neutralWattHour,E2_neutral_error,E2phaseEnergy(KVAH),E2neutralEnergy(KVAH),E2phaseReactiveEnergy,E2neutralReactiveEnergy,E2cumulativeEnergy,E2theoryEnergy,E2powerWH,E2testDuration,E2ErrorDetails,E2CalibLedPulse,"
                        "NS_startTestTime,NS_endTestTime,NS_timeDuration,"
                        "NSisTestPass,NSlastState,NSnetworkAddress,NSchannelAddress,NSmeterMemoryNumber,NStestDuration,NSerrorDetails,LASloaNumber,LASmfgDate,LASserialNumber,MaxTestDuration\r\n";


QStringList patternlist = {"failedAt" , "functionTestResult" ,"combinedCalibration","phaseCalibration", "neutralCalibration", "lowCurrentTestResult","highCurrentTestResult","startingCurrentTestResult","hvTestResult","megarTestResult","creepTestResult","nicSyncTestResult","laserEngraveResult","meterTmpSerialNumber","meterFinalSerialNumber"};



QStringList FT_Result = {"FT_startTestTime","FT_endTestTime","FT_timeDuration","FT_isTestPass","FT_lastState","FT_errorDetails","FT_coverClosed","FT_magnet1","FT_magnet2","FT_Relay_neutralOff","FT_Relay_neutralOn","FT_Relay_phaseOff","FT_Relay_phaseOn","FT_pushButton","FT_rtcDriftSecond","FT_fetchingVI_neutralCurrent","FT_fetchingVI_phaseCurrent","FT_fetchingVI_voltage","PCBnumber"};
QStringList PHC_Result = {"PHC_startTestTime","PHC_endTestTime","PHC_timeDuration","PHC_isTestPass","PHC_lastState","PHC_errorDetails"};
QStringList NEC_Result = {"NEC_startTestTime","NEC_endTestTime","NEC_timeDuration","NEC_isTestPass","NEC_lastState","NEC_errorDetails"};
QStringList E1_Result = { "E1startTestTime","E1endTestTime","E1timeDuration","E1isTestPass","E1lastState","E1errorDetails","E1CummulativeEnergy","E1meterEnergy","E1neutralEnergy","E1neutralReactiveEnergy","E1neutralWattHour","E1neutralError","E1phaseEnergy","E1phaseReactiveEnergy","E1phaseWattHour","E1phaseError","E1powerWH","E1startingCumlativeEnergy","E1testCurrent","E1testVoltage","E1theoryEnergy","E1timeMs"};
QStringList E2_Result = { "E2startTestTime","E2endTestTime","E2timeDuration","E2isTestPass","E2lastState","E2errorDetails","E2CummulativeEnergy","E2meterEnergy","E2neutralEnergy","E2neutralReactiveEnergy","E2neutralWattHour","E2neutralError","E2phaseEnergy","E2phaseReactiveEnergy","E2phaseWattHour","E2phaseError","E2powerWH","E2startingCumlativeEnergy","E2testCurrent","E2testVoltage","E2theoryEnergy","E2timeMs"};
QStringList SC_Result = {"SC_startTestTime","SC_endTestTime","SC_timeDuration","SC_isTestPass","SC_lastState","SC_errorDetails","SC_CummulativeEnergy","SC_meterEnergy","SC_neutralEnergy","SC_neutralReactiveEnergy","SC_neutralWattHour","E1phaseEnergy","SC_phaseReactiveEnergy","SC_phaseWattHour","SC_powerWH","SC_startingCumlativeEnergy","SC_testCurrent","SC_testVoltage","SC_theoryEnergy","SC_timeMs"};
QStringList NS_Result = {"NS_startTestTime","NS_endTestTime","NS_timeDuration","NS_isTestPass","NS_lastState","NS_errorDetails","NS_channelAddress","NS_meterMemoryNumber","NS_meterNumberPrint","NS_networkAddress","NS_noloadNeutralCurrent","NS_noLoadPhaseCurrent","NS_RFkey"};
QStringList COMB_Result = {"combinedCalibration_startTestTime","combinedCalibration_endTestTime","combinedCalibration_testDuration","combinedCalibration_isTestPass","combinedCalibration_LastState","combinedCalibration_errorDetails"};
QStringList CREEP_Result = {"CP_startTestTime","CP_endTestTime","CP_timeDuration","CP_isTestPass","CP_lastState","CP_errorDetails"};

JsonUtils::JsonUtils()
{

}

void JsonUtils::addheaderlist(const QString &header, QStringList &values)
{
    if(header == "failedAt")
    {
        values << "failedAt";
    }
    else if(header == "functionTestResult")
    {
        for (const QString &val : FT_Result) {

            values << val;
        }
    }
    else if(header == "phaseCalibration")
    {
        for (const QString &val : PHC_Result) {

            values << val;
        }
    }
    else if(header == "neutralCalibration")
    {
        for (const QString &val : NEC_Result) {

            values << val;
        }
    }
    else if(header == "lowCurrentTestResult")
    {
        for (const QString &val : E1_Result) {

            values << val;
        }
    }

    else if(header == "highCurrentTestResult")
    {
        for (const QString &val : E2_Result) {

            values << val;
        }
    }
    else if(header == "startingCurrentTestResult")
    {
        for (const QString &val : SC_Result) {

            values << val;
        }
    }
    else if(header == "hvTestResult")
    {
        values << "hvTestResult";
    }
    else if(header == "megarTestResult")
    {
        values << "IRTestResult";
    }
    else if(header == "nicSyncTestResult")
    {
        for (const QString &val : NS_Result) {

            values << val;
        }
    }
    else if(header == "laserEngraveResult")
    {
        values << "laserEngraveResult_loaNumber" << "laserEngraveResult_mfgDate" << "laserEngraveResult_serialNumber";
    }
    else if(header == "meterTmpSerialNumber")
    {
        values << "meterTmpSerialNumber";
    }
    else if(header == "meterFinalSerialNumber")
    {
        values << "meterFinalSerialNumber";
    }
    else if(header == "combinedCalibration")
    {
        for (const QString &val : COMB_Result) {

            values << val;
        }
    }
    else if(header == "creepTestResult")
    {
        for (const QString &val : CREEP_Result) {

            values << val;
        }
    }

}

void JsonUtils::addRows(QJsonObject &jsonObject,const QString &test, QStringList &values)
{
    if(test == "failedAt")
    {
//        values << jsonObject.value(test).toString();
        if(jsonObject.value(test).toString().size() <= 1)
        {
            QString temp = "";

            if (!jsonObject.value("failedAt").toString().isEmpty()) {
                QStringList testResults = {"functionTestResult","megarTestResult", "hvTestResult", "phaseCalibration", "neutralCalibration", "lowCurrentTestResult", "highCurrentTestResult","startingCurrentTestResult", "creepTestResult","laserEngraveResult","nicSyncTestResult"};

                // Iterate over the test results array
                for (const QString &testResult : testResults) {
                    if(testResult == "hvTestResult"|| testResult == "megarTestResult" || testResult == "phaseCalibration" || testResult == "neutralCalibration") {
                        if (jsonObject.contains(testResult) && !jsonObject.value(testResult).toObject().value("isTestPass").toBool()) {
    //                         values << testResult;
                             temp = testResult;
                             break;
                        }
                     }else{
                        if (jsonObject.contains(testResult) && !jsonObject.value(testResult).toObject().value("common").toObject().value("isTestPass").toBool()) {
    //                         values << testResult;
                            temp = testResult;
                             break;
                        }
                    }

                }
            }else{
    //            values << jsonObject.value("failedAt").toString();
                temp = "";
            }
            values << temp;
        }
        else
        {
            values << jsonObject.value(test).toString();
        }


    }
    if(test == "functionTestResult")
    {
        values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("startTestTime").toString("yyyy-MM-dd HH:mm:ss");
        values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("endTestTime").toString("yyyy-MM-dd HH:mm:ss");
        int currentTestDuration = (jsonObject.value("functionTestResult").toObject().value("common").toObject().value("testDuration").toInt());

        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("functionTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("errorDetails").toString();

        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("coverClosed").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("magnetStat1").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("magnetStat2").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("neutralCurrentOff").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("neutralCurrentOn").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("phaseCurrentOff").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("phaseCurrentOn").toString());
        values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("pushButton").toString());
        values << QString::number(jsonObject.value("functionTestResult").toObject().value("rtc").toObject().value("rtcDriftSecond").toInt());

         values << QString::number(jsonObject.value("functionTestResult").toObject().value("vi").toObject().value("neutralCurrent").toDouble());
         values << QString::number(jsonObject.value("functionTestResult").toObject().value("vi").toObject().value("phaseCurrent").toDouble());
         values << QString::number(jsonObject.value("functionTestResult").toObject().value("vi").toObject().value("voltage").toDouble());

         values << QString::number(jsonObject.value("functionTestResult").toObject().value("pcbNumber").toObject().value("pcbNumber").toInt());

    }
    else if(test == "combinedCalibration")
    {
        values << jsonObject.value("combinedCalibration").toObject().value("startTestTime").toString("yyyy-MM-dd HH:mm:ss");
        values << jsonObject.value("combinedCalibration").toObject().value("endTestTime").toString("yyyy-MM-dd HH:mm:ss");
        values << QString::number(jsonObject.value("combinedCalibration").toObject().value("testDuration").toInt());
        values << (jsonObject.value("combinedCalibration").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("combinedCalibration").toObject().value("lastState").toString();
        values << jsonObject.value("combinedCalibration").toObject().value("errorDetails").toString();
    }
    else if(test == "phaseCalibration")
    {
        values << jsonObject.value("phaseCalibration").toObject().value("startTestTime").toString();
        values << jsonObject.value("phaseCalibration").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("phaseCalibration").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("phaseCalibration").toObject().value("isTestPass").toBool() ?  "True" : "False");
        values << jsonObject.value("phaseCalibration").toObject().value("lastState").toString();
//        values << QString::number(jsonObject.value("phaseCalibration").toObject().value("testDuration").toInt());
        values << jsonObject.value("phaseCalibration").toObject().value("errorDetails").toString();
    }
    else if(test == "neutralCalibration")
    {
        values << jsonObject.value("neutralCalibration").toObject().value("startTestTime").toString();
        values << jsonObject.value("neutralCalibration").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("neutralCalibration").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("neutralCalibration").toObject().value("isTestPass").toBool() ?  "True" : "False");
        values << jsonObject.value("neutralCalibration").toObject().value("lastState").toString();
//        values << QString::number(jsonObject.value("neutralCalibration").toObject().value("testDuration").toInt());
        values << jsonObject.value("neutralCalibration").toObject().value("errorDetails").toString();
    }
    else if(test == "lowCurrentTestResult")
    {
        values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
        values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("meterEnergyWH").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralWattHour").toDouble());

        double E1neutral_Energy = 0;
        double E1theoryEnergy = 0;
        double E1neutral_error = 0;
        E1neutral_Energy = jsonObject.value("lowCurrentTestResult").toObject().value("neutralWattHour").toDouble();
        E1theoryEnergy = jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble();
        E1neutral_error = ((E1neutral_Energy-E1theoryEnergy)/E1theoryEnergy)*100;
        values << QString::number(E1neutral_error);


        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseWattHour").toDouble());

        double E1phase_Energy = 0;
//             double E1theoryEnergy = 0;
        double E1error = 0;

        E1phase_Energy = jsonObject.value("lowCurrentTestResult").toObject().value("phaseWattHour").toDouble();
        E1theoryEnergy = jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble();
        E1error = ((E1phase_Energy-E1theoryEnergy)/E1theoryEnergy)*100;
        values << QString::number(E1error);

        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("powerWH").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("startingCumlativeEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("testCurrent").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("testVoltage").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble());
        values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("timeMS").toDouble());
    }
    else if(test == "highCurrentTestResult")
    {
        values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
        values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("meterEnergyWH").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralWattHour").toDouble());

        double E2neutral_Energy = 0;
        double E2theoryEnergy = 0;
        double E2neutral_error = 0;
        E2neutral_Energy = jsonObject.value("highCurrentTestResult").toObject().value("neutralWattHour").toDouble();
        E2theoryEnergy = jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble();
        E2neutral_error = ((E2neutral_Energy-E2theoryEnergy)/E2theoryEnergy)*100;
        values << QString::number(E2neutral_error);


        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseWattHour").toDouble());

        double E2phase_Energy = 0;
//             double E2theoryEnergy = 0;
        double E2error = 0;
        E2phase_Energy = jsonObject.value("highCurrentTestResult").toObject().value("phaseWattHour").toDouble();
        E2theoryEnergy = jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble();
        E2error = ((E2phase_Energy-E2theoryEnergy)/E2theoryEnergy)*100;
        values << QString::number(E2error);

        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("powerWH").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("startingCumlativeEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("testCurrent").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("testVoltage").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble());
        values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("timeMS").toDouble());

    }
    else if(test == "startingCurrentTestResult")
    {
        values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
        values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("meterEnergyWH").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralWattHour").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseWattHour").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("powerWH").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("startingCumlativeEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("testCurrent").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("testVoltage").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("theoryEnergy").toDouble());
        values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("timeMS").toDouble());

    }
    else if(test == "hvTestResult")
    {
        values << (jsonObject.value("hvTestResult").toObject().value("isTestPass").toBool() ? "True" : "False");
    }
    else if(test == "megarTestResult")
    {
        values << (jsonObject.value("megarTestResult").toObject().value("isTestPass").toBool() ? "True" : "False");
    }
    else if(test == "nicSyncTestResult")
    {
        values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("startTestTime").toString();
        values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("endTestTime").toString();
        int currentTestDuration = (jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("testDuration").toInt());
        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("errorDetails").toString();
        values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("channelAddrss").toInt());
        values << jsonObject.value("nicSyncTestResult").toObject().value("meterMemoryNumber").toString();
        values << jsonObject.value("nicSyncTestResult").toObject().value("meterNumberPrint").toString();
        values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("netowrkAddress").toDouble());
        values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("noLoadNeutralCurrent").toDouble());
        values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("noLoadPhaseCurrent").toDouble());
        values << jsonObject.value("nicSyncTestResult").toObject().value("rfkey").toString();
    }
    else if(test == "laserEngraveResult")
    {
        values << jsonObject.value("laserEngraveResult").toObject().value("loaNumber").toString();
        values << jsonObject.value("laserEngraveResult").toObject().value("mfgDate").toString();
        values << jsonObject.value("laserEngraveResult").toObject().value("serialNumber").toString();
    }
    else if(test == "meterTmpSerialNumber")
    {
        values << QString::number(jsonObject.value("meterTmpSerialNumber").toInt());
    }
    else if(test == "meterFinalSerialNumber")
    {
        values << QString::number(jsonObject.value("meterFinalSerialNumber").toInt());
    }
    else if(test == "creepTestResult")
    {
        values << jsonObject.value("creepTestResult").toObject().value("common").toObject().value("startTestTime").toString("yyyy-MM-dd HH:mm:ss");
        values << jsonObject.value("creepTestResult").toObject().value("common").toObject().value("endTestTime").toString("yyyy-MM-dd HH:mm:ss");
        int currentTestDuration = (jsonObject.value("creepTestResult").toObject().value("common").toObject().value("testDuration").toInt());

        values << QString::number(currentTestDuration);
        maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
        values << (jsonObject.value("creepTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
        values << jsonObject.value("creepTestResult").toObject().value("common").toObject().value("lastState").toString();
        values << jsonObject.value("creepTestResult").toObject().value("common").toObject().value("errorDetails").toString();
    }
}

void JsonUtils::flattenJson(const QJsonObject &jsonObject, QStringList &values)
{
    for (const QString& key : jsonObject.keys()) {
        QJsonValue value = jsonObject[key];
        if (value.isObject()) {
            flattenJson(value.toObject(), values);
        } else {
            values.append(value.toVariant().toString());
        }
    }
}

bool JsonUtils::convertJsonToCSV(QTextStream& in, QTextStream& out, QString fileName)
{
    maxTestDuration = 0;
    int currentTestDuration;
    static bool parseNext = false;
//    bool headingdone = false;
    int lineNumber = 0;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        lineNumber++;

        if(!parseNext){
            if(line.contains("--WatchMe--")&&!line.contains("--WatchMe--laser--"))
            {
                 parseNext = true;
            }


        }
        if(!parseNext)
            continue;

        int index = line.indexOf(jsonLogPattern);
        if(index != -1)
        {

            parseNext = false;
            line = line.mid(5);
            QStringList values;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(line.toLatin1());
            if (!jsonDoc.isObject()) {
              return 1;
            }
            QJsonObject jsonObject = jsonDoc.object();
//            qDebug() << jsonObject;

            QStringList keys = jsonObject.keys();

            QSet<QString> keySet;

             for (const QString &key : keys) {
                 keySet.insert(key);
             }

             if(headingdone == false)
             {
                 headingdone = true;
                 for (const QString &key : patternlist) {
                     if(keySet.contains(key))
                     {
                         qDebug() << key;
                         addheaderlist(key,values);
                     }
                 }

                 for (const QString& value : values) {
                   out << "\"" << value << "\",";
                 }
                 out << "\n";
             }

             values.clear();

             for (const QString &key : patternlist) {
                 if(keySet.contains(key))
                 {
                     addRows(jsonObject,key,values);
                 }
             }




//            flattenJson(jsonObject, values);
//            QJsonObject functionTestResult = jsonObject.value("functionTestResult").toObject();
//            qDebug() << functionTestResult;

//            QJsonObject comman;
//            comman = functionTestResult.value("rtc").toObject();
//            qDebug() << comman;
//            qDebug() << comman.value("rtcDriftSecond");
//            qDebug() << comman.value("rtcDriftSecond").toString();
//            qDebug() << comman.value("rtcDriftSecond").toInt();
//            qDebug() << jsonObject.value("meterFinalSerialNumber").toString();

////


//            if (!jsonObject.value("failedAt").toString().isEmpty()) {
//                QStringList testResults = {"functionTestResult", "phaseCalibration", "neutralCalibration", "lowCurrentTestResult", "highCurrentTestResult","startingCurrentTestResult", "nicSyncTestResult","hvTestResult", "megarTestResult"};

//                // Iterate over the test results array
//                for (const QString &testResult : testResults) {
//                    if(testResult == "hvTestResult"|| testResult == "megarTestResult" || testResult == "phaseCalibration" || testResult == "neutralCalibration") {
//                        if (!jsonObject.value(testResult).toObject().value("isTestPass").toBool()) {
//                             values << testResult;
//                             break;
//                        }
//                     }else{
//                        if (!jsonObject.value(testResult).toObject().value("common").toObject().value("isTestPass").toBool()) {
//                             values << testResult;
//                             break;
//                        }
//                    }

//                }
//            }else{
//                values << jsonObject.value("failedAt").toString();
//            }


//            maxTestDuration = 0;

//            values << QString::number(jsonObject.value("meterTmpSerialNumber").toInt());
//            values << QString::number(jsonObject.value("functionTestResult").toObject().value("pcbNumber").toObject().value("pcbNumber").toInt());
//            values << jsonObject.value("nicSyncTestResult").toObject().value("meterMemoryNumber").toString();
//            values << QString::number(jsonObject.value("meterFinalSerialNumber").toInt());
//            values << QString::number(jsonObject.value("meterFeedDelay").toInt());
//            values << QString::number(jsonObject.value("cycleTime").toInt());
//            QString dateTime =  jsonObject.value("functionTestResult").toObject().value("common").toObject().value("startTestTime").toString("yyyy-MM-dd HH:mm:ss");
////            values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("endTestTime").toString("yyyy-MM-dd HH:mm:ss");
//            QDateTime dateTime1 = QDateTime::fromString(dateTime, Qt::ISODate);
//            QDate date = dateTime1.date();
//            QTime time = dateTime1.time();
//            values << date.toString();
//            values << time.toString();

//            values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("startTestTime").toString("yyyy-MM-dd HH:mm:ss");
//            values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("endTestTime").toString("yyyy-MM-dd HH:mm:ss");
//            currentTestDuration = (jsonObject.value("functionTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("functionTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
//            values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("lastState").toString();
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("coverClosed").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("magnetStat1").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("magnetStat2").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("neutralCurrentOff").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("neutralCurrentOn").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("phaseCurrentOff").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("phaseCurrentOn").toString());
//            values << (jsonObject.value("functionTestResult").toObject().value("functionTest").toObject().value("pushButton").toString());
//            values << QString::number(jsonObject.value("functionTestResult").toObject().value("rtc").toObject().value("rtcDriftSecond").toInt());
////            values << QString::number(jsonObject.value("functionTestResult").toObject().value("common").toObject().value("testDuration").toInt());
////            values << jsonObject.value("functionTestResult").toObject().value("common").toObject().value("errorDetails").toString();

//            values << (jsonObject.value("hvTestResult").toObject().value("isTestPass").toBool() ? "True" : "False");

//            values << (jsonObject.value("megarTestResult").toObject().value("isTestPass").toBool() ? "True" : "False");

//            values << jsonObject.value("phaseCalibration").toObject().value("startTestTime").toString();
//            values << jsonObject.value("phaseCalibration").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("phaseCalibration").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("phaseCalibration").toObject().value("isTestPass").toBool() ?  "True" : "False");
//            values << jsonObject.value("phaseCalibration").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("phaseCalibration").toObject().value("testDuration").toInt());
//            values << jsonObject.value("phaseCalibration").toObject().value("errorDetails").toString();

//            values << jsonObject.value("neutralCalibration").toObject().value("startTestTime").toString();
//            values << jsonObject.value("neutralCalibration").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("neutralCalibration").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("neutralCalibration").toObject().value("isTestPass").toBool() ?  "True" : "False");
//            values << jsonObject.value("neutralCalibration").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("neutralCalibration").toObject().value("testDuration").toInt());
//            values << jsonObject.value("neutralCalibration").toObject().value("errorDetails").toString();

////          "SCisTestPass,SClastState,SCphaseWattHour,SCneutralWattHour,SCphaseEnergy,SCneutralEnergy,SCphaseReactiveEnergy,SCneutralReactiveEnergy,"
////          "SCcumulativeEnergy,SCtheoryEnergy,SCpowerWH"
//            values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
//            values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
//            values << jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseWattHour").toDouble());
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralWattHour").toDouble());
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseEnergy").toDouble()); //VAH
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble()); //VARH
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("theoryEnergy").toDouble());
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("powerWH").toDouble()); //powerWH
//            values << QString::number(jsonObject.value("startingCurrentTestResult").toObject().value("common").toObject().value("testDuration").toDouble());


//            values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
//            values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
//            values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseWattHour").toDouble());
//            double E1phase_Energy = 0;
//            double E1theoryEnergy = 0;
//            double E1error = 0;
//            E1phase_Energy = jsonObject.value("lowCurrentTestResult").toObject().value("phaseWattHour").toDouble();
//            E1theoryEnergy = jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble();
//            E1error = ((E1phase_Energy-E1theoryEnergy)/E1theoryEnergy)*100;
//            values << QString::number(E1error);
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralWattHour").toDouble());
//            double E1neutral_Energy = 0;
////            double E1theoryEnergy = 0;
//            double E1neutral_error = 0;
//            E1neutral_Energy = jsonObject.value("lowCurrentTestResult").toObject().value("neutralWattHour").toDouble();
//            E1theoryEnergy = jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble();
//            E1neutral_error = ((E1neutral_Energy-E1theoryEnergy)/E1theoryEnergy)*100;
//            values << QString::number(E1neutral_error);
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseEnergy").toDouble()); //VAH
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble()); //VARH
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("theoryEnergy").toDouble());
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("powerWH").toDouble()); //powerWH
//            values << QString::number(jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << jsonObject.value("lowCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();


//            values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("startTestTime").toString();
//            values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
//            values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseWattHour").toDouble());
//            double E2phase_Energy = 0;
//            double E2theoryEnergy = 0;
//            double E2error = 0;
//            E2phase_Energy = jsonObject.value("highCurrentTestResult").toObject().value("phaseWattHour").toDouble();
//            E2theoryEnergy = jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble();
//            E2error = ((E2phase_Energy-E2theoryEnergy)/E2theoryEnergy)*100;
//            values << QString::number(E2error);
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralWattHour").toDouble());
//            double E2neutral_Energy = 0;
////            double E1theoryEnergy = 0;
//            double E2neutral_error = 0;
//            E2neutral_Energy = jsonObject.value("highCurrentTestResult").toObject().value("neutralWattHour").toDouble();
//            E2theoryEnergy = jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble();
//            E2neutral_error = ((E2neutral_Energy-E2theoryEnergy)/E2theoryEnergy)*100;
//            values << QString::number(E2neutral_error);
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseEnergy").toDouble()); //VAH
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("phaseReactiveEnergy").toDouble()); //VARH
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("neutralReactiveEnergy").toDouble()); // VAH
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("cumulativeEnergy").toDouble());
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("theoryEnergy").toDouble());
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("powerWH").toDouble()); //powerWH
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();
//            values << QString::number(jsonObject.value("highCurrentTestResult").toObject().value("calibLedPulse").toDouble());

//            values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("startTestTime").toString();
//            values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("endTestTime").toString();
//            currentTestDuration = (jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("testDuration").toInt());
//            values << QString::number(currentTestDuration);
//            maxTestDuration = (maxTestDuration < currentTestDuration) ? currentTestDuration : maxTestDuration;
//            values << (jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("isTestPass").toBool() ? "True" : "False");
//            values << jsonObject.value("nicSyncTestResult").toObject().value("common").toObject().value("lastState").toString();
//            values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("netowrkAddress").toDouble());
//            values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("channelAddrss").toInt());
//            values << jsonObject.value("nicSyncTestResult").toObject().value("meterMemoryNumber").toString();
//            values << QString::number(jsonObject.value("nicSyncTestResult").toObject().value("testDuration").toInt());
//            values << jsonObject.value("highCurrentTestResult").toObject().value("common").toObject().value("errorDetails").toString();

//            values << jsonObject.value("laserEngraveResult").toObject().value("loaNumber").toString();
//            values << jsonObject.value("laserEngraveResult").toObject().value("mfgDate").toString();
//            values << jsonObject.value("laserEngraveResult").toObject().value("serialNumber").toString();
//            values << QString::number(maxTestDuration);

//            values << fileName;
//            values << QString("%1").arg(lineNumber);

            for (const QString& value : values) {
              out << "\"" << value << "\",";
            }
            out << "\n";
        }
    }
    return true;
}

bool JsonUtils::convertJsonFileToCSV(const QString& dbgFilePath, QFile& csvFile)
{
    if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Cannot open csv file";
        return false;
    }

    QTextStream out(&csvFile);
//    out << header;

    QFile file(dbgFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open debug file " << file.errorString();
        return false;
    }

    QTextStream in(&file);
    bool result = convertJsonToCSV(in, out);
    file.close();
    out.flush();
    return result;
}

bool JsonUtils::convertJsonFileDirToCSV(const QString& dbgDirPath, QFile& csvFile)
{
    if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Cannot open csv file";
        return false;
    }

    QTextStream out(&csvFile);
//    out << header;

    QDir dir(dbgDirPath);
    QStringList files = dir.entryList(QDir::Files);
    for(QString&  fileName : files) {
        fileName = dbgDirPath + "/" + fileName;
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Cannot open debug file " << file.errorString();
            return false;
        }

        QTextStream in(&file);
        bool result = convertJsonToCSV(in, out, fileName);
        file.close();
        if (!result) {
            return false;
        }
    }
    out.flush();
    return true;
}


