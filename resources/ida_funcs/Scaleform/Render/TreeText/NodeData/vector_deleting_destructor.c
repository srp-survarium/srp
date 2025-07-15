Scaleform::Render::TreeText::NodeData *__thiscall Scaleform::Render::TreeText::NodeData::`vector deleting destructor'(
        Scaleform::Render::TreeText::NodeData *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  this->__vftable = (Scaleform::Render::TreeText::NodeData_vtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pLayout.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pDocView.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  if ( this->States.ArraySize )
    Scaleform::Render::StateData::destroyBag_NotEmpty(&this->States);
  Scaleform::Render::ContextImpl::EntryData::~EntryData(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
