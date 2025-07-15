void __thiscall Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> pfocusInfo)
{
  Scaleform::GFx::ProcessFocusKeyInfo *pObject; // edi
  int v4; // ecx
  char *v5; // esi
  int pWeakProxy; // eax
  Scaleform::GFx::Sprite *v7; // ebp
  Scaleform::GFx::Sprite *v8; // ecx

  pObject = (Scaleform::GFx::ProcessFocusKeyInfo *)pfocusInfo.pObject;
  v4 = this->FocusGroupIndexes[LOBYTE(pfocusInfo.pObject->LastHitTestY)] << 6;
  v5 = (char *)this->FocusGroups + v4;
  if ( LOBYTE(pfocusInfo.pObject->pRenNode.pObject) )
  {
    if ( (*(&this->FocusGroups[0].TabableArrayStatus + v4) & 1) != 0 )
    {
      pWeakProxy = (int)pfocusInfo.pObject->pWeakProxy;
      if ( pWeakProxy >= 0 && pWeakProxy < *(signed int *)((char *)&this->FocusGroups[0].TabableArray.Data.Size + v4) )
      {
        v7 = (Scaleform::GFx::Sprite *)(*(Scaleform::Ptr<Scaleform::GFx::InteractiveObject> **)((char *)&this->FocusGroups[0].TabableArray.Data.Data
                                                                                              + v4))[pWeakProxy].pObject;
        Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
          (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)&this->FocusGroups[0].LastFocused + v4),
          &pfocusInfo);
        v8 = pfocusInfo.pObject;
        if ( pfocusInfo.pObject )
        {
          ++pfocusInfo.pObject->RefCount;
          Scaleform::RefCountNTSImpl::Release(v8);
          v8 = pfocusInfo.pObject;
        }
        if ( v8 != v7 )
        {
          *((_DWORD *)v5 + 7) = pObject->PrevKeyCode;
          Scaleform::Render::Rect<float>::operator=((Scaleform::Render::Rect<float> *)v5 + 2, &pObject->Prev_aRect);
          Scaleform::GFx::MovieImpl::QueueSetFocusTo(
            this,
            v7,
            0,
            pObject->KeyboardIndex,
            GFx_FocusMovedByKeyboard,
            pObject);
          v8 = pfocusInfo.pObject;
        }
        if ( v7 )
        {
          if ( v7->GetType(v7) == MouseWheel )
          {
            if ( v5[48] )
              this->FocusRectChanged = 1;
            v8 = pfocusInfo.pObject;
            v5[48] = 0;
LABEL_18:
            if ( v8 )
              Scaleform::RefCountNTSImpl::Release(v8);
            return;
          }
          v8 = pfocusInfo.pObject;
        }
        if ( !v5[48] )
          this->FocusRectChanged = 1;
        v5[48] = 1;
        goto LABEL_18;
      }
    }
  }
}
