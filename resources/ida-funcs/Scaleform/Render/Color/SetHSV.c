void __thiscall Scaleform::Render::Color::SetHSV(Scaleform::Render::Color *this, float h, float s, float v)
{
  double v4; // st6
  double v5; // st7
  int v6; // eax
  double v7; // st6
  double v8; // st7
  float v9; // [esp+10h] [ebp-8h]
  float v10; // [esp+14h] [ebp-4h]
  float b; // [esp+1Ch] [ebp+4h]
  float v12; // [esp+1Ch] [ebp+4h]
  float v13; // [esp+1Ch] [ebp+4h]
  float r; // [esp+20h] [ebp+8h]
  float v15; // [esp+20h] [ebp+8h]

  if ( s == 0.0 )
  {
    b = v;
    r = v;
  }
  else
  {
    if ( h == 1.0 )
    {
      v4 = 0.0;
      v5 = s;
    }
    else
    {
      v5 = s;
      v4 = h * 6.0;
    }
    v12 = v4;
    v6 = (int)v12;
    v15 = v12 - (double)v6;
    v13 = (1.0 - v5) * v;
    v10 = (1.0 - v15 * v5) * v;
    v7 = (1.0 - v5 * (1.0 - v15)) * v;
    v8 = v;
    switch ( v6 )
    {
      case 0:
        r = v;
        v = v7;
        v8 = v13;
        break;
      case 1:
        r = v10;
        v8 = v13;
        break;
      case 2:
        r = v13;
        v9 = v7;
        v8 = v9;
        break;
      case 3:
        r = v13;
        v = v10;
        break;
      case 4:
        r = v7;
        v = v13;
        break;
      default:
        r = v;
        v = v13;
        v8 = v10;
        break;
    }
    b = v8;
  }
  Scaleform::Render::Color::SetRGBFloat(this, r, v, b);
}
