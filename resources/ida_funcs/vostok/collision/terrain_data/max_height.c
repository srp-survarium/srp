void __usercall vostok::collision::terrain_data::max_height(vostok::collision::terrain_data *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  float v3; // xmm0_4
  unsigned int v4; // esi
  float *v5; // ecx
  unsigned int v6; // edx
  float *v7; // ecx
  unsigned int v8; // eax

  v2 = *(_DWORD *)(a2 + 4) * *(_DWORD *)(a2 + 4);
  v3 = -infinity_5;
  v4 = 0;
  if ( v2 >= 4 )
  {
    v5 = (float *)(*(_DWORD *)(a2 + 8) + 8);
    v6 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v4 = 4 * v6;
    do
    {
      if ( v3 <= *(v5 - 2) )
        v3 = *(v5 - 2);
      if ( v3 <= *(v5 - 1) )
        v3 = *(v5 - 1);
      if ( v3 <= *v5 )
        v3 = *v5;
      if ( v3 <= v5[1] )
        v3 = v5[1];
      v5 += 4;
      --v6;
    }
    while ( v6 );
  }
  if ( v4 < v2 )
  {
    v7 = (float *)(*(_DWORD *)(a2 + 8) + 4 * v4);
    v8 = v2 - v4;
    do
    {
      if ( v3 <= *v7 )
        v3 = *v7;
      ++v7;
      --v8;
    }
    while ( v8 );
  }
}
