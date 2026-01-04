# Spanish Translations - Active Implementation

## Estado / Status

✅ **Sistema de traducción implementado y activo** / Translation system implemented and active

## Traducciones Activas / Active Translations

### Menú Principal / Main Menu (9 categorías)

| Inglés / English | Español / Spanish |
|------------------|-------------------|
| Self | Yo |
| Vehicle | Vehículo |
| Teleport | Teletransporte |
| Network | Red |
| Players | Jugadores |
| World | Mundo |
| Recovery | Recuperación |
| Settings | Configuración |
| Debug | Depuración |

### Categorías Comunes / Common Categories (~25 items)

| Inglés / English | Español / Spanish |
|------------------|-------------------|
| Main | Principal |
| Globals | Globales |
| Movement | Movimiento |
| Tools | Herramientas |
| Special Ability | Habilidad Especial |
| Wanted | Buscado |
| Misc | Varios |
| Weapons | Armas |
| Session | Sesión |
| Hotkeys | Teclas Rápidas |
| GUI | Interfaz |
| Businesses | Negocios |
| Casino | Casino |
| General | General |
| Join | Unirse |
| Bounty | Recompensa |
| Toxic | Tóxico |

### Submenús de Vehículo / Vehicle Submenus

| Inglés / English | Español / Spanish |
|------------------|-------------------|
| Spawn Vehicle | Generar Vehículo |
| Vehicle Editor | Editor de Vehículo |
| Saved Vehicles | Vehículos Guardados |

### Submenús de Configuración / Settings Submenus

| Inglés / English | Español / Spanish |
|------------------|-------------------|
| GUI Settings | Configuración de Interfaz |
| Customize | Personalizar |

### Elementos de UI Comunes / Common UI Elements

| Inglés / English | Español / Spanish |
|------------------|-------------------|
| Godmode | Modo Dios |
| Keep Fixed | Mantener Reparado |
| Lower Stance | Bajar Altura |
| Level | Nivel |
| Custom Locations | Ubicaciones Personalizadas |
| Outfit Editor | Editor de Atuendo |

## Archivos Modificados / Modified Files

- `src/core/localization/Translator.hpp` - Sistema de traducción / Translation system
- `src/core/localization/Translator.cpp` - Traducciones al español / Spanish translations
- `src/game/frontend/Menu.cpp` - Inicialización / Initialization
- `src/game/frontend/submenus/*.cpp` - 9 archivos de submenú actualizados / 9 submenu files updated

## Cómo Funciona / How It Works

El sistema usa la macro `TR("text")` para traducir cualquier texto:

```cpp
// Antes / Before:
Submenu::Submenu("Vehicle", ICON_FA_CAR)

// Ahora / Now:
Submenu::Submenu(TR("Vehicle"), ICON_FA_CAR)
// Muestra / Shows: "Vehículo"
```

Si una traducción no existe, el sistema devuelve el texto original en inglés automáticamente.

## Próximos Pasos Sugeridos / Suggested Next Steps

Para expandir las traducciones / To expand translations:

1. **Agregar más categorías** - Edit `Translator.cpp`, add entries to `m_Translations`
2. **Traducir descripciones de comandos** - Update command initialization files
3. **Traducir mensajes y notificaciones** - Update notification system
4. **Traducir diálogos** - Update dialog text throughout the codebase

## Ejemplo de Cómo Agregar Traducciones / Example: How to Add Translations

Edita `src/core/localization/Translator.cpp`:

```cpp
void Translator::InitializeSpanishTranslations()
{
    // ... existing translations ...
    
    // Add new translations:
    m_Translations["Your English Text"] = "Tu Texto en Español";
}
```

Luego usa en el código / Then use in code:
```cpp
auto myCategory = std::make_shared<Category>(TR("Your English Text"));
```

---

**Total de traducciones activas:** ~50 strings traducidos y funcionando en la interfaz del menú.

**Total active translations:** ~50 translated strings working in the menu interface.
