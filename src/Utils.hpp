#pragma once

#define SDI "weebify.separate_dual_icons"
#define BEST_IN_PERCENTAGE "best-in-percentage_enabled"

using namespace geode::prelude;

namespace Utils {
	template<class T> T getSetting(const std::string_view setting);
	bool getBool(const std::string_view setting);
	int64_t getInt(const std::string_view setting);
	double getDouble(const std::string_view setting);
	std::string getString(const std::string_view setting, bool isPath = false);
	ccColor3B getColor(const std::string_view setting);
	ccColor4B getColorAlpha(const std::string_view setting);
	bool modEnabled();
	
	bool isModLoaded(const std::string& modID);
	Mod* getMod(const std::string& modID);
	std::string getModVersion(Mod* mod);

	PlayerObject* getSelectedPlayerObjectToModfy(const PlayLayer* pl = PlayLayer::get());

	std::string getNodeName(CCObject* node);
	#ifdef GEODE_IS_ANDROID
	void openSettings(CCObject* sender = nullptr);
	void addButtonToNode(CCNode* node, CCLayer* layer, cocos2d::SEL_MenuHandler callback);
	#endif

	bool isSupportedFMODExtension(const std::string& path);
}