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


		return true;
	}
};
