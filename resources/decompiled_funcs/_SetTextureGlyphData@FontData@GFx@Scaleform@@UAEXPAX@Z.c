void __thiscall Scaleform::GFx::FontData::SetTextureGlyphData(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::TextureGlyphData *pvdata)
{
  Scaleform::GFx::TextureGlyphData *pObject; // ecx

  if ( pvdata )
    ++pvdata->RefCount;
  pObject = this->pTGData.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pTGData.pObject = pvdata;
}
