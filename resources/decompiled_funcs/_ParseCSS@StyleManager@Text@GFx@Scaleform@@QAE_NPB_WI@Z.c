// attributes: thunk
bool __thiscall Scaleform::GFx::Text::StyleManager::ParseCSS(
        Scaleform::GFx::Text::StyleManager *this,
        const wchar_t *buffer,
        unsigned int len)
{
  return Scaleform::GFx::Text::StyleManager::ParseCSSImpl<wchar_t>(this, buffer, len);
}
