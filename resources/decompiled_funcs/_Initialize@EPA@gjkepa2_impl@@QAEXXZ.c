void __usercall gjkepa2_impl::EPA::Initialize(gjkepa2_impl::EPA *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // ecx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  _DWORD *v7; // edx
  bool v8; // zf
  int v9; // [esp+0h] [ebp-14h]

  *(_QWORD *)(a2 + 48) = 0;
  *(_DWORD *)a2 = 9;
  *(_QWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 10320) = 0;
  v2 = (_DWORD *)(a2 + 10308);
  v9 = 32;
  do
  {
    *(v2 - 1) = 0;
    *v2 = *(_DWORD *)(a2 + 10332);
    v3 = *(_DWORD *)(a2 + 10332);
    if ( v3 )
      *(_DWORD *)(v3 + 48) = v2 - 13;
    ++*(_DWORD *)(a2 + 10336);
    *(_DWORD *)(a2 + 10332) = v2 - 13;
    *(v2 - 17) = 0;
    *(v2 - 16) = *(_DWORD *)(a2 + 10332);
    v4 = *(_DWORD *)(a2 + 10332);
    if ( v4 )
      *(_DWORD *)(v4 + 48) = v2 - 29;
    ++*(_DWORD *)(a2 + 10336);
    *(_DWORD *)(a2 + 10332) = v2 - 29;
    *(v2 - 33) = 0;
    *(v2 - 32) = *(_DWORD *)(a2 + 10332);
    v5 = *(_DWORD *)(a2 + 10332);
    if ( v5 )
      *(_DWORD *)(v5 + 48) = v2 - 45;
    ++*(_DWORD *)(a2 + 10336);
    *(_DWORD *)(a2 + 10332) = v2 - 45;
    *(v2 - 49) = 0;
    *(v2 - 48) = *(_DWORD *)(a2 + 10332);
    v6 = *(_DWORD *)(a2 + 10332);
    if ( v6 )
      *(_DWORD *)(v6 + 48) = v2 - 61;
    ++*(_DWORD *)(a2 + 10336);
    v7 = v2 - 61;
    v2 -= 64;
    v8 = v9-- == 1;
    *(_DWORD *)(a2 + 10332) = v7;
  }
  while ( !v8 );
}
