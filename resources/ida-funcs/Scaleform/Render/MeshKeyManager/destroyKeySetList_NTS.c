void __thiscall Scaleform::Render::MeshKeyManager::destroyKeySetList_NTS(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeyManager::KeySetListType type)
{
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> *v2; // eax
  unsigned int *v3; // ecx
  Scaleform::Render::MeshKeySet *v4; // esi
  Scaleform::Render::MeshKeySet *v5; // ecx
  Scaleform::Render::MeshKeySet *pNext; // edi
  Scaleform::Render::MeshKeySet *pPrev; // ecx
  Scaleform::Render::MeshProvider_KeySupport *pDelegate; // eax
  Scaleform::RefCountVImpl *v9; // eax
  int v10; // [esp+0h] [ebp-Ch] BYREF
  Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet> v11; // [esp+4h] [ebp-8h] BYREF

  v2 = &this->KeySets[type];
  if ( (Scaleform::Render::MeshKeyManager *)((char *)this + 8 * type) == (Scaleform::Render::MeshKeyManager *)-32 )
    v3 = 0;
  else
    v3 = &this->KeySetLock.cs.SpinCount + 2 * type;
  if ( (unsigned int *)v2->Root.pNext != v3 )
  {
    v4 = (Scaleform::Render::MeshKeySet *)&v10;
    v11.Root.pPrev = (Scaleform::Render::MeshKeySet *)&v10;
    v11.Root.pNext = (Scaleform::Render::MeshKeySet *)&v10;
    if ( v2 )
      v5 = (Scaleform::Render::MeshKeySet *)&v2[-1].Root.4;
    else
      v5 = 0;
    pNext = v2->Root.pNext;
    if ( pNext != v5 )
    {
      pPrev = v2->Root.pPrev;
      v2->Root.pPrev = (Scaleform::Render::MeshKeySet *)&v2[-1].Root.4;
      v2->Root.pNext = (Scaleform::Render::MeshKeySet *)&v2[-1].Root.4;
      pPrev->pNext = (Scaleform::Render::MeshKeySet *)&v10;
      pNext->pPrev = (Scaleform::Render::MeshKeySet *)&v10;
      v4 = pNext;
      v11.Root.pNext->pPrev = pPrev;
      v11.Root.pNext = pNext;
    }
    while ( 1 )
    {
      if ( type != KeySet_KillList )
      {
        pDelegate = v4->pDelegate;
        if ( pDelegate )
        {
          pDelegate->hKeySet.pKeySet = 0;
          v9 = (Scaleform::RefCountVImpl *)InterlockedExchange((volatile LONG *)&pDelegate->hKeySet, 0);
          if ( v9 )
            Scaleform::RefCountImpl::Release(v9);
          v4->pDelegate = 0;
        }
      }
      v4->pPrev->pNext = v4->pNext;
      v4->pNext->pPrev = v4->pPrev;
      if ( v4 )
        ((void (__thiscall *)(Scaleform::Render::MeshKeySet *, int))v4->~Scaleform::Render::MeshKeySet)(v4, 1);
      if ( Scaleform::List<Scaleform::Render::MeshKeySet,Scaleform::Render::MeshKeySet>::IsEmpty(&v11) )
        break;
      v4 = v11.Root.pNext;
    }
  }
}
