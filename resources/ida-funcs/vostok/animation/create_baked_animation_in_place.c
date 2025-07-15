void __usercall vostok::animation::create_baked_animation_in_place(char *raw_buffer@<eax>)
{
  char *v1; // ecx
  char *v2; // edi
  const char *v3; // esi
  char *v4; // edx
  int v5; // eax
  unsigned __int16 *v6; // edi
  int v7; // ebx
  int v8; // [esp+10h] [ebp-8h]

  v1 = raw_buffer + 4;
  v2 = &raw_buffer[72 * *(unsigned __int16 *)raw_buffer + 4];
  v3 = &v2[16 * (unsigned __int8)raw_buffer[2]];
  while ( v1 != v2 )
  {
    v4 = v1 + 72;
    while ( v1 != v4 )
    {
      *(_DWORD *)v1 = v3;
      v3 += 8 * *(_DWORD *)v3 + 4;
      v1 += 8;
    }
    v1 = v4;
  }
  v5 = (unsigned __int8)raw_buffer[2];
  if ( v5 )
  {
    v6 = (unsigned __int16 *)(v2 + 8);
    v8 = v5;
    do
    {
      *((_DWORD *)v6 - 2) = v3;
      v7 = 4 * *v6;
      strlen(&v3[*((unsigned __int8 *)v6 + 2) + v7]);
      v3 += v7 + vostok::math::align_up<unsigned long>(4u);
      v6 += 8;
      --v8;
    }
    while ( v8 );
  }
}
