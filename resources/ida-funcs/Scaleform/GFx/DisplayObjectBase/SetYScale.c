void __thiscall Scaleform::GFx::DisplayObjectBase::SetYScale(
        Scaleform::GFx::DisplayObjectBase *this,
        long double yscale)
{
  bool v3; // al
  Scaleform::GFx::DisplayObjectBase_vtbl *v4; // edx
  int v5; // edi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // edi
  float sy; // [esp+8h] [ebp-58h]
  float radians; // [esp+Ch] [ebp-54h]
  double v9; // [esp+20h] [ebp-40h]
  float v10; // [esp+20h] [ebp-40h]
  float v11; // [esp+20h] [ebp-40h]
  float sx; // [esp+20h] [ebp-40h]
  double v13; // [esp+28h] [ebp-38h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+40h] [ebp-20h] BYREF

  v9 = yscale;
  if ( ((HIDWORD(v9) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(v9) & 0xFFFFF | LODWORD(v9)))
    && yscale != -INFINITY
    && yscale != INFINITY )
  {
    this->SetAcceptAnimMoves(this, 0);
    this->pGeomData->YScale = yscale;
    v3 = Scaleform::GFx::DisplayObjectBase::Has3D(this);
    v4 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( v3 )
    {
      v4->UpdateTransform3D(this);
    }
    else
    {
      v5 = (int)v4->GetMatrix(this);
      Scaleform::Render::Matrix2x4<float>::operator=(&m, &this->pGeomData->OrigMatrix);
      m.M[0][3] = *(float *)(v5 + 12);
      m.M[1][3] = *(float *)(v5 + 28);
      v13 = sqrt(m.M[1][1] * m.M[1][1] + m.M[0][1] * m.M[0][1]);
      if ( 0.0 == v13 || yscale > 1.0e16 )
      {
        yscale = 0.0;
        v13 = 1.0;
      }
      pGeomData = this->pGeomData;
      v10 = pGeomData->Rotation * 3.141592653589793 / 180.0 - atan2(m.M[1][0], m.M[0][0]);
      radians = v10;
      v11 = yscale / (v13 * 100.0);
      sy = v11;
      sx = pGeomData->XScale / (sqrt(m.M[0][0] * m.M[0][0] + m.M[1][0] * m.M[1][0]) * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&m, sx, sy, radians);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        this->SetMatrix(this, &m);
    }
  }
}
