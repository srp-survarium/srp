void __usercall vostok::ai::npc_statistics::~npc_statistics(vostok::ai::npc_statistics *this@<ecx>, int *a2@<eax>)
{
  int i; // ecx
  int j; // ecx
  int v4; // ecx

  a2[7391] = a2[7390];
  a2[7202] = a2[7201];
  a2[7170] = a2[7169];
  a2[7005] = a2[7004];
  a2[5584] = a2[5583];
  for ( i = a2[2534]; i != a2[2535]; i += 1012 )
    *(_DWORD *)(i + 48) = *(_DWORD *)(i + 44);
  a2[2535] = a2[2534];
  for ( j = a2[1267]; j != a2[1268]; j += 1012 )
    *(_DWORD *)(j + 48) = *(_DWORD *)(j + 44);
  a2[1268] = a2[1267];
  v4 = *a2;
  if ( *a2 == a2[1] )
  {
    a2[1] = v4;
  }
  else
  {
    do
    {
      *(_DWORD *)(v4 + 48) = *(_DWORD *)(v4 + 44);
      v4 += 1012;
    }
    while ( v4 != a2[1] );
    a2[1] = *a2;
  }
}
