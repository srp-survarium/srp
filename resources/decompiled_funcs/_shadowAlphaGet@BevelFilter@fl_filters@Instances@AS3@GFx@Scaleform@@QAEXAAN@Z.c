void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowAlphaGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        long double *result)
{
  *result = (double)*(unsigned __int8 *)(((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *))this->GetBevelFilterData)(
                                           this,
                                           this)
                                       + 47)
          / 255.0;
}
