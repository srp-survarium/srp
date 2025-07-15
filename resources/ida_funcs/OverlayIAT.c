void __usercall OverlayIAT(_IMAGE_THUNK_DATA32 *pitdDst@<ecx>, const _IMAGE_THUNK_DATA32 *pitdSrc@<eax>)
{
  _IMAGE_THUNK_DATA32 *v2; // esi
  int i; // edx
  int v4; // ecx
  int v5; // esi

  v2 = pitdDst;
  for ( i = 0; pitdDst->u1.ForwarderString; ++i )
    ++pitdDst;
  v4 = 4 * i;
  if ( 4 * i )
  {
    v5 = (char *)v2 - (char *)pitdSrc;
    do
    {
      --v4;
      *((_BYTE *)&pitdSrc->u1.ForwarderString + v5) = pitdSrc->u1.ForwarderString;
      pitdSrc = (const _IMAGE_THUNK_DATA32 *)((char *)pitdSrc + 1);
    }
    while ( v4 );
  }
}
