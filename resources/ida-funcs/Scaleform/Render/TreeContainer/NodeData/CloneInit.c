char __thiscall Scaleform::Render::TreeContainer::NodeData::CloneInit(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::TreeNode *node,
        Scaleform::Render::ContextImpl::Context *context)
{
  char result; // al
  unsigned int v5; // eax
  Scaleform::Render::TreeNodeArray *p_Children; // esi
  int v7; // ebp
  unsigned int v8; // eax
  int v9; // esi
  Scaleform::Render::TreeNode *v10; // edi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // esi
  Scaleform::Render::TreeNodeArray *WritableData; // eax
  unsigned int v17; // [esp+Ch] [ebp-10h]
  Scaleform::Render::TreeNodeArray *v18; // [esp+10h] [ebp-Ch]

  result = Scaleform::Render::TreeNode::NodeData::CloneInit(this, node, context);
  if ( result )
  {
    v5 = this->Children.pData[0];
    p_Children = &this->Children;
    v7 = 0;
    v18 = p_Children;
    if ( v5 )
    {
      if ( (v5 & 1) != 0 )
        v17 = *(_DWORD *)((v5 & 0xFFFFFFFE) + 4);
      else
        v17 = (p_Children->pData[1] != 0) + 1;
    }
    else
    {
      v17 = 0;
    }
    if ( v17 )
    {
      while ( 1 )
      {
        if ( ((int)p_Children->pNodes[0] & 1) != 0 )
          v8 = (p_Children->pData[0] & 0xFFFFFFFE) + 8;
        else
          v8 = (unsigned int)p_Children;
        v9 = *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v8 + 4 * v7) & 0xFFFFF000) + 0x10)
                       + 4 * ((int)(*(_DWORD *)(v8 + 4 * v7) - (*(_DWORD *)(v8 + 4 * v7) & 0xFFFFF000) - 28) / 28)
                       + 20);
        v10 = (Scaleform::Render::TreeNode *)(*(int (__thiscall **)(int, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v9 + 32))(
                                               v9,
                                               context);
        if ( v10 )
          (*(void (__thiscall **)(int, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v9 + 36))(
            v9,
            v10,
            context);
        v11 = *(_DWORD *)(*(_DWORD *)(((unsigned int)node & 0xFFFFF000) + 0x10)
                        + 4 * ((int)((int)&node[-1] - ((unsigned int)node & 0xFFFFF000)) / 28)
                        + 20);
        v12 = *(_DWORD *)(v11 + 144);
        v13 = v11 + 144;
        if ( v12 )
        {
          if ( (v12 & 1) != 0 )
            v14 = *(_DWORD *)((v12 & 0xFFFFFFFE) + 4);
          else
            v14 = (*(_DWORD *)(v13 + 4) != 0) + 1;
        }
        else
        {
          v14 = 0;
        }
        WritableData = (Scaleform::Render::TreeNodeArray *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                             node,
                                                             0x100u);
        if ( Scaleform::Render::TreeNodeArray::Insert(WritableData + 18, v14, v10) )
        {
          ++v10->RefCount;
          v10->pParent = node;
          if ( !node->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
            Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(node);
        }
        if ( v10 )
        {
          if ( v10->RefCount-- == 1 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
        }
        if ( ++v7 >= v17 )
          break;
        p_Children = v18;
      }
    }
    return 1;
  }
  return result;
}
