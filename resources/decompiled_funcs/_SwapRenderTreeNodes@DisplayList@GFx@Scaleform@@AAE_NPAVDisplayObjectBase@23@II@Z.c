char __thiscall Scaleform::GFx::DisplayList::SwapRenderTreeNodes(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index1,
        unsigned int index2)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // edi
  Scaleform::GFx::DisplayList::DisplayEntry *v5; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  unsigned int MaskTreeIndex; // ecx
  Scaleform::Render::TreeContainer *pParent; // ebp
  Scaleform::Render::TreeNode *v9; // eax
  unsigned int TreeIndex; // ecx
  Scaleform::Render::TreeContainer *v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // [esp-10h] [ebp-2Ch]
  Scaleform::Render::TreeNode *v18; // [esp-Ch] [ebp-28h]
  unsigned int treeIndex1; // [esp+8h] [ebp-14h]
  unsigned int treeIndex2; // [esp+Ch] [ebp-10h]
  Scaleform::Render::TreeNode *n2; // [esp+10h] [ebp-Ch]
  Scaleform::Render::TreeNode *n1; // [esp+14h] [ebp-8h]

  v4 = &this->DisplayObjectArray.Data.Data[index1];
  v5 = &this->DisplayObjectArray.Data.Data[index2];
  if ( (v4->pCharacter->Flags & 0x8000u) != 0 || (v5->pCharacter->Flags & 0x8000u) != 0 )
    return 0;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
  MaskTreeIndex = v4->MaskTreeIndex;
  n1 = RenderNode;
  if ( MaskTreeIndex == -1 )
    MaskTreeIndex = v4->TreeIndex;
  treeIndex1 = MaskTreeIndex;
  pParent = (Scaleform::Render::TreeContainer *)RenderNode->pParent;
  v9 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5->pCharacter);
  TreeIndex = v5->MaskTreeIndex;
  n2 = v9;
  if ( TreeIndex == -1 )
    TreeIndex = v5->TreeIndex;
  v11 = (Scaleform::Render::TreeContainer *)v9->pParent;
  treeIndex2 = TreeIndex;
  if ( !v4->pCharacter->ClipDepth && !v5->pCharacter->ClipDepth )
  {
    if ( pParent == v11 )
    {
      if ( treeIndex1 >= TreeIndex )
      {
        Scaleform::Render::TreeContainer::Remove(v11, TreeIndex, 1u);
        Scaleform::Render::TreeContainer::Remove(pParent, treeIndex1 - 1, 1u);
        Scaleform::Render::TreeContainer::Insert(v11, treeIndex2, n1);
        Scaleform::Render::TreeContainer::Insert(pParent, treeIndex1, n2);
LABEL_15:
        v12 = v4->TreeIndex;
        v4->TreeIndex = v5->TreeIndex;
        v5->TreeIndex = v12;
        v13 = v4->MaskTreeIndex;
        v4->MaskTreeIndex = v5->MaskTreeIndex;
        v5->MaskTreeIndex = v13;
        return 1;
      }
      Scaleform::Render::TreeContainer::Remove(pParent, treeIndex1, 1u);
      Scaleform::Render::TreeContainer::Remove(v11, treeIndex2 - 1, 1u);
      Scaleform::Render::TreeContainer::Insert(pParent, treeIndex1, n2);
      v18 = n1;
      v17 = treeIndex2;
    }
    else
    {
      Scaleform::Render::TreeContainer::Remove(pParent, treeIndex1, 1u);
      Scaleform::Render::TreeContainer::Remove(v11, treeIndex2, 1u);
      Scaleform::Render::TreeContainer::Insert(pParent, treeIndex1, n2);
      v18 = n1;
      v17 = treeIndex2;
    }
    Scaleform::Render::TreeContainer::Insert(v11, v17, v18);
    goto LABEL_15;
  }
  v15 = v4->TreeIndex;
  v4->TreeIndex = v5->TreeIndex;
  v5->TreeIndex = v15;
  v16 = v4->MaskTreeIndex;
  v4->MaskTreeIndex = v5->MaskTreeIndex;
  v5->MaskTreeIndex = v16;
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index1);
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index2);
  Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index1);
  Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index2);
  return 1;
}
