#include <Geode/modify/FMODAudioEngine.hpp>
#include "Manager.hpp"
#include "Utils.hpp"

using namespace geode::prelude;

class $modify (MyFMODAudioEngine, FMODAudioEngine) {
	static void onModify(auto& self) {
		(void) self.setHookPriority("FMODAudioEngine::playEffect", -1999);
	}
	void playEffect(gd::string p0, float p1, float p2, float p3) {
		Manager* manager = Manager::getSharedInstance();
		std::string desiredPath = manager->filthyPath.string();
		if (!manager->filthyGameplay && GJBaseGameLayer::get()) {
			if (PlayLayer::get() && !CCScene::get()->getChildByType<PauseLayer>(0)) desiredPath = p0;
			if (LevelEditorLayer::get() && !CCScene::get()->getChildByType<EditorPauseLayer>(0)) desiredPath = p0;
		}
		if (!manager->filthyPath.string().empty()) {
			if (!std::filesystem::exists(manager->filthyPath)) desiredPath = p0;
			if (!Utils::isSupportedFMODExtension(manager->filthyPath.string())) desiredPath = p0;
		}
		if (!Utils::modEnabled() || !manager->filth) desiredPath = p0;
		if (manager->filthyPath.string().empty()) {
			#ifdef GEODE_IS_ANDROID
			desiredPath = "sfx/s4451.ogg";
			#else
			desiredPath = p0;
			#endif
		}
		return FMODAudioEngine::playEffect(desiredPath, p1, p2, p3);
	}
};