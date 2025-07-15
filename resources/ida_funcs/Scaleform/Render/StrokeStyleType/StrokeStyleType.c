void __thiscall Scaleform::Render::StrokeStyleType::StrokeStyleType(
        Scaleform::Render::StrokeStyleType *this,
        const Scaleform::Render::StrokeStyleType *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v4; // ecx

  this->Width = __that->Width;
  this->Units = __that->Units;
  this->Flags = __that->Flags;
  this->Miter = __that->Miter;
  this->Color = __that->Color;
  pObject = (Scaleform::GFx::Resource *)__that->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pFill.pObject = __that->pFill.pObject;
  v4 = (Scaleform::GFx::Resource *)__that->pDashes.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  this->pDashes.pObject = __that->pDashes.pObject;
}
