void __thiscall Scaleform::Render::GlyphCache::~GlyphCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::PrimitiveFill *pObject; // ecx
  Scaleform::Render::PrimitiveFill *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::Render::Texture::UpdateDesc *Data; // eax
  Scaleform::Render::RawImage *v6; // ecx
  $5BC0278F55994A57ED32D3AA213E1041 *v7; // edi
  Scaleform::RefCountNTSImpl *pNext; // ecx
  Scaleform::Render::GlyphSlot *v9; // ecx
  Scaleform::Render::GlyphSlot *v10; // ecx
  Scaleform::Render::GlyphSlot *v11; // ebx
  int v12; // [esp+1Ch] [ebp-4h]

  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::GlyphCache_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>'};
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::CacheBase_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->Scaleform::Render::GlyphCacheConfig::__vftable = (Scaleform::Render::GlyphCacheConfig_vtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::GlyphCacheConfig'};
  Scaleform::Render::GlyphCache::Destroy(this);
  this->TmpPath2.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->TmpPath1.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->mStroker.__vftable = (Scaleform::Render::Stroker_vtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap1);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->BlurSum.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->BlurStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->KnockOutCopy.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RasterDataSrc.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RasterData.Data.Data);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Ras.LHeap);
  this->Ras.__vftable = (Scaleform::Render::Rasterizer_vtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Fitter.LHeap);
  this->Fitter.__vftable = (Scaleform::Render::GlyphFitter_vtbl *)&Scaleform::Render::TessBase::`vftable';
  pObject = this->pMaskFill.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = this->pSolidFill.pObject;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>(&this->VectorGlyphCache);
  v4 = (Scaleform::RefCountVImpl *)this->pFontHandleManager.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Data = this->RectsToUpdate.Data;
  this->Notifier.__vftable = (Scaleform::Render::GlyphCache::EvictNotifier_vtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->GlyphsToUpdate);
  v6 = this->UpdateBuffer.pObject;
  if ( v6 )
    v6->Release(v6);
  Scaleform::Render::GlyphQueue::~GlyphQueue(&this->Queue);
  v12 = 31;
  v7 = &this->Queue.ActiveSlots.Root.4;
  do
  {
    pNext = (Scaleform::RefCountNTSImpl *)v7[-20].pNext;
    v7 -= 20;
    if ( pNext )
      Scaleform::RefCountNTSImpl::Release(pNext);
    v9 = v7[-1].pNext;
    if ( v9 )
      ((void (__thiscall *)(Scaleform::Render::GlyphSlot *))v9->pPrev->pRoot)(v9);
    v10 = v7[-2].pNext;
    if ( v10 )
      ((void (__thiscall *)(Scaleform::Render::GlyphSlot *))v10->pPrev->pRoot)(v10);
    Scaleform::Render::ImageData::freePlanes((Scaleform::Render::ImageData *)&v7[-12]);
    v11 = v7[-8].pNext;
    if ( v11 && InterlockedExchangeAdd((volatile LONG *)v11, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
    --v12;
  }
  while ( v12 >= 0 );
  this->Scaleform::Render::GlyphCacheConfig::__vftable = (Scaleform::Render::GlyphCacheConfig_vtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::CacheBase_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
