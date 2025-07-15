BOOL __thiscall Scaleform::Render::BlurFilter::IsContributing(Scaleform::Render::BlurFilter *this)
{
  return (this->Params.BlurX > 20.0 || this->Params.BlurY > 20.0) && this->Params.Passes;
}
