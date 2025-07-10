void __thiscall Scaleform::Render::GlowFilter::GlowFilter(
        Scaleform::Render::GlowFilter *this,
        const Scaleform::Render::BlurFilterParams *params)
{
  this->__vftable = (Scaleform::Render::GlowFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_Glow;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::GlowFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->Distance = 0.0;
  this->__vftable = (Scaleform::Render::GlowFilter_vtbl *)&Scaleform::Render::GlowFilter::`vftable';
  this->Angle = 0.0;
}
