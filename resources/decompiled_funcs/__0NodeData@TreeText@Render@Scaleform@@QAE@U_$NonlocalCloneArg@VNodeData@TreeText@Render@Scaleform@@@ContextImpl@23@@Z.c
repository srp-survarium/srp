void __thiscall Scaleform::Render::TreeText::NodeData::NodeData(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData> src)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(
    this,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)src.pC);
  this->__vftable = (Scaleform::Render::TreeText::NodeData_vtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  if ( src.pC->pDocView.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)src.pC->pDocView.pObject);
  this->pDocView.pObject = src.pC->pDocView.pObject;
  if ( src.pC->pLayout.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)src.pC->pLayout.pObject);
  this->pLayout.pObject = src.pC->pLayout.pObject;
  this->TextFlags = src.pC->TextFlags;
}
