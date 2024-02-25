#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "./settings.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SectionSettingValue>("menulayer-section");
};

