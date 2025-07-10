void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::qualityGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        int *result)
{
  *result = this->GetBevelFilterData(this)->Params.Passes;
}
