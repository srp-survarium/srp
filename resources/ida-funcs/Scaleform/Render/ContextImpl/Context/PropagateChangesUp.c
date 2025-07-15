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
  unsigned int j; // esi
  unsigned int v9; // eax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // ebx
  $363A0FCA69BD73149BBDBDD2FBDCBCB5 *v11; // edi
  int v12; // ecx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v13; // ebp
  unsigned int v14; // esi
  unsigned int i; // [esp+10h] [ebp-98h]
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::ContextImpl::Entry::PropagateNode *> DepthUpdates; // [esp+14h] [ebp-94h] BYREF

  v1 = this->pSnapshots[0];
  pHeap = this->pHeap;
  DepthUpdates.pDepth = DepthUpdates.ArrayReserve;
  v3 = 0;
  DepthUpdates.DepthUsed = 0;
  DepthUpdates.DepthAvailable = 32;
  DepthUpdates.pHeap = pHeap;
  DepthUpdates.NullValue = 0;
  do
    DepthUpdates.ArrayReserve[v3++] = DepthUpdates.NullValue;
  while ( v3 < 0x20 );
  pNext = v1->PropagateEntrys.Root.pNext;
  p_PropagateEntrys = &v1->PropagateEntrys;
  if ( pNext != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys )
  {
    do
    {
      pPrev = pNext[-1].pNext;
      v7 = pNext->pNext;
      for ( j = 0; pPrev; ++j )
        pPrev = pPrev[2].pPrev;
      if ( j < DepthUpdates.DepthAvailable
        || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
             (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)&DepthUpdates,
             j + 1) )
      {
        pNext->pNext = DepthUpdates.pDepth[j];
        DepthUpdates.pDepth[j] = pNext;
        if ( DepthUpdates.DepthUsed < j + 1 )
          DepthUpdates.DepthUsed = j + 1;
      }
      pNext->pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)1;
      pNext = v7;
    }
    while ( v7 != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys );
  }
  p_PropagateEntrys->Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  p_PropagateEntrys->Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  v9 = DepthUpdates.DepthUsed - 1;
  i = DepthUpdates.DepthUsed - 1;
  if ( DepthUpdates.DepthUsed )
  {
    do
    {
      v10 = DepthUpdates.pDepth[v9];
      if ( v10 )
      {
        do
        {
          v11 = &v10[-3].4;
          v12 = *(_DWORD *)(*(_DWORD *)(((unsigned int)&v10[-3].4 & 0xFFFFF000) + 0x10)
                          + 4 * ((int)((int)&v10[-3].4 - ((unsigned int)&v10[-3].4 & 0xFFFFF000) - 28) / 28)
                          + 20);
          if ( (*(unsigned __int8 (__thiscall **)(int, $363A0FCA69BD73149BBDBDD2FBDCBCB5 *))(*(_DWORD *)v12 + 20))(
                 v12,
                 &v10[-3].4) )
          {
            v13 = v11[4].pNext;
            if ( v13 )
            {
              if ( !v13[3].pPrev )
              {
                v14 = i - 1;
                if ( i - 1 < DepthUpdates.DepthAvailable
                  || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                       (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)&DepthUpdates,
                       i) )
                {
                  v13[3].pPrev = DepthUpdates.pDepth[v14];
                  DepthUpdates.pDepth[v14] = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)((char *)v13 + 20);
                  if ( DepthUpdates.DepthUsed < i )
                    DepthUpdates.DepthUsed = i;
                }
              }
            }
          }
          v10 = v10->pNext;
          v11[6].pNext = 0;
          v11[5].pNext = 0;
        }
        while ( v10 );
        v9 = i;
      }
      i = --v9;
    }
    while ( v9 != -1 );
  }
  if ( DepthUpdates.pDepth != DepthUpdates.ArrayReserve )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, DepthUpdates.pDepth);
}
