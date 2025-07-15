void __thiscall Scaleform::GFx::FontDataBound::FontDataBound(
        Scaleform::GFx::FontDataBound *this,
        Scaleform::GFx::Resource *pfont,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  const Scaleform::GFx::TextureGlyphData *v4; // edi
  Scaleform::GFx::TextureGlyphData *v5; // eax
  Scaleform::GFx::TextureGlyphData *v6; // eax
  Scaleform::GFx::TextureGlyphData *v7; // edi
  Scaleform::GFx::TextureGlyphData *pObject; // ecx
  int v9; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::TextureGlyphBinder binder; // [esp+Ch] [ebp-8h] BYREF

  this->__vftable = (Scaleform::GFx::FontDataBound_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::FontDataBound_vtbl *)&Scaleform::Render::Font::`vftable';
  this->RefCount = 1;
  this->Ascent = *(float *)&pfont->pLib;
  this->Descent = *(float *)&pfont[1].__vftable;
  this->Leading = *(float *)&pfont[1].RefCount.Value;
  this->Flags = (unsigned int)pfont[1].pLib;
  this->LowerCaseTop = (__int16)pfont[2].__vftable;
  this->UpperCaseTop = HIWORD(pfont[2].__vftable);
  this->hRef.pManager.Value = 0;
  this->hRef.pFontHandle = 0;
  this->__vftable = (Scaleform::GFx::FontDataBound_vtbl *)&Scaleform::GFx::FontDataBound::`vftable';
  Scaleform::RefCountImpl::AddRef(pfont);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  this->pTGData.pObject = 0;
  v4 = (const Scaleform::GFx::TextureGlyphData *)pfont->__vftable[2].GetResourceReport(pfont);
  v9 = 261;
  v5 = (Scaleform::GFx::TextureGlyphData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             44,
                                             &v9);
  if ( v5 )
  {
    Scaleform::GFx::TextureGlyphData::TextureGlyphData(v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  pObject = this->pTGData.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  binder.ResBinding = pbinding;
  this->pTGData.pObject = v7;
  binder.__vftable = (Scaleform::GFx::TextureGlyphBinder_vtbl *)&Scaleform::GFx::TextureGlyphBinder::`vftable';
  Scaleform::GFx::TextureGlyphData::VisitTextureGlyphs(v7, &binder);
}
