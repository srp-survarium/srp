void __thiscall Scaleform::GFx::Sprite::CheckActiveSounds(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // edi
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int v3; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *Data; // ebp
  unsigned int v5; // edx
  unsigned int v6; // esi
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  int v8; // ebp
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v9; // ecx
  unsigned int Size; // ebp
  unsigned int v11; // edi
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v12; // ebx
  Scaleform::GFx::Sprite::ActiveSoundItem *pObject; // esi
  Scaleform::GFx::ASSoundIntf *pSoundObject; // ecx
  unsigned int v15; // esi
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v16; // edi
  int v17; // ebp
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v18; // ecx
  unsigned int Flags; // eax
  bool v20; // al
  int v21; // eax
  unsigned int v22; // ebx
  Scaleform::GFx::Sprite::ActiveSounds *v23; // esi
  unsigned int v24; // edi
  Scaleform::GFx::Sprite::ActiveSoundItem **v25; // eax
  Scaleform::RefCountNTSImpl **v26; // edi
  int v27; // ebp
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v28; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v29; // esi
  unsigned int v30; // edi
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v31; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v32; // esi
  unsigned int v33; // edi
  unsigned int i; // [esp+8h] [ebp-24h]
  unsigned int ia; // [esp+8h] [ebp-24h]
  unsigned int ib; // [esp+8h] [ebp-24h]
  Scaleform::RefCountNTSImpl *psi; // [esp+10h] [ebp-1Ch]
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2,Scaleform::ArrayDefaultPolicy> sounds; // [esp+14h] [ebp-18h] BYREF
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem>,2,Scaleform::ArrayDefaultPolicy> completeSounds; // [esp+20h] [ebp-Ch] BYREF

  v1 = this;
  pActiveSounds = this->pActiveSounds;
  v3 = 0;
  if ( pActiveSounds )
  {
    Data = 0;
    v5 = 0;
    memset(&sounds, 0, sizeof(sounds));
    if ( pActiveSounds->Sounds.Data.Size )
    {
      do
      {
        v6 = v5 + 1;
        i = (unsigned int)&v1->pActiveSounds->Sounds.Data.Data[v3];
        if ( v5 + 1 >= v5 )
        {
          if ( v6 >= sounds.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&sounds,
              &sounds,
              v6 + (v6 >> 2));
        }
        else
        {
          p_pObject = &Data[v5 - 1].pObject;
          v8 = -1;
          do
          {
            if ( *p_pObject )
              Scaleform::RefCountNTSImpl::Release(*p_pObject);
            --p_pObject;
            --v8;
          }
          while ( v8 );
          if ( v6 < sounds.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&sounds,
              &sounds,
              v6);
          v1 = this;
        }
        Data = sounds.Data.Data;
        v9 = &sounds.Data.Data[v6 - 1];
        v5 = v6;
        sounds.Data.Size = v6;
        if ( &sounds.Data.Data[v6] != (Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *)4 )
        {
          if ( *(_DWORD *)i )
            ++*(_DWORD *)(*(_DWORD *)i + 4);
          v9->pObject = *(Scaleform::GFx::Sprite::ActiveSoundItem **)i;
        }
        ++v3;
      }
      while ( v3 < v1->pActiveSounds->Sounds.Data.Size );
    }
    memset(&completeSounds, 0, sizeof(completeSounds));
    ia = 0;
    if ( v5 )
    {
      Size = sounds.Data.Size;
      v11 = 0;
      do
      {
        v12 = &sounds.Data.Data[ia];
        if ( v12->pObject )
          ++v12->pObject->RefCount;
        pObject = v12->pObject;
        psi = v12->pObject;
        if ( v12->pObject->pChannel.pObject->IsPlaying(v12->pObject->pChannel.pObject) )
        {
          ++ia;
        }
        else
        {
          pSoundObject = pObject->pSoundObject;
          if ( pSoundObject )
            pSoundObject->ExecuteOnSoundComplete(pSoundObject);
          v15 = v11 + 1;
          if ( v11 + 1 >= v11 )
          {
            if ( v15 >= completeSounds.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&completeSounds,
                &completeSounds,
                v15 + (v15 >> 2));
          }
          else
          {
            v16 = &completeSounds.Data.Data[v11 - 1];
            v17 = -1;
            do
            {
              if ( v16->pObject )
                Scaleform::RefCountNTSImpl::Release(v16->pObject);
              --v16;
              --v17;
            }
            while ( v17 );
            if ( v15 < completeSounds.Data.Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&completeSounds,
                &completeSounds,
                v15);
            Size = sounds.Data.Size;
          }
          v18 = &completeSounds.Data.Data[v15 - 1];
          v11 = v15;
          completeSounds.Data.Size = v15;
          if ( &completeSounds.Data.Data[v15] != (Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *)4 )
          {
            if ( v12->pObject )
              ++v12->pObject->RefCount;
            v18->pObject = v12->pObject;
          }
          if ( Size == 1 )
          {
            if ( sounds.Data.Data->pObject )
              Scaleform::RefCountNTSImpl::Release(sounds.Data.Data->pObject);
            if ( (sounds.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
            {
              if ( sounds.Data.Data )
              {
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, sounds.Data.Data);
                sounds.Data.Data = 0;
              }
              sounds.Data.Policy.Capacity = 0;
            }
            Size = 0;
          }
          else
          {
            if ( v12->pObject )
              Scaleform::RefCountNTSImpl::Release(v12->pObject);
            memmove((unsigned __int8 *)v12, (unsigned __int8 *)&v12[1], 4 * (Size - ia) - 4);
            --Size;
          }
          Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
          sounds.Data.Size = Size;
          v20 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
          v21 = Scaleform::GFx::Sprite::CheckAdvanceStatus(this, v20);
          if ( v21 == -1 )
          {
            this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
          }
          else if ( v21 == 1 )
          {
            Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
          }
        }
        Scaleform::RefCountNTSImpl::Release(psi);
      }
      while ( ia < Size );
    }
    v22 = 0;
    for ( ib = 0; v22 < completeSounds.Data.Size; ib = v22 )
    {
      v23 = this->pActiveSounds;
      if ( v23 )
      {
        v24 = 0;
        if ( v23->Sounds.Data.Size )
        {
          v25 = &v23->Sounds.Data.Data->pObject;
          while ( *v25 != completeSounds.Data.Data[v22].pObject )
          {
            ++v24;
            ++v25;
            if ( v24 >= this->pActiveSounds->Sounds.Data.Size )
              goto LABEL_81;
          }
          if ( v24 != -1 )
          {
            if ( v23->Sounds.Data.Size == 1 )
            {
              v26 = &v23->Sounds.Data.Data->pObject;
              v27 = 1;
              do
              {
                if ( *v26 )
                  Scaleform::RefCountNTSImpl::Release(*v26);
                --v26;
                --v27;
              }
              while ( v27 );
              if ( (v23->Sounds.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
              {
                if ( v23->Sounds.Data.Data )
                {
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23->Sounds.Data.Data);
                  v23->Sounds.Data.Data = 0;
                }
                v23->Sounds.Data.Policy.Capacity = 0;
              }
              v23->Sounds.Data.Size = 0;
              v22 = ib;
            }
            else
            {
              if ( v23->Sounds.Data.Data[v24].pObject )
                Scaleform::RefCountNTSImpl::Release(v23->Sounds.Data.Data[v24].pObject);
              memmove(
                (unsigned __int8 *)&v23->Sounds.Data.Data[v24],
                (unsigned __int8 *)&v23->Sounds.Data.Data[v24 + 1],
                4 * (v23->Sounds.Data.Size - v24) - 4);
              --v23->Sounds.Data.Size;
            }
          }
        }
      }
LABEL_81:
      ++v22;
    }
    v28 = completeSounds.Data.Data;
    v29 = &completeSounds.Data.Data[completeSounds.Data.Size - 1];
    if ( completeSounds.Data.Size )
    {
      v30 = completeSounds.Data.Size;
      do
      {
        if ( v29->pObject )
          Scaleform::RefCountNTSImpl::Release(v29->pObject);
        --v29;
        --v30;
      }
      while ( v30 );
    }
    if ( v28 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
    v31 = sounds.Data.Data;
    v32 = &sounds.Data.Data[sounds.Data.Size - 1];
    if ( sounds.Data.Size )
    {
      v33 = sounds.Data.Size;
      do
      {
        if ( v32->pObject )
          Scaleform::RefCountNTSImpl::Release(v32->pObject);
        --v32;
        --v33;
      }
      while ( v33 );
    }
    if ( v31 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
  }
}
