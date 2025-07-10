void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::strengthSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float valuea; // [esp+8h] [ebp+8h]

  valuea = value;
  this->GetBevelFilterData(this)->Params.Strength = valuea;
}
