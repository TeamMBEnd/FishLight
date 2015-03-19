#ifndef _DETERMINEDSTAGE_H_
#define _DETERMINEDSTAGE_H_

#include <string>

class DeterminedStage{
public:
	static void init(){
		stageName = "";
		determinedStageFailePath = "ParameterPlist/Array.plist";
		stageNum = 0;
	};
	static std::string determinedStageFailePath;
	static std::string stageName;
	static int stageNum;

	static void set(){
		std::string filePath[] =
		{
			"ParameterPlist/Stage1.plist", "ParameterPlist/Stage2.plist", "ParameterPlist/Stage3.plist",
			"ParameterPlist/Stage4.plist", "ParameterPlist/Stage5.plist", "ParameterPlist/Stage6.plist",
			"ParameterPlist/Stage7.plist", "ParameterPlist/Stage8.plist", "ParameterPlist/Stage9.plist",
			"ParameterPlist/Stage10.plist", "ParameterPlist/Stage11.plist", "ParameterPlist/Stage12.plist",
		};

		determinedStageFailePath = filePath[stageNum];
	}

private:
  	
};

#endif
