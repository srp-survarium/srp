void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::~Sound(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this)
{
  Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *pObject; // ecx
  unsigned int RefCount; // eax
  volatile LONG *v4; // edi
  Scaleform::GFx::SoundResource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->pChannel.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pChannel.pObject = (Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v4 = (volatile LONG *)(this->SoundURL.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = this->pSoundResource.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pSoundObject.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
}
