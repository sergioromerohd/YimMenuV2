# Translation and UI Customization Notes

## Cambios Realizados / Changes Made

### 1. Tema de Color Azul / Blue Color Theme ✅

Se han cambiado los colores principales del menú de verde a azul en el archivo `src/core/frontend/manager/styles/Themes.cpp`.

Los siguientes elementos ahora usan tonos azules en lugar de verdes:
- Botones (Buttons)
- Pestañas (Tabs)
- Encabezados (Headers)
- Controles deslizantes (Sliders)
- Casillas de verificación (Checkmarks)
- Separadores (Separators)
- Controles de redimensión (Resize grips)
- Gráficos (Plots)
- Navegación (Navigation highlights)

### 2. Traducción al Español / Spanish Translation ⚠️

La traducción completa de la interfaz al español requeriría cambios extensos en el código base, ya que actualmente **no existe un sistema de localización/traducción** implementado.

## Cómo Implementar Traducciones / How to Implement Translations

Para implementar un sistema completo de traducciones, se necesitaría:

### Opción 1: Sistema de Traducción Simple

1. **Crear un sistema de traducción centralizado:**
   ```cpp
   // src/core/localization/Translator.hpp
   class Translator {
   public:
       static std::string Get(const std::string& key);
       static void SetLanguage(const std::string& lang);
   private:
       static std::unordered_map<std::string, std::string> translations;
       static std::string currentLanguage;
   };
   ```

2. **Crear archivos de traducción:**
   ```json
   // translations/es_ES.json
   {
       "MENU_SELF": "Yo",
       "MENU_TELEPORT": "Teletransporte",
       "MENU_VEHICLE": "Vehículo",
       "MENU_WEAPON": "Armas",
       "MENU_NETWORK": "Red",
       "MENU_WORLD": "Mundo",
       "MENU_MISC": "Varios",
       "MENU_SETTINGS": "Configuración",
       ...
   }
   ```

3. **Reemplazar strings hardcodeados:**
   - Actualmente hay cientos de strings en inglés distribuidos en múltiples archivos
   - Cada string necesitaría ser reemplazado con una llamada a `Translator::Get("KEY")`
   - Esto afectaría archivos en:
     - `src/game/frontend/submenus/` (todos los submenús)
     - `src/game/frontend/items/` (elementos del menú)
     - `src/core/frontend/` (componentes de frontend)

### Opción 2: Sistema de Traducción con gettext

Usar gettext (estándar de la industria):
1. Marcar strings con `_("text")` macro
2. Extraer strings con `xgettext`
3. Traducir con archivos .po/.mo
4. Cargar traducciones en runtime

## Alcance del Cambio / Change Scope

**Estimación de archivos afectados para traducción completa:**
- ~50+ archivos de submenús
- ~30+ archivos de items
- ~20+ archivos de componentes de UI
- Total: **100+ archivos necesitarían modificaciones**

**Tiempo estimado:** Varios días de trabajo para una traducción completa.

## Estado Actual / Current Status

✅ **Completado:**
- Cambio de tema de color de verde a azul

⚠️ **Pendiente (requiere implementación extensa):**
- Sistema de localización/traducción
- Traducción de strings de UI
- Selector de idioma en configuración

## Próximos Pasos Sugeridos / Suggested Next Steps

Si deseas implementar la traducción al español:

1. Decidir entre sistema de traducción simple vs gettext
2. Implementar el sistema de traducción base
3. Crear archivo de traducción español (es_ES.json o es_ES.po)
4. Migrar strings gradualmente por secciones:
   - Primero: Menú principal
   - Segundo: Submenús más usados
   - Tercero: Resto de la UI
5. Agregar selector de idioma en Settings

## Personalización Adicional / Additional Customization

Los usuarios pueden personalizar los colores del menú en tiempo de ejecución:
1. Abrir el menú
2. Ir a Settings → GUI Settings → Customize
3. Modificar colores individuales
4. Los cambios se guardan en `%APPDATA%\YimMenuV2\themes.json`

---

## Nota Final / Final Note

**Este documento fue creado como parte de la solicitud de cambio de color a azul y traducción al español.**

**Estado / Status:**
- ✅ **Cambio de color:** Completado
- ⚠️ **Traducción al español:** Requiere desarrollo adicional significativo más allá del alcance de cambios mínimos
