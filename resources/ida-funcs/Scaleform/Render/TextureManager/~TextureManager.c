void __thiscall Scaleform::Render::TextureManager::~TextureManager(Scaleform::Render::TextureManager *this)
{
  unsigned int v2; // edi
  Scaleform::Render::TextureFormat *v3; // ecx
  Scaleform::ArrayLH<Scaleform::Render::TextureFormat *,2,Scaleform::ArrayDefaultPolicy> *p_TextureFormats; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  v2 = 0;
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::TextureManager_vtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>'};
  for ( this->Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
        v2 < this->TextureFormats.Data.Size;
        ++v2 )
  {
    v3 = this->TextureFormats.Data.Data[v2];
    if ( v3 )
      ((void (__thiscall *)(Scaleform::Render::TextureFormat *, int))v3->~Scaleform::Render::TextureFormat)(v3, 1);
  }
  p_TextureFormats = &this->TextureFormats;
  if ( this->TextureFormats.Data.Size )
  {
    if ( (this->TextureFormats.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_TextureFormats->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TextureFormats->Data.Data);
        p_TextureFormats->Data.Data = 0;
      }
      this->TextureFormats.Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->TextureFormats.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->TextureFormats.Data,
      &this->TextureFormats,
      0);
  }
  this->TextureFormats.Data.Size = 0;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TextureFormats->Data.Data);
  Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(&this->ImageUpdates);
  pObject = (Scaleform::RefCountVImpl *)this->pLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v6 = (Scaleform::RefCountVImpl *)this->pTextureCache.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->ServiceCommandInstance);
  this->Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::Render::StateData::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
