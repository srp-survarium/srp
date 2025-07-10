Scaleform::Render::DICommand_ApplyFilter *__thiscall Scaleform::Render::DICommand_ApplyFilter::`scalar deleting destructor'(
        Scaleform::Render::DICommand_ApplyFilter *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::DrawableImage *v4; // ecx
  Scaleform::Render::DrawableImage *v5; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pSource.pObject;
  if ( v4 )
    v4->Release(v4);
  this->__vftable = (Scaleform::Render::DICommand_ApplyFilter_vtbl *)&Scaleform::Render::DICommand::`vftable';
  v5 = this->pImage.pObject;
  if ( v5 )
    v5->Release(v5);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
