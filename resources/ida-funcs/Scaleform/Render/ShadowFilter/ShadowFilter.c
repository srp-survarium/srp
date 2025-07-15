void __thiscall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        const Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  Scaleform::Render::Point<float> v5; // [esp+4h] [ebp-8h]
  float __that; // [esp+10h] [ebp+4h]
  float v7; // [esp+14h] [ebp+8h]
  float v8; // [esp+18h] [ebp+Ch]

  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_Shadow;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  __that = dist * 20.0;
  this->Angle = angle;
  this->Distance = __that;
  v8 = cos(angle);
  v5.x = v8 * __that;
  v7 = sin(angle);
  v5.y = v7 * __that;
  this->Params.Offset = v5;
}


void __thiscall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        float angle,
        float dist,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::Point<float> v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+18h] [ebp+Ch]
  float v10; // [esp+1Ch] [ebp+10h]

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Shadow);
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  this->Params.Passes = passes;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  v9 = 20.0 * dist;
  this->Angle = angle;
  this->Distance = v9;
  v10 = cos(angle);
  v7.x = v10 * v9;
  v8 = sin(angle);
  v7.y = v8 * v9;
  this->Params.Offset = v7;
  this->Params.Colors[0].Channels.Red = 0;
  this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
}
