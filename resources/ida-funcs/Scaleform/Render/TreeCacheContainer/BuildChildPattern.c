void __thiscall Scaleform::Render::TreeCacheContainer::BuildChildPattern(
        Scaleform::Render::TreeCacheContainer *this,
        Scaleform::Render::BundleEntryRange *pattern,
        unsigned int flags)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int State; // eax
  int v5; // eax
  BOOL v6; // eax
  Scaleform::Render::TreeCacheContainer *v7; // ecx
  Scaleform::Render::TreeCacheNode *pNext; // esi
  int v9; // eax
  bool (__thiscall *GetPatternChain)(Scaleform::Render::TreeCacheNode *, Scaleform::Render::BundleEntryRange *, unsigned int); // eax
  Scaleform::Render::BundleEntry *v11; // eax
  Scaleform::Render::BundleEntry *v12; // eax
  Scaleform::Render::BundleEntry *pFirst; // esi
  Scaleform::Render::BundleEntry *pLast; // eax
  Scaleform::Render::BundleEntry *v15; // eax
  unsigned int v16; // esi
  Scaleform::Render::TreeCacheContainer *v17; // ecx
  double y2; // st6
  double x2; // st5
  double y1; // rt0
  char v21; // [esp+8h] [ebp-4B2h]
  Scaleform::Render::Rect<float> v22; // [esp+Ah] [ebp-4B0h] BYREF
  Scaleform::Render::TreeCacheNode *v23; // [esp+22h] [ebp-498h]
  Scaleform::Render::TreeCacheContainer *v24; // [esp+26h] [ebp-494h]
  Scaleform::Render::Rect<float> pdest; // [esp+2Ah] [ebp-490h] BYREF
  Scaleform::Render::BundleEntryRange other; // [esp+3Eh] [ebp-47Ch] BYREF
  Scaleform::Render::Rect<float> r; // [esp+4Ah] [ebp-470h] BYREF
  Scaleform::Render::BundleEntryRangeMatcher v28; // [esp+66h] [ebp-454h] BYREF
  unsigned int mergeDepth; // [esp+96h] [ebp-424h] BYREF
  Scaleform::Render::FixedSizeArrayRect2F v30; // [esp+9Ah] [ebp-420h] BYREF

  pdest.x1 = 0.0;
  pdest.y1 = 0.0;
  pdest.x2 = 0.0;
  pdest.y2 = 0.0;
  v30.pData = (Scaleform::Render::Rect2F *)&v30.DataReserve[8];
  pattern->pLast = 0;
  pattern->pFirst = 0;
  pattern->Length = 0;
  pNode = this->pNode;
  v24 = this;
  v30.Size = 0;
  v30.Reserve = 32;
  v30.HalfRect = 0;
  memset(&v28, 0, 12);
  v28.LastEntryCount = 0;
  v21 = 0;
  State = Scaleform::Render::StateBag::GetState(
            (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                                                       + 4
                                                       * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000))
                                                        / 28)
                                                       + 20)
                                           & 0xFFFFFFFE)
                                          + 64),
            State_MultitouchInterface);
  if ( State )
  {
    v5 = *(_DWORD *)(State + 4);
    v6 = (*(_BYTE *)(v5 + 20) & 4) != 0 && *(_BYTE *)(v5 + 16);
    flags |= v6;
  }
  v7 = v24;
  pNext = v24->Children.Root.pNext;
  v23 = pNext;
  while ( 1 )
  {
    v9 = v7 == (Scaleform::Render::TreeCacheContainer *)-80 ? 0 : (int)&v7->SortParentBounds;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v9 )
      break;
    GetPatternChain = pNext->GetPatternChain;
    memset(&other, 0, sizeof(other));
    if ( !GetPatternChain(pNext, &other, flags) )
      goto LABEL_61;
    if ( (other.Length & 0x7FFFFFFF) <= 8 )
    {
      v22.x1 = 0.0;
      v22.y1 = 0.0;
      v22.x2 = 0.0;
      v22.y2 = 0.0;
      if ( pNext->pNode )
      {
        v22.x1 = pNext->SortParentBounds.x1;
        v22.y1 = pNext->SortParentBounds.y1;
        v22.x2 = pNext->SortParentBounds.x2;
        v22.y2 = pNext->SortParentBounds.y2;
      }
      if ( (pNext->Flags & 0x410) != 0 )
      {
        if ( pNext->pMask )
        {
          r.x1 = 0.0;
          r.y1 = 0.0;
          r.x2 = 0.0;
          r.y2 = 0.0;
          if ( Scaleform::Render::TreeCacheNode::calcChildMaskBounds(v24, &r, pNext) )
          {
            if ( v21 )
            {
              Scaleform::Render::Rect<float>::operator=(&pdest, &r);
            }
            else
            {
              v21 = 1;
              Scaleform::Render::Rect<float>::UnionRect(&pdest, &pdest, &r);
            }
            if ( v22.x2 <= (double)v22.x1 || v22.y2 <= (double)v22.y1 )
              Scaleform::Render::Rect<float>::operator=(&v22, &r);
            else
              Scaleform::Render::Rect<float>::UnionRect(&v22, &v22, &r);
          }
        }
        if ( v21 )
        {
          pdest.x1 = v22.x1;
          pdest.y1 = v22.y1;
          pdest.x2 = v22.x2;
          pdest.y2 = v22.y2;
        }
        else
        {
          v21 = 1;
          Scaleform::Render::Rect<float>::UnionRect(&pdest, &pdest, &v22);
        }
      }
      pFirst = v28.pFirst;
      if ( v28.pFirst )
      {
        if ( (flags & 1) != 1 )
        {
          if ( (v23->Flags & 0x200) == 0 && Scaleform::Render::FixedSizeArrayRect2F::Intersects(&v30, (__m128 *)&v22) )
          {
            if ( (v28.Length & 0x7FFFFFFF) == 1
              && (other.Length & 0x7FFFFFFF) == 1
              && Scaleform::Render::SortKey::MatchSingleItemOverlap(&pFirst->Key, &other.pFirst->Key) )
            {
LABEL_45:
              mergeDepth = v24->Depth;
              Scaleform::Render::BundleEntryRangeMatcher::Match(&v28, &other, &mergeDepth);
              goto LABEL_57;
            }
          }
          else
          {
            if ( Scaleform::Render::BundleEntryRangeMatcher::Match(&v28, &other, 0) )
              goto LABEL_45;
            pFirst = v28.pFirst;
          }
        }
        if ( pFirst )
        {
          if ( pattern->pFirst )
            pattern->pLast->pNextPattern = pFirst;
          else
            pattern->pFirst = pFirst;
          pLast = v28.pLast;
          pattern->Length += v28.Length;
          pattern->pLast = pLast;
        }
      }
      v28.Scaleform::Render::BundleEntryRange = other;
      v28.LastEntryCount = 0;
      v30.Size = 0;
      v30.HalfRect = 0;
LABEL_57:
      if ( v22.x2 > (double)v22.x1 && v22.y2 > (double)v22.y1 )
        Scaleform::Render::FixedSizeArrayRect2F::PushBack(&v30, (__m128 *)&v22);
      pNext = v23;
LABEL_61:
      v7 = v24;
      v23 = pNext->pNext;
      pNext = v23;
    }
    else
    {
      if ( v28.pFirst )
      {
        if ( pattern->pFirst )
          pattern->pLast->pNextPattern = v28.pFirst;
        else
          pattern->pFirst = v28.pFirst;
        v11 = v28.pLast;
        pattern->Length += v28.Length;
        pattern->pLast = v11;
      }
      if ( other.pFirst )
      {
        if ( pattern->pFirst )
          pattern->pLast->pNextPattern = other.pFirst;
        else
          pattern->pFirst = other.pFirst;
        v12 = other.pLast;
        pattern->Length += other.Length;
        pattern->pLast = v12;
      }
      v7 = v24;
      memset(&v28, 0, 12);
      v30.Size = 0;
      v30.HalfRect = 0;
      v23 = pNext->pNext;
      pNext = v23;
    }
  }
  if ( v28.pFirst )
  {
    if ( pattern->pFirst )
      pattern->pLast->pNextPattern = v28.pFirst;
    else
      pattern->pFirst = v28.pFirst;
    v15 = v28.pLast;
    pattern->Length += v28.Length;
    pattern->pLast = v15;
  }
  if ( v21 )
  {
    v16 = *(_DWORD *)(*(_DWORD *)(((int)v7->pNode & 0xFFFFF000) + 0x14)
                    + 4 * ((int)((int)&v7->pNode[-1] - ((int)v7->pNode & 0xFFFFF000)) / 28)
                    + 20)
        & 0xFFFFFFFE;
    if ( *(float *)(v16 + 120) > (double)*(float *)(v16 + 112) && *(float *)(v16 + 124) > (double)*(float *)(v16 + 116) )
      Scaleform::Render::Rect<float>::UnionRect(&pdest, &pdest, (const Scaleform::Render::Rect<float> *)(v16 + 112));
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(
      (Scaleform::Render::Matrix2x4<float> *)(v16 + 16),
      (__m128 *)&pdest,
      (__m128 *)&pdest);
    v17 = v24;
    y2 = pdest.y2;
    x2 = pdest.x2;
    if ( v24->SortParentBounds.x1 != pdest.x1
      || v24->SortParentBounds.x2 != x2
      || v24->SortParentBounds.y1 != pdest.y1
      || v24->SortParentBounds.y2 != y2 )
    {
      y1 = pdest.y1;
      v24->SortParentBounds.x1 = pdest.x1;
      v17->SortParentBounds.y1 = y1;
      v17->SortParentBounds.x2 = x2;
      v17->SortParentBounds.y2 = y2;
      v17->Flags |= 0x400u;
    }
  }
  ++BuildPatternCount;
  v30.Size = 0;
  if ( (unsigned __int8 *)v30.pData != &v30.DataReserve[8] )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30.pData);
}
