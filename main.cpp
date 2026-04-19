#include <Geode/Geode.hpp>
#include <Geode/modify/CCLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Слой для счетчика FPS
class $modify(FPSLayer, CCLayer) {
    CCLabelBMFont* m_fpsLabel;

    bool init() {
        if (!CCLayer::init()) return false;

        // Создаем текст (используем стандартный золотой шрифт)
        m_fpsLabel = CCLabelBMFont::create("FPS: 60", "goldFont.fnt");
        m_fpsLabel->setID("fps-label"_spr);
        
        // Позиция в углу
        m_fpsLabel->setAnchorPoint({0, 0});
        m_fpsLabel->setPosition({5, 5});
        
        // Берем масштаб из настроек mod.json
        float scale = Mod::get()->getSettingValue<double>("font-size");
        m_fpsLabel->setScale(scale);

        this->addChild(m_fpsLabel, 1000);
        this->scheduleUpdate();

        return true;
    }

    void update(float dt) {
        CCLayer::update(dt);
        if (m_fpsLabel) {
            int fps = static_cast<int>(std::round(1.0f / dt));
            m_fpsLabel->setString(fmt::format("FPS: {}", fps).c_str());
        }
    }
};

// Модификация главного меню
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Логируем запуск от твоего имени
        log::info("WERTX Mod: Меню инициализировано успешно.");
        
        return true;
    }
};
