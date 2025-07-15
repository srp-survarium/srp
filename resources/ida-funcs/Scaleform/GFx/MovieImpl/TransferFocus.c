void __thiscall Scaleform::GFx::MovieImpl::TransferFocus(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *pNewFocus,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl *v4; // ebx
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // edi
  Scaleform::GFx::Sprite *pObject; // ebp
  Scaleform::GFx::InteractiveObject *v7; // esi
  Scaleform::GFx::ASMovieRootBase *v8; // eax
  Scaleform::WeakPtrProxy *v9; // eax
  bool v10; // zf
  Scaleform::WeakPtrProxy *WeakProxy; // ebx
  Scaleform::WeakPtrProxy *v12; // eax
  Scaleform::WeakPtrProxy *v13; // eax
  Scaleform::WeakPtrProxy *v14; // ebx
  Scaleform::WeakPtrProxy *v15; // eax
  Scaleform::WeakPtrProxy *v16; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+1Ch] [ebp-4h] BYREF
  int avmVersion; // [esp+24h] [ebp+4h]

  v4 = this;
  p_LastFocused = &this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)p_LastFocused,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  v7 = pNewFocus;
  if ( pObject != pNewFocus )
  {
    v8 = v4->pASMovieRoot.pObject;
    v4->FocusRectChanged = 1;
    avmVersion = v8->AVMVersion;
    if ( avmVersion == 2 )
    {
      if ( !v7 )
      {
        v13 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v10 = v13->RefCount-- == 1;
          if ( v10 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
        }
        goto LABEL_18;
      }
      if ( !v7->IsFocusEnabled(v7, fmt) )
      {
        v9 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v10 = v9->RefCount-- == 1;
          if ( v10 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
        }
        v7 = 0;
LABEL_18:
        p_LastFocused->pProxy.pObject = 0;
        goto LABEL_19;
      }
      WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(v7);
      v12 = p_LastFocused->pProxy.pObject;
      if ( p_LastFocused->pProxy.pObject )
      {
        v10 = v12->RefCount-- == 1;
        if ( v10 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      }
      p_LastFocused->pProxy.pObject = WeakProxy;
      v4 = this;
    }
LABEL_19:
    if ( pObject && pObject->pParent )
      pObject->OnFocus(pObject, Unknown, v7, controllerIdx, fmt);
    if ( avmVersion == 1 )
    {
      if ( !v7 )
      {
        v16 = p_LastFocused->pProxy.pObject;
        if ( p_LastFocused->pProxy.pObject )
        {
          v10 = v16->RefCount-- == 1;
          if ( v10 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
        }
        p_LastFocused->pProxy.pObject = 0;
        goto LABEL_30;
      }
      v14 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(v7);
      v15 = p_LastFocused->pProxy.pObject;
      if ( p_LastFocused->pProxy.pObject )
      {
        v10 = v15->RefCount-- == 1;
        if ( v10 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
      }
      p_LastFocused->pProxy.pObject = v14;
      v4 = this;
    }
    if ( v7 )
      v7->OnFocus(v7, MouseMove, pObject, controllerIdx, fmt);
LABEL_30:
    v4->pASMovieRoot.pObject->NotifyTransferFocus(v4->pASMovieRoot.pObject, pObject, v7, controllerIdx);
  }
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
}
