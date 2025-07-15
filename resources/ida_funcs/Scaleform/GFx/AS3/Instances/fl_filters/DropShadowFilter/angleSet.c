void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::angleSet(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float *pObject; // esi
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]
  float valuea; // [esp+18h] [ebp+8h]
  float valueb; // [esp+18h] [ebp+8h]
  float valuec; // [esp+18h] [ebp+8h]

  pObject = (float *)this->FilterData.pObject;
  v4 = pObject[13];
  valuea = value;
  valueb = valuea * 3.141592653589793 / 180.0;
  pObject[14] = valueb;
  pObject[13] = v4;
  v5 = cos(valueb);
  v6 = v5 * v4;
  valuec = sin(valueb);
  v7 = valuec * v4;
  pObject[8] = v6;
  pObject[9] = v7;
}
