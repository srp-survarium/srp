BOOL __thiscall Scaleform::Render::BevelFilter::IsContributing(Scaleform::Render::BevelFilter *this)
{
  return (this->Params.Colors[0].Channels.Alpha || this->Params.Colors[1].Channels.Alpha) && this->Params.Passes;
}
