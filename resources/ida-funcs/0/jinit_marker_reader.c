int __cdecl jinit_marker_reader(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ecx
  int v3; // edx

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 168);
  *(_DWORD *)(a1 + 420) = v1;
  *v1 = sub_372F70;
  v1[1] = sub_372A80;
  v1[2] = sub_372DD0;
  v1[6] = sub_372810;
  v1[23] = 0;
  v2 = v1 + 24;
  v3 = 16;
  do
  {
    *(v2 - 17) = sub_372810;
    *v2++ = 0;
    --v3;
  }
  while ( v3 );
  v1[7] = sub_372680;
  v1[21] = sub_372680;
  return sub_372F70((_DWORD *)a1);
}
