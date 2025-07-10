void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // edi
  double v3; // st7
  double v4; // st6
  char *v5; // esi

  v2 = count;
  if ( count )
  {
    v3 = 1.0;
    v4 = 0.0;
    v5 = p + 8;
    do
    {
      if ( v5 != (char *)8 )
      {
        *((float *)v5 - 2) = v3;
        *((float *)v5 + 3) = v3;
        *((float *)v5 - 1) = v4;
        *(float *)v5 = v4;
        *((float *)v5 + 1) = v4;
        *((float *)v5 + 2) = v4;
        *((float *)v5 + 4) = v4;
        *((float *)v5 + 5) = v4;
        Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)(v5 + 24));
        v3 = 1.0;
        *((_DWORD *)v5 + 14) = 0;
        v4 = 0.0;
        *((_DWORD *)v5 + 15) = 0x40000;
        v5[72] = 0;
      }
      v5 += 96;
      --v2;
    }
    while ( v2 );
  }
}
