void __thiscall Scaleform::Render::GlowFilter::GlowFilter(
        Scaleform::Render::GlowFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Glow);
  this->Params.Passes = passes;
  this->__vftable = (Scaleform::Render::GlowFilter_vtbl *)&Scaleform::Render::GlowFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = 20.0 * blury;
  this->Params.Offset.x = 0.0;
  this->Params.Offset.y = 0.0;
  this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Red = -1;
  this->Params.Colors[0].Channels.Alpha = -1;
  this->Params.Strength = 2.0;
}
