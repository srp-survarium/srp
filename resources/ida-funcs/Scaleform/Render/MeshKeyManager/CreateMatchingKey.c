Scaleform::Render::MeshKey *__thiscall Scaleform::Render::MeshKeyManager::CreateMatchingKey(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySet *keySet,
        unsigned int layer,
        unsigned int flags,
        float *keyData,
        const Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKey *result; // eax

  result = Scaleform::Render::MeshKeySet::findMatchingKey(keySet, layer, flags, keyData, cfg);
  if ( !result )
    return Scaleform::Render::MeshKeySet::CreateKey(keySet, (const __m128i *)keyData, flags);
  ++result->UseCount;
  return result;
}


Scaleform::Render::MeshKey *__thiscall Scaleform::Render::MeshKeyManager::CreateMatchingKey(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshProvider_KeySupport *provider,
        unsigned int layer,
        unsigned int flags,
        float *keyData,
        const Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKeySet *v7; // eax
  Scaleform::Render::MeshKeySet *v8; // edi
  Scaleform::Render::MeshKey *result; // eax
  Scaleform::Render::MeshKeySet *volatile pKeySet; // eax
  Scaleform::Render::MeshKeySet *v11; // ebx
  Scaleform::Lock *p_KeySetLock; // [esp-4h] [ebp-14h]

  if ( !provider->hKeySet.pManager.Value )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
    InterlockedExchange((volatile LONG *)&provider->hKeySet, (LONG)this);
  }
  if ( !provider->hKeySet.pKeySet )
  {
    EnterCriticalSection(&this->KeySetLock.cs);
    v7 = (Scaleform::Render::MeshKeySet *)this->pRenderHeap->Alloc(this->pRenderHeap, 28, 0);
    v8 = v7;
    if ( v7 )
    {
      v7->__vftable = (Scaleform::Render::MeshKeySet_vtbl *)&Scaleform::Render::MeshKeySet::`vftable';
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
      v8->pManager.pObject = this;
      v8->pDelegate = provider;
      v8->Meshes.Root.pPrev = (Scaleform::Render::MeshKey *)&v8->Meshes;
      v8->Meshes.Root.pNext = (Scaleform::Render::MeshKey *)&v8->Meshes;
    }
    else
    {
      v8 = 0;
    }
    provider->hKeySet.pKeySet = v8;
    p_KeySetLock = &this->KeySetLock;
    if ( !provider->hKeySet.pKeySet )
    {
      LeaveCriticalSection(&p_KeySetLock->cs);
      return 0;
    }
    pKeySet = provider->hKeySet.pKeySet;
    pKeySet->pPrev = this->KeySets[0].Root.pPrev;
    pKeySet->pNext = (Scaleform::Render::MeshKeySet *)&this->KeySetLock.cs.SpinCount;
    this->KeySets[0].Root.pPrev->pNext = pKeySet;
    this->KeySets[0].Root.pPrev = pKeySet;
    LeaveCriticalSection(&p_KeySetLock->cs);
  }
  v11 = provider->hKeySet.pKeySet;
  result = Scaleform::Render::MeshKeySet::findMatchingKey(v11, layer, flags, keyData, cfg);
  if ( !result )
    return Scaleform::Render::MeshKeySet::CreateKey(v11, (const __m128i *)keyData, flags);
  ++result->UseCount;
  return result;
}
