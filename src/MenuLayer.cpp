#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "./settings.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto mod = Mod::get();

		if(mod->getSettingValue<bool>("menulayer-achievements")) {
			this->getChildByID("buttom-menu")->getChildByID("achievements-button")->setVisible(false);
		}

		return true;
	}
};