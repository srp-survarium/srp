Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::AS3::AvmBitmap::CreateRenderNode(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeNode::NodeData *v4; // eax
  Scaleform::Render::TreeNode::NodeData *v5; // esi
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::Render::TreeNode *v8; // esi
  bool v9; // zf
  Scaleform::Render::TreeNode *v10; // ecx
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v11; // eax
  Scaleform::Render::TreeNode *v12; // eax

  v4 = (Scaleform::Render::TreeNode::NodeData *)context->pHeap->Alloc(context->pHeap, 160, 0);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v4, ET_Shape);
    v5->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable';
    v5[1].__vftable = 0;
    *(float *)&v5[1].Type = 0.0;
  }
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(
                  context,
                  &v5->Scaleform::Render::ContextImpl::EntryData);
  pObject = this->pRenNode.pObject;
  v8 = (Scaleform::Render::TreeNode *)EntryHelper;
  if ( pObject )
  {
    v9 = pObject->RefCount-- == 1;
    if ( v9 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenNode.pObject = v8;
  if ( Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(this) )
  {
    v12 = this->pRenNode.pObject;
    if ( v12 )
      ++v12->RefCount;
    v11 = result;
    result->pObject = (Scaleform::Render::TreeNode *)this->pRenNode;
  }
  else
  {
    v10 = this->pRenNode.pObject;
    if ( v10 )
    {
      v9 = v10->RefCount-- == 1;
      if ( v9 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
    }
    v11 = result;
    this->pRenNode.pObject = 0;
    result->pObject = 0;
  }
  return v11;
}
