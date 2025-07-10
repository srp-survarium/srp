void __thiscall Scaleform::GFx::MovieImpl::InitFocusKeyInfo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo,
        const Scaleform::GFx::InputEventsQueueEntry::KeyEntry *keyEntry,
        Scaleform::Ptr<Scaleform::GFx::Sprite> inclFocusEnabled,
        float pfocusGroup)
{
  Scaleform::GFx::FocusGroupDescr *v7; // edi
  char pObject; // dl
  Scaleform::GFx::Sprite *v9; // ebp
  Scaleform::GFx::InteractiveObject *v10; // ecx
  Scaleform::GFx::InteractiveObject *v11; // edx
  unsigned int Size; // ecx
  int v13; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *i; // edi
  float pfocusInfoa; // [esp+8h] [ebp+4h]
  float keyEntrya; // [esp+Ch] [ebp+8h]

  if ( !pfocusInfo->Initialized )
  {
    v7 = (Scaleform::GFx::FocusGroupDescr *)LODWORD(pfocusGroup);
    if ( pfocusGroup == 0.0 )
      v7 = &this->FocusGroups[this->FocusGroupIndexes[keyEntry->KeyboardIndex]];
    pfocusInfo->pFocusGroup = v7;
    pfocusInfo->PrevKeyCode = v7->LastFocusKeyCode;
    pObject = (char)inclFocusEnabled.pObject;
    pfocusInfoa = v7->LastFocusedRect.y1;
    pfocusGroup = v7->LastFocusedRect.x2;
    keyEntrya = v7->LastFocusedRect.y2;
    pfocusInfo->Prev_aRect.x1 = v7->LastFocusedRect.x1;
    pfocusInfo->Prev_aRect.y1 = pfocusInfoa;
    pfocusInfo->Prev_aRect.x2 = pfocusGroup;
    pfocusInfo->Prev_aRect.y2 = keyEntrya;
    pfocusInfo->InclFocusEnabled = pObject;
    pfocusInfo->ManualFocus = 0;
    pfocusInfo->KeyboardIndex = keyEntry->KeyboardIndex;
    pfocusInfo->KeyCode = keyEntry->Code;
    pfocusInfo->KeysState = keyEntry->KeysState;
    Scaleform::GFx::MovieImpl::FillTabableArray(this, pfocusInfo);
    pfocusInfo->CurFocusIdx = -1;
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v7->LastFocused,
      &inclFocusEnabled);
    v9 = inclFocusEnabled.pObject;
    if ( inclFocusEnabled.pObject )
      ++inclFocusEnabled.pObject->RefCount;
    v10 = pfocusInfo->CurFocused.pObject;
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    pfocusInfo->CurFocused.pObject = v9;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v11 = pfocusInfo->CurFocused.pObject;
    if ( v11 )
    {
      Size = v7->TabableArray.Data.Size;
      v13 = 0;
      if ( Size )
      {
        for ( i = v7->TabableArray.Data.Data; i->pObject != v11; ++i )
        {
          if ( ++v13 >= Size )
          {
            pfocusInfo->Initialized = 1;
            return;
          }
        }
        pfocusInfo->CurFocusIdx = v13;
      }
    }
    pfocusInfo->Initialized = 1;
  }
}
