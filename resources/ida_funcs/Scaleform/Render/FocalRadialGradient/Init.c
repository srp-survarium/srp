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
  float da; // [esp+4h] [ebp+4h]
  float db; // [esp+4h] [ebp+4h]
  float dc; // [esp+4h] [ebp+4h]
  float d; // [esp+4h] [ebp+4h]
  float dd; // [esp+4h] [ebp+4h]
  float de; // [esp+4h] [ebp+4h]
  float df; // [esp+4h] [ebp+4h]

  v4 = r;
  this->Radius = r;
  this->FocusX = fx;
  v5 = fy;
  this->FocusY = fy;
  da = v4 * v4;
  v6 = da;
  this->Radius2 = da;
  db = v5 * v5;
  v7 = db;
  dc = fx * fx;
  d = v6 - (v7 + dc);
  if ( 0.0 == d )
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
    dd = this->FocusX * this->FocusX;
    v20 = dd;
    de = this->FocusY * this->FocusY;
    df = v18 - (v20 + de);
    this->Multiplier = v4 / df;
  }
  else
  {
    this->Multiplier = v4 / d;
  }
}
