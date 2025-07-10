void __cdecl Scaleform::ConstructorMov<Scaleform::Render::ComplexMesh::FillRecord>::DestructArray(
        Scaleform::Render::ComplexMesh::FillRecord *p,
        unsigned int count)
{
  Scaleform::Render::ComplexMesh::FillRecord *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pFill.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->pFill.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
