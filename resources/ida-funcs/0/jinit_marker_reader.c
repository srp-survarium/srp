int __cdecl jinit_marker_reader(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ecx
  int v3; // edx

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 168);
  *(_DWORD *)(a1 + 420) = v1;
  *v1 = sub_47FC30;
  v1[1] = sub_47F740;
  v1[2] = sub_47FA90;
  v1[6] = sub_47F4D0;
  v1[23] = 0;
  v2 = v1 + 24;
  v3 = 16;
  do
  {
    *(v2 - 17) = sub_47F4D0;
    *v2++ = 0;
    --v3;
  }
  while ( v3 );
  v1[7] = sub_47F340;
  v1[21] = sub_47F340;
  return sub_47FC30((_DWORD *)a1);
}
