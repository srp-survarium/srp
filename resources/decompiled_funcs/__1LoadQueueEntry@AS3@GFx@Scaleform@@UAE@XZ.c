void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::~LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // edi
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v5; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v9; // ecx
  unsigned int v10; // eax
  volatile LONG *v11; // esi

  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable';
  if ( this->NotifyLoadInitCInterface.pObject )
  {
    pObject = (Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->NotifyLoadInitCInterface.pObject = 0;
  }
  v3 = (Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = this->mBytes.pObject;
  if ( v4 )
  {
    if ( this->mBytes.Owner )
    {
      this->mBytes.Owner = 0;
      if ( v4->Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
    }
    this->mBytes.pObject = 0;
  }
  this->mBytes.Owner = 0;
  v5 = this->mURLRequest.pObject;
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      this->mURLRequest.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)v5 - 1);
    }
    else
    {
      RefCount = v5->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
  v7 = this->mURLLoader.pObject;
  if ( v7 )
  {
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      this->mURLLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)((char *)v7 - 1);
    }
    else
    {
      v8 = v7->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
  v9 = this->mLoader.pObject;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      this->mLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)((char *)v9 - 1);
    }
    else
    {
      v10 = v9->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v10) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  v11 = (volatile LONG *)(this->URL.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v11 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v11);
}
