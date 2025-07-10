void __thiscall Scaleform::GFx::Sprite::StopActiveSounds(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // edi
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // eax
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // eax
  Scaleform::RefCountNTSImpl *v7; // esi
  Scaleform::GFx::Sprite::ActiveSounds *v8; // esi
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Sounds; // esi
  Scaleform::RefCountNTSImpl **v11; // edi
  unsigned int v12; // ebx
  unsigned int v13; // edi
  int v14; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
  {
    for ( i = 0; i < pActiveSounds->Sounds.Data.Size; ++i )
    {
      Data = pActiveSounds->Sounds.Data.Data;
      pObject = Data[i].pObject;
      p_pObject = &Data[i].pObject;
      if ( pObject )
        ++pObject->RefCount;
      v7 = *p_pObject;
      (*((void (__thiscall **)(Scaleform::RefCountNTSImpl_vtbl *))(*p_pObject)[1].~Scaleform::RefCountNTSImpl + 3))((*p_pObject)[1].__vftable);
      Scaleform::RefCountNTSImpl::Release(v7);
      pActiveSounds = this->pActiveSounds;
    }
    v8 = this->pActiveSounds;
    Size = v8->Sounds.Data.Size;
    p_Sounds = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v8->Sounds;
    if ( Size )
    {
      v11 = (Scaleform::RefCountNTSImpl **)&p_Sounds->Data[Size - 1];
      v12 = Size;
      do
      {
        if ( *v11 )
          Scaleform::RefCountNTSImpl::Release(*v11);
        --v11;
        --v12;
      }
      while ( v12 );
      if ( (p_Sounds->Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( p_Sounds->Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Sounds->Data);
          p_Sounds->Data = 0;
        }
        p_Sounds->Policy.Capacity = 0;
      }
    }
    else if ( !p_Sounds->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Sounds,
        p_Sounds,
        0);
    }
    p_Sounds->Size = 0;
  }
  v13 = 0;
  if ( this->mDisplayList.DisplayObjectArray.Data.Size )
  {
    v14 = 0;
    do
    {
      pCharacter = this->mDisplayList.DisplayObjectArray.Data.Data[v14].pCharacter;
      if ( (pCharacter->Flags & 0x80u) != 0 && (pCharacter->Flags & 0x400) != 0 )
        pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetFOV(pCharacter);
      ++v13;
      ++v14;
    }
    while ( v13 < this->mDisplayList.DisplayObjectArray.Data.Size );
  }
}
