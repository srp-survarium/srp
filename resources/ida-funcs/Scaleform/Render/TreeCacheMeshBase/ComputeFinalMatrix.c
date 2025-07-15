void __thiscall Scaleform::Render::TreeCacheMeshBase::ComputeFinalMatrix(
        Scaleform::Render::TreeCacheMeshBase *this,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  bool v3; // zf
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // edi
  Scaleform::Render::Cxform *p_Cx; // ebx
  unsigned __int8 v6; // si
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix v8; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::Render::Matrix3x4<float> m; // [esp+10h] [ebp-30h] BYREF

  v3 = this->M.pHandle == &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  p_M = &this->M;
  v8.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)this;
  if ( v3 )
  {
    p_Cx = &t->Cx;
    v6 = !Scaleform::Render::Cxform::operator==(&t->Cx, &Scaleform::Render::Cxform::Identity);
    if ( (flags & 0x80u) == 0 )
    {
      v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
             (Scaleform::Render::MatrixPoolImpl::MatrixPool *)&v8.pHandle[8].pHeader[154],
             &v8,
             &t->Mat,
             p_Cx,
             v6);
    }
    else
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &m);
      v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
             (Scaleform::Render::MatrixPoolImpl::MatrixPool *)&v8.pHandle[8].pHeader[154],
             &v8,
             (const __m128i *)&m,
             p_Cx,
             v6 | 0x10);
    }
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v7);
    if ( v8.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v8.pHandle->pHeader);
  }
  else
  {
    if ( (flags & 0x80u) == 0 )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->M, &t->Mat);
    }
    else
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &m);
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(p_M, &m);
    }
    if ( (flags & 2) != 0 )
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(p_M, &t->Cx);
  }
}
