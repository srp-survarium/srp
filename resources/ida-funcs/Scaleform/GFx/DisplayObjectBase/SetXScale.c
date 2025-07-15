void __thiscall Scaleform::GFx::DisplayObjectBase::SetXScale(Scaleform::GFx::DisplayObjectBase *this, double xscale)
{
  bool v3; // al
  Scaleform::GFx::DisplayObjectBase_vtbl *v4; // edx
  int v5; // edi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // edi
  float m_16; // [esp+48h] [ebp-58h]
  float m_20; // [esp+4Ch] [ebp-54h]
  double v9; // [esp+60h] [ebp-40h]
  float v10; // [esp+60h] [ebp-40h]
  float v11; // [esp+60h] [ebp-40h]
  float v12; // [esp+60h] [ebp-40h]
  double v13; // [esp+68h] [ebp-38h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+80h] [ebp-20h] BYREF

  v9 = xscale;
  if ( ((HIDWORD(v9) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v9) | LODWORD(v9)))
    && xscale != -INFINITY
    && xscale != INFINITY )
  {
    this->SetAcceptAnimMoves(this, 0);
    this->pGeomData->XScale = xscale;
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
      v13 = sqrt(m.M[1][0] * m.M[1][0] + m.M[0][0] * m.M[0][0]);
      if ( 0.0 == v13 || xscale > 1.0e16 )
      {
        xscale = 0.0;
        v13 = 1.0;
      }
      pGeomData = this->pGeomData;
      v10 = pGeomData->Rotation * 3.141592653589793 / 180.0 - atan2(m.M[1][0], m.M[0][0]);
      m_20 = v10;
      v11 = pGeomData->YScale / (sqrt(m.M[0][1] * m.M[0][1] + m.M[1][1] * m.M[1][1]) * 100.0);
      m_16 = v11;
      v12 = xscale / (100.0 * v13);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(&m, v12, m_16, m_20);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        this->SetMatrix(this, &m);
    }
  }
}
