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
