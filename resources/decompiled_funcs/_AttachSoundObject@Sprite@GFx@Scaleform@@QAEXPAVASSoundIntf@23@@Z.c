void __thiscall Scaleform::GFx::Sprite::AttachSoundObject(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::ASSoundIntf *psobj)
{
  Scaleform::GFx::Sprite::ActiveSounds *v3; // eax
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // esi
  unsigned int Size; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_ASSounds; // esi
  unsigned int v7; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx

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
  pActiveSounds = this->pActiveSounds;
  Size = pActiveSounds->ASSounds.Data.Size;
  p_ASSounds = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&pActiveSounds->ASSounds;
  v7 = Size + 1;
  if ( v7 >= p_ASSounds->Size )
  {
    if ( v7 >= p_ASSounds->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ASSounds,
        p_ASSounds,
        v7 + (v7 >> 2));
  }
  else if ( v7 < p_ASSounds->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ASSounds,
      p_ASSounds,
      v7);
  }
  Data = p_ASSounds->Data;
  p_ASSounds->Size = v7;
  if ( &Data[v7] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
    Data[v7 - 1].pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)psobj;
}
