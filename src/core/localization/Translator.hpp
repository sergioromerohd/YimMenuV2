#pragma once
#include <string>
#include <unordered_map>

namespace YimMenu
{
class Translator
{
private:
static inline std::unordered_map<std::string, std::string> m_Translations;
static inline bool m_Initialized = false;

static void InitializeSpanishTranslations();

public:
static void Initialize();
static std::string Get(const std::string& key);
};
}

// Helper macro for easier translation
#define TR(key) YimMenu::Translator::Get(key)
