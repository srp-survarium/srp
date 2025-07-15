char __thiscall Scaleform::Render::TreeNode::NodeData::CloneInit(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::TreeNode *node,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::StateBag *p_States; // esi
  unsigned int v4; // ebp
  char v5; // bl
  unsigned int v6; // edi
  Scaleform::Render::StateBag *v7; // eax
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int State; // eax
  int v11; // esi
  Scaleform::Render::TreeNode *v12; // edi
  Scaleform::Render::StateBag *WritableData; // [esp+10h] [ebp-4h]

  p_States = &this->States;
  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(node, 0xFF0000u);
  if ( ((int)p_States->pInterface & 1) != 0 )
    v4 = 1;
  else
    v4 = p_States->ArraySize >> 1;
  v5 = 0;
  v6 = 0;
  if ( v4 )
  {
    do
    {
      v7 = Scaleform::Render::StateBag::GetAt(p_States, v6);
      v8 = v7->ArraySize & 0xFFFFFFFE;
      if ( v8 )
        v9 = *(_DWORD *)(v8 + 4);
      else
        v9 = 0;
      if ( v9 == 4 )
      {
        v5 = 1;
      }
      else if ( v9 != 9 )
      {
        Scaleform::Render::StateBag::SetStateVoid(
          WritableData + 8,
          (Scaleform::Render::StateData::Interface *)v8,
          v7->pData);
      }
      ++v6;
    }
    while ( v6 < v4 );
    if ( v5 )
    {
      State = Scaleform::Render::StateBag::GetState(p_States, State_UserEventHandler);
      v11 = *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(State + 4) & 0xFFFFF000) + 0x10)
                      + 4 * ((int)(*(_DWORD *)(State + 4) - (*(_DWORD *)(State + 4) & 0xFFFFF000) - 28) / 28)
                      + 20);
      v12 = (Scaleform::Render::TreeNode *)(*(int (__thiscall **)(int, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v11 + 32))(
                                             v11,
                                             context);
      if ( v12 )
        (*(void (__thiscall **)(int, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_DWORD *)v11 + 36))(
          v11,
          v12,
          context);
      Scaleform::Render::TreeNode::SetMaskNode(node, v12);
      if ( v12 )
      {
        if ( v12->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
      }
    }
  }
  return 1;
}
