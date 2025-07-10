void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::blurXGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        long double *result)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = *(float *)(((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *))this->GetBevelFilterData)(
                    this,
                    this)
                + 24)
     * 0.05000000074505806;
  *result = v2;
}
