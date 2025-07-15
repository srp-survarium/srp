void __thiscall Scaleform::GFx::AS2::MovieRoot::GenerateMouseEvents(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int mouseIndex)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v7; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::MouseState *v9; // ebp
  Scaleform::GFx::Sprite *v10; // ecx
  Scaleform::GFx::Sprite *v11; // esi
  Scaleform::GFx::Sprite *v12; // ecx
  Scaleform::GFx::Sprite *v13; // edi
  unsigned __int8 v14; // dl
  bool v15; // al
  char i; // cl
  unsigned int v17; // edx
  int v18; // ebp
  Scaleform::GFx::MouseState *v19; // ecx
  Scaleform::GFx::Sprite_vtbl *v20; // eax
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::Sprite_vtbl *v22; // eax
  bool (__thiscall *v23)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::Sprite_vtbl *v24; // eax
  bool (__thiscall *v25)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned __int8 v26; // cl
  bool (__thiscall *v27)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned __int8 RollOverCnt; // al
  char v29; // al
  bool (__thiscall *v30)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned __int8 v31; // cl
  bool (__thiscall *v32)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::MouseState *v33; // ecx
  unsigned __int8 v34; // al
  char v35; // al
  bool (__thiscall *v36)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  bool (__thiscall *v37)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned __int8 v38; // cl
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  Scaleform::WeakPtrProxy **p_pObject; // ebp
  Scaleform::WeakPtrProxy *v41; // eax
  bool v42; // zf
  Scaleform::WeakPtrProxy *v43; // eax
  unsigned __int8 v44; // [esp+Fh] [ebp-2Dh]
  char v45; // [esp+10h] [ebp-2Ch]
  bool v46; // [esp+11h] [ebp-2Bh]
  unsigned __int8 v47; // [esp+12h] [ebp-2Ah]
  char v48; // [esp+13h] [ebp-29h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::MouseState *v50; // [esp+18h] [ebp-24h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> v51; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_ActiveEntity; // [esp+20h] [ebp-1Ch]
  unsigned int v53; // [esp+24h] [ebp-18h]
  int v54; // [esp+28h] [ebp-14h] BYREF
  int v55; // [esp+2Ch] [ebp-10h]
  int v56; // [esp+30h] [ebp-Ch]
  unsigned __int8 v57; // [esp+34h] [ebp-8h]
  char v58; // [esp+38h] [ebp-4h]
  char v59; // [esp+39h] [ebp-3h]
  char v60; // [esp+3Ah] [ebp-2h]
  char v61; // [esp+3Bh] [ebp-1h]
  Scaleform::WeakPtrProxy *v62; // [esp+40h] [ebp+4h]

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v5 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v7 = Data;
    while ( v7->Level )
    {
      ++v5;
      ++v7;
      if ( v5 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v5].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  v47 = *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                            + pObject->AvmObjOffset)
                                                          + 124))((int)pObject + 4 * pObject->AvmObjOffset)
                             + 116)
                 + 52) != 1
      ? 1
      : 16;
  if ( mouseIndex < 6 )
  {
    v50 = &this->pMovieImpl->mMouseState[mouseIndex];
    v9 = v50;
  }
  else
  {
    v9 = 0;
    v50 = 0;
  }
  p_ActiveEntity = &v9->ActiveEntity;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v9->ActiveEntity,
    &result);
  v10 = result.pObject;
  if ( result.pObject )
    ++result.pObject->RefCount;
  v11 = v10;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)v9,
    &v51);
  v12 = v51.pObject;
  if ( v51.pObject )
    ++v51.pObject->RefCount;
  v13 = v12;
  if ( v12 )
  {
    Scaleform::RefCountNTSImpl::Release(v12);
    v12 = v51.pObject;
  }
  if ( result.pObject && (result.pObject->Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(result.pObject);
    v12 = v51.pObject;
    v11 = 0;
  }
  if ( v12
    && (v12->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(v12);
    v13 = 0;
  }
  if ( v11 )
    ++v11->RefCount;
  v14 = 0;
  v53 = v9->CurButtonsState ^ v9->PrevButtonsState;
  v15 = (*((_BYTE *)v9 + 52) & 4) != 0;
  result.pObject = v11;
  v48 = 0;
  v45 = v15;
  v44 = 0;
  v51.pObject = 0;
  for ( i = 0; ; i = (char)v51.pObject )
  {
    v46 = v14 != 0;
    v17 = v53 >> i;
    v18 = 1 << i;
    v19 = v50;
    if ( (v17 & 1) != 0 )
    {
      if ( (v18 & v50->PrevButtonsState) == 0 )
        goto LABEL_39;
      if ( (v18 & v50->CurButtonsState) == 0 && v11 )
      {
        if ( (*((_BYTE *)v50 + 52) & 4) != 0 )
        {
          v57 = v44;
          v54 = v46 ? (int)&loc_FF800 + 2048 : 2048;
          v20 = v11->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
          v59 = mouseIndex;
          OnMouseEvent = v20->OnMouseEvent;
          v55 = 0;
          v56 = 0;
          v60 = 0;
          v61 = 0;
          v58 = 0;
          OnMouseEvent(v11, (const Scaleform::GFx::EventId *)&v54);
          v15 = v45;
          v19 = v50;
        }
        else
        {
          if ( (v11->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x4000) == 0 )
          {
            v57 = v44;
            v54 = v46 ? 0x200000 : 4096;
            v22 = v11->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
            v59 = mouseIndex;
            v23 = v22->OnMouseEvent;
            v55 = 0;
            v56 = 0;
            v60 = 0;
            v61 = 0;
            v58 = 0;
            v23(v11, (const Scaleform::GFx::EventId *)&v54);
            v15 = v45;
            v19 = v50;
          }
          v48 = 1;
        }
      }
      if ( (v18 & v19->PrevButtonsState) == 0 )
      {
LABEL_39:
        if ( (v18 & v19->CurButtonsState) != 0 )
        {
          if ( v13 )
            ++v13->RefCount;
          if ( result.pObject )
            Scaleform::RefCountNTSImpl::Release(result.pObject);
          result.pObject = v13;
          if ( v13 )
          {
            v57 = v44;
            v54 = v46 ? (int)&loc_7FC00 + 1024 : 1024;
            v24 = v13->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
            v59 = mouseIndex;
            v25 = v24->OnMouseEvent;
            v55 = 0;
            v56 = 0;
            v60 = 0;
            v61 = 0;
            v58 = 0;
            v25(v13, (const Scaleform::GFx::EventId *)&v54);
          }
          v15 = 1;
          v45 = 1;
        }
      }
      goto LABEL_69;
    }
    if ( (v18 & v50->CurButtonsState) == 0 )
      goto LABEL_69;
    if ( (*((_BYTE *)v50 + 52) & 4) != 0 )
    {
      if ( v13 == v11 )
        goto LABEL_61;
      if ( v11 )
      {
        RollOverCnt = v11->RollOverCnt;
        if ( RollOverCnt )
        {
          v29 = RollOverCnt - 1;
          v11->RollOverCnt = v29;
        }
        else
        {
          v29 = -1;
        }
        v54 = (int)&_sbh_sizeHeaderList + (v46 ? 0x7F0000 : 0);
        v57 = v44;
        v30 = v11->OnMouseEvent;
        v58 = v29;
        v59 = mouseIndex;
        v55 = 0;
        v56 = 0;
        v60 = 0;
        v61 = 0;
        v30(v11, (const Scaleform::GFx::EventId *)&v54);
      }
      v15 = 0;
    }
    else
    {
      if ( v13 != v11 )
        goto LABEL_61;
      if ( v11 )
      {
        v26 = v11->RollOverCnt;
        v11->RollOverCnt = v26 + 1;
        v54 = v46 ? 0x400000 : 0x8000;
        v57 = v44;
        v27 = v11->OnMouseEvent;
        v59 = mouseIndex;
        v58 = v26;
        v55 = 0;
        v56 = 0;
        v60 = 0;
        v61 = 0;
        v27(v11, (const Scaleform::GFx::EventId *)&v54);
      }
      v15 = 1;
    }
    v45 = v15;
LABEL_61:
    if ( (!v11 || (v11->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x4000) != 0)
      && v13
      && v13 != v11
      && (v13->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x4000) != 0 )
    {
      ++v13->RefCount;
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      v31 = v13->RollOverCnt;
      v13->RollOverCnt = v31 + 1;
      v54 = v46 ? 0x400000 : 0x8000;
      v57 = v44;
      v32 = v13->OnMouseEvent;
      v59 = mouseIndex;
      v58 = v31;
      result.pObject = v13;
      v55 = 0;
      v56 = 0;
      v60 = 0;
      v61 = 0;
      v32(v13, (const Scaleform::GFx::EventId *)&v54);
      v45 = 1;
      v15 = 1;
    }
LABEL_69:
    ++v51.pObject;
    v14 = v44 + 1;
    v44 = v14;
    if ( v14 >= v47 )
      break;
  }
  v33 = v50;
  if ( (v50->PrevButtonsState & 1) == 0 && v13 != v11 )
  {
    if ( !v48 && v11 )
    {
      v34 = v11->RollOverCnt;
      if ( v34 )
      {
        v35 = v34 - 1;
        v11->RollOverCnt = v35;
      }
      else
      {
        v35 = -1;
      }
      v36 = v11->OnMouseEvent;
      v58 = v35;
      v59 = mouseIndex;
      v54 = 0x4000;
      v55 = 0;
      v56 = 0;
      v60 = 0;
      v61 = 0;
      v57 = 0;
      v36(v11, (const Scaleform::GFx::EventId *)&v54);
    }
    if ( v13 )
      ++v13->RefCount;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    result.pObject = v13;
    if ( v13 )
    {
      v37 = v13->OnMouseEvent;
      v38 = v13->RollOverCnt;
      v13->RollOverCnt = v38 + 1;
      v59 = mouseIndex;
      v58 = v38;
      v54 = 0x2000;
      v55 = 0;
      v56 = 0;
      v60 = 0;
      v61 = 0;
      v57 = 0;
      v37(v13, (const Scaleform::GFx::EventId *)&v54);
    }
    v33 = v50;
    v15 = 1;
  }
  *((_BYTE *)v33 + 52) ^= (*((_BYTE *)v33 + 52) ^ (4 * v15)) & 4;
  if ( result.pObject )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(result.pObject);
    p_pObject = &p_ActiveEntity->pProxy.pObject;
    v62 = WeakProxy;
    v41 = p_ActiveEntity->pProxy.pObject;
    if ( p_ActiveEntity->pProxy.pObject )
    {
      v42 = v41->RefCount-- == 1;
      if ( v42 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v41);
    }
    *p_pObject = v62;
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  }
  else
  {
    v43 = p_ActiveEntity->pProxy.pObject;
    if ( p_ActiveEntity->pProxy.pObject )
    {
      v42 = v43->RefCount-- == 1;
      if ( v42 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
    }
    p_ActiveEntity->pProxy.pObject = 0;
  }
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
}
