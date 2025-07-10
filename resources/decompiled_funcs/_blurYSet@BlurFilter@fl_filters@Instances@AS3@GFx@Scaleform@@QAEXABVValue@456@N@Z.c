void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurYSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float valuea; // [esp+8h] [ebp+8h]
  float valueb; // [esp+8h] [ebp+8h]

  valuea = value;
  valueb = valuea * 20.0;
  *(float *)&this->FilterData.pObject[1].Frozen = valueb;
}
