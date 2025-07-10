void __thiscall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        float angle,
        float dist,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::Point<float> v7; // [esp+4h] [ebp-8h]
  float anglea; // [esp+10h] [ebp+4h]
  float blurxa; // [esp+18h] [ebp+Ch]
  float blurya; // [esp+1Ch] [ebp+10h]

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Shadow);
  this->__vftable = (Scaleform::Render::ShadowFilter_vtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  this->Params.Passes = passes;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  blurxa = 20.0 * dist;
  this->Angle = angle;
  this->Distance = blurxa;
  blurya = cos(angle);
  v7.x = blurya * blurxa;
  anglea = sin(angle);
  v7.y = anglea * blurxa;
  this->Params.Offset = v7;
  this->Params.Colors[0].Channels.Red = 0;
  this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
}
