void __thiscall Scaleform::Render::BlurFilterImpl::BlurFilterImpl(
        Scaleform::Render::BlurFilterImpl *this,
        Scaleform::Render::FilterType type)
{
  unsigned int Mode; // ecx

  this->__vftable = (Scaleform::Render::BlurFilterImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = type;
  this->__vftable = (Scaleform::Render::BlurFilterImpl_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  this->Frozen = 0;
  this->Params.BlurX = 100.0;
  this->Params.BlurY = 100.0;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.Offset.x = 0.0;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Colors[0].Channels.Red = 0;
  this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
  this->Params.Colors[1].Channels.Red = 0;
  this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Blue = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  this->Distance = 0.0;
  Mode = this->Params.Mode;
  this->Angle = 0.0;
  this->Params.Mode = type | Mode & 0xFFFFFFF8;
}
