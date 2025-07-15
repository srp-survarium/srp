void __thiscall Scaleform::Render::MeshKeyManager::destroyKeySet(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySet *keySet)
{
  Scaleform::Lock *p_KeySetLock; // ebp
  Scaleform::Render::MeshProvider_KeySupport *pDelegate; // eax
  Scaleform::RefCountVImpl *v5; // eax
  Scaleform::Render::MeshKeySet *v6; // ecx

  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  pDelegate = keySet->pDelegate;
  if ( pDelegate )
  {
    pDelegate->hKeySet.pKeySet = 0;
    v5 = (Scaleform::RefCountVImpl *)InterlockedExchange((volatile LONG *)&pDelegate->hKeySet, 0);
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    keySet->pDelegate = 0;
  }
  keySet->pPrev->pNext = keySet->pNext;
  keySet->pNext->pPrev = keySet->pPrev;
  ((void (__thiscall *)(Scaleform::Render::MeshKeySet *, int))keySet->~Scaleform::Render::MeshKeySet)(keySet, 1);
  if ( this == (Scaleform::Render::MeshKeyManager *)-40 )
    v6 = 0;
  else
    v6 = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.4;
  if ( this->KeySets[1].Root.pNext != v6 )
    Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(this, KeySet_KillList);
  LeaveCriticalSection(&p_KeySetLock->cs);
}
