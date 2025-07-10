void __thiscall Scaleform::GFx::Sprite::StopActiveSounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::SoundResource *pres)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // eax
  int v6; // edi
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // ecx
  Scaleform::GFx::Sprite::ActiveSoundItem **p_pObject; // eax
  Scaleform::GFx::Sprite::ActiveSoundItem *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Sounds; // esi
  unsigned int v11; // edi
  int v12; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> psi; // [esp+Ch] [ebp-4h]

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
  {
    for ( i = 0; i < pActiveSounds->Sounds.Data.Size; pActiveSounds = this->pActiveSounds )
    {
      Data = pActiveSounds->Sounds.Data.Data;
      v6 = i;
      pObject = Data[i].pObject;
      p_pObject = &Data[i].pObject;
      if ( pObject )
        ++pObject->RefCount;
      v9 = *p_pObject;
      psi.pObject = v9;
      if ( v9->pResource == pres )
      {
        v9->pChannel.pObject->Stop(v9->pChannel.pObject);
        p_Sounds = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pActiveSounds->Sounds;
        if ( this->pActiveSounds->Sounds.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            p_Sounds,
            p_Sounds,
            0);
          v9 = psi.pObject;
        }
        else
        {
          if ( p_Sounds->Data[v6].pObject )
            Scaleform::RefCountNTSImpl::Release(p_Sounds->Data[v6].pObject);
          memmove(
            (unsigned __int8 *)&p_Sounds->Data[v6],
            (unsigned __int8 *)&p_Sounds->Data[v6 + 1],
            4 * (p_Sounds->Size - i) - 4);
          v9 = psi.pObject;
          --p_Sounds->Size;
        }
      }
      else
      {
        ++i;
      }
      Scaleform::RefCountNTSImpl::Release(v9);
    }
  }
  v11 = 0;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v12 = 0;
    do
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v12].pCharacter;
      if ( (pCharacter->Flags & 0x80u) != 0 && (pCharacter->Flags & 0x400) != 0 )
        ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::SoundResource *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetFOV)(
          pCharacter,
          pres);
      ++v11;
      ++v12;
    }
    while ( v11 < this->mDisplayList.DisplayObjectArray.Data.Size );
  }
}
