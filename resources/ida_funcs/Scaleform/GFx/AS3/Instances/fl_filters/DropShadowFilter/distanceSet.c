void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::distanceSet(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float *pObject; // esi
  float v4; // [esp+4h] [ebp-10h]
  float v5; // [esp+8h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-Ch]
  float v7; // [esp+Ch] [ebp-8h]
  float v8; // [esp+10h] [ebp-4h]
  float valuea; // [esp+1Ch] [ebp+8h]
  float valueb; // [esp+1Ch] [ebp+8h]

  pObject = (float *)this->FilterData.pObject;
  v4 = pObject[14];
  valuea = value;
  valueb = valuea * 20.0;
  pObject[14] = v4;
  pObject[13] = valueb;
  v5 = cos(v4);
  v7 = v5 * valueb;
  v6 = sin(v4);
  v8 = v6 * valueb;
  pObject[8] = v7;
  pObject[9] = v8;
}
