void __thiscall Scaleform::Render::Scale9GridTess::addVertices(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        const Scaleform::Render::Matrix2x4<float> *toUV,
        float x,
        float y,
        unsigned int code1,
        unsigned int code2)
{
  double v9; // st7
  double v10; // st5
  double v11; // st7
  float *p_x; // eax
  float v; // [esp+4h] [ebp-1Ch]
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer1; // [esp+8h] [ebp-18h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer2; // [esp+14h] [ebp-Ch] BYREF
  float u; // [esp+28h] [ebp+8h]

  v9 = toUV->M[0][1] * y;
  v10 = toUV->M[0][0];
  tmpVer2.AreaCode = code2;
  u = v10 * x + v9 + toUV->M[0][3];
  v11 = x * toUV->M[1][0] + y * toUV->M[1][1] + toUV->M[1][3];
  tmpVer1.AreaCode = code1;
  v = v11;
  tmpVer1.VerIdx = this->VerCount;
  tmpVer2.VerIdx = tmpVer1.VerIdx;
  tmpVer1.Slope = 0.0;
  tmpVer2.Slope = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer1);
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer2);
  p_x = &this->Vertices[this->VerCount].x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = u;
  p_x[3] = v;
  ++this->VerCount;
}
