Scaleform::Render::ExternalFontWinAPI *__thiscall Scaleform::Render::ExternalFontWinAPI::`vector deleting destructor'(
        Scaleform::Render::ExternalFontWinAPI *this,
        char a2)
{
  Scaleform::Render::ExternalFontWinAPI::~ExternalFontWinAPI(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
