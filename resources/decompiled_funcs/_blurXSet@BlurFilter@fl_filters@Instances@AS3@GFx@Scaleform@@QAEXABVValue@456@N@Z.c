void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float valuea; // [esp+8h] [ebp+8h]
  Scaleform::Render::FilterType valueb; // [esp+8h] [ebp+8h]

  valuea = value;
  *(float *)&valueb = valuea * 20.0;
  this->FilterData.pObject[1].Type = valueb;
}
