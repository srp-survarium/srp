void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership>::DestructArray(
        Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *p,
        unsigned int count)
{
  Scaleform::GFx::XML::DOMBuilder::PrefixOwnership *v2; // esi
  unsigned int v3; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      pObject = v2->Owner.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      if ( v2->mPrefix.pObject )
        Scaleform::RefCountNTSImpl::Release(v2->mPrefix.pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
