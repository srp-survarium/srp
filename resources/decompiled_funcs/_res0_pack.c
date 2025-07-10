void __cdecl res0_pack(unsigned int *vr, oggpack_buffer *opb)
{
  int v2; // ebx
  signed int v3; // ebp
  unsigned int *v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  int i; // ecx
  unsigned int *v10; // edi
  int acc; // [esp+10h] [ebp-4h]

  v2 = 0;
  acc = 0;
  oggpack_write(opb, *vr, 0x18u);
  oggpack_write(opb, vr[1], 0x18u);
  oggpack_write(opb, vr[2] - 1, 0x18u);
  oggpack_write(opb, vr[3] - 1, 6u);
  oggpack_write(opb, vr[5], 8u);
  v3 = 0;
  if ( (int)vr[3] > 0 )
  {
    v4 = vr + 6;
    do
    {
      v5 = *v4;
      v6 = *v4;
      v7 = 0;
      if ( !*v4 )
        goto LABEL_7;
      do
      {
        ++v7;
        v6 >>= 1;
      }
      while ( v6 );
      if ( v7 > 3 )
      {
        oggpack_write(opb, v5, 3u);
        oggpack_write(opb, 1u, 1u);
        oggpack_write(opb, (int)*v4 >> 3, 5u);
      }
      else
      {
LABEL_7:
        oggpack_write(opb, v5, 4u);
      }
      v8 = *v4;
      for ( i = 0; v8; v8 >>= 1 )
        i += v8 & 1;
      acc += i;
      ++v3;
      ++v4;
    }
    while ( v3 < (int)vr[3] );
    v2 = acc;
  }
  if ( v2 > 0 )
  {
    v10 = vr + 70;
    do
    {
      oggpack_write(opb, *v10++, 8u);
      --v2;
    }
    while ( v2 );
  }
}
