void __thiscall Scaleform::Render::MeshKeyManager::providerLost(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySetHandle *handle)
{
  Scaleform::Lock *p_KeySetLock; // edi
  Scaleform::Render::MeshKeySet *volatile pKeySet; // eax

  p_KeySetLock = &this->KeySetLock;
  EnterCriticalSection(&this->KeySetLock.cs);
  pKeySet = handle->pKeySet;
  if ( pKeySet )
  {
    pKeySet->pPrev->pNext = pKeySet->pNext;
    pKeySet->pNext->pPrev = pKeySet->pPrev;
    pKeySet->pPrev = this->KeySets[1].Root.pPrev;
    pKeySet->pNext = (Scaleform::Render::MeshKeySet *)&this->KeySets[0].Root.4;
    this->KeySets[1].Root.pPrev->pNext = pKeySet;
    this->KeySets[1].Root.pPrev = pKeySet;
    pKeySet->pDelegate = 0;
    handle->pKeySet = 0;
    LeaveCriticalSection(&p_KeySetLock->cs);
  }
  else
  {
    LeaveCriticalSection(&p_KeySetLock->cs);
  }
}
