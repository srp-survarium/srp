void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 12;
    do
    {
      if ( v3 != (char *)12 )
      {
        v3[4] = 0;
        *((_DWORD *)v3 - 1) = 0;
        *(_DWORD *)v3 = 0;
      }
      v3 += 28;
      --v2;
    }
    while ( v2 );
  }
}
