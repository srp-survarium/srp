bool __thiscall Scaleform::GFx::Text::StyleManager::ParseCSS(
        Scaleform::GFx::Text::StyleManager *this,
        char *buffer,
        unsigned int len)
{
  wchar_t *v4; // esi
  unsigned int v5; // eax
  bool v6; // bl

  v4 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * len + 2, 0);
  v5 = Scaleform::UTF8Util::DecodeString(v4, buffer, len);
  v6 = Scaleform::GFx::Text::StyleManager::ParseCSSImpl<wchar_t>(this, v4, v5);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  return v6;
}


// attributes: thunk
bool __thiscall Scaleform::GFx::Text::StyleManager::ParseCSS(
        Scaleform::GFx::Text::StyleManager *this,
        const wchar_t *buffer,
        unsigned int len)
{
  return Scaleform::GFx::Text::StyleManager::ParseCSSImpl<wchar_t>(this, buffer, len);
}
