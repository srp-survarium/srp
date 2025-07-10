Scaleform::Render::StrokeStyleType *__thiscall Scaleform::Render::StrokeStyleType::operator=(
        Scaleform::Render::StrokeStyleType *this,
        const Scaleform::Render::StrokeStyleType *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  this->Width = __that->Width;
  this->Units = __that->Units;
  this->Flags = __that->Flags;
  this->Miter = __that->Miter;
  this->Color = __that->Color;
  pObject = (Scaleform::GFx::Resource *)__that->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pFill.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pFill.pObject = __that->pFill.pObject;
  v5 = (Scaleform::GFx::Resource *)__that->pDashes.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pDashes.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pDashes.pObject = __that->pDashes.pObject;
  return this;
}
