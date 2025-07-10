void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::MDKillListEntry>::DestructArray(
        Scaleform::GFx::MovieImpl::MDKillListEntry *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p_pMovieDef; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_pMovieDef = &p[count - 1].pMovieDef;
    v3 = count;
    do
    {
      if ( p_pMovieDef->pObject )
        Scaleform::GFx::Resource::Release(p_pMovieDef->pObject);
      p_pMovieDef -= 4;
      --v3;
    }
    while ( v3 );
  }
}
