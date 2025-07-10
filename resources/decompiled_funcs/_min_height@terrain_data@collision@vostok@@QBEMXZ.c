void __usercall vostok::collision::terrain_data::min_height(vostok::collision::terrain_data *this@<ecx>, int a2@<edi>)
{
  float v2; // xmm0_4
  int v3; // eax
  unsigned int v4; // esi
  float *v5; // ecx
  unsigned int v6; // edx
  float *v7; // ecx
  unsigned int v8; // eax

  v2 = infinity_5;
  v3 = *(_DWORD *)(a2 + 4) * *(_DWORD *)(a2 + 4);
  v4 = 0;
  if ( v3 >= 4 )
  {
    v5 = (float *)(*(_DWORD *)(a2 + 8) + 8);
    v6 = ((unsigned int)(v3 - 4) >> 2) + 1;
    v4 = 4 * v6;
    do
    {
      if ( *(v5 - 2) <= v2 )
        v2 = *(v5 - 2);
      if ( *(v5 - 1) <= v2 )
        v2 = *(v5 - 1);
      if ( *v5 <= v2 )
        v2 = *v5;
      if ( v5[1] <= v2 )
        v2 = v5[1];
      v5 += 4;
      --v6;
    }
    while ( v6 );
  }
  if ( v4 < v3 )
  {
    v7 = (float *)(*(_DWORD *)(a2 + 8) + 4 * v4);
    v8 = v3 - v4;
    do
    {
      if ( *v7 <= v2 )
        v2 = *v7;
      ++v7;
      --v8;
    }
    while ( v8 );
  }
}
