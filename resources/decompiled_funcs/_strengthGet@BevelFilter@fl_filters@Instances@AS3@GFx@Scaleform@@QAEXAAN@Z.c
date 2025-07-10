void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::strengthGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        long double *result)
{
  *result = this->GetBevelFilterData(this)->Params.Strength;
}
