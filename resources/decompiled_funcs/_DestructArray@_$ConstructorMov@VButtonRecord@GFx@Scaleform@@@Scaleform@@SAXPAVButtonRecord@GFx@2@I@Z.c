void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::DestructArray(
        Scaleform::GFx::ButtonRecord *p,
        unsigned int count)
{
  Scaleform::RefCountVImpl **p_pFilters; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pFilters = (Scaleform::RefCountVImpl **)&p[count - 1].pFilters;
    v3 = count;
    do
    {
      if ( *p_pFilters )
        Scaleform::RefCountImpl::Release(*p_pFilters);
      p_pFilters -= 24;
      --v3;
    }
    while ( v3 );
  }
}
