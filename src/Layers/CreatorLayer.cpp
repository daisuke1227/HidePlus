#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/binding/CreatorLayer.hpp>
#include "../settings.hpp"
#include "../utils.hpp"

using namespace geode::prelude;


void hidebtns(auto replace,auto btnslayer) {
	remove("CreatorLayer-Featured",replace,btnslayer->getChildByID("featured-button"));
	remove("CreatorLayer-Lists",replace,btnslayer->getChildByID("lists-button"));
	remove("CreatorLayer-Paths",replace,btnslayer->getChildByID("paths-button"));
	remove("CreatorLayer-Map-Packs",replace,btnslayer->getChildByID("map-packs-button"));
	remove("CreatorLayer-Search",replace,btnslayer->getChildByID("search-button"));
	remove("CreatorLayer-Map",replace,btnslayer->getChildByID("map-button"));
	remove("CreatorLayer-Daily",replace,btnslayer->getChildByID("daily-button"));
	remove("CreatorLayer-Weekly",replace,btnslayer->getChildByID("weekly-button"));
	remove("CreatorLayer-Event",replace,btnslayer->getChildByID("event-button"));
	remove("CreatorLayer-Gauntles",replace,btnslayer->getChildByID("gauntles-button"));
	remove("CreatorLayer-Create",replace,btnslayer->getChildByID("create-button"));
	remove("CreatorLayer-Saved",replace,btnslayer->getChildByID("saved-button"));
	remove("CreatorLayer-Scores",replace,btnslayer->getChildByID("scores-button"));
	remove("CreatorLayer-Quests",replace,btnslayer->getChildByID("quests-button"));
	remove("CreatorLayer-Versus",replace,btnslayer->getChildByID("versus-button"));
};

class $modify(CreatorLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("MenuLayer::init", -26902);
    }
	
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto mod = Mod::get();

		if (!mod->getSettingValue<bool>("hideplus-enable")) return true;
	
		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("bottom-menu-re"_spr);
		this->addChild(bottomMenuReplacement);

		hide("CreatorLayer-background",bottomMenuReplacement,this->getChildByID("background"));
		remove("CreatorLayer-LeftCorner",bottomMenuReplacement,this->getChildByID("bottom-left-corner"));
		if(auto creatorbtns = this->getChildByID("creator-buttons-menu")) {
			hidebtns(bottomMenuReplacement,creatorbtns);
		};

		return true;
	}
};
