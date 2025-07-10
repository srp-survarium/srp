void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::DisplayList::DisplayEntry>::ConstructArray(
        _DWORD *p,
        unsigned int count)
{
  unsigned int i; // ecx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = 0;
      p[2] = -1;
      p[1] = -1;
    }
    p += 3;
  }
}
