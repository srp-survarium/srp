void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::strengthSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::Render::FilterType valuea; // [esp+8h] [ebp+8h]

  *(float *)&valuea = value;
  this->FilterData.pObject[2].Type = valuea;
}
