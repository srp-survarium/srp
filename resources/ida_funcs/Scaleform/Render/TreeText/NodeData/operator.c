Scaleform::Render::TreeText::NodeData *__thiscall Scaleform::Render::TreeText::NodeData::operator=(
        Scaleform::Render::TreeText::NodeData *this,
        const Scaleform::Render::TreeText::NodeData *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  Scaleform::Render::TreeNode::NodeData::operator=(this, __that);
  pObject = (Scaleform::GFx::Resource *)__that->pDocView.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pDocView.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pDocView.pObject = __that->pDocView.pObject;
  v5 = (Scaleform::GFx::Resource *)__that->pLayout.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pLayout.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pLayout.pObject = __that->pLayout.pObject;
  this->TextFlags = __that->TextFlags;
  return this;
}
