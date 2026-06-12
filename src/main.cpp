#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <vector>
#include <cmath>

using namespace geode::prelude;

struct AIBot {
    int generation = 1;
    float bestFitness = 0.0f;
    float currentFitness = 0.0f;
    std::vector<float> jumpPositions;
    std::vector<float> bestJumpPositions;
    bool isTraining = true;
} g_bot;

class $modify(MyPlayLayer, PlayLayer) {
    CCLabelBMFont* m_aiStatusLabel;

    bool init(GJGameLevel* level, bool useReplay, bool dontRunOnMainThread) {
        if (!PlayLayer::init(level, useReplay, dontRunOnMainThread)) return false;

        // In-game HUD overlay to watch the bot live
        m_fields->m_aiStatusLabel = CCLabelBMFont::create("AI Bot Initializing...", "bigFont.fnt");
        m_fields->m_aiStatusLabel->setPosition({10, 10});
        m_fields->m_aiStatusLabel->setAnchorPoint({0, 0});
        m_fields->m_aiStatusLabel->setScale(0.4f);
        m_fields->m_aiStatusLabel->setZOrder(999);
        this->addChild(m_fields->m_aiStatusLabel);

        if (g_bot.jumpPositions.empty()) {
            g_bot.jumpPositions.push_back(100.0f);
        }

        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);
        if (!g_bot.isTraining || !m_player1) return;

        float currentX = m_player1->m_position.x;
        g_bot.currentFitness = currentX;

        // Update UI text every frame
        std::string statusStr = fmt::format(
            "GEN: {} | BEST DIST: {:.1f} | CURRENT DIST: {:.1f} | JUMPS: {}", 
            g_bot.generation, g_bot.bestFitness, g_bot.currentFitness, g_bot.jumpPositions.size()
        );
        m_fields->m_aiStatusLabel->setString(statusStr.c_str());

        // Bot checks its DNA array to see if it should jump at this X coordinate
        for (float jumpX : g_bot.jumpPositions) {
            if (std::abs(currentX - jumpX) < 5.0f) {
                this->pushButton(PlayerButton::Jump, true);
                this->runAction(CCSequence::create(
                    CCDelayTime::create(0.1f),
                    CCCallFunc::create(this, callfunc_selector(MyPlayLayer::releaseJump)),
                    nullptr
                ));
            }
        }
    }

    void releaseJump() {
        this->releaseButton(PlayerButton::Jump, true);
    }

    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        PlayLayer::destroyPlayer(player, obstacle);

        if (g_bot.isTraining) {
            // Evolve: If it got further, save the path
            if (g_bot.currentFitness > g_bot.bestFitness) {
                g_bot.bestFitness = g_bot.currentFitness;
                g_bot.bestJumpPositions = g_bot.jumpPositions;
            }

            // Mutation: Mutate the path by placing a jump right before where it just died
            g_bot.jumpPositions = g_bot.bestJumpPositions;
            float deathX = g_bot.currentFitness;
            g_bot.jumpPositions.push_back(deathX - 42.0f); 
            g_bot.generation++;
        }
    }
};
