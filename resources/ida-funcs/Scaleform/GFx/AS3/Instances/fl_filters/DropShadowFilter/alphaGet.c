void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::alphaGet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        long double *result)
{
  *result = (double)*((unsigned __int8 *)&this->FilterData.pObject[2].Frozen + 3) / 255.0;
}
