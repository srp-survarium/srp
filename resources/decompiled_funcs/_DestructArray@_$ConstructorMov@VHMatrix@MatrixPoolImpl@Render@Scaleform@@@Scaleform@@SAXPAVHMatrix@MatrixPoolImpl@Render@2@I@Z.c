void __cdecl Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
        Scaleform::Render::MatrixPoolImpl::HMatrix *p,
        unsigned int count)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v2->pHandle->pHeader);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
