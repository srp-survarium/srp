Scaleform::Render::HAL::MaskStackEntry *__thiscall Scaleform::Render::HAL::MaskStackEntry::`scalar deleting destructor'(
        Scaleform::Render::HAL::MaskStackEntry *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pPrimitive.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
