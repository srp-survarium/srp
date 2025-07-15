Scaleform::Render::Color *__thiscall Scaleform::Render::Cxform::Transform(
        Scaleform::Render::Cxform *this,
        Scaleform::Render::Color *result,
        const Scaleform::Render::Color in)
{
  double v4; // st6
  double v5; // st5
  double v6; // st6
  double v7; // st7
  Scaleform::Render::Color *v8; // eax
  float v9; // [esp+0h] [ebp-10h]
  float v10; // [esp+4h] [ebp-Ch]
  float v11; // [esp+8h] [ebp-8h]
  float v12; // [esp+18h] [ebp+8h]
  float v13; // [esp+18h] [ebp+8h]
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]

  v12 = this->M[1][3] * 255.0 + (double)HIBYTE(in.Raw) * this->M[0][3];
  if ( v12 >= 255.0 )
  {
    v4 = 0.0;
    v12 = 255.0;
  }
  else
  {
    v4 = 0.0;
    if ( v12 < 0.0 )
    {
      v5 = 0.0;
      v6 = 255.0;
      v11 = 0.0;
      goto LABEL_6;
    }
  }
  v11 = v12;
  v5 = v4;
  v6 = 255.0;
LABEL_6:
  v13 = this->M[0][2] * (double)in.Channels.Blue + this->M[1][2] * 255.0;
  if ( v13 >= 255.0 )
  {
    v13 = v6;
  }
  else if ( v13 < v5 )
  {
    v10 = v5;
    goto LABEL_11;
  }
  v10 = v13;
LABEL_11:
  v14 = (double)in.Channels.Green * this->M[0][1] + this->M[1][1] * 255.0;
  if ( v14 >= 255.0 )
  {
    v14 = v6;
  }
  else if ( v14 < v5 )
  {
    v9 = v5;
    goto LABEL_16;
  }
  v9 = v14;
LABEL_16:
  v15 = (double)in.Channels.Red * this->M[0][0] + this->M[1][0] * 255.0;
  if ( v15 >= 255.0 )
  {
    v15 = v6;
    goto LABEL_18;
  }
  v7 = v5;
  if ( v15 >= v5 )
LABEL_18:
    v7 = v15;
  v16 = v7;
  result->Channels.Red = (int)v16;
  result->Channels.Green = (int)v9;
  result->Channels.Blue = (int)v10;
  v8 = result;
  result->Channels.Alpha = (int)v11;
  return v8;
}
