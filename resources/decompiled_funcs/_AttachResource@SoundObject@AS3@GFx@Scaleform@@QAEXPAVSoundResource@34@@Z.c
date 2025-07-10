void __thiscall Scaleform::GFx::AS3::SoundObject::AttachResource(
        Scaleform::GFx::AS3::SoundObject *this,
        Scaleform::GFx::SoundResource *presource)
{
  Scaleform::RefCountVImpl *v3; // edi
  Scaleform::Sound::SoundRenderer *v4; // ebx
  Scaleform::GFx::SoundResource *pObject; // ecx
  Scaleform::Sound::SoundSample *v6; // eax
  Scaleform::Sound::SoundSample *v7; // edi
  Scaleform::Sound::SoundSample *v8; // ebx

  v3 = (Scaleform::RefCountVImpl *)this->pMovieRoot->GetStateAddRef(&this->pMovieRoot->Scaleform::GFx::StateBag, 29);
  if ( v3 )
  {
    v4 = (Scaleform::Sound::SoundRenderer *)((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->AddRef)(v3);
    Scaleform::RefCountImpl::Release(v3);
    if ( v4 )
    {
      if ( presource && (presource->GetResourceTypeCode(presource) & 0xFF00) == 0x400 )
      {
        Scaleform::RefCountImpl::AddRef(presource);
        pObject = this->pResource.pObject;
        if ( pObject )
          Scaleform::GFx::Resource::Release(pObject);
        this->pResource.pObject = presource;
        v6 = presource->pSoundInfo.pObject->GetSoundSample(presource->pSoundInfo.pObject, v4);
        v7 = v6;
        if ( v6 )
          InterlockedExchangeAdd(&v6->RefCount.Value, 1);
        v8 = this->pSample.pObject;
        if ( v8 )
        {
          if ( InterlockedExchangeAdd(&v8->RefCount.Value, -1) == 1 )
            ((void (__thiscall *)(Scaleform::Sound::SoundSample *, int))v8->~Scaleform::Sound::SoundSample)(v8, 1);
        }
        this->pSample.pObject = v7;
      }
    }
  }
}
