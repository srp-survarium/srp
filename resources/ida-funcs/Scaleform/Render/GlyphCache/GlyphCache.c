void __thiscall Scaleform::Render::GlyphCache::GlyphCache(
        Scaleform::Render::GlyphCache *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::GlyphTextureMapper *Textures; // ecx
  int v4; // ebp
  unsigned int *p_Pitch; // eax
  unsigned int *p_Capacity; // ecx
  Scaleform::Render::TextMeshProvider *v7; // ecx
  Scaleform::Render::VectorGlyphShape *p_Notifier; // ecx
  int v9; // ecx
  unsigned int i; // eax
  Scaleform::Log *GlobalLog; // eax

  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::GlyphCache_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::CacheBase_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  this->Scaleform::Render::GlyphCacheConfig::__vftable = (Scaleform::Render::GlyphCacheConfig_vtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::GlyphCache_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>'};
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::CacheBase_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->Scaleform::Render::GlyphCacheConfig::__vftable = (Scaleform::Render::GlyphCacheConfig_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::GlyphCacheConfig'};
  Scaleform::Render::GlyphCacheParams::GlyphCacheParams(&this->Param, 1u, 0x400u, 0x400u, 0x30u);
  this->ScaleU = 0.0;
  this->ScaleV = 0.0;
  Textures = this->Textures;
  this->ShadowQuality = 1.0;
  this->pHeap = heap;
  this->pRenderer = 0;
  this->pFillMan = 0;
  this->pTexMan = 0;
  this->TextureWidth = 0;
  this->TextureHeight = 0;
  this->MaxNumTextures = 0;
  this->MaxSlotHeight = 0;
  this->SlotPadding = 0;
  v4 = 31;
  p_Pitch = &this->Textures[0].Data.Plane0.Pitch;
  do
  {
    Textures->Valid = 0;
    *(p_Pitch - 11) = 0;
    *(p_Pitch - 10) = 0;
    *(p_Pitch - 9) = 0;
    *(p_Pitch - 8) = 0;
    *(p_Pitch - 7) = 0;
    *(p_Pitch - 6) = 0;
    *((_BYTE *)p_Pitch - 20) = 0;
    *((_BYTE *)p_Pitch - 19) = 0;
    *((_WORD *)p_Pitch - 9) = 1;
    *(p_Pitch - 4) = (unsigned int)(p_Pitch - 2);
    *(p_Pitch - 3) = 0;
    *(p_Pitch - 1) = 0;
    *p_Pitch = 0;
    p_Pitch[1] = 0;
    p_Pitch[2] = 0;
    *(p_Pitch - 2) = 0;
    p_Pitch[3] = 0;
    p_Pitch[4] = 0;
    p_Pitch[5] = 0;
    *((_BYTE *)p_Pitch + 24) = 0;
    p_Pitch[7] = 0;
    ++Textures;
    p_Pitch += 20;
    --v4;
  }
  while ( v4 >= 0 );
  Scaleform::Render::GlyphQueue::GlyphQueue(&this->Queue);
  this->Method = TU_DirectMap;
  this->UpdatePacker.Width = 0;
  this->UpdatePacker.Height = 0;
  this->UpdatePacker.LastX = 0;
  this->UpdatePacker.LastY = 0;
  this->UpdatePacker.LastMaxHeight = 0;
  this->UpdateBuffer.pObject = 0;
  this->GlyphsToUpdate.Size = 0;
  this->GlyphsToUpdate.NumPages = 0;
  this->GlyphsToUpdate.MaxPages = 0;
  this->GlyphsToUpdate.Pages = 0;
  this->RectsToUpdate.Data = 0;
  this->RectsToUpdate.Size = 0;
  this->RectsToUpdate.Capacity = 0;
  if ( this == (Scaleform::Render::GlyphCache *)-2924 )
    p_Capacity = 0;
  else
    p_Capacity = &this->RectsToUpdate.Capacity;
  this->TextInUse.Root.pPrev = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  this->TextInUse.Root.pNext = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  if ( this == (Scaleform::Render::GlyphCache *)-2932 )
    v7 = 0;
  else
    v7 = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.4;
  this->TextInPin.Root.pPrev = v7;
  this->TextInPin.Root.pNext = v7;
  this->Notifier.__vftable = (Scaleform::Render::GlyphCache::EvictNotifier_vtbl *)&Scaleform::Render::GlyphCache::EvictNotifier::`vftable';
  this->pFontHandleManager.pObject = 0;
  this->pRQCaches = 0;
  if ( this == (Scaleform::Render::GlyphCache *)-2960 )
    p_Notifier = 0;
  else
    p_Notifier = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
  this->VectorGlyphShapeList.Root.pPrev = p_Notifier;
  this->VectorGlyphShapeList.Root.pNext = p_Notifier;
  this->VectorGlyphCache.pTable = 0;
  this->pSolidFill.pObject = 0;
  this->pMaskFill.pObject = 0;
  Scaleform::Render::GlyphFitter::GlyphFitter(&this->Fitter, heap, 1024);
  Scaleform::Render::Rasterizer::Rasterizer(&this->Ras, heap);
  Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(&this->ScanlineFilter, 0.8888889, 0.22222222, 0.022222223);
  this->RasterData.Data.Data = 0;
  this->RasterData.Data.Size = 0;
  this->RasterData.Data.Policy.Capacity = 0;
  this->RasterDataSrc.Data.Data = 0;
  this->RasterDataSrc.Data.Size = 0;
  this->RasterDataSrc.Data.Policy.Capacity = 0;
  this->KnockOutCopy.Data.Data = 0;
  this->KnockOutCopy.Data.Size = 0;
  this->KnockOutCopy.Data.Policy.Capacity = 0;
  this->RasterPitch = 0;
  this->BlurStack.Data.Data = 0;
  this->BlurStack.Data.Size = 0;
  this->BlurStack.Data.Policy.Capacity = 0;
  this->BlurSum.Data.Data = 0;
  this->BlurSum.Data.Size = 0;
  this->BlurSum.Data.Policy.Capacity = 0;
  this->LHeap1.pHeap = heap;
  this->LHeap1.pPagePool = 0;
  this->LHeap1.pLastPage = 0;
  this->LHeap1.MaxPages = 0;
  this->LHeap1.Granularity = 0x2000;
  this->LHeap2.pHeap = heap;
  this->LHeap2.Granularity = 0x2000;
  this->LHeap2.pPagePool = 0;
  this->LHeap2.pLastPage = 0;
  this->LHeap2.MaxPages = 0;
  Scaleform::Render::Stroker::Stroker(&this->mStroker, &this->LHeap2);
  this->TmpPath1.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::VertexPath::`vftable';
  this->TmpPath1.Vertices.pHeap = &this->LHeap1;
  this->TmpPath1.Vertices.Size = 0;
  this->TmpPath1.Vertices.NumPages = 0;
  this->TmpPath1.Vertices.MaxPages = 0;
  this->TmpPath1.Vertices.Pages = 0;
  this->TmpPath1.Paths.pHeap = &this->LHeap1;
  this->TmpPath1.Paths.Size = 0;
  this->TmpPath1.Paths.NumPages = 0;
  this->TmpPath1.Paths.MaxPages = 0;
  this->TmpPath1.Paths.Pages = 0;
  this->TmpPath2.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::VertexPath::`vftable';
  this->TmpPath2.Vertices.pHeap = &this->LHeap2;
  this->TmpPath2.Vertices.Size = 0;
  this->TmpPath2.Vertices.NumPages = 0;
  this->TmpPath2.Vertices.MaxPages = 0;
  this->TmpPath2.Vertices.Pages = 0;
  this->TmpPath2.Paths.pHeap = &this->LHeap2;
  this->TmpPath2.Paths.Size = 0;
  this->TmpPath2.Paths.NumPages = 0;
  this->TmpPath2.Paths.MaxPages = 0;
  this->TmpPath2.Paths.Pages = 0;
  this->RasterizationCount = 0;
  this->RasterCacheWarning = 1;
  this->RasterTooBigWarning = 1;
  this->Notifier.pCache = this;
  v9 = 0;
  for ( i = 0; i < 0x100; ++i )
  {
    if ( i > FontSizeRamp[v9 + 1] )
      ++v9;
    this->FontSizeMap[i] = v9;
  }
  GlobalLog = Scaleform::Log::GetGlobalLog();
  this->pLog = GlobalLog;
  if ( !GlobalLog )
    this->pLog = Scaleform::Log::GetDefaultLog();
}
