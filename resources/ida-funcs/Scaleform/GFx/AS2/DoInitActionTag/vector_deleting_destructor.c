Scaleform::GFx::AS3::DoAbc *__thiscall Scaleform::GFx::AS2::DoInitActionTag::`vector deleting destructor'(
        Scaleform::GFx::AS3::DoAbc *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pAbc.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::AS3::DoAbc_vtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
