void __thiscall Scaleform::GFx::Sprite::SetStreamingSound(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::Resource *pchan)
{
  Scaleform::GFx::Sprite::ActiveSounds *v3; // eax
  Scaleform::Sound::SoundChannel *pObject; // ecx
  Scaleform::RefCountVImpl **p_pStreamSound; // edi
  Scaleform::Sound::SoundChannel *v6; // edi
  Scaleform::Sound::SoundChannel_vtbl *v7; // ebp
  float RealSoundVolume; // [esp+8h] [ebp-14h]

  if ( pchan || this->pActiveSounds )
  {
    if ( !this->pActiveSounds )
    {
      v3 = (Scaleform::GFx::Sprite::ActiveSounds *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     40,
                                                     0);
      if ( v3 )
      {
        v3->Sounds.Data.Data = 0;
        v3->Sounds.Data.Size = 0;
        v3->Sounds.Data.Policy.Capacity = 0;
        v3->ASSounds.Data.Data = 0;
        v3->ASSounds.Data.Size = 0;
        v3->ASSounds.Data.Policy.Capacity = 0;
        v3->pStreamSound.pObject = 0;
        v3->Volume = 100;
        v3->Pan = 0;
      }
      else
      {
        v3 = 0;
      }
      this->pActiveSounds = v3;
    }
    pObject = this->pActiveSounds->pStreamSound.pObject;
    if ( pObject )
      pObject->Stop(pObject);
    p_pStreamSound = (Scaleform::RefCountVImpl **)&this->pActiveSounds->pStreamSound;
    if ( pchan )
      Scaleform::RefCountImpl::AddRef(pchan);
    if ( *p_pStreamSound )
      Scaleform::RefCountImpl::Release(*p_pStreamSound);
    *p_pStreamSound = (Scaleform::RefCountVImpl *)pchan;
    v6 = this->pActiveSounds->pStreamSound.pObject;
    if ( v6 )
    {
      v7 = v6->__vftable;
      RealSoundVolume = Scaleform::GFx::Sprite::GetRealSoundVolume(this);
      ((void (__thiscall *)(Scaleform::Sound::SoundChannel *, _DWORD))v7->SetVolume)(v6, LODWORD(RealSoundVolume));
      Scaleform::GFx::Sprite::AddActiveSound(this, pchan, 0, 0);
    }
  }
}
