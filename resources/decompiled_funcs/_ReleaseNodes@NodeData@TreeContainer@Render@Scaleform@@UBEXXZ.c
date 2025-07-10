void __thiscall Scaleform::Render::TreeContainer::NodeData::ReleaseNodes(
        Scaleform::Render::TreeContainer::NodeData *this)
{
  Scaleform::Render::TreeContainer::NodeData *v1; // esi
  unsigned int v2; // ecx
  unsigned int *p_Children; // eax
  int v4; // edi
  unsigned int v5; // ecx
  Scaleform::Render::ContextImpl::Entry **v6; // esi
  Scaleform::Render::ContextImpl::Entry *v7; // ecx
  Scaleform::Render::TreeContainer::NodeData *v9; // [esp+4h] [ebp-4h]

  v1 = this;
  v2 = this->Children.pData[0];
  p_Children = (unsigned int *)&v1->Children;
  v9 = v1;
  if ( v2 )
  {
    v4 = (v2 & 1) != 0 ? *(_DWORD *)((v2 & 0xFFFFFFFE) + 4) : (v1->Children.pData[1] != 0) + 1;
    if ( v4 )
    {
      v5 = *p_Children;
      if ( *p_Children )
      {
        if ( (v5 & 1) != 0 )
          p_Children = (unsigned int *)((v5 & 0xFFFFFFFE) + 8);
        v6 = (Scaleform::Render::ContextImpl::Entry **)p_Children;
      }
      else
      {
        v6 = 0;
      }
      do
      {
        (*v6)->pParent = 0;
        v7 = *v6;
        --v4;
        if ( (*v6)->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
        ++v6;
      }
      while ( v4 );
      v1 = v9;
    }
  }
  if ( (v1->Flags & 0x10) != 0 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner(v1);
  Scaleform::Render::StateBag::ReleaseNodes(&v1->States);
}
