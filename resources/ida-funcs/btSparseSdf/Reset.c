void __usercall btSparseSdf<3>::Reset(btSparseSdf<3> *this@<ecx>, int a2@<esi>)
{
  int v2; // edi
  _DWORD **v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // ebx
  int v6; // [esp+4h] [ebp-4h]

  v2 = 0;
  v6 = *(_DWORD *)(a2 + 4);
  if ( v6 > 0 )
  {
    do
    {
      v3 = (_DWORD **)(*(_DWORD *)(a2 + 12) + 4 * v2);
      v4 = *v3;
      *v3 = 0;
      if ( v4 )
      {
        do
        {
          v5 = (_DWORD *)v4[70];
          operator delete(v4);
          v4 = v5;
        }
        while ( v5 );
      }
      ++v2;
    }
    while ( v2 < v6 );
  }
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 20) = FLOAT_0_25;
  *(_DWORD *)(a2 + 32) = 1;
  *(_DWORD *)(a2 + 36) = 1;
}
