void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXGet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        long double *result)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = *(float *)&this->FilterData.pObject[1].Type * 0.05000000074505806;
  *result = v2;
}
