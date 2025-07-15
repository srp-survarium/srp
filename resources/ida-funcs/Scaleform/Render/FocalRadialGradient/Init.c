void __thiscall Scaleform::Render::FocalRadialGradient::Init(
        Scaleform::Render::FocalRadialGradient *this,
        float r,
        float fx,
        float fy)
{
  double v4; // st7
  double v5; // st5
  double v6; // st4
  double v7; // st2
  double v8; // st2
  double v9; // st6
  double v10; // st2
  bool v11; // c0
  bool v12; // c3
  double v13; // rtt
  double v14; // st4
  double v15; // st5
  double v16; // rt0
  double v17; // st5
  double v18; // st6
  double v19; // rt1
  double v20; // st5
  float v21; // [esp+4h] [ebp+4h]
  float v22; // [esp+4h] [ebp+4h]
  float v23; // [esp+4h] [ebp+4h]
  float v24; // [esp+4h] [ebp+4h]
  float v25; // [esp+4h] [ebp+4h]
  float v26; // [esp+4h] [ebp+4h]
  float v27; // [esp+4h] [ebp+4h]

  v4 = r;
  this->Radius = r;
  this->FocusX = fx;
  v5 = fy;
  this->FocusY = fy;
  v21 = v4 * v4;
  v6 = v21;
  this->Radius2 = v21;
  v22 = v5 * v5;
  v7 = v22;
  v23 = fx * fx;
  v24 = v6 - (v7 + v23);
  if ( 0.0 == v24 )
  {
    if ( 0.0 == fx )
    {
      v9 = 1.0;
    }
    else
    {
      v8 = fx;
      v9 = 1.0;
      if ( fx >= 0.0 )
        v10 = v8 - 1.0;
      else
        v10 = v8 + 1.0;
      this->FocusX = v10;
    }
    if ( 0.0 == v5 )
    {
      v18 = v6;
    }
    else
    {
      v11 = v5 > 0.0;
      v12 = 0.0 == v5;
      v13 = v6;
      v14 = fy;
      v15 = v13;
      if ( v11 || v12 )
      {
        v19 = v15;
        v17 = v14 - v9;
        v18 = v19;
      }
      else
      {
        v16 = v15;
        v17 = v9 + v14;
        v18 = v16;
      }
      this->FocusY = v17;
    }
    v25 = this->FocusX * this->FocusX;
    v20 = v25;
    v26 = this->FocusY * this->FocusY;
    v27 = v18 - (v20 + v26);
    this->Multiplier = v4 / v27;
  }
  else
  {
    this->Multiplier = v4 / v24;
  }
}
