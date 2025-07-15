void __thiscall Scaleform::Render::Text::TextFilter::TextFilter(Scaleform::Render::Text::TextFilter *this)
{
  this->__vftable = (Scaleform::Render::Text::TextFilter_vtbl *)&Scaleform::Render::Text::TextFilter::`vftable';
  this->RefCount = 1;
  this->ShadowParams.BlurX = 100.0;
  this->ShadowParams.BlurY = 100.0;
  this->ShadowParams.Passes = 1;
  this->ShadowParams.Mode = 0;
  this->ShadowParams.Offset.x = 0.0;
  this->ShadowParams.Offset.y = 0.0;
  this->ShadowParams.Strength = 1.0;
  this->ShadowParams.Colors[0].Channels.Red = 0;
  this->ShadowParams.Colors[0].Channels.Green = 0;
  this->ShadowParams.Colors[0].Channels.Blue = 0;
  this->ShadowParams.Colors[0].Channels.Alpha = -1;
  this->ShadowParams.Colors[1].Channels.Red = 0;
  this->ShadowParams.Colors[1].Channels.Green = 0;
  this->ShadowParams.Colors[1].Channels.Blue = 0;
  this->ShadowParams.Colors[1].Channels.Alpha = 0;
  Scaleform::Render::Text::TextFilter::SetDefaultShadow(this);
}
