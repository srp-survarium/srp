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
  char cp3; // [esp+4h] [ebp-44h]
  char cp6; // [esp+6h] [ebp-42h]
  float c4; // [esp+8h] [ebp-40h]
  float c1; // [esp+Ch] [ebp-3Ch]
  float c2; // [esp+10h] [ebp-38h]
  float c3; // [esp+14h] [ebp-34h]
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer1; // [esp+18h] [ebp-30h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer2; // [esp+24h] [ebp-24h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer3; // [esp+30h] [ebp-18h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer4; // [esp+3Ch] [ebp-Ch] BYREF
  float u; // [esp+50h] [ebp+8h]
  float v; // [esp+5Ch] [ebp+14h]

  v12 = y;
  v13 = x;
  c1 = (x - c[2]) * (c[3] - c[1]) - (y - c[3]) * (c[2] - *c);
  c2 = (x - c[4]) * (c[5] - c[3]) - (c[4] - c[2]) * (y - c[5]);
  c3 = (x - c[6]) * (c[7] - c[5]) - (c[6] - c[4]) * (y - c[7]);
  c4 = (x - *c) * (c[1] - c[7]) - (*c - c[6]) * (y - c[1]);
  v14 = c2 <= 0.0;
  cp3 = c3 <= 0.0;
  cp6 = c2 >= 0.0;
  v15 = c3 >= 0.0;
  if ( c1 <= 0.0 == v14 && v14 == cp3 && cp3 == c4 <= 0.0 || c1 >= 0.0 == cp6 && cp6 == v15 && v15 == c4 >= 0.0 )
  {
    v16 = toUV->M[0][1] * v12;
    v17 = toUV->M[0][0];
    tmpVer2.AreaCode = code2;
    tmpVer3.AreaCode = code3;
    tmpVer4.AreaCode = code4;
    u = v16 + v17 * v13 + toUV->M[0][3];
    v18 = v12 * toUV->M[1][1] + v13 * toUV->M[1][0] + toUV->M[1][3];
    tmpVer1.AreaCode = code1;
    v = v18;
    tmpVer1.VerIdx = this->VerCount;
    tmpVer2.VerIdx = tmpVer1.VerIdx;
    tmpVer1.Slope = 0.0;
    tmpVer3.VerIdx = tmpVer1.VerIdx;
    tmpVer2.Slope = 0.0;
    tmpVer4.VerIdx = tmpVer1.VerIdx;
    tmpVer3.Slope = 0.0;
    tmpVer4.Slope = 0.0;
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer1);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer2);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer3);
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer4);
    p_x = &this->Vertices[this->VerCount].x;
    *p_x = x;
    p_x[1] = y;
    p_x[2] = u;
    p_x[3] = v;
    ++this->VerCount;
  }
}
