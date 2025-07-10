int *__usercall sub_37A780@<eax>(int a1@<eax>)
{
  int v1; // esi
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  int *result; // eax

  v1 = *(_DWORD *)(a1 + 436);
  v2 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 3072);
  *(_DWORD *)(v1 + 24) = v2;
  v3 = 0;
  v4 = 0;
  v5 = 0x8000;
  result = (int *)(v2 + 2048);
  do
  {
    *result = v5;
    *(result - 512) = v4;
    *(result - 256) = v3;
    v5 += 7471;
    v4 += 19595;
    ++result;
    v3 += 38470;
  }
  while ( v5 <= (int)byte_1D91D1 );
  return result;
}
