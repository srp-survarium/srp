void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::strengthGet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        long double *result)
{
  *result = *(float *)&this->FilterData.pObject[2].Type;
}
