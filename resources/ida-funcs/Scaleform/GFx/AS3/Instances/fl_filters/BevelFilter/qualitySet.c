void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::qualitySet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  unsigned int v3; // esi

  v3 = value;
  if ( value >= 0xF )
    v3 = 15;
  this->GetBevelFilterData(this)->Params.Passes = v3;
}
