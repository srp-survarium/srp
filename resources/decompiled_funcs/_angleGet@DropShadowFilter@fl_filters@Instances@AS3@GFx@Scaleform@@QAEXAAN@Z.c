void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::angleGet(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        long double *result)
{
  *result = *(float *)&this->FilterData.pObject[3].Type * 180.0 / 3.141592653589793;
}
