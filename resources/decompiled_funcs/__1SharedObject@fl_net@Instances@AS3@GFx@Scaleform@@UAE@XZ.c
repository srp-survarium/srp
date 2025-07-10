void __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::~SharedObject(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax

  v2 = (volatile LONG *)(this->LocalPath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  pObject = this->DataObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->DataObj.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
      return;
    }
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}
