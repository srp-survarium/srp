void __thiscall Scaleform::GFx::DisplayObjectBase::SetRotation(
        Scaleform::GFx::DisplayObjectBase *this,
        long double rotation)
{
  long double v3; // st7
  bool v4; // al
  Scaleform::GFx::DisplayObjectBase_vtbl *v5; // edx
  int v6; // eax
  float *p_X; // ecx
  double v8; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // edi
  float sy; // [esp+8h] [ebp-58h]
  float radians; // [esp+Ch] [ebp-54h]
  double v13; // [esp+18h] [ebp-48h]
  float v14; // [esp+18h] [ebp-48h]
  float v15; // [esp+18h] [ebp-48h]
  float sx; // [esp+18h] [ebp-48h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+40h] [ebp-20h] BYREF

  if ( (HIDWORD(rotation) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(rotation) & 0xFFFFF | LODWORD(rotation)) )
  {
    this->SetAcceptAnimMoves(this, 0);
    v3 = fmod(rotation, 360.0);
    v13 = v3;
    if ( v3 <= 180.0 )
    {
      if ( v3 >= -180.0 )
        goto LABEL_8;
      v3 = v3 + 360.0;
    }
    else
    {
      v3 = v3 - 360.0;
    }
    v13 = v3;
LABEL_8:
    this->pGeomData->Rotation = v3;
    v4 = Scaleform::GFx::DisplayObjectBase::Has3D(this);
    v5 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v4 )
    {
      v5->UpdateTransform3D(this);
    }
    else
    {
      v6 = (int)v5->GetMatrix(this);
      p_X = (float *)&this->pGeomData->X;
      v8 = p_X[8];
      p_X += 8;
      m.M[0][0] = v8;
      pGeomData = this->pGeomData;
      m.M[0][1] = p_X[1];
      m.M[0][2] = p_X[2];
      m.M[0][3] = p_X[3];
      m.M[1][0] = p_X[4];
      m.M[1][1] = p_X[5];
      m.M[1][2] = p_X[6];
      m.M[1][3] = p_X[7];
      m.M[0][3] = *(float *)(v6 + 12);
      m.M[1][3] = *(float *)(v6 + 28);
      v14 = v13 * 3.141592653589793 / 180.0 - atan2(m.M[1][0], m.M[0][0]);
      radians = v14;
      v15 = pGeomData->YScale / (sqrt(m.M[0][1] * m.M[0][1] + m.M[1][1] * m.M[1][1]) * 100.0);
      sy = v15;
      sx = pGeomData->XScale / (sqrt(m.M[0][0] * m.M[0][0] + m.M[1][0] * m.M[1][0]) * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&m, sx, sy, radians);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        this->SetMatrix(this, &m);
    }
  }
}
