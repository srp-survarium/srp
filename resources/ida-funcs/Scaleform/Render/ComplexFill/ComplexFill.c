void __thiscall Scaleform::Render::ComplexFill::ComplexFill(
        Scaleform::Render::ComplexFill *this,
        const Scaleform::Render::ComplexFill *o)
{
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::GradientData *v4; // ecx
  Scaleform::Render::GradientData *v5; // ecx

  this->__vftable = (Scaleform::Render::ComplexFill_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::ComplexFill_vtbl *)&Scaleform::Render::ComplexFill::`vftable';
  pObject = o->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = o->pImage.pObject;
  v4 = o->pGradient.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v4);
  v5 = o->pGradient.pObject;
  this->ImageMatrix.M[0][0] = o->ImageMatrix.M[0][0];
  this->pGradient.pObject = v5;
  this->ImageMatrix.M[0][1] = o->ImageMatrix.M[0][1];
  this->ImageMatrix.M[0][2] = o->ImageMatrix.M[0][2];
  this->ImageMatrix.M[0][3] = o->ImageMatrix.M[0][3];
  this->ImageMatrix.M[1][0] = o->ImageMatrix.M[1][0];
  this->ImageMatrix.M[1][1] = o->ImageMatrix.M[1][1];
  this->ImageMatrix.M[1][2] = o->ImageMatrix.M[1][2];
  this->ImageMatrix.M[1][3] = o->ImageMatrix.M[1][3];
  this->FillMode.Fill = o->FillMode.Fill;
  this->BindIndex = o->BindIndex;
}


void __thiscall Scaleform::Render::ComplexFill::ComplexFill(Scaleform::Render::ComplexFill *this)
{
  this->__vftable = (Scaleform::Render::ComplexFill_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::ComplexFill_vtbl *)&Scaleform::Render::ComplexFill::`vftable';
  this->ImageMatrix.M[0][0] = 1.0;
  this->ImageMatrix.M[0][1] = 0.0;
  this->pImage.pObject = 0;
  this->ImageMatrix.M[0][2] = 0.0;
  this->pGradient.pObject = 0;
  this->ImageMatrix.M[0][3] = 0.0;
  this->ImageMatrix.M[1][0] = 0.0;
  this->ImageMatrix.M[1][2] = 0.0;
  this->ImageMatrix.M[1][3] = 0.0;
  this->ImageMatrix.M[1][1] = 1.0;
  this->FillMode.Fill = 0;
  this->BindIndex = -1;
}
