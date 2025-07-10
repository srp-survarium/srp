Scaleform::Render::TreeContainer *__thiscall Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::TreeNode::NodeData *v2; // eax
  Scaleform::Render::TreeNode::NodeData *v3; // esi

  v2 = (Scaleform::Render::TreeNode::NodeData *)this->pHeap->Alloc(this->pHeap, 160, 0);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v2, ET_Container);
    v3->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v3[1].Type = 0;
    v3[1].__vftable = 0;
  }
  return (Scaleform::Render::TreeContainer *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                               this,
                                               &v3->Scaleform::Render::ContextImpl::EntryData);
}
