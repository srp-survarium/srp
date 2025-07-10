void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
        Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *p,
        unsigned int count)
{
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->pObject )
        Scaleform::GFx::Resource::Release(v2->pObject);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
