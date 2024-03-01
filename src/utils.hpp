#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

void remove(std::string ee, CCMenu* bottomMenuReplacement, CCNode* achievements) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(ee)) return;
    if(!achievements) return;
	achievements->setVisible(false);
	achievements->removeFromParent();
	bottomMenuReplacement->addChild(achievements);
}
void hide(std::string ee, CCMenu* bottomMenuReplacement, CCNode* achievements) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(ee)) return;
    if(!achievements) return;
	achievements->setVisible(false);
}