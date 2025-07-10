void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::Text::CSSToken<wchar_t>>::ConstructArray(
        _DWORD *p,
        unsigned int count)
{
  unsigned int i; // ecx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = 11;
      p[1] = 0;
      p[2] = 0;
    }
    p += 3;
  }
}
