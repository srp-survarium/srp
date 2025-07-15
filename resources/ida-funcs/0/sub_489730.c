int __usercall sub_489730@<eax>(int a1@<eax>, int a2@<ecx>)
{
  int v3; // ebp
  int v4; // ebx
  double *v5; // edi
  int v6; // esi
  int i; // ecx
  int v8; // eax

  v3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v4 = (a2 << 9) - 512;
  v5 = dbl_6F6898;
  v6 = v3;
  do
  {
    for ( i = 0; i < 16; ++i )
    {
      v8 = (65025 - 510 * *((unsigned __int8 *)v5 + i)) / v4;
      v6 += 4;
      *(_DWORD *)(v6 - 4) = v8;
    }
    v5 += 2;
  }
  while ( (int)v5 < (int)dword_6F6998 );
  return v3;
}
