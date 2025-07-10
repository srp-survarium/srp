void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::highlightAlphaGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        long double *result)
{
  *result = (double)*(unsigned __int8 *)(((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *))this->GetBevelFilterData)(
                                           this,
                                           this)
                                       + 51)
          / 255.0;
}
