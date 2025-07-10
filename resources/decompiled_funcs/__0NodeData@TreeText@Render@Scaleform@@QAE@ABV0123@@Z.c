void __thiscall Scaleform::Render::TreeText::NodeData::NodeData(
        Scaleform::Render::TreeText::NodeData *this,
        const Scaleform::Render::TreeText::NodeData *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  Scaleform::Render::TreeNode::NodeData::NodeData(this, __that);
  this->__vftable = (Scaleform::Render::TreeText::NodeData_vtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  pObject = (Scaleform::GFx::Resource *)__that->pDocView.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pDocView.pObject = __that->pDocView.pObject;
  v4 = (Scaleform::GFx::Resource *)__that->pLayout.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->pLayout.pObject = __that->pLayout.pObject;
  this->TextFlags = __that->TextFlags;
}
