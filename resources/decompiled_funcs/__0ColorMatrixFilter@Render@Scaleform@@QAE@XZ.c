void __thiscall Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(Scaleform::Render::ColorMatrixFilter *this)
{
  this->__vftable = (Scaleform::Render::ColorMatrixFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_ColorMatrix;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::ColorMatrixFilter_vtbl *)&Scaleform::Render::ColorMatrixFilter::`vftable';
  qmemcpy(this->MatrixData, ColorMatrix_Identity, sizeof(this->MatrixData));
}
