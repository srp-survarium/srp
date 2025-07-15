void __thiscall Scaleform::Render::StrokeStyleType::StrokeStyleType(
        Scaleform::Render::StrokeStyleType *this,
        const Scaleform::Render::StrokeStyleType *__that)
{
  Scaleform::Render::ComplexFill *pObject; // ecx
  Scaleform::Render::DashArray *v4; // ecx

  this->Width = __that->Width;
  this->Units = __that->Units;
  this->Flags = __that->Flags;
  this->Miter = __that->Miter;
  this->Color = __that->Color;
  pObject = __that->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
  this->pFill.pObject = __that->pFill.pObject;
  v4 = __that->pDashes.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v4);
  this->pDashes.pObject = __that->pDashes.pObject;
}
