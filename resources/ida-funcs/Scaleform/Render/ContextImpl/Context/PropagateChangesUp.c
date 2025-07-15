void __thiscall Scaleform::Render::ContextImpl::Context::PropagateChangesUp(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v3; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pNext; // edi
  Scaleform::List<Scaleform::Render::ContextImpl::Entry::PropagateNode,Scaleform::Render::ContextImpl::Entry::PropagateNode> *p_PropagateEntrys; // ebp
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // ebx
  unsigned int i; // esi
  unsigned int v9; // eax
  Scaleform::Render::TreeCacheNode *v10; // ebx
  _DWORD *v11; // edi
  int v12; // ecx
  int v13; // ebp
  unsigned int v14; // esi
  unsigned int v15; // [esp+10h] [ebp-98h]
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> v16; // [esp+14h] [ebp-94h] BYREF

  v1 = this->pSnapshots[0];
  pHeap = this->pHeap;
  v16.pDepth = v16.ArrayReserve;
  v3 = 0;
  v16.DepthUsed = 0;
  v16.DepthAvailable = 32;
  v16.pHeap = pHeap;
  v16.NullValue = 0;
  do
    v16.ArrayReserve[v3++] = v16.NullValue;
  while ( v3 < 0x20 );
  pNext = v1->PropagateEntrys.Root.pNext;
  p_PropagateEntrys = &v1->PropagateEntrys;
  if ( pNext != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys )
  {
    do
    {
      pPrev = pNext[-1].pNext;
      v7 = pNext->pNext;
      for ( i = 0; pPrev; ++i )
        pPrev = pPrev[2].pPrev;
      if ( i < v16.DepthAvailable
        || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(&v16, i + 1) )
      {
        pNext->pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v16.pDepth[i];
        v16.pDepth[i] = (Scaleform::Render::TreeCacheNode *)pNext;
        if ( v16.DepthUsed < i + 1 )
          v16.DepthUsed = i + 1;
      }
      pNext->pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)1;
      pNext = v7;
    }
    while ( v7 != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys );
  }
  p_PropagateEntrys->Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  p_PropagateEntrys->Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  v9 = v16.DepthUsed - 1;
  v15 = v16.DepthUsed - 1;
  if ( v16.DepthUsed )
  {
    do
    {
      v10 = v16.pDepth[v9];
      if ( v10 )
      {
        do
        {
          v11 = &v10[-1].pNextUpdate + 1;
          v12 = *(_DWORD *)(*(_DWORD *)(((unsigned int)(&v10[-1].pNextUpdate + 1) & 0xFFFFF000) + 0x10)
                          + 4
                          * ((int)((int)&v10->pNextUpdate - ((unsigned int)(&v10[-1].pNextUpdate + 1) & 0xFFFFF000) - 104)
                           / 28)
                          + 20);
          if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::Render::TreeCacheNode **))(*(_DWORD *)v12 + 20))(
                 v12,
                 &v10[-1].pNextUpdate + 1) )
          {
            v13 = v11[4];
            if ( v13 )
            {
              if ( !*(_DWORD *)(v13 + 24) )
              {
                v14 = v15 - 1;
                if ( v15 - 1 < v16.DepthAvailable
                  || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(&v16, v15) )
                {
                  *(_DWORD *)(v13 + 24) = v16.pDepth[v14];
                  v16.pDepth[v14] = (Scaleform::Render::TreeCacheNode *)(v13 + 20);
                  if ( v16.DepthUsed < v15 )
                    v16.DepthUsed = v15;
                }
              }
            }
          }
          v10 = (Scaleform::Render::TreeCacheNode *)*((_DWORD *)&v10->__vftable + 1);
          v11[6] = 0;
          v11[5] = 0;
        }
        while ( v10 );
        v9 = v15;
      }
      v15 = --v9;
    }
    while ( v9 != -1 );
  }
  if ( v16.pDepth != v16.ArrayReserve )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16.pDepth);
}
