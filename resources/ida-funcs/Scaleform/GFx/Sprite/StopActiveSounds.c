void __thiscall Scaleform::GFx::Sprite::StopActiveSounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::ASSoundIntf *psndobj)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // eax
  int v6; // edi
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // eax
  Scaleform::RefCountNTSImpl *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Sounds; // esi
  unsigned int v11; // edi
  int v12; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx
  Scaleform::RefCountNTSImpl *v14; // [esp+Ch] [ebp-4h]

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
      v14 = v9;
      if ( (Scaleform::GFx::ASSoundIntf *)v9[1].RefCount == psndobj )
      {
        (*((void (__thiscall **)(Scaleform::RefCountNTSImpl_vtbl *))v9[1].~Scaleform::RefCountNTSImpl + 3))(v9[1].__vftable);
        p_Sounds = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pActiveSounds->Sounds;
        if ( this->pActiveSounds->Sounds.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            p_Sounds,
            p_Sounds,
            0);
          v9 = v14;
        }
        else
        {
          if ( p_Sounds->Data[v6].pObject )
            Scaleform::RefCountNTSImpl::Release(p_Sounds->Data[v6].pObject);
          memmove((int)&p_Sounds->Data[v6], (const __m128i *)&p_Sounds->Data[v6 + 1], 4 * (p_Sounds->Size - i) - 4);
          v9 = v14;
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
        ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::ASSoundIntf *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetYRotation)(
          pCharacter,
          psndobj);
      ++v11;
      ++v12;
    }
    while ( v11 < this->mDisplayList.DisplayObjectArray.Data.Size );
  }
}


void __thiscall Scaleform::GFx::Sprite::StopActiveSounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::SoundResource *pres)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int i; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // eax
  int v6; // edi
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // eax
  Scaleform::RefCountNTSImpl *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Sounds; // esi
  unsigned int v11; // edi
  int v12; // esi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx
  Scaleform::RefCountNTSImpl *v14; // [esp+Ch] [ebp-4h]

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
      v14 = v9;
      if ( (Scaleform::GFx::SoundResource *)v9[2].__vftable == pres )
      {
        (*((void (__thiscall **)(Scaleform::RefCountNTSImpl_vtbl *))v9[1].~Scaleform::RefCountNTSImpl + 3))(v9[1].__vftable);
        p_Sounds = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pActiveSounds->Sounds;
        if ( this->pActiveSounds->Sounds.Data.Size == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            p_Sounds,
            p_Sounds,
            0);
          v9 = v14;
        }
        else
        {
          if ( p_Sounds->Data[v6].pObject )
            Scaleform::RefCountNTSImpl::Release(p_Sounds->Data[v6].pObject);
          memmove((int)&p_Sounds->Data[v6], (const __m128i *)&p_Sounds->Data[v6 + 1], 4 * (p_Sounds->Size - i) - 4);
          v9 = v14;
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
