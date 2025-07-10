void __thiscall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        const Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  Scaleform::Render::Point<float> v5; // [esp+4h] [ebp-8h]
  float paramsa; // [esp+10h] [ebp+4h]
  float anglea; // [esp+14h] [ebp+8h]
  float dista; // [esp+18h] [ebp+Ch]

  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_Shadow;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  paramsa = dist * 20.0;
  this->Angle = angle;
  this->Distance = paramsa;
  dista = cos(angle);
  v5.x = dista * paramsa;
  anglea = sin(angle);
  v5.y = anglea * paramsa;
  this->Params.Offset = v5;
}
