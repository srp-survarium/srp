BOOL __thiscall Scaleform::Render::ShadowFilter::IsContributing(Scaleform::Render::GlowFilter *this)
{
  return this->Params.Colors[0].Channels.Alpha && this->Params.Passes;
}
