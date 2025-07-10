void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::alphaSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  *(&this->FilterData.pObject[2].Frozen + 3) = (int)(value * 255.0);
}
