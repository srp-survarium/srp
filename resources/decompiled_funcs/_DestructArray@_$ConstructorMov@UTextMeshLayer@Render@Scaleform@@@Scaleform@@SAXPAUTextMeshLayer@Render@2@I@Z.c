void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextMeshLayer>::DestructArray(
        Scaleform::Render::TextMeshLayer *p,
        unsigned int count)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pHandle; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // eax
  Scaleform::Render::MeshKey *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  if ( count )
  {
    p_M = &p[count - 1].M;
    v3 = count;
    do
    {
      pHandle = (Scaleform::RefCountNTSImpl *)p_M[1].pHandle;
      if ( pHandle )
        Scaleform::RefCountNTSImpl::Release(pHandle);
      if ( p_M->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(p_M->pHandle->pHeader);
      v5 = p_M[-1].pHandle;
      if ( v5 )
        (*(void (__thiscall **)(Scaleform::Render::MatrixPoolImpl::EntryHandle *))&v5[2].pHeader->DataPageOffset)(v5 + 2);
      v6 = (Scaleform::Render::MeshKey *)p_M[-2].pHandle;
      if ( v6 )
        Scaleform::Render::MeshKey::Release(v6);
      v7 = (Scaleform::RefCountVImpl *)p_M[-3].pHandle;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      p_M -= 9;
      --v3;
    }
    while ( v3 );
  }
}
