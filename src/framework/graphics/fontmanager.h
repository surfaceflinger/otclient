/*
 * Copyright (c) 2010-2022 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include "bitmapfont.h"

 //@bindsingleton g_fonts
class FontManager
{
public:
    void terminate();
    void clearFonts();

    bool importFont(const std::string& file);

    bool fontExists(const std::string_view fontName);
    BitmapFontPtr getFont(const std::string_view fontName);

    BitmapFontPtr getCreatureNameFont() { return m_creatureNameFont; }
    BitmapFontPtr getAnimatedTextFont() { return m_animatedTextFont; }
    BitmapFontPtr getStaticTextFont() { return m_staticTextFont; }
    BitmapFontPtr getWidgetTextFont() { return m_widgetTextFont; }

    void setCreatureNameFont(const std::string_view fontName) { m_creatureNameFont = getFont(fontName); }
    void setAnimatedTextFont(const std::string_view fontName) { m_animatedTextFont = getFont(fontName); }
    void setStaticTextFont(const std::string_view fontName) { m_staticTextFont = getFont(fontName); }
    void setWidgetTextFont(const std::string_view fontName) { m_widgetTextFont = getFont(fontName); }

private:
    std::vector<BitmapFontPtr> m_fonts;
    BitmapFontPtr m_creatureNameFont;
    BitmapFontPtr m_animatedTextFont;
    BitmapFontPtr m_staticTextFont;
    BitmapFontPtr m_widgetTextFont;
};

extern FontManager g_fonts;
