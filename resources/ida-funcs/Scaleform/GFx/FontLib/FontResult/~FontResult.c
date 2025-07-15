void __thiscall Scaleform::GFx::FontLib::FontResult::~FontResult(Scaleform::GFx::FontLib::FontResult *this)
{
  Scaleform::GFx::MovieDef *pMovieDef; // ecx
  Scaleform::GFx::FontResource *pFontResource; // ecx

  pMovieDef = this->pMovieDef;
  if ( pMovieDef )
    Scaleform::GFx::Resource::Release(pMovieDef);
  pFontResource = this->pFontResource;
  if ( pFontResource )
    Scaleform::GFx::Resource::Release(pFontResource);
}
