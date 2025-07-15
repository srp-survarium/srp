void __thiscall Scaleform::GFx::Sprite::UpdateActiveSoundPan(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // esi
  unsigned int i; // edi
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  unsigned int v7; // edi
  int v8; // esi
  Scaleform::GFx::Sprite *pCharacter; // ecx
  float RealSoundPan; // [esp+10h] [ebp-4h]

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
  {
    RealSoundPan = Scaleform::GFx::Sprite::GetRealSoundPan(this);
    for ( i = 0; i < pActiveSounds->Sounds.Data.Size; ++i )
    {
      v4 = (int)&pActiveSounds->Sounds.Data.Data[i];
      if ( *(_DWORD *)v4 )
        ++*(_DWORD *)(*(_DWORD *)v4 + 4);
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)(*(_DWORD *)v4 + 12);
      if ( v6 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 16))(v6) )
        RealSoundPan = (double)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 12) + 24))(*(_DWORD *)(v5 + 12))
                     / 100.0;
      (*(void (__stdcall **)(float))(**(_DWORD **)(v5 + 8) + 48))(COERCE_FLOAT(LODWORD(RealSoundPan)));
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v5);
      pActiveSounds = this->pActiveSounds;
    }
    v7 = 0;
    if ( this->mDisplayList.DisplayObjectArray.Data.Size )
    {
      v8 = 0;
      do
      {
        pCharacter = (Scaleform::GFx::Sprite *)this->mDisplayList.DisplayObjectArray.Data.Data[v8].pCharacter;
        if ( (pCharacter->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x80u) != 0
          && (pCharacter->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x400) != 0 )
        {
          Scaleform::GFx::Sprite::UpdateActiveSoundPan(pCharacter);
        }
        ++v7;
        ++v8;
      }
      while ( v7 < this->mDisplayList.DisplayObjectArray.Data.Size );
    }
  }
}
