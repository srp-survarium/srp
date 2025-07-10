void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::DisplayList::DisplayEntry>::DestructArray(
        Scaleform::GFx::DisplayList::DisplayEntry *p,
        unsigned int count)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pCharacter )
        Scaleform::RefCountNTSImpl::Release(v2->pCharacter);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
