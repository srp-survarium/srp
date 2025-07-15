void __cdecl res0_pack(unsigned int *vr, oggpack_buffer *opb)
{
  unsigned int *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ecx
  int v6; // edx
  unsigned int v7; // eax
  int i; // ecx
  int v9; // edi
  unsigned int *v10; // esi
  int v11; // [esp+Ch] [ebp-4h]
  signed int v12; // [esp+18h] [ebp+8h]

  v11 = 0;
  oggpack_write(opb, *vr, 0x18u);
  oggpack_write(opb, vr[1], 0x18u);
  oggpack_write(opb, vr[2] - 1, 0x18u);
  oggpack_write(opb, vr[3] - 1, 6u);
  oggpack_write(opb, vr[5], 8u);
  v12 = 0;
  if ( (int)vr[3] > 0 )
  {
    v3 = vr + 6;
    do
    {
      v4 = *v3;
      v5 = *v3;
      v6 = 0;
      if ( !*v3 )
        goto LABEL_7;
      do
      {
        ++v6;
        v5 >>= 1;
      }
      while ( v5 );
      if ( v6 > 3 )
      {
        oggpack_write(opb, v4, 3u);
        oggpack_write(opb, 1u, 1u);
        oggpack_write(opb, (int)*v3 >> 3, 5u);
      }
      else
      {
LABEL_7:
        oggpack_write(opb, v4, 4u);
      }
      v7 = *v3;
      for ( i = 0; v7; v7 >>= 1 )
        i += v7 & 1;
      v11 += i;
      ++v12;
      ++v3;
    }
    while ( v12 < (int)vr[3] );
  }
  v9 = v11;
  if ( v11 > 0 )
  {
    v10 = vr + 70;
    do
    {
      oggpack_write(opb, *v10++, 8u);
      --v9;
    }
    while ( v9 );
  }
}
