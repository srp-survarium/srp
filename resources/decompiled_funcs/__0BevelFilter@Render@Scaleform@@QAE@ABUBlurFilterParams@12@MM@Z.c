void __thiscall Scaleform::Render::BevelFilter::BevelFilter(
        Scaleform::Render::BevelFilter *this,
        const Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  Scaleform::Render::Point<float> v5; // [esp+4h] [ebp-8h]
  float paramsa; // [esp+10h] [ebp+4h]
  float anglea; // [esp+14h] [ebp+8h]
  float dista; // [esp+18h] [ebp+Ch]

  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Type = Filter_Bevel;
  this->Frozen = 0;
  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  this->__vftable = (Scaleform::Render::BevelFilter_vtbl *)&Scaleform::Render::BevelFilter::`vftable';
  paramsa = dist * 20.0;
  this->Angle = angle;
  this->Distance = paramsa;
  dista = cos(angle);
  v5.x = dista * paramsa;
  anglea = sin(angle);
  v5.y = anglea * paramsa;
  this->Params.Offset = v5;
}
