#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "./settings.hpp"

using namespace geode::prelude;

SettingNode* SectionSettingValue::createNode(float width) {return SectionSettingNode::create(this, width);}

$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SectionSettingValue>("hideplus-section", "none");
	Mod::get()->addCustomSetting<SectionSettingValue>("menulayer-section", "none");
};

