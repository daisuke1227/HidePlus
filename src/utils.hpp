#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

static void remove(std::string ee, CCMenu* bottomMenuReplacement, CCNode* achievements) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(ee)) return;
    if(!achievements) return;
    auto parent = achievements->getParent();
	achievements->setVisible(false);
	achievements->removeFromParent();
	bottomMenuReplacement->addChild(achievements);
    if (auto parentAsLayer = static_cast<CCMenu*>(parent)) parent->updateLayout();
}
static void hide(std::string ee, CCMenu* bottomMenuReplacement, CCNode* achievements) {
	auto mod = Mod::get();
	if(!mod->getSettingValue<bool>(ee)) return;
    if(!achievements) return;
	achievements->setVisible(false);
}
