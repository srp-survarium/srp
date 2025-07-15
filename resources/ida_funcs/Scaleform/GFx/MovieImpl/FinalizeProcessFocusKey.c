void __thiscall Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *v2; // edi
  int v4; // ecx
  char *v5; // esi
  int CurFocusIdx; // eax
  Scaleform::GFx::Sprite *pObject; // ebp
  Scaleform::RefCountNTSImpl *v8; // ecx

  v2 = pfocusInfo;
  v4 = this->FocusGroupIndexes[pfocusInfo->KeyboardIndex] << 6;
  v5 = (char *)this->FocusGroups + v4;
  if ( pfocusInfo->Initialized && (*(&this->FocusGroups[0].TabableArrayStatus + v4) & 1) != 0 )
  {
    CurFocusIdx = pfocusInfo->CurFocusIdx;
    if ( CurFocusIdx >= 0 && CurFocusIdx < *(signed int *)((char *)&this->FocusGroups[0].TabableArray.Data.Size + v4) )
    {
      pObject = (Scaleform::GFx::Sprite *)(*(Scaleform::Ptr<Scaleform::GFx::InteractiveObject> **)((char *)&this->FocusGroups[0].TabableArray.Data.Data
                                                                                                 + v4))[CurFocusIdx].pObject;
      Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)&this->FocusGroups[0].LastFocused + v4),
        (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&pfocusInfo);
      v8 = (Scaleform::RefCountNTSImpl *)pfocusInfo;
      if ( pfocusInfo )
      {
        ++pfocusInfo->CurFocused.pObject;
        Scaleform::RefCountNTSImpl::Release(v8);
        v8 = (Scaleform::RefCountNTSImpl *)pfocusInfo;
      }
      if ( v8 != pObject )
      {
        *((_DWORD *)v5 + 7) = v2->PrevKeyCode;
        Scaleform::Render::Rect<float>::operator=((Scaleform::Render::Rect<float> *)v5 + 2, &v2->Prev_aRect);
        Scaleform::GFx::MovieImpl::QueueSetFocusTo(this, pObject, 0, v2->KeyboardIndex, GFx_FocusMovedByKeyboard, v2);
        v8 = (Scaleform::RefCountNTSImpl *)pfocusInfo;
      }
      if ( pObject )
      {
        if ( pObject->GetType(pObject) == MouseWheel )
        {
          if ( v5[48] )
            this->FocusRectChanged = 1;
          v8 = (Scaleform::RefCountNTSImpl *)pfocusInfo;
          v5[48] = 0;
LABEL_18:
          if ( v8 )
            Scaleform::RefCountNTSImpl::Release(v8);
          return;
        }
        v8 = (Scaleform::RefCountNTSImpl *)pfocusInfo;
      }
      if ( !v5[48] )
        this->FocusRectChanged = 1;
      v5[48] = 1;
      goto LABEL_18;
    }
  }
}
