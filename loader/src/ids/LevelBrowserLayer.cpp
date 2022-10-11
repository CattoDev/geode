#include <Geode/Modify.hpp>
#include <Geode/Bindings.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/ui/EnterLayerEvent.hpp>
#include "AddIDs.hpp"

USE_GEODE_NAMESPACE();

class $modify(LevelBrowserLayer) {
    bool init(GJSearchObject* search) {
        std::cout << __FUNCTION__ << "\n";

        if (!LevelBrowserLayer::init(search))
            return false;

        std::cout << "setting ids\n";
        
        this->setID("LevelBrowserLayer");

        if (auto menu = getChildOfType<CCMenu>(this, 0)) {
            menu->setID("go-back-menu");
            setIDSafe(menu, 0, "back-button");
        }

        if (search->m_searchType == SearchType::MyLevels) {
            if (auto menu = getChildOfType<CCMenu>(this, 1)) {
                menu->setID("new-level-menu");
                setIDSafe(menu, 0, "new-level-button");

                if (auto myLevelsBtn = setIDSafe(menu, 1, "my-levels-button")) {
                    detachIntoOwnMenu(this, myLevelsBtn, "my-levels-menu", 
                        ColumnLayout::create(5.f, 0.f)->setAlignment(Alignment::End)
                    );
                }

                menu->setLayout(
                    ColumnLayout::create(5.f, 0.f)->setAlignment(Alignment::End)
                );
            }
        }

        EnterLayerEvent("LevelBrowserLayer", this).post();

        return true;
    }
};
