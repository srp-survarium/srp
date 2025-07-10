void __cdecl Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  _DWORD *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 16;
    do
    {
      if ( v3 != (_DWORD *)16 )
      {
        *(v3 - 4) = 0;
        *(v3 - 3) = 0;
        *(v3 - 2) = 0;
        *(v3 - 1) = 0;
        *v3 = 0;
      }
      v3 += 5;
      --v2;
    }
    while ( v2 );
  }
}
