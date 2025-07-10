void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextMeshEntry>::DestructArray(
        Scaleform::Render::TextMeshEntry *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::Render::PrimitiveFill> *p_pFill; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pFill = &p[count - 1].pFill;
    v3 = count;
    do
    {
      if ( p_pFill->pObject )
        Scaleform::RefCountNTSImpl::Release(p_pFill->pObject);
      p_pFill -= 8;
      --v3;
    }
    while ( v3 );
  }
}
