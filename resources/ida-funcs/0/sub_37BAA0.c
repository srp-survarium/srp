int __usercall sub_37BAA0@<eax>(int a1@<edi>, int a2)
{
  int *v2; // esi
  int v3; // ebx
  int v4; // ebp
  int v5; // eax

  v2 = (int *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 32 * a2);
  v3 = 0;
  *v2 = 0;
  v2[1] = 31;
  v2[2] = 0;
  v2[3] = 63;
  v2[4] = 0;
  v2[5] = 31;
  sub_37B3F0(v2);
  v4 = sub_37B7D0(a1, (int)v2, 1, a2);
  if ( v4 > 0 )
  {
    do
    {
      sub_37B920(v2, a1, v3++);
      v2 += 8;
    }
    while ( v3 < v4 );
  }
  v5 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 112) = v4;
  *(_DWORD *)(v5 + 20) = 98;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = v4;
  return (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, 1);
}
