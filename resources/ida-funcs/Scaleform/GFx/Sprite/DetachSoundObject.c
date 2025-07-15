void __thiscall Scaleform::GFx::Sprite::DetachSoundObject(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::ASSoundIntf *psobj)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // esi
  int v5; // ecx
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::GFx::Sprite::ActiveSounds *v7; // esi
  unsigned int Size; // ecx
  int v9; // eax
  Scaleform::GFx::ASSoundIntf **j; // edx

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds && psobj )
  {
    for ( i = 0; i < pActiveSounds->Sounds.Data.Size; ++i )
    {
      v5 = (int)&pActiveSounds->Sounds.Data.Data[i];
      if ( *(_DWORD *)v5 )
        ++*(_DWORD *)(*(_DWORD *)v5 + 4);
      v6 = *(Scaleform::RefCountNTSImpl **)v5;
      if ( (Scaleform::GFx::ASSoundIntf *)v6[1].RefCount == psobj )
        v6[1].RefCount = 0;
      Scaleform::RefCountNTSImpl::Release(v6);
      pActiveSounds = this->pActiveSounds;
    }
    v7 = this->pActiveSounds;
    Size = v7->ASSounds.Data.Size;
    v9 = 0;
    if ( Size )
    {
      for ( j = v7->ASSounds.Data.Data; *j != psobj; ++j )
      {
        if ( ++v9 >= Size )
          return;
      }
      if ( Size == 1 )
      {
        if ( (v7->ASSounds.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
        {
          if ( v7->ASSounds.Data.Data )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7->ASSounds.Data.Data);
            v7->ASSounds.Data.Data = 0;
          }
          v7->ASSounds.Data.Policy.Capacity = 0;
        }
        v7->ASSounds.Data.Size = 0;
      }
      else
      {
        memmove((int)&v7->ASSounds.Data.Data[v9], (const __m128i *)&v7->ASSounds.Data.Data[v9 + 1], 4 * (Size - v9) - 4);
        --v7->ASSounds.Data.Size;
      }
    }
  }
}
