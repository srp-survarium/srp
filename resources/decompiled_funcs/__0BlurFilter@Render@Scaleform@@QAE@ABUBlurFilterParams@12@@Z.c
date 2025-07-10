void __thiscall Scaleform::Render::BlurFilter::BlurFilter(
        Scaleform::Render::BlurFilter *this,
        const Scaleform::Render::BlurFilterParams *params)
{
  this->Type = Filter_Blur;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::BlurFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::BlurFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->Distance = 0.0;
  this->__vftable = (Scaleform::Render::BlurFilter_vtbl *)&Scaleform::Render::BlurFilter::`vftable';
  this->Angle = 0.0;
}
