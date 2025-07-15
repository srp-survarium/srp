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
  float sy; // [esp+58h] [ebp-58h]
  float radians; // [esp+5Ch] [ebp-54h]
  double v13; // [esp+68h] [ebp-48h]
  float v14; // [esp+68h] [ebp-48h]
  float v15; // [esp+68h] [ebp-48h]
  float sx; // [esp+68h] [ebp-48h]
  Scaleform::Render::Matrix2x4<float> v17; // [esp+90h] [ebp-20h] BYREF

  if ( (HIDWORD(rotation) & 0x7FF00000) != 0x7FF00000
    || !((unsigned int)&loc_FFFFF & HIDWORD(rotation) | LODWORD(rotation)) )
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
      v17.M[0][0] = v8;
      pGeomData = this->pGeomData;
      v17.M[0][1] = p_X[1];
      v17.M[0][2] = p_X[2];
      v17.M[0][3] = p_X[3];
      v17.M[1][0] = p_X[4];
      v17.M[1][1] = p_X[5];
      v17.M[1][2] = p_X[6];
      v17.M[1][3] = p_X[7];
      v17.M[0][3] = *(float *)(v6 + 12);
      v17.M[1][3] = *(float *)(v6 + 28);
      v14 = v13 * 3.141592653589793 / 180.0 - atan2(v17.M[1][0], v17.M[0][0]);
      radians = v14;
      v15 = pGeomData->YScale / (sqrt(v17.M[0][1] * v17.M[0][1] + v17.M[1][1] * v17.M[1][1]) * 100.0);
      sy = v15;
      sx = pGeomData->XScale / (sqrt(v17.M[0][0] * v17.M[0][0] + v17.M[1][0] * v17.M[1][0]) * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&v17, sx, sy, radians);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v17) )
        this->SetMatrix(this, &v17);
    }
  }
}
