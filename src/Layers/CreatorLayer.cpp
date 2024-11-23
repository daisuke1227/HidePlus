#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/binding/CreatorLayer.hpp>
#include "../utils.hpp"

using namespace geode::prelude;


void hidebtns(auto replace,auto btnslayer) {
	remove("creatorlayer-featured",replace,btnslayer->getChildByID("featured-button"));
	remove("creatorlayer-lists",replace,btnslayer->getChildByID("lists-button"));
	remove("creatorlayer-paths",replace,btnslayer->getChildByID("paths-button"));
	remove("creatorlayer-mappacks",replace,btnslayer->getChildByID("map-packs-button"));
	remove("creatorlayer-search",replace,btnslayer->getChildByID("search-button"));
	remove("creatorlayer-map",replace,btnslayer->getChildByID("map-button"));
	remove("creatorlayer-daily",replace,btnslayer->getChildByID("daily-button"));
	remove("creatorlayer-weekly",replace,btnslayer->getChildByID("weekly-button"));
	remove("creatorlayer-event",replace,btnslayer->getChildByID("event-button"));
	remove("creatorlayer-gauntlets",replace,btnslayer->getChildByID("gauntlets-button"));
	remove("creatorlayer-create",replace,btnslayer->getChildByID("create-button"));
	remove("creatorlayer-saved",replace,btnslayer->getChildByID("saved-button"));
	remove("creatorlayer-scores",replace,btnslayer->getChildByID("scores-button"));
	remove("creatorlayer-quests",replace,btnslayer->getChildByID("quests-button"));
	remove("creatorlayer-versus",replace,btnslayer->getChildByID("versus-button"));
};

class $modify(CreatorLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("CreatorLayer::init", -26902);
    }
	
	bool init() {
		if (!CreatorLayer::init()) {
			return false;
		}

		auto mod = Mod::get();

		if (!mod->getSettingValue<bool>("hideplus-enable")) return true;
	
		auto bottomMenuReplacement = CCMenu::create();
		bottomMenuReplacement->setVisible(false);
		bottomMenuReplacement->setID("replacer"_spr);
		this->addChild(bottomMenuReplacement);

		hide("creatorlayer-background",bottomMenuReplacement,this->getChildByID("background"));
		remove("creatorlayer-leftcorner",bottomMenuReplacement,this->getChildByID("bottom-left-corner"));
		remove("creatorlayer-leftcorner",bottomMenuReplacement,this->getChildByID("top-left-corner"));
		if(auto creatorbtns = this->getChildByID("creator-buttons-menu")) {
			hidebtns(bottomMenuReplacement,creatorbtns);
		};
		if(auto topr = this->getChildByID("top-right-menu")) {
			remove("creatorlayer-Vault",bottomMenuReplacement,topr->getChildByID("vault-button"));
		}
		else {
			remove("creatorlayer-Vault",bottomMenuReplacement,this->getChildByIDRecursive("vault-button"));
		}
		if(auto botmr = this->getChildByID("bottom-right-menu")) {
			remove("creatorlayer-Treasure-Room",bottomMenuReplacement,botmr->getChildByID("treasure-room-button"));
		}
		else {
			remove("creatorlayer-Treasure-Room",bottomMenuReplacement,this->getChildByIDRecursive("treasure-room-button"));
		}
		return true;
	}
};
