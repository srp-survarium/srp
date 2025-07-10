bool __thiscall Scaleform::GFx::Text::StyleManager::ParseCSSImpl<wchar_t>(
        Scaleform::GFx::Text::StyleManager *this,
        const wchar_t *buffer,
        unsigned int len)
{
  Scaleform::GFx::Text::TextStyleParserHandler<wchar_t> handler; // [esp+4h] [ebp-44h] BYREF
  Scaleform::Array<Scaleform::Render::Text::Style *,2,Scaleform::ArrayDefaultPolicy> selectors; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::Text::CSSParser<wchar_t> parser; // [esp+18h] [ebp-30h] BYREF
  bool lena; // [esp+50h] [ebp+8h]

  parser.SelectorName.Type = TT_Unknown;
  parser.PropertyName.Type = TT_Unknown;
  handler.pManager = this;
  parser.SelectorName.pBase = 0;
  parser.SelectorName.Length = 0;
  memset(&parser.PropertyName.pBase, 0, 22);
  memset(&selectors, 0, sizeof(selectors));
  handler.__vftable = (Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>_vtbl *)&Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::`vftable';
  lena = Scaleform::GFx::Text::CSSParser<wchar_t>::Parse(&parser, buffer, len, &handler, &selectors);
  handler.__vftable = (Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>_vtbl *)&Scaleform::GFx::Text::CSSHandler<wchar_t>::`vftable';
  if ( selectors.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, selectors.Data.Data);
  if ( parser.PropertyValue.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, parser.PropertyValue.Data.Data);
  return lena;
}
