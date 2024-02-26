#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "./settings.hpp"

using namespace geode::prelude;

void remove(std::string ee, CCMenu* bottomMenuReplacement, CCLayer* thise, std::string menuitem1, std::string menuitem2) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(ee)) return;
	CCNode* achievements;
	if(menuitem2 == "") {achievements = thise->getChildByID(menuitem1)->getChildByID(menuitem2);}
	else {achievements = thise->getChildByID(menuitem1);}
	achievements->setVisible(false);
	achievements->removeFromParent();
	bottomMenuReplacement->addChild(achievements);
}

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto mod = Mod::get();

		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("coop.bottom-menu-re");
		this->addChild(bottomMenuReplacement);

		remove("menulayer-achievements",bottomMenuReplacement,this,"bottom-menu","achievements-button");

		/*if(mod->getSettingValue<bool>("menulayer-achievements")) {
			auto achievements = this->getChildByID("bottom-menu")->getChildByID("achievements-button");
			achievements->setVisible(false);
			achievements->removeFromParent();
			bottomMenuReplacement->addChild(achievements);
		}*/

		remove("menulayer-stats",bottomMenuReplacement,this,"bottom-menu","stats-button");

		return true;
	}
};