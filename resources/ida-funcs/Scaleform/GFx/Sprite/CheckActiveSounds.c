void __thiscall Scaleform::GFx::Sprite::CheckActiveSounds(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // edi
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // ebp
  unsigned int v5; // edx
  unsigned int v6; // esi
  Scaleform::RefCountNTSImpl **v7; // edi
  int v8; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v9; // ecx
  unsigned int Size; // ebp
  unsigned int v11; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v12; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v13; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // ecx
  unsigned int v15; // esi
  Scaleform::RefCountNTSImpl **v16; // edi
  int v17; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v18; // ecx
  unsigned int Flags; // eax
  bool v20; // al
  int v21; // eax
  unsigned int v22; // ebx
  Scaleform::GFx::Sprite::ActiveSounds *v23; // esi
  unsigned int v24; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v25; // eax
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  int v27; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v28; // ebx
  Scaleform::RefCountNTSImpl **v29; // esi
  unsigned int v30; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v31; // ebx
  Scaleform::RefCountNTSImpl **v32; // esi
  unsigned int v33; // edi
  int v34; // [esp+8h] [ebp-24h]
  unsigned int v35; // [esp+8h] [ebp-24h]
  unsigned int i; // [esp+8h] [ebp-24h]
  Scaleform::RefCountNTSImpl *v38; // [esp+10h] [ebp-1Ch]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+14h] [ebp-18h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> v40; // [esp+20h] [ebp-Ch] BYREF

  v1 = this;
  pActiveSounds = this->pActiveSounds;
  v3 = 0;
  if ( pActiveSounds )
  {
    Data = 0;
    v5 = 0;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    if ( pActiveSounds->Sounds.Data.Size )
    {
      do
      {
        v6 = v5 + 1;
        v34 = (int)&v1->pActiveSounds->Sounds.Data.Data[v3];
        if ( v5 + 1 >= v5 )
        {
          if ( v6 >= pheapAddr.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v6 + (v6 >> 2));
        }
        else
        {
          v7 = (Scaleform::RefCountNTSImpl **)&Data[v5 - 1];
          v8 = -1;
          do
          {
            if ( *v7 )
              Scaleform::RefCountNTSImpl::Release(*v7);
            --v7;
            --v8;
          }
          while ( v8 );
          if ( v6 < pheapAddr.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v6);
          v1 = this;
        }
        Data = pheapAddr.Data;
        v9 = &pheapAddr.Data[v6 - 1];
        v5 = v6;
        pheapAddr.Size = v6;
        if ( &pheapAddr.Data[v6] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
        {
          if ( *(_DWORD *)v34 )
            ++*(_DWORD *)(*(_DWORD *)v34 + 4);
          *v9 = *(Scaleform::GFx::AS3::Instances::fl::Object **)v34;
        }
        ++v3;
      }
      while ( v3 < v1->pActiveSounds->Sounds.Data.Size );
    }
    memset(&v40, 0, sizeof(v40));
    v35 = 0;
    if ( v5 )
    {
      Size = pheapAddr.Size;
      v11 = 0;
      do
      {
        v12 = &pheapAddr.Data[v35];
        if ( *v12 )
          ++(*v12)->pRCCRaw;
        v13 = *v12;
        v38 = (Scaleform::RefCountNTSImpl *)*v12;
        if ( ((unsigned __int8 (__thiscall *)(const Scaleform::GFx::AS3::RefCountBaseGC<328> *))(*v12)->pNext->Finalize_GC)((*v12)->pNext) )
        {
          ++v35;
        }
        else
        {
          pPrev = v13->pPrev;
          if ( pPrev )
            pPrev->GetAS3ObjectType(pPrev);
          v15 = v11 + 1;
          if ( v11 + 1 >= v11 )
          {
            if ( v15 >= v40.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &v40,
                &v40,
                v15 + (v15 >> 2));
          }
          else
          {
            v16 = (Scaleform::RefCountNTSImpl **)&v40.Data[v11 - 1];
            v17 = -1;
            do
            {
              if ( *v16 )
                Scaleform::RefCountNTSImpl::Release(*v16);
              --v16;
              --v17;
            }
            while ( v17 );
            if ( v15 < v40.Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &v40,
                &v40,
                v15);
            Size = pheapAddr.Size;
          }
          v18 = &v40.Data[v15 - 1];
          v11 = v15;
          v40.Size = v15;
          if ( &v40.Data[v15] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
          {
            if ( *v12 )
              ++(*v12)->pRCCRaw;
            *v18 = *v12;
          }
          if ( Size == 1 )
          {
            if ( *pheapAddr.Data )
              Scaleform::RefCountNTSImpl::Release(*(Scaleform::RefCountNTSImpl **)pheapAddr.Data);
            if ( (pheapAddr.Policy.Capacity & 0xFFFFFFFE) != 0 )
            {
              if ( pheapAddr.Data )
              {
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
                pheapAddr.Data = 0;
              }
              pheapAddr.Policy.Capacity = 0;
            }
            Size = 0;
          }
          else
          {
            if ( *v12 )
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)*v12);
            memmove((int)v12, (const __m128i *)(v12 + 1), 4 * (Size - v35) - 4);
            --Size;
          }
          Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
          pheapAddr.Size = Size;
          v20 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
          v21 = Scaleform::GFx::Sprite::CheckAdvanceStatus(this, v20);
          if ( v21 == -1 )
          {
            this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)&loc_400000;
          }
          else if ( v21 == 1 )
          {
            Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
          }
        }
        Scaleform::RefCountNTSImpl::Release(v38);
      }
      while ( v35 < Size );
    }
    v22 = 0;
    for ( i = 0; v22 < v40.Size; i = v22 )
    {
      v23 = this->pActiveSounds;
      if ( v23 )
      {
        v24 = 0;
        if ( v23->Sounds.Data.Size )
        {
          v25 = (Scaleform::GFx::AS3::Instances::fl::Object **)v23->Sounds.Data.Data;
          while ( *v25 != v40.Data[v22] )
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
              p_pObject = &v23->Sounds.Data.Data->pObject;
              v27 = 1;
              do
              {
                if ( *p_pObject )
                  Scaleform::RefCountNTSImpl::Release(*p_pObject);
                --p_pObject;
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
              v22 = i;
            }
            else
            {
              if ( v23->Sounds.Data.Data[v24].pObject )
                Scaleform::RefCountNTSImpl::Release(v23->Sounds.Data.Data[v24].pObject);
              memmove(
                (int)&v23->Sounds.Data.Data[v24],
                (const __m128i *)&v23->Sounds.Data.Data[v24 + 1],
                4 * (v23->Sounds.Data.Size - v24) - 4);
              --v23->Sounds.Data.Size;
            }
          }
        }
      }
LABEL_81:
      ++v22;
    }
    v28 = v40.Data;
    v29 = (Scaleform::RefCountNTSImpl **)&v40.Data[v40.Size - 1];
    if ( v40.Size )
    {
      v30 = v40.Size;
      do
      {
        if ( *v29 )
          Scaleform::RefCountNTSImpl::Release(*v29);
        --v29;
        --v30;
      }
      while ( v30 );
    }
    if ( v28 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
    v31 = pheapAddr.Data;
    v32 = (Scaleform::RefCountNTSImpl **)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( pheapAddr.Size )
    {
      v33 = pheapAddr.Size;
      do
      {
        if ( *v32 )
          Scaleform::RefCountNTSImpl::Release(*v32);
        --v32;
        --v33;
      }
      while ( v33 );
    }
    if ( v31 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
  }
}
