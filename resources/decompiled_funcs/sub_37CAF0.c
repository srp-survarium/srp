void __usercall sub_37CAF0(int a1@<ebx>)
{
  int v1; // ebp
  int v2; // esi
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // edx
  int v7; // eax

  v1 = *(_DWORD *)(a1 + 440);
  v2 = 0;
  if ( *(int *)(a1 + 100) > 0 )
  {
    v3 = (int *)(v1 + 52);
    do
    {
      v4 = *(v3 - 5);
      v5 = 0;
      if ( v2 <= 0 )
        goto LABEL_9;
      v6 = (_DWORD *)(v1 + 32);
      while ( v4 != *v6 )
      {
        ++v5;
        ++v6;
        if ( v5 >= v2 )
          goto LABEL_9;
      }
      v7 = *(_DWORD *)(v1 + 4 * v5 + 52);
      if ( !v7 )
LABEL_9:
        v7 = sub_37CA70(a1, v4);
      *v3 = v7;
      ++v2;
      ++v3;
    }
    while ( v2 < *(_DWORD *)(a1 + 100) );
  }
}
