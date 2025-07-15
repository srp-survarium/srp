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


void __thiscall Scaleform::Render::TreeText::NodeData::NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(this, ET_Text);
  this->__vftable = (Scaleform::Render::TreeText::NodeData_vtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  this->pDocView.pObject = 0;
  this->pLayout.pObject = 0;
  this->TextFlags = 0;
}
