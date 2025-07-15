void __thiscall Scaleform::GFx::MovieImpl::FillTabableArray(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::FocusGroupDescr *pFocusGroup; // edi
  unsigned __int8 TabableArrayStatus; // al
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  bool InclFocusEnabled; // al
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::DisplayObjContainer *v8; // esi
  signed int i; // esi
  Scaleform::GFx::DisplayObjContainer *v10; // ecx
  Scaleform::GFx::InteractiveObject::FillTabableParams params; // [esp+Ch] [ebp-10h] BYREF

  pFocusGroup = pfocusInfo->pFocusGroup;
  if ( pfocusInfo->InclFocusEnabled )
  {
    TabableArrayStatus = pFocusGroup->TabableArrayStatus;
    if ( (TabableArrayStatus & 1) != 0 && (TabableArrayStatus & 2) == 0 )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>>::Resize(
        &pFocusGroup->TabableArray,
        0);
      pFocusGroup->TabableArrayStatus = 0;
    }
  }
  if ( (pFocusGroup->TabableArrayStatus & 1) == 0 )
  {
    pObject = pFocusGroup->ModalClip.pObject;
    InclFocusEnabled = pfocusInfo->InclFocusEnabled;
    params.TabIndexed = 0;
    params.TabChildrenInProto.Value = 0;
    params.Array = &pFocusGroup->TabableArray;
    params.InclFocusEnabled = InclFocusEnabled;
    if ( pObject
      && (v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, this),
          (v8 = (Scaleform::GFx::DisplayObjContainer *)v7) != 0) )
    {
      ++v7->RefCount;
      Scaleform::RefCountNTSImpl::Release(v7);
      Scaleform::GFx::DisplayObjContainer::FillTabableArray(v8, &params);
    }
    else
    {
      for ( i = this->MovieLevels.Data.Size; i > 0; --i )
      {
        v10 = (Scaleform::GFx::DisplayObjContainer *)this->MovieLevels.Data.Data[i - 1].pSprite.pObject;
        if ( (v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
            & 0x200) != 0 )
          Scaleform::GFx::DisplayObjContainer::FillTabableArray(v10, &params);
      }
    }
    if ( params.TabIndexed )
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::TabIndexSortFunctor>(
        &pFocusGroup->TabableArray,
        0,
        pFocusGroup->TabableArray.Data.Size);
    else
      Scaleform::Alg::QuickSortSliced<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AutoTabSortFunctor>(
        &pFocusGroup->TabableArray,
        0,
        pFocusGroup->TabableArray.Data.Size,
        *(unsigned __int8 *)&stru_8E6BBC);
    pFocusGroup->TabableArrayStatus = 1;
    if ( pfocusInfo->InclFocusEnabled )
      pFocusGroup->TabableArrayStatus = 3;
  }
}
