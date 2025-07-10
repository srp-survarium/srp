void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        Scaleform::GFx::AS3::Value *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Value *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( (v2->Flags & 0x1F) > 9 )
      {
        if ( (v2->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v2);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
