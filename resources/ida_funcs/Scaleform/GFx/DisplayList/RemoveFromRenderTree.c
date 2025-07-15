void __thiscall Scaleform::GFx::DisplayList::RemoveFromRenderTree(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // edi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // edi
  Scaleform::GFx::MovieDefImpl *v6; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::GFx::MovieDefImpl *v8; // eax
  Scaleform::Render::TreeContainer *v9; // ecx
  Scaleform::Render::TreeContainer *v10; // ebp
  unsigned int v11; // ecx
  int v12; // esi
  int v13; // eax
  char *v14; // esi
  Scaleform::Render::TreeNode *v15; // eax
  Scaleform::Render::TreeNode *v16; // edi
  unsigned int v18; // ecx
  unsigned int v19; // esi
  unsigned int TreeIndex; // edx
  Scaleform::Render::TreeContainer *v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // ebp
  unsigned int v24; // edx
  unsigned int v25; // [esp-10h] [ebp-28h]
  unsigned int MaskTreeIndex; // [esp-10h] [ebp-28h]
  Scaleform::GFx::DisplayList::DisplayEntry *dobj; // [esp+8h] [ebp-10h]
  int treeIndexDelta; // [esp+Ch] [ebp-Ch]
  int v29; // [esp+10h] [ebp-8h]
  Scaleform::Render::TreeContainer *pcontainerNode; // [esp+14h] [ebp-4h]
  unsigned int i; // [esp+1Ch] [ebp+4h]

  v4 = &this->DisplayObjectArray.Data.Data[index];
  dobj = v4;
  if ( v4->TreeIndex == -1 )
  {
    pCharacter = v4->pCharacter;
    if ( (pCharacter->Flags & 0x8000u) != 0 )
      Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, pCharacter, 0);
    return;
  }
  v6 = v4->pCharacter->GetResourceMovieDef(v4->pCharacter);
  if ( v6 != owner->GetResourceMovieDef(owner) )
  {
    pMovieImpl = v4->pCharacter->pASRoot->pMovieImpl;
    v8 = v4->pCharacter->GetResourceMovieDef(v4->pCharacter);
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(pMovieImpl, v8);
  }
  v9 = owner->GetRenderContainer(owner);
  pcontainerNode = v9;
  if ( v4->MaskTreeIndex == -1 )
  {
    v10 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v9, v4->TreeIndex);
    treeIndexDelta = -1;
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v10 & 0xFFFFF000) + 0x10)
                               + 4 * ((int)((int)&v10[-1] - ((unsigned int)v10 & 0xFFFFF000)) / 28)
                               + 20)
                   + 6)
        & 0x10) != 0 )
    {
      v11 = index + 1;
      i = index + 1;
      if ( index + 1 < this->DisplayObjectArray.Data.Size )
      {
        v12 = 12 * v11;
        v29 = 12 * v11;
        do
        {
          v13 = *(unsigned int *)((char *)&this->DisplayObjectArray.Data.Data->TreeIndex + v12);
          v14 = (char *)this->DisplayObjectArray.Data.Data + v12;
          if ( (v13 != v4->TreeIndex || *((_DWORD *)v14 + 2) == -1) && v13 != -1 )
            break;
          ++index;
          if ( v13 != -1 )
          {
            v15 = Scaleform::Render::TreeContainer::GetAt(v10, 0);
            v16 = v15;
            if ( v15 )
              ++v15->RefCount;
            Scaleform::Render::TreeContainer::Remove(v10, 0, 1u);
            v25 = dobj->TreeIndex + *((_DWORD *)v14 + 2);
            *((_DWORD *)v14 + 1) = v25;
            *((_DWORD *)v14 + 2) = -1;
            Scaleform::Render::TreeContainer::Insert(pcontainerNode, v25, v16);
            ++treeIndexDelta;
            if ( v16 )
            {
              if ( v16->RefCount-- == 1 )
                Scaleform::Render::ContextImpl::Entry::destroyHelper(v16);
            }
            v4 = dobj;
            v11 = i;
          }
          ++v11;
          v12 = v29 + 12;
          i = v11;
          v29 += 12;
        }
        while ( v11 < this->DisplayObjectArray.Data.Size );
      }
    }
    Scaleform::Render::TreeContainer::Remove(pcontainerNode, v4->TreeIndex + treeIndexDelta + 1, 1u);
    v18 = index + 1;
    if ( index + 1 < this->DisplayObjectArray.Data.Size )
    {
      v19 = v18;
      do
      {
        TreeIndex = this->DisplayObjectArray.Data.Data[v19].TreeIndex;
        if ( TreeIndex != -1 )
          this->DisplayObjectArray.Data.Data[v19].TreeIndex = treeIndexDelta + TreeIndex;
        ++v18;
        ++v19;
      }
      while ( v18 < this->DisplayObjectArray.Data.Size );
    }
    goto LABEL_26;
  }
  MaskTreeIndex = v4->MaskTreeIndex;
  v21 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v9, v4->TreeIndex);
  Scaleform::Render::TreeContainer::Remove(v21, MaskTreeIndex, 1u);
  v22 = index + 1;
  if ( index + 1 >= this->DisplayObjectArray.Data.Size )
  {
LABEL_26:
    v4->MaskTreeIndex = -1;
    v4->TreeIndex = -1;
    return;
  }
  v23 = v22;
  do
  {
    v24 = this->DisplayObjectArray.Data.Data[v23].TreeIndex;
    if ( v24 != -1 )
    {
      if ( v24 != v4->TreeIndex )
        goto LABEL_26;
      --this->DisplayObjectArray.Data.Data[v23].MaskTreeIndex;
    }
    ++v22;
    ++v23;
  }
  while ( v22 < this->DisplayObjectArray.Data.Size );
  v4->MaskTreeIndex = -1;
  v4->TreeIndex = -1;
}
