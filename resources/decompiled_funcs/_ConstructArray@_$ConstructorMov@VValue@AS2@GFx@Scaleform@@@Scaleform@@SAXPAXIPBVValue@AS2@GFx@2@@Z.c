void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::ConstructArray(
        Scaleform::GFx::AS2::Value *p,
        unsigned int count,
        const Scaleform::GFx::AS2::Value *psource)
{
  unsigned int i; // ebx

  for ( i = count; i; --i )
  {
    if ( p )
      Scaleform::GFx::AS2::Value::Value(p, psource);
    ++psource;
    ++p;
  }
}
