#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "../settings.hpp"
#include "../utils.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("MenuLayer::init", -26902);
    }
	
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto mod = Mod::get();

		if (!mod->getSettingValue<bool>("hideplus-enable")) return false;

		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("coop.bottom-menu-re");
		this->addChild(bottomMenuReplacement);

		if (Loader::get()->getLoadedMod("beat.click-sound") && !Loader::get()->getLoadedMod("geode.node-ids")) return false;


		remove("menulayer-achievements",bottomMenuReplacement,this->getChildByID("bottom-menu")->getChildByID("achievements-button"));
		remove("menulayer-stats",bottomMenuReplacement,this->getChildByID("bottom-menu")->getChildByID("stats-button"));
		remove("menulayer-newgrounds",bottomMenuReplacement,this->getChildByID("bottom-menu")->getChildByID("newgrounds-button"));

		hide("menulayer-social",bottomMenuReplacement,this->getChildByID("social-media-menu"));
		hide("menulayer-title",bottomMenuReplacement,this->getChildByID("main-title"));
		hide("menulayer-moregames",bottomMenuReplacement,this->getChildByID("more-games-menu"));
		hide("menulayer-profile",bottomMenuReplacement,this->getChildByID("profile-menu"));
		hide("menulayer-username",bottomMenuReplacement,this->getChildByID("player-username"));
		remove("menulayer-daily",bottomMenuReplacement,this->getChildByID("right-side-menu")->getChildByID("daily-chest-button"));
		remove("menulayer-garage",bottomMenuReplacement,this->getChildByID("main-menu")->getChildByID("icon-kit-button"));
		remove("menulayer-build",bottomMenuReplacement,this->getChildByID("main-menu")->getChildByID("editor-button"));
		remove("menulayer-play",bottomMenuReplacement,this->getChildByID("main-menu")->getChildByID("play-button"));
		
		if (Loader::get()->getLoadedMod("iristraa.spinoffsubtitles")) {
			hide("menulayer-title",bottomMenuReplacement,this->getChildByID("meltdown-title"));
			hide("menulayer-title",bottomMenuReplacement,this->getChildByID("world-title"));
			hide("menulayer-title",bottomMenuReplacement,this->getChildByID("subzero-title"));
			hide("menulayer-title",bottomMenuReplacement,this->getChildByID("twopointtwo-title"));
			hide("menulayer-title",bottomMenuReplacement,this->getChildByID("lite-title"));
		}


		return true;
	}
};
