void __thiscall Scaleform::GFx::AS3::SoundObject::~SoundObject(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::ASSoundIntf *v3; // ebx
  Scaleform::GFx::Sprite *v4; // eax
  Scaleform::GFx::CharacterHandle *v5; // edi
  Scaleform::GFx::SoundResource *v6; // ecx
  Scaleform::Sound::SoundSample *v7; // edi
  Scaleform::GFx::AS3::Instances::fl_media::Sound *v8; // ecx
  unsigned int RefCount; // eax

  pObject = this->pTargetHandle.pObject;
  v3 = &this->Scaleform::GFx::ASSoundIntf;
  this->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::SoundObject_vtbl *)&Scaleform::GFx::AS3::SoundObject::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>'};
  this->Scaleform::GFx::ASSoundIntf::__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::AS3::SoundObject::`vftable'{for `Scaleform::GFx::ASSoundIntf'};
  if ( pObject )
  {
    v4 = (Scaleform::GFx::Sprite *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, this->pMovieRoot);
    if ( v4 )
    {
      if ( ((v4->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
           & 0x400) != 0
          ? (unsigned int)v4
          : 0) != 0 )
        Scaleform::GFx::Sprite::DetachSoundObject(
          (v4->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
         & 0x400) != 0
        ? v4
        : 0,
          &this->Scaleform::GFx::ASSoundIntf);
    }
  }
  v5 = this->pTargetHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v5);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  v6 = this->pResource.pObject;
  if ( v6 )
    Scaleform::GFx::Resource::Release(v6);
  v7 = this->pSample.pObject;
  if ( v7 && InterlockedExchangeAdd(&v7->RefCount.Value, -1) == 1 )
    ((void (__thiscall *)(Scaleform::Sound::SoundSample *, int))v7->~Scaleform::Sound::SoundSample)(v7, 1);
  v8 = this->pSound.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->pSound.pObject = (Scaleform::GFx::AS3::Instances::fl_media::Sound *)((char *)v8 - 1);
      v3->__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::ASSoundIntf::`vftable';
      Scaleform::RefCountImplCore::~RefCountImplCore(this);
      return;
    }
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
    }
  }
  v3->__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::ASSoundIntf::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
