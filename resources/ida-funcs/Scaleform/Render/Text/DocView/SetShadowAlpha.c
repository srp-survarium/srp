void __thiscall Scaleform::Render::Text::DocView::SetShadowAlpha(Scaleform::Render::Text::DocView *this, float a)
{
  double v2; // st7
  bool v3; // c0
  bool v4; // c3
  double v5; // st7
  unsigned __int8 v6; // al
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]

  v7 = a * 255.0;
  v2 = v7;
  if ( v7 >= 255.0 )
  {
    v7 = 255.0;
    goto LABEL_3;
  }
  v3 = v2 > 0.0;
  v4 = 0.0 == v2;
  v5 = 0.0;
  if ( v3 || v4 )
LABEL_3:
    v5 = v7;
  v8 = v5;
  v6 = (int)v8;
  this->Filter.ShadowAlpha = v6;
  this->Filter.ShadowParams.Colors[0].Channels.Alpha = v6;
}
