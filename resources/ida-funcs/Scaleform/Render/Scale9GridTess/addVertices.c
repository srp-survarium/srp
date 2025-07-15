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
  float v13; // [esp+4h] [ebp-1Ch]
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [esp+8h] [ebp-18h] BYREF
  Scaleform::Render::Scale9GridTess::TmpVertexType v15; // [esp+14h] [ebp-Ch] BYREF
  float v16; // [esp+28h] [ebp+8h]

  v9 = toUV->M[0][1] * y;
  v10 = toUV->M[0][0];
  v15.AreaCode = code2;
  v16 = v10 * x + v9 + toUV->M[0][3];
  v11 = x * toUV->M[1][0] + y * toUV->M[1][1] + toUV->M[1][3];
  val.AreaCode = code1;
  v13 = v11;
  val.VerIdx = this->VerCount;
  v15.VerIdx = val.VerIdx;
  val.Slope = 0.0;
  v15.Slope = 0.0;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &v15);
  p_x = &this->Vertices[this->VerCount].x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = v16;
  p_x[3] = v13;
  ++this->VerCount;
}
