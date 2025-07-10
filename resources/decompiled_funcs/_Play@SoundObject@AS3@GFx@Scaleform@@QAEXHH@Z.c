void __thiscall Scaleform::GFx::AS3::SoundObject::Play(
        Scaleform::GFx::AS3::SoundObject *this,
        int startTime,
        int loops)
{
  Scaleform::GFx::InteractiveObject *v4; // eax
  Scaleform::GFx::Sprite *v5; // ebx
  Scaleform::GFx::State *v6; // eax
  Scaleform::RefCountVImpl *v7; // esi
  int v8; // ebp
  Scaleform::Sound::SoundSample *pObject; // eax
  Scaleform::Sound::SoundChannel *v10; // esi
  int SoundVolume; // eax
  int SoundPan; // eax
  float startTimea; // [esp+34h] [ebp+4h]
  float loopsa; // [esp+38h] [ebp+8h]
  float loopsb; // [esp+38h] [ebp+8h]

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->pTargetHandle.pObject, this->pMovieRoot);
  if ( v4 )
  {
    v5 = (v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0
       ? (Scaleform::GFx::Sprite *)v4
       : 0;
    if ( v5 )
    {
      v6 = this->pMovieRoot->GetStateAddRef(&this->pMovieRoot->Scaleform::GFx::StateBag, 29);
      v7 = (Scaleform::RefCountVImpl *)v6;
      if ( v6 )
      {
        v8 = ((int (__thiscall *)(Scaleform::GFx::State *))v6->__vftable[1].~Scaleform::GFx::State)(v6);
        Scaleform::RefCountImpl::Release(v7);
        if ( v8 )
        {
          if ( !loops )
            loops = 1;
          pObject = this->pSample.pObject;
          if ( pObject )
          {
            v10 = (Scaleform::Sound::SoundChannel *)(*(int (__thiscall **)(int, Scaleform::Sound::SoundSample *, int))(*(_DWORD *)v8 + 20))(
                                                      v8,
                                                      pObject,
                                                      1);
            if ( v10 )
            {
              if ( startTime > 0 || loops > 0 )
              {
                startTimea = (double)startTime / 1000.0;
                ((void (__thiscall *)(Scaleform::Sound::SoundChannel *, int, _DWORD, _DWORD))v10->Loop)(
                  v10,
                  loops,
                  LODWORD(startTimea),
                  0.0);
              }
              SoundVolume = Scaleform::GFx::Sprite::GetSoundVolume(v5);
              this->Volume = SoundVolume;
              loopsa = (double)SoundVolume / 100.0;
              ((void (__thiscall *)(Scaleform::Sound::SoundChannel *, _DWORD))v10->SetVolume)(v10, LODWORD(loopsa));
              SoundPan = Scaleform::GFx::Sprite::GetSoundPan(v5);
              this->Pan = SoundPan;
              loopsb = (double)SoundPan / 100.0;
              ((void (__thiscall *)(Scaleform::Sound::SoundChannel *, _DWORD))v10->SetPan)(v10, LODWORD(loopsb));
              v10->Pause(v10, 0);
              Scaleform::GFx::Sprite::AddActiveSound(
                v5,
                v10,
                &this->Scaleform::GFx::ASSoundIntf,
                (Scaleform::RefCountNTSImpl_vtbl *)this->pResource.pObject);
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
            }
          }
        }
      }
    }
  }
}
