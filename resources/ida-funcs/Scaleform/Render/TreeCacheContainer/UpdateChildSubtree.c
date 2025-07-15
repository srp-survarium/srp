void __thiscall Scaleform::Render::TreeCacheContainer::UpdateChildSubtree(
        Scaleform::Render::TreeCacheContainer *this,
        const Scaleform::Render::TreeNode::NodeData *pdata,
        int depth)
{
  Scaleform::Render::TreeCacheNode *pPrev; // ebp
  Scaleform::Render::TreeNodeArray *v5; // esi
  int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // [esp-8h] [ebp-1Ch]
  Scaleform::Render::TreeNodeArray *v11; // [esp+18h] [ebp+4h]

  Scaleform::Render::TreeCacheNode::UpdateChildSubtree(this, pdata, depth);
  pPrev = this->Children.Root.pNext->pPrev;
  v5 = (Scaleform::Render::TreeNodeArray *)&pdata[1];
  v11 = v5;
  v6 = 0;
  if ( Scaleform::Render::TreeNodeArray::GetSize(v5) )
  {
    while ( 1 )
    {
      v7 = ((int)v5->pNodes[0] & 1) != 0 ? (v5->pData[0] & 0xFFFFFFFE) + 8 : (unsigned int)v5;
      v9 = *(_DWORD *)(v7 + 4 * v6);
      v8 = *(_DWORD *)(*(_DWORD *)((v9 & 0xFFFFF000) + 0x14) + 4 * ((int)(v9 - (v9 & 0xFFFFF000) - 28) / 28) + 20)
         & 0xFFFFFFFE;
      pPrev = (Scaleform::Render::TreeCacheNode *)(*(int (__thiscall **)(unsigned int, Scaleform::Render::TreeCacheContainer *, Scaleform::Render::TreeCacheNode *, int, int))(*(_DWORD *)v8 + 24))(
                                                    v8,
                                                    this,
                                                    pPrev,
                                                    v9,
                                                    depth);
      if ( ++v6 >= (unsigned int)Scaleform::Render::TreeNodeArray::GetSize(v11) )
        break;
      v5 = v11;
    }
  }
}
