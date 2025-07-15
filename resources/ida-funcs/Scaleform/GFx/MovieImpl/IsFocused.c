char __thiscall Scaleform::GFx::MovieImpl::IsFocused(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch)
{
  int v2; // ebp
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *i; // edi
  Scaleform::WeakPtrProxy *pObject; // eax
  Scaleform::GFx::InteractiveObject *v5; // esi

  v2 = 0;
  if ( !this->FocusGroupsCnt )
    return 0;
  for ( i = &this->FocusGroups[0].LastFocused; ; i += 16 )
  {
    pObject = i->pProxy.pObject;
    v5 = 0;
    if ( i->pProxy.pObject )
    {
      if ( pObject->pObject )
      {
        v5 = (Scaleform::GFx::InteractiveObject *)pObject->pObject;
        if ( v5->RefCount )
        {
          ++v5->RefCount;
          ++v5->RefCount;
          Scaleform::RefCountNTSImpl::Release(v5);
        }
        else
        {
          v5 = 0;
        }
      }
      else
      {
        if ( pObject->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
        i->pProxy.pObject = 0;
      }
    }
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
    if ( v5 == ch )
      break;
    if ( ++v2 >= this->FocusGroupsCnt )
      return 0;
  }
  return 1;
}


bool __thiscall Scaleform::GFx::MovieImpl::IsFocused(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx)
{
  Scaleform::GFx::InteractiveObject *v3; // esi

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v3 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
  if ( controllerIdx )
  {
    ++*(_DWORD *)(controllerIdx + 4);
    Scaleform::RefCountNTSImpl::Release(v3);
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  return v3 == ch;
}
