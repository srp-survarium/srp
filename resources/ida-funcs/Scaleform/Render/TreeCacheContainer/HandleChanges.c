void __thiscall Scaleform::Render::TreeCacheContainer::HandleChanges(
        Scaleform::Render::TreeCacheContainer *this,
        __int16 changeBits)
{
  Scaleform::Render::TreeCacheNode *pParent; // edi
  int v4; // edx
  Scaleform::Render::EdgeAAMode v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  Scaleform::Render::TreeCacheNode *pNext; // ebx
  unsigned int v9; // edx
  unsigned int v10; // eax
  int v11; // edi
  Scaleform::Render::TreeCacheNode *v12; // esi
  Scaleform::Render::TreeCacheContainer *v13; // eax
  Scaleform::Render::TreeCacheNode *v14; // edi
  Scaleform::Render::Rect<float> *v15; // eax
  Scaleform::Render::TreeCacheRoot *pRoot; // ecx
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // edx
  Scaleform::Render::Rect<float> *p_SortParentBounds; // eax
  Scaleform::Render::Rect<float> *v21; // eax
  Scaleform::Render::TreeCacheNode *v22; // esi
  Scaleform::Render::TreeCacheRoot *v23; // eax
  int v24; // ecx
  unsigned int index; // [esp+14h] [ebp-Ch]
  unsigned int childCount; // [esp+18h] [ebp-8h]
  _DWORD *v27; // [esp+1Ch] [ebp-4h]
  char change; // [esp+24h] [ebp+4h]
  Scaleform::Render::TreeCacheNode *changea; // [esp+24h] [ebp+4h]

  if ( (changeBits & 0x20) != 0 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      v4 = pParent->Flags & 0xC;
      if ( v4 == 12 )
      {
        v5 = EdgeAA_Disable;
LABEL_8:
        this->propagateEdgeAA(this, v5);
        goto LABEL_9;
      }
    }
    else
    {
      v4 = 4;
    }
    v5 = *(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                               + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                               + 20)
                   & 0xFFFFFFFE)
                  + 6)
       & 0xC;
    if ( v5 == EdgeAA_Inherit )
      v5 = v4;
    goto LABEL_8;
  }
LABEL_9:
  if ( (changeBits & 0x300) != 0 )
  {
    v6 = (_DWORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                               + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                               + 20)
                   & 0xFFFFFFFE)
                  + 144);
    v7 = *v6;
    change = 0;
    v27 = v6;
    if ( *v6 )
    {
      if ( (v7 & 1) != 0 )
        childCount = *(_DWORD *)((v7 & 0xFFFFFFFE) + 4);
      else
        childCount = (*(_DWORD *)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                             + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                                             + 20)
                                 & 0xFFFFFFFE)
                                + 148) != 0)
                   + 1;
    }
    else
    {
      childCount = 0;
    }
    pNext = this->Children.Root.pNext;
    v9 = 0;
    index = 0;
    if ( childCount )
    {
      while ( 1 )
      {
        v10 = (*(_BYTE *)v6 & 1) != 0 ? (*v6 & 0xFFFFFFFE) + 8 : (unsigned int)v6;
        v11 = *(_DWORD *)(v10 + 4 * v9);
        v12 = *(Scaleform::Render::TreeCacheNode **)(v11 + 12);
        if ( v12 != pNext )
          break;
        pNext = pNext->pNext;
LABEL_45:
        v9 = index + 1;
        index = v9;
        if ( v9 >= childCount )
          goto LABEL_46;
      }
      if ( v12 )
      {
        v13 = (Scaleform::Render::TreeCacheContainer *)v12->pParent;
        changea = v13;
        if ( v13 == this && v12->pPrev )
        {
          do
          {
            v14 = pNext->pNext;
            Scaleform::Render::TreeCacheNode::RemoveFromParent(pNext);
            pNext = v14;
            if ( v14 == v12 )
              break;
            v15 = this == (Scaleform::Render::TreeCacheContainer *)-80 ? 0 : &this->SortParentBounds;
          }
          while ( v14 != (Scaleform::Render::TreeCacheNode *)v15 );
          --index;
          change = 1;
LABEL_44:
          v6 = v27;
          goto LABEL_45;
        }
        if ( v13 )
        {
          Scaleform::Render::TreeCacheNode::RemoveFromParent(v12);
          pRoot = changea->pRoot;
          if ( pRoot )
            Scaleform::Render::TreeCacheRoot::AddToUpdate(
              pRoot,
              changea,
              (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
        }
      }
      v17 = (_DWORD *)(*(int (__thiscall **)(unsigned int, Scaleform::Render::TreeCacheContainer *, Scaleform::Render::TreeCacheNode *, int, _DWORD))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)((v11 & 0xFFFFF000) + 0x14) + 4 * ((int)(v11 - (v11 & 0xFFFFF000) - 28) / 28) + 20) & 0xFFFFFFFE) + 24))(
                        *(_DWORD *)(*(_DWORD *)((v11 & 0xFFFFF000) + 0x14)
                                  + 4 * ((int)(v11 - (v11 & 0xFFFFF000) - 28) / 28)
                                  + 20)
                      & 0xFFFFFFFE,
                        this,
                        pNext->pPrev,
                        v11,
                        (unsigned __int16)(this->Depth + 1));
      if ( v17 )
      {
        v18 = v17[6];
        if ( v18 )
        {
          v19 = 3;
          if ( (int)v17[13] >= 0 )
          {
            v17[14] = *(_DWORD *)(v18 + 148);
            *(_DWORD *)(v18 + 148) = v17;
            v19 = -2147483645;
          }
          v17[13] |= v19;
        }
      }
      change = 1;
      if ( this == (Scaleform::Render::TreeCacheContainer *)-80 )
        p_SortParentBounds = 0;
      else
        p_SortParentBounds = &this->SortParentBounds;
      if ( pNext != (Scaleform::Render::TreeCacheNode *)p_SortParentBounds && pNext->pParent != this )
      {
        pNext = this->Children.Root.pNext;
        index = -1;
      }
      goto LABEL_44;
    }
LABEL_46:
    while ( 1 )
    {
      v21 = this == (Scaleform::Render::TreeCacheContainer *)-80 ? 0 : &this->SortParentBounds;
      if ( pNext == (Scaleform::Render::TreeCacheNode *)v21 )
        break;
      v22 = pNext->pNext;
      Scaleform::Render::TreeCacheNode::RemoveFromParent(pNext);
      pNext = v22;
      change = 1;
    }
    if ( change && this->IsPatternChainValid(this) )
    {
      v23 = this->pRoot;
      v24 = (int)&vostok::memory::s_CRT_arena[5574200];
      if ( (this->UpdateFlags & 0x80000000) == 0 )
      {
        this->pNextUpdate = v23->pUpdateList;
        v23->pUpdateList = this;
        v24 = -2130706432;
      }
      this->UpdateFlags |= v24;
    }
  }
}
