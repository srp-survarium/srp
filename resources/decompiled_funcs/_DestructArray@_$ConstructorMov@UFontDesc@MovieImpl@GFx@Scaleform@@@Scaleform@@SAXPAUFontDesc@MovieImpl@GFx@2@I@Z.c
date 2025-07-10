void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::FontDesc>::DestructArray(
        Scaleform::GFx::MovieImpl::FontDesc *p,
        unsigned int count)
{
  Scaleform::GFx::MovieImpl::FontDesc *v2; // esi
  unsigned int v3; // edi
  Scaleform::GFx::Resource *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->pFont.pObject;
      if ( pObject )
        Scaleform::GFx::Resource::Release(pObject);
      if ( v2->pMovieDef.pObject )
        Scaleform::GFx::Resource::Release(v2->pMovieDef.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
