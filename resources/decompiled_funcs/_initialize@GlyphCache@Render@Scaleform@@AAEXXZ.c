void __thiscall Scaleform::Render::GlyphCache::initialize(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextureManager *v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned int TextureHeight; // ebp
  unsigned int NumTextures; // edi
  unsigned int MaxSlotHeight; // ebx
  unsigned int TextureWidth; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  char v11; // cl
  char i; // bp
  unsigned int v13; // eax
  unsigned int SlotPadding; // ecx
  double Width; // st6
  char v16; // al
  unsigned int v17; // ebx
  Scaleform::Render::RawImage *v18; // eax
  Scaleform::Render::RawImage *pObject; // ecx
  Scaleform::Render::RawImage *v20; // edi
  unsigned int v21; // edi
  Scaleform::Render::GlyphTextureMapper *Textures; // ebp
  unsigned int v23; // ecx
  Scaleform::MemoryHeap *v24; // edx
  Scaleform::Render::GlyphCache::TextureUpdateMethod Method; // eax
  Scaleform::Render::FontCacheHandleManager *v26; // eax
  Scaleform::Render::FontCacheHandleManager *v27; // edi
  Scaleform::MemoryHeap *v28; // ebp
  Scaleform::RefCountVImpl *v29; // ecx
  Scaleform::Render::PrimitiveFillManager *v30; // ecx
  Scaleform::Render::PrimitiveFill *v31; // eax
  Scaleform::Render::PrimitiveFill *v32; // ecx
  Scaleform::Render::PrimitiveFill *v33; // edi
  Scaleform::Render::PrimitiveFill *v34; // eax
  Scaleform::Render::PrimitiveFill *v35; // ecx
  Scaleform::Render::PrimitiveFill *v36; // edi
  Scaleform::Render::RQCacheInterface *v37; // eax
  const Scaleform::Render::VertexFormat **p_pFormat; // esi
  int j; // edi
  Scaleform::RefCountVImpl *v40; // ecx
  const Scaleform::Render::VertexFormat **v41; // esi
  int k; // edi
  Scaleform::RefCountVImpl *v43; // ecx
  Scaleform::Render::PrimitiveFillManager *pFillMan; // [esp-10h] [ebp-68h]
  Scaleform::MemoryHeap *pHeap; // [esp-8h] [ebp-60h]
  bool fenceWaitOnFull; // [esp+10h] [ebp-48h]
  unsigned int texUpdWidth; // [esp+14h] [ebp-44h]
  unsigned int texUpdHeight[2]; // [esp+18h] [ebp-40h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [esp+20h] [ebp-38h] BYREF
  Scaleform::Render::PrimitiveFillData fillDataMask; // [esp+28h] [ebp-30h] BYREF
  Scaleform::Render::PrimitiveFillData fillDataSolid; // [esp+40h] [ebp-18h] BYREF

  Scaleform::Render::GlyphCache::Destroy(this);
  v2 = this->pRenderer->GetTextureManager(this->pRenderer);
  v3 = this->Param.TexUpdWidth;
  v4 = this->Param.TexUpdHeight;
  TextureHeight = this->Param.TextureHeight;
  NumTextures = this->Param.NumTextures;
  MaxSlotHeight = this->Param.MaxSlotHeight;
  this->pTexMan = v2;
  TextureWidth = this->Param.TextureWidth;
  texUpdWidth = v3;
  LOBYTE(v3) = this->Param.FenceWaitOnFullCache;
  texUpdHeight[0] = v4;
  fenceWaitOnFull = v3;
  if ( TextureWidth >= 0x40 )
    v9 = TextureWidth - 1;
  else
    v9 = 63;
  v10 = 63;
  if ( TextureHeight >= 0x40 )
    v10 = TextureHeight - 1;
  v11 = 0;
  for ( i = 0; v9; v9 >>= 1 )
    ++v11;
  for ( ; v10; v10 >>= 1 )
    ++i;
  if ( NumTextures > 0x20 )
    NumTextures = 32;
  v13 = 1 << v11;
  SlotPadding = this->Param.SlotPadding;
  this->TextureWidth = v13;
  this->TextureHeight = 1 << i;
  this->MaxNumTextures = NumTextures;
  this->MaxSlotHeight = MaxSlotHeight;
  this->SlotPadding = SlotPadding;
  size.Width = 1 << i;
  this->ScaleU = 1.0 / (double)v13;
  Width = (double)(int)size.Width;
  if ( 1 << i < 0 )
    Width = Width + 4294967300.0;
  this->ScaleV = 1.0 / Width;
  this->ShadowQuality = this->Param.ShadowQuality;
  if ( NumTextures )
  {
    Scaleform::Render::GlyphQueue::Init(
      &this->Queue,
      &this->Notifier,
      0,
      NumTextures,
      this->Param.TextureWidth,
      this->Param.TextureHeight,
      MaxSlotHeight,
      fenceWaitOnFull);
    v16 = this->pTexMan->GetTextureUseCaps(this->pTexMan, Image_A8);
    if ( v16 >= 0 )
    {
      if ( (v16 & 0x20) != 0 )
      {
        v17 = texUpdHeight[0];
        this->UpdatePacker.Width = texUpdWidth;
        this->UpdatePacker.Height = v17;
        this->UpdatePacker.LastX = 0;
        this->UpdatePacker.LastY = 0;
        pHeap = this->pHeap;
        this->UpdatePacker.LastMaxHeight = 0;
        this->Method = TU_MultipleUpdate;
        size.Width = texUpdWidth;
        size.Height = v17;
        v18 = Scaleform::Render::RawImage::Create(Image_A8, 1u, &size, 0, pHeap, 0);
        pObject = this->UpdateBuffer.pObject;
        v20 = v18;
        if ( pObject )
          pObject->Release(pObject);
        this->UpdateBuffer.pObject = v20;
      }
      else
      {
        this->Method = TU_WholeImage;
      }
    }
    else
    {
      this->Method = TU_DirectMap;
    }
    v21 = 0;
    if ( this->MaxNumTextures )
    {
      Textures = this->Textures;
      do
      {
        v23 = this->TextureHeight;
        v24 = this->pHeap;
        texUpdHeight[0] = this->TextureWidth;
        pFillMan = this->pFillMan;
        Method = this->Method;
        texUpdHeight[1] = v23;
        Scaleform::Render::GlyphTextureMapper::Create(
          Textures++,
          Method,
          v24,
          this->pTexMan,
          pFillMan,
          this,
          v21++,
          (const Scaleform::Render::Size<unsigned long> *)texUpdHeight);
      }
      while ( v21 < this->MaxNumTextures );
    }
  }
  if ( !this->pFontHandleManager.pObject )
  {
    v26 = (Scaleform::Render::FontCacheHandleManager *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         56,
                                                         0);
    v27 = v26;
    if ( v26 )
    {
      v28 = this->pHeap;
      v26->__vftable = (Scaleform::Render::FontCacheHandleManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v26->RefCount = 1;
      v26->__vftable = (Scaleform::Render::FontCacheHandleManager_vtbl *)&Scaleform::Render::FontCacheHandleManager::`vftable';
      Scaleform::Lock::Lock(&v26->FontLock, 0);
      v27->Fonts[0].Root.pPrev = (Scaleform::Render::FontCacheHandle *)v27->Fonts;
      v27->Fonts[0].Root.pNext = (Scaleform::Render::FontCacheHandle *)v27->Fonts;
      v27->Fonts[1].Root.pPrev = (Scaleform::Render::FontCacheHandle *)&v27->Fonts[1];
      v27->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&v27->Fonts[1];
      v27->pRenderHeap = v28;
      v27->pCache = this;
    }
    else
    {
      v27 = 0;
    }
    v29 = (Scaleform::RefCountVImpl *)this->pFontHandleManager.pObject;
    if ( v29 )
      Scaleform::RefCountImpl::Release(v29);
    this->pFontHandleManager.pObject = v27;
  }
  v30 = this->pFillMan;
  fillDataSolid.Type = PrimFill_VColor_EAlpha;
  fillDataSolid.SolidColor.Raw = 0;
  fillDataSolid.FillModes[0].Fill = 0;
  fillDataSolid.FillModes[1].Fill = 0;
  fillDataSolid.Textures[0].pObject = 0;
  fillDataSolid.Textures[1].pObject = 0;
  fillDataSolid.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  fillDataMask.Type = PrimFill_Mask;
  fillDataMask.SolidColor.Raw = 0;
  fillDataMask.FillModes[0].Fill = 0;
  fillDataMask.FillModes[1].Fill = 0;
  fillDataMask.Textures[0].pObject = 0;
  fillDataMask.Textures[1].pObject = 0;
  fillDataMask.pFormat = &Scaleform::Render::VertexXY16i::Format;
  v31 = Scaleform::Render::PrimitiveFillManager::CreateFill(v30, &fillDataSolid);
  v32 = this->pSolidFill.pObject;
  v33 = v31;
  if ( v32 )
    Scaleform::RefCountNTSImpl::Release(v32);
  this->pSolidFill.pObject = v33;
  v34 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pFillMan, &fillDataMask);
  v35 = this->pMaskFill.pObject;
  v36 = v34;
  if ( v35 )
    Scaleform::RefCountNTSImpl::Release(v35);
  this->pMaskFill.pObject = v36;
  v37 = this->pRenderer->GetRQCacheInterface(this->pRenderer);
  this->pRQCaches = v37;
  v37->pCaches[1] = &this->Scaleform::Render::CacheBase;
  p_pFormat = &fillDataMask.pFormat;
  for ( j = 1; j >= 0; --j )
  {
    v40 = (Scaleform::RefCountVImpl *)*--p_pFormat;
    if ( v40 )
      Scaleform::RefCountImpl::Release(v40);
  }
  v41 = &fillDataSolid.pFormat;
  for ( k = 1; k >= 0; --k )
  {
    v43 = (Scaleform::RefCountVImpl *)*--v41;
    if ( v43 )
      Scaleform::RefCountImpl::Release(v43);
  }
}
