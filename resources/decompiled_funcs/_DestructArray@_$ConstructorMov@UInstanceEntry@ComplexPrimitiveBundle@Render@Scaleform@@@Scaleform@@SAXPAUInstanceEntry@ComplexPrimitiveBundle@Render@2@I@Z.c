void __cdecl Scaleform::ConstructorMov<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry>::DestructArray(
        Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *p,
        unsigned int count)
{
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = (Scaleform::RefCountVImpl *)v2->pMesh.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      if ( v2->M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v2->M.pHandle->pHeader);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
