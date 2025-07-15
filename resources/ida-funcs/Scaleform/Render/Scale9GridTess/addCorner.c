void __thiscall Scaleform::Render::Scale9GridTess::addCorner(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        const float *c,
        float x,
        float y,
        const Scaleform::Render::Matrix2x4<float> *toUV,
        unsigned int code1,
        unsigned int code2,
        unsigned int code3,
        unsigned int code4)
{
  double v12; // st6
  double v13; // st7
  char v14; // bl
  char v15; // cl
  double v16; // st4
  double v17; // st3
  double v18; // st6
  float *p_x; // eax
  char v20; // [esp+4h] [ebp-44h]
  char v21; // [esp+6h] [ebp-42h]
  float v22; // [esp+8h] [ebp-40h]
  float v23; // [esp+Ch] [ebp-3Ch]
  float v24; // [esp+10h] [ebp-38h]
  float v25; // [esp+14h] [ebp-34h]
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [esp+18h] [ebp-30h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v27; // [esp+24h] [ebp-24h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v28; // [esp+30h] [ebp-18h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v29; // [esp+3Ch] [ebp-Ch] BYREF
  float v30; // [esp+50h] [ebp+8h]
  float v31; // [esp+5Ch] [ebp+14h]

  v12 = y;
  v13 = x;
  v23 = (x - c[2]) * (c[3] - c[1]) - (y - c[3]) * (c[2] - *c);
  v24 = (x - c[4]) * (c[5] - c[3]) - (c[4] - c[2]) * (y - c[5]);
  v25 = (x - c[6]) * (c[7] - c[5]) - (c[6] - c[4]) * (y - c[7]);
  v22 = (x - *c) * (c[1] - c[7]) - (*c - c[6]) * (y - c[1]);
  v14 = v24 <= 0.0;
  v20 = v25 <= 0.0;
  v21 = v24 >= 0.0;
  v15 = v25 >= 0.0;
  if ( v23 <= 0.0 == v14 && v14 == v20 && v20 == v22 <= 0.0 || v23 >= 0.0 == v21 && v21 == v15 && v15 == v22 >= 0.0 )
  {
    v16 = toUV->M[0][1] * v12;
    v17 = toUV->M[0][0];
    v27.AreaCode = code2;
    v28.AreaCode = code3;
    v29.AreaCode = code4;
    v30 = v16 + v17 * v13 + toUV->M[0][3];
    v18 = v12 * toUV->M[1][1] + v13 * toUV->M[1][0] + toUV->M[1][3];
    val.AreaCode = code1;
    v31 = v18;
    val.VerIdx = this->VerCount;
    v27.VerIdx = val.VerIdx;
    val.Slope = 0.0;
    v28.VerIdx = val.VerIdx;
    v27.Slope = 0.0;
    v29.VerIdx = val.VerIdx;
    v28.Slope = 0.0;
    v29.Slope = 0.0;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v27);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v28);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v29);
    p_x = &this->Vertices[this->VerCount].x;
    *p_x = x;
    p_x[1] = y;
    p_x[2] = v30;
    p_x[3] = v31;
    ++this->VerCount;
  }
}
