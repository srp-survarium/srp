void __usercall btSparseSdf<3>::GarbageCollect(btSparseSdf<3> *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx
  _DWORD **v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int i; // [esp+0h] [ebp-Ch]
  _DWORD *v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v8 = 0;
  v2 = a2[6] - 256;
  for ( i = v2; v8 < a2[1]; ++v8 )
  {
    v7 = 0;
    v3 = (_DWORD **)(a2[3] + 4 * v8);
    v4 = *v3;
    if ( *v3 )
    {
      do
      {
        v5 = (_DWORD *)v4[70];
        if ( v4[67] < v2 )
        {
          if ( v7 )
            v7[70] = v5;
          else
            *v3 = v5;
          operator delete(v4);
          v4 = v7;
          --a2[7];
          v2 = i;
        }
        v7 = v4;
        v4 = v5;
      }
      while ( v5 );
    }
  }
  ++a2[6];
  a2[9] = 1;
  a2[8] = 1;
}
