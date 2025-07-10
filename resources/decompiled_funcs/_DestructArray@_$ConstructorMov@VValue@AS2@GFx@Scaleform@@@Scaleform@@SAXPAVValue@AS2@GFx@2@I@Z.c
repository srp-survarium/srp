void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(
        Scaleform::GFx::AS2::Value *p,
        unsigned int count)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( v2->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v2);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
