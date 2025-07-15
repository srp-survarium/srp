void __fastcall btSoftBody::Body::activate(btSoftBody::Body *this, int a2)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 && (*(_BYTE *)(v2 + 216) & 3) == 0 )
  {
    v3 = *(_DWORD *)(v2 + 228);
    if ( v3 != 4 && v3 != 5 )
      *(_DWORD *)(v2 + 228) = 1;
    *(_DWORD *)(v2 + 232) = 0;
  }
  v4 = *(_DWORD *)(a2 + 8);
  if ( v4 && (*(_BYTE *)(v4 + 216) & 3) == 0 )
  {
    v5 = *(_DWORD *)(v4 + 228);
    if ( v5 != 4 && v5 != 5 )
      *(_DWORD *)(v4 + 228) = 1;
    *(_DWORD *)(v4 + 232) = 0;
  }
}
