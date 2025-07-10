void __thiscall Scaleform::Render::TreeContainer::Remove(
        Scaleform::Render::TreeContainer *this,
        unsigned int index,
        unsigned int count)
{
  unsigned int v3; // edi
  Scaleform::Render::TreeNodeArray *v4; // ebx
  unsigned int v5; // eax
  Scaleform::Render::ContextImpl::Entry **v6; // esi
  unsigned int v7; // eax
  Scaleform::Render::ContextImpl::Entry *v8; // ecx

  v3 = count;
  if ( count )
  {
    v4 = (Scaleform::Render::TreeNodeArray *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200u)[18];
    v5 = v4->pData[0];
    if ( v4->pData[0] || index )
    {
      if ( (v5 & 1) != 0 )
        v7 = (v5 & 0xFFFFFFFE) + 8;
      else
        v7 = (unsigned int)v4;
      v6 = (Scaleform::Render::ContextImpl::Entry **)(v7 + 4 * index);
    }
    else
    {
      v6 = 0;
    }
    do
    {
      (*v6)->pParent = 0;
      v8 = *v6;
      --v3;
      if ( (*v6)->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
      ++v6;
    }
    while ( v3 );
    if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
      Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
    Scaleform::Render::TreeNodeArray::Remove(v4, index, count);
  }
}
