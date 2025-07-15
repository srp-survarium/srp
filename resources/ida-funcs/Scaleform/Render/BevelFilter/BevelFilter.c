void __thiscall Scaleform::Render::BevelFilter::BevelFilter(
        Scaleform::Render::BevelFilter *this,
        const Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  Scaleform::Render::Point<float> v5; // [esp+4h] [ebp-8h]
  float __that; // [esp+10h] [ebp+4h]
  float v7; // [esp+14h] [ebp+8h]
  float v8; // [esp+18h] [ebp+Ch]

  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_Bevel;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::Render::BevelFilter::`vftable';
  __that = dist * 20.0;
  this->Angle = angle;
  this->Distance = __that;
  v8 = cos(angle);
  v5.x = v8 * __that;
  v7 = sin(angle);
  v5.y = v7 * __that;
  this->Params.Offset = v5;
}


void __thiscall Scaleform::Render::BevelFilter::BevelFilter(
        Scaleform::Render::BevelFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::Point<float> v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+10h] [ebp+4h]
  float v7; // [esp+10h] [ebp+4h]

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Bevel);
  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::Render::BevelFilter::`vftable';
  this->Params.Passes = passes;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = 20.0 * blury;
  this->Angle = 0.78539819;
  this->Distance = 80.0;
  v6 = cos(0.7853981852531433);
  v5.x = v6 * 80.0;
  v7 = sin(0.7853981852531433);
  v5.y = v7 * 80.0;
  this->Params.Offset = v5;
  this->Params.Mode |= 0xA0u;
  this->Params.Colors[0].Channels.Red = 0;
  this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
  this->Params.Colors[1].Channels.Red = -1;
  this->Params.Colors[1].Channels.Green = -1;
  this->Params.Colors[1].Channels.Blue = -1;
  this->Params.Colors[1].Channels.Alpha = -1;
}
