Scaleform::Render::FontProviderWinAPI *__thiscall Scaleform::Render::FontProviderWinAPI::`scalar deleting destructor'(
        Scaleform::Render::FontProviderWinAPI *this,
        char a2)
{
  Scaleform::Render::FontProviderWinAPI::~FontProviderWinAPI(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
