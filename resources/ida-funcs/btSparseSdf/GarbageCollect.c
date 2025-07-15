void __thiscall btSparseSdf<3>::GarbageCollect(btSparseSdf<3> *this, _DWORD *lifetime)
{
  int v3; // edx
  int v4; // ecx
  bool v5; // cc
  _DWORD **v6; // ebp
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  _DWORD *v9; // edi
  int life; // [esp+4h] [ebp-4h]
  int i; // [esp+Ch] [ebp+4h]

  v3 = 0;
  v4 = lifetime[6] - 256;
  v5 = lifetime[1] <= 0;
  life = v4;
  i = 0;
  if ( !v5 )
  {
    do
    {
      v6 = (_DWORD **)(lifetime[3] + 4 * v3);
      v7 = *v6;
      v8 = 0;
      if ( *v6 )
      {
        do
        {
          v9 = (_DWORD *)v7[70];
          if ( v7[67] < v4 )
          {
            if ( v8 )
              v8[70] = v9;
            else
              *v6 = v9;
            operator delete(v7);
            v4 = life;
            --lifetime[7];
            v7 = v8;
          }
          v8 = v7;
          v7 = v9;
        }
        while ( v9 );
        v3 = i;
      }
      i = ++v3;
    }
    while ( v3 < lifetime[1] );
  }
  ++lifetime[6];
  lifetime[9] = 1;
  lifetime[8] = 1;
}
