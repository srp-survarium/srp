void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::angleSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::Render::BevelFilter *v4; // eax
  float Distance; // [esp+4h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]
  float valuea; // [esp+18h] [ebp+8h]
  float valueb; // [esp+18h] [ebp+8h]
  float valuec; // [esp+18h] [ebp+8h]

  Distance = this->GetBevelFilterData(this)->Distance;
  v4 = this->GetBevelFilterData(this);
  valuea = value;
  valueb = valuea * 3.141592653589793 / 180.0;
  v4->Angle = valueb;
  v4->Distance = Distance;
  v6 = cos(valueb);
  v7 = v6 * Distance;
  valuec = sin(valueb);
  v8 = valuec * Distance;
  v4->Params.Offset.x = v7;
  v4->Params.Offset.y = v8;
}
