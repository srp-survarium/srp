bool __thiscall Scaleform::Render::GlyphTextureMapper::Create(
        Scaleform::Render::GlyphTextureMapper *this,
        unsigned int method,
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::TextureManager *texMan,
        Scaleform::Render::PrimitiveFillManager *fillMan,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        const Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::GlyphTextureImage *pObject; // ecx
  Scaleform::Render::RawImage *v10; // eax
  Scaleform::Render::RawImage *v11; // ecx
  Scaleform::Render::RawImage *v12; // edi
  Scaleform::Render::RawImage *v13; // ecx
  Scaleform::Render::GlyphTextureImage *v14; // eax
  Scaleform::Render::GlyphTextureImage *v15; // ecx
  bool v16; // bl
  Scaleform::GFx::Resource *v17; // eax
  Scaleform::Render::PrimitiveFill *v18; // eax
  Scaleform::Render::PrimitiveFill *v19; // ecx
  Scaleform::Render::PrimitiveFill *v20; // edi
  Scaleform::Render::PrimitiveFillData fillData; // [esp+10h] [ebp-18h] BYREF

  this->pTexMan = texMan;
  this->Method = method;
  if ( method == 2 )
  {
    pObject = this->pTexImg.pObject;
    if ( pObject )
      pObject->Release(pObject);
    this->pTexImg.pObject = 0;
    v10 = Scaleform::Render::RawImage::Create(Image_A8, 1u, size, 0x10u, heap, 0);
    v11 = this->pRawImg.pObject;
    v12 = v10;
    if ( v11 )
      v11->Release(v11);
    this->pRawImg.pObject = v12;
  }
  else
  {
    v13 = this->pRawImg.pObject;
    if ( v13 )
      v13->Release(v13);
    this->pRawImg.pObject = 0;
    v14 = Scaleform::Render::GlyphTextureImage::Create(heap, texMan, cache, textureId, size, method != 1 ? 192 : 32);
    v15 = this->pTexImg.pObject;
    v12 = (Scaleform::Render::RawImage *)v14;
    if ( v15 )
      v15->Release(v15);
    this->pTexImg.pObject = (Scaleform::Render::GlyphTextureImage *)v12;
  }
  v16 = v12 != 0;
  if ( v12 )
  {
    v17 = (Scaleform::GFx::Resource *)v12->GetTexture(v12, texMan);
    Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
      &fillData,
      PrimFill_UVTextureAlpha_VColor,
      &Scaleform::Render::RasterGlyphVertex::Format,
      v17,
      (Scaleform::Render::ImageFillMode)3,
      0,
      0);
    v18 = Scaleform::Render::PrimitiveFillManager::CreateFill(fillMan, &fillData);
    v19 = this->pFill.pObject;
    v20 = v18;
    if ( v19 )
      Scaleform::RefCountNTSImpl::Release(v19);
    this->pFill.pObject = v20;
    Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&fillData);
  }
  this->Valid = v16;
  return v16;
}
