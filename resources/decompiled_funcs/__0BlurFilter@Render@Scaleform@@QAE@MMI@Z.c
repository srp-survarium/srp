void __thiscall Scaleform::Render::BlurFilter::BlurFilter(
        Scaleform::Render::BlurFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Blur);
  this->Params.Passes = passes;
  this->__vftable = (Scaleform::Render::BlurFilter_vtbl *)&Scaleform::Render::BlurFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = 20.0 * blury;
}
