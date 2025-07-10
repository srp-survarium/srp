void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::typeGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        Scaleform::GFx::ASString *result)
{
  if ( (this->GetBevelFilterData(this)->Params.Mode & 0x20) != 0 )
    Scaleform::GFx::ASString::operator=(result, "inner");
  else
    Scaleform::GFx::ASString::operator=(result, "outer");
}
