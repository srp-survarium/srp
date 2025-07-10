void __thiscall Scaleform::GFx::Sprite::AddActiveSound(
        Scaleform::GFx::Sprite *this,
        Scaleform::Sound::SoundChannel *pchan,
        Scaleform::GFx::ASSoundIntf *psobj,
        Scaleform::RefCountNTSImpl_vtbl *pres)
{
  Scaleform::GFx::Sprite *v4; // ebp
  Scaleform::GFx::Sprite::ActiveSounds *v5; // eax
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // ecx
  unsigned int v7; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // edx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v9; // ecx
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // ecx
  Scaleform::RefCountNTSImpl *v11; // esi
  Scaleform::GFx::AS3::ClassTraits::Traits *v12; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v13; // ebx
  Scaleform::RefCountVImpl *pNext; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v15; // esi
  unsigned int Size; // edi
  unsigned int v17; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v18; // esi
  unsigned int v19; // edi
  Scaleform::Sound::SoundChannel *v20; // eax
  Scaleform::RefCountNTSImpl **v21; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v22; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v23; // edi
  unsigned int Flags; // eax
  bool v25; // al
  int v26; // eax
  Scaleform::Sound::SoundChannel *pchana; // [esp+1Ch] [ebp+4h]

  v4 = this;
  if ( !this->pActiveSounds )
  {
    v5 = (Scaleform::GFx::Sprite::ActiveSounds *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   40,
                                                   0);
    if ( v5 )
    {
      v5->Sounds.Data.Data = 0;
      v5->Sounds.Data.Size = 0;
      v5->Sounds.Data.Policy.Capacity = 0;
      v5->ASSounds.Data.Data = 0;
      v5->ASSounds.Data.Size = 0;
      v5->ASSounds.Data.Policy.Capacity = 0;
      v5->pStreamSound.pObject = 0;
      v5->Volume = 100;
      v5->Pan = 0;
    }
    else
    {
      v5 = 0;
    }
    v4->pActiveSounds = v5;
  }
  pActiveSounds = v4->pActiveSounds;
  v7 = 0;
  if ( !pActiveSounds->Sounds.Data.Size )
    goto LABEL_14;
  Data = pActiveSounds->Sounds.Data.Data;
  v9 = Data;
  while ( v9->pObject->pChannel.pObject != pchan )
  {
    ++v7;
    ++v9;
    if ( v7 >= v4->pActiveSounds->Sounds.Data.Size )
      goto LABEL_14;
  }
  pObject = Data[v7].pObject;
  if ( pObject )
    ++pObject->RefCount;
  v11 = Data[v7].pObject;
  if ( !v11 )
  {
LABEL_14:
    v12 = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        20,
                                                        0);
    if ( v12 )
    {
      v12->pRCCRaw = 1;
      v12->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::Sprite::ActiveSoundItem::`vftable';
      v12->pNext = 0;
      v12->pPrev = 0;
      v12->RefCount = 0;
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    if ( pchan )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pchan);
    pNext = (Scaleform::RefCountVImpl *)v13->pNext;
    if ( pNext )
      Scaleform::RefCountImpl::Release(pNext);
    v13->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pchan;
    v15 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)v4->pActiveSounds;
    Size = v15[1].Size;
    v17 = Size;
    v18 = v15 + 1;
    v19 = Size + 1;
    if ( v19 >= v17 )
    {
      if ( v19 >= v18->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v18,
          v18,
          v19 + (v19 >> 2));
    }
    else
    {
      v20 = (Scaleform::Sound::SoundChannel *)(v17 - v19);
      v21 = (Scaleform::RefCountNTSImpl **)&v18->Data[(_DWORD)v20 + v19 - 1];
      if ( v20 )
      {
        pchana = v20;
        do
        {
          if ( *v21 )
            Scaleform::RefCountNTSImpl::Release(*v21);
          --v21;
          pchana = (Scaleform::Sound::SoundChannel *)((char *)pchana - 1);
        }
        while ( pchana );
      }
      if ( v19 < v18->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v18,
          v18,
          v19);
      v4 = this;
    }
    v22 = v18->Data;
    v18->Size = v19;
    v23 = &v22[v19 - 1];
    if ( v23 )
    {
      if ( v13 )
        ++v13->pRCCRaw;
      v23->pObject = v13;
    }
    Flags = v4->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
    v25 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v26 = Scaleform::GFx::Sprite::CheckAdvanceStatus(v4, v25);
    if ( v26 == -1 )
    {
      v4->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
    }
    else if ( v26 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v4);
    }
    v11 = (Scaleform::RefCountNTSImpl *)v13;
  }
  v11[1].RefCount = (int)psobj;
  v11[2].__vftable = pres;
  if ( pres )
  {
    ++pres[7].~Scaleform::RefCountNTSImpl;
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v11[2].__vftable);
  }
  Scaleform::RefCountNTSImpl::Release(v11);
}
