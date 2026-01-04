#include "Translator.hpp"

namespace YimMenu
{
void Translator::InitializeSpanishTranslations()
{
// Main menu categories
m_Translations["Self"] = "Yo";
m_Translations["Vehicle"] = "Vehículo";
m_Translations["Teleport"] = "Teletransporte";
m_Translations["Network"] = "Red";
m_Translations["Players"] = "Jugadores";
m_Translations["World"] = "Mundo";
m_Translations["Recovery"] = "Recuperación";
m_Translations["Settings"] = "Configuración";
m_Translations["Debug"] = "Depuración";

// Common categories
m_Translations["Main"] = "Principal";
m_Translations["Globals"] = "Globales";
m_Translations["Movement"] = "Movimiento";
m_Translations["Tools"] = "Herramientas";
m_Translations["Special Ability"] = "Habilidad Especial";
m_Translations["Wanted"] = "Buscado";
m_Translations["Misc"] = "Varios";
m_Translations["Weapons"] = "Armas";
m_Translations["Outfit Editor"] = "Editor de Atuendo";
m_Translations["Session"] = "Sesión";
m_Translations["Hotkeys"] = "Teclas Rápidas";
m_Translations["GUI"] = "Interfaz";
m_Translations["Businesses"] = "Negocios";
m_Translations["Casino"] = "Casino";
m_Translations["General"] = "General";
m_Translations["IPLs"] = "IPLs";
m_Translations["Join"] = "Unirse";
m_Translations["Bounty"] = "Recompensa";
m_Translations["Toxic"] = "Tóxico";

// Vehicle submenu
m_Translations["Spawn Vehicle"] = "Generar Vehículo";
m_Translations["Vehicle Editor"] = "Editor de Vehículo";
m_Translations["Saved Vehicles"] = "Vehículos Guardados";

// Teleport submenu
m_Translations["Custom Locations"] = "Ubicaciones Personalizadas";

// Settings submenu
m_Translations["GUI Settings"] = "Configuración de Interfaz";
m_Translations["Customize"] = "Personalizar";

// Common UI elements
m_Translations["Godmode"] = "Modo Dios";
m_Translations["Keep Fixed"] = "Mantener Reparado";
m_Translations["Lower Stance"] = "Bajar Altura";
m_Translations["Level"] = "Nivel";
}

void Translator::Initialize()
{
if (m_Initialized)
return;

InitializeSpanishTranslations();
m_Initialized = true;
}

std::string Translator::Get(const std::string& key)
{
if (!m_Initialized)
Initialize();

auto it = m_Translations.find(key);
if (it != m_Translations.end())
return it->second;

// Return original key if no translation found
return key;
}
}
