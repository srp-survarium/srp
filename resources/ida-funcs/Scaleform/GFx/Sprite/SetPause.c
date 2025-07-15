void __thiscall Scaleform::GFx::Sprite::SetPause(Scaleform::GFx::Sprite *this, BOOL pause)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // esi
  Scaleform::Sound::SoundChannel *pObject; // ecx
  unsigned int v6; // ebx
  int v7; // esi
  char *pCharacter; // ecx

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
  {
    for ( i = 0; i < pActiveSounds->Sounds.Data.Size; ++i )
    {
      pObject = pActiveSounds->Sounds.Data.Data[i].pObject->pChannel.pObject;
      if ( pObject )
        pObject->Pause(pObject, pause);
      pActiveSounds = this->pActiveSounds;
    }
  }
  v6 = 0;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v7 = 0;
    do
    {
      pCharacter = (char *)this->mDisplayList.DisplayObjectArray.Data.Data[v7].pCharacter;
      if ( pCharacter[62] < 0 )
        (*(void (__thiscall **)(char *, BOOL))(*(_DWORD *)pCharacter + 372))(pCharacter, pause);
      ++v6;
      ++v7;
    }
    while ( v6 < this->mDisplayList.DisplayObjectArray.Data.Size );
  }
}
