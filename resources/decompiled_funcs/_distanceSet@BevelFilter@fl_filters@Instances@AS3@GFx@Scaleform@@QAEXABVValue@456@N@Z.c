void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::distanceSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  Scaleform::Render::BevelFilter *v4; // eax
  float Angle; // [esp+4h] [ebp-10h]
  float v6; // [esp+8h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-Ch]
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+10h] [ebp-4h]
  float valuea; // [esp+1Ch] [ebp+8h]
  float valueb; // [esp+1Ch] [ebp+8h]

  Angle = this->GetBevelFilterData(this)->Angle;
  v4 = this->GetBevelFilterData(this);
  valuea = value;
  valueb = valuea * 20.0;
  v4->Angle = Angle;
  v4->Distance = valueb;
  v6 = cos(Angle);
  v8 = v6 * valueb;
  v7 = sin(Angle);
  v9 = v7 * valueb;
  v4->Params.Offset.x = v8;
  v4->Params.Offset.y = v9;
}
