void __thiscall Scaleform::GFx::DisplayObjectBase::SetWidth(Scaleform::GFx::DisplayObjectBase *this, double width)
{
  float *p_X; // eax
  double v4; // st7
  const Scaleform::Render::Matrix2x4<float> *(__thiscall *GetMatrix)(Scaleform::GFx::DisplayObjectBase *); // edx
  int v6; // eax
  double v7; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // eax
  Scaleform::Render::Rect<float> *v9; // eax
  double v10; // st7
  double v11; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v12; // edi
  long double v13; // st7
  double v14; // st6
  double XScale; // st7
  long double YScale; // st6
  long double v17; // st7
  float sy; // [esp+10h] [ebp-78h]
  float radians; // [esp+14h] [ebp-74h]
  double v20; // [esp+28h] [ebp-60h]
  float v21; // [esp+28h] [ebp-60h]
  float v22; // [esp+28h] [ebp-60h]
  float v23; // [esp+28h] [ebp-60h]
  float v24; // [esp+28h] [ebp-60h]
  float v25; // [esp+28h] [ebp-60h]
  double v26; // [esp+28h] [ebp-60h]
  float v27; // [esp+28h] [ebp-60h]
  float v28; // [esp+28h] [ebp-60h]
  float sx; // [esp+28h] [ebp-60h]
  double v30; // [esp+30h] [ebp-58h]
  long double v31[2]; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+48h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v33; // [esp+68h] [ebp-20h] BYREF

  v20 = width;
  if ( ((HIDWORD(v20) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(v20) & 0xFFFFF | LODWORD(v20))) && width != -INFINITY )
  {
    if ( width == INFINITY )
      width = 0.0;
    this->SetAcceptAnimMoves(this, 0);
    p_X = (float *)&this->pGeomData->X;
    v4 = p_X[8];
    p_X += 8;
    m.M[0][0] = v4;
    m.M[0][1] = p_X[1];
    m.M[0][2] = p_X[2];
    m.M[0][3] = p_X[3];
    m.M[1][0] = p_X[4];
    m.M[1][1] = p_X[5];
    m.M[1][2] = p_X[6];
    GetMatrix = this->GetMatrix;
    m.M[1][3] = p_X[7];
    v6 = (int)GetMatrix(this);
    m.M[0][3] = *(float *)(v6 + 12);
    v7 = *(float *)(v6 + 28);
    pGeomData = this->pGeomData;
    m.M[1][3] = v7;
    v33.M[0][0] = m.M[0][0];
    v33.M[0][1] = m.M[0][1];
    v33.M[0][2] = m.M[0][2];
    v33.M[0][3] = m.M[0][3];
    v33.M[1][0] = m.M[1][0];
    v33.M[1][1] = m.M[1][1];
    v33.M[1][2] = m.M[1][2];
    v33.M[1][3] = m.M[1][3];
    v21 = pGeomData->Rotation * 3.141592653589793 / 180.0 - atan2(m.M[1][0], m.M[0][0]);
    Scaleform::Render::Matrix2x4<float>::AppendRotation(&v33, v21);
    v9 = this->GetBounds(this, v31, &v33);
    v22 = v9->x2 - v9->x1;
    v10 = v22;
    v23 = fabs(v22);
    if ( v23 <= 0.000001 )
    {
      v11 = 0.0;
    }
    else
    {
      v24 = width * 20.0;
      v11 = v24 / v10;
    }
    v30 = sqrt(m.M[1][0] * m.M[1][0] + m.M[0][0] * m.M[0][0]);
    v25 = v11;
    v26 = v25 * v30 * 100.0;
    this->pGeomData->XScale = v26;
    if ( 0.0 == v30 )
    {
      v26 = 0.0;
      v30 = 1.0;
    }
    v31[0] = atan2(m.M[1][0], m.M[0][0]);
    v12 = this->pGeomData;
    v13 = v12->YScale / (sqrt(m.M[1][1] * m.M[1][1] + m.M[0][1] * m.M[0][1]) * 100.0);
    if ( v13 < 0.0 )
      v13 = -v13;
    v14 = v26 / (100.0 * v30);
    if ( v14 < 0.0 )
      v14 = -v14;
    v27 = v12->Rotation * 3.141592653589793 / 180.0 - v31[0];
    radians = v27;
    v28 = v13;
    sy = v28;
    sx = v14;
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&m, sx, sy, radians);
    XScale = v12->XScale;
    if ( XScale < 0.0 )
      XScale = -XScale;
    v12->XScale = XScale;
    YScale = this->pGeomData->YScale;
    v17 = YScale;
    if ( YScale < 0.0 )
      v17 = -YScale;
    this->pGeomData->YScale = v17;
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
      this->SetMatrix(this, &m);
  }
}
