void __thiscall Scaleform::GFx::DisplayObjectBase::SetHeight(Scaleform::GFx::DisplayObjectBase *this, double height)
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
  double v12; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v13; // edi
  long double v14; // st7
  double XScale; // st7
  long double YScale; // st6
  long double v17; // st7
  float sy; // [esp+168h] [ebp-78h]
  float radians; // [esp+16Ch] [ebp-74h]
  double v20; // [esp+180h] [ebp-60h]
  float v21; // [esp+180h] [ebp-60h]
  float v22; // [esp+180h] [ebp-60h]
  float v23; // [esp+180h] [ebp-60h]
  float v24; // [esp+180h] [ebp-60h]
  float v25; // [esp+180h] [ebp-60h]
  double v26; // [esp+180h] [ebp-60h]
  float v27; // [esp+180h] [ebp-60h]
  float v28; // [esp+180h] [ebp-60h]
  float sx; // [esp+180h] [ebp-60h]
  double v30; // [esp+188h] [ebp-58h]
  double v31; // [esp+188h] [ebp-58h]
  long double v32[2]; // [esp+190h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> v33; // [esp+1A0h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v34; // [esp+1C0h] [ebp-20h] BYREF

  v20 = height;
  if ( ((HIDWORD(v20) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v20) | LODWORD(v20)))
    && height != -INFINITY )
  {
    if ( height == INFINITY )
      height = 0.0;
    this->SetAcceptAnimMoves(this, 0);
    p_X = (float *)&this->pGeomData->X;
    v4 = p_X[8];
    p_X += 8;
    v33.M[0][0] = v4;
    v33.M[0][1] = p_X[1];
    v33.M[0][2] = p_X[2];
    v33.M[0][3] = p_X[3];
    v33.M[1][0] = p_X[4];
    v33.M[1][1] = p_X[5];
    v33.M[1][2] = p_X[6];
    GetMatrix = this->GetMatrix;
    v33.M[1][3] = p_X[7];
    v6 = (int)GetMatrix(this);
    v33.M[0][3] = *(float *)(v6 + 12);
    v7 = *(float *)(v6 + 28);
    pGeomData = this->pGeomData;
    v33.M[1][3] = v7;
    v34.M[0][0] = v33.M[0][0];
    v34.M[0][1] = v33.M[0][1];
    v34.M[0][2] = v33.M[0][2];
    v34.M[0][3] = v33.M[0][3];
    v34.M[1][0] = v33.M[1][0];
    v34.M[1][1] = v33.M[1][1];
    v34.M[1][2] = v33.M[1][2];
    v34.M[1][3] = v33.M[1][3];
    v21 = pGeomData->Rotation * 3.141592653589793 / 180.0 - atan2(v33.M[1][0], v33.M[0][0]);
    Scaleform::Render::Matrix2x4<float>::AppendRotation(&v34, v21);
    v9 = this->GetBounds(this, v32, &v34);
    v22 = v9->y2 - v9->y1;
    v10 = v22;
    v23 = fabs(v22);
    if ( v23 <= 0.000001 )
    {
      v11 = 0.0;
    }
    else
    {
      v24 = height * 20.0;
      v11 = v24 / v10;
    }
    v30 = sqrt(v33.M[1][1] * v33.M[1][1] + v33.M[0][1] * v33.M[0][1]);
    v25 = v11;
    v26 = v25 * v30 * 100.0;
    this->pGeomData->YScale = v26;
    if ( 0.0 == v30 )
    {
      v26 = 0.0;
      v30 = 1.0;
    }
    v32[0] = atan2(v33.M[1][0], v33.M[0][0]);
    v12 = v26 / (v30 * 100.0);
    if ( v12 < 0.0 )
      v12 = -v12;
    v13 = this->pGeomData;
    v31 = v12;
    v14 = v13->XScale / (sqrt(v33.M[1][0] * v33.M[1][0] + v33.M[0][0] * v33.M[0][0]) * 100.0);
    if ( v14 < 0.0 )
      v14 = -v14;
    v27 = v13->Rotation * 3.141592653589793 / 180.0 - v32[0];
    radians = v27;
    v28 = v31;
    sy = v28;
    sx = v14;
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&v33, sx, sy, radians);
    XScale = v13->XScale;
    if ( XScale < 0.0 )
      XScale = -XScale;
    v13->XScale = XScale;
    YScale = this->pGeomData->YScale;
    v17 = YScale;
    if ( YScale < 0.0 )
      v17 = -YScale;
    this->pGeomData->YScale = v17;
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v33) )
      this->SetMatrix(this, &v33);
  }
}
