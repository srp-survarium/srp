void __thiscall Scaleform::GFx::Sprite::ReleaseAllSounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::MovieDefImpl *powner)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // edi
  Scaleform::GFx::ASSoundIntf *v5; // esi
  Scaleform::GFx::Sprite::ActiveSounds *v6; // esi
  unsigned int Size; // eax
  Scaleform::ArrayLH<Scaleform::GFx::ASSoundIntf *,2,Scaleform::ArrayDefaultPolicy> *p_ASSounds; // esi

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
  {
    for ( i = 0; i < pActiveSounds->ASSounds.Data.Size; pActiveSounds = this->pActiveSounds )
    {
      v5 = pActiveSounds->ASSounds.Data.Data[i];
      if ( v5->GetOwner(v5) == powner )
      {
        v5->ReleaseTarget(v5);
        v6 = this->pActiveSounds;
        Size = v6->ASSounds.Data.Size;
        p_ASSounds = &v6->ASSounds;
        if ( Size == 1 )
        {
          if ( (p_ASSounds->Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( p_ASSounds->Data.Data )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ASSounds->Data.Data);
              p_ASSounds->Data.Data = 0;
            }
            p_ASSounds->Data.Policy.Capacity = 0;
          }
          p_ASSounds->Data.Size = 0;
        }
        else
        {
          memmove((int)&p_ASSounds->Data.Data[i], (const __m128i *)&p_ASSounds->Data.Data[i + 1], 4 * (Size - i) - 4);
          --p_ASSounds->Data.Size;
        }
      }
      else
      {
        ++i;
      }
    }
  }
}
