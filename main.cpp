#include <Geode/Geode.hpp>
#include <Geode/modify/CCLayer.hpp>

using namespace geode::prelude;

class $modify(FPSLayer, CCLayer) {
    CCLabelBMFont* m_label;

    bool init() {
        if (!CCLayer::init()) return false;

        m_label = CCLabelBMFont::create("FPS: --", "goldFont.fnt");
        m_label->setScale(0.5f);
        m_label->setAnchorPoint({0, 0});
        m_label->setPosition({10, 10});
        m_label->setID("fps-label"_spr);

        this->addChild(m_label, 1000);
        this->scheduleUpdate();

        return true;
    }

    void update(float dt) {
        CCLayer::update(dt);
        if (m_label) {
            int fps = static_cast<int>(1.f / dt);
            m_label->setString(fmt::format("FPS: {}", fps).c_str());
        }
    }
};
