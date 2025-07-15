void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::angleGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        long double *result)
{
  *result = this->GetBevelFilterData(this)->Angle * 180.0 / 3.141592653589793;
}
