void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::distanceGet(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        long double *result)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = *(float *)&this->FilterData.pObject[3].RefCount * 0.05000000074505806;
  *result = v2;
}
