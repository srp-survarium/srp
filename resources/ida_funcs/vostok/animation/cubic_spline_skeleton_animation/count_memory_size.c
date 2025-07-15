int __cdecl vostok::animation::cubic_spline_skeleton_animation::count_memory_size(
        const vostok::animation::bi_spline_skeleton_animation_baked *animation)
{
  const vostok::animation::bi_spline_skeleton_animation_baked *v1; // ecx
  int result; // eax
  int v3; // esi
  const vostok::animation::bi_spline_channel_animation_baked **v4; // ebx
  int v5; // ebp
  unsigned int v6; // eax
  bool v7; // zf
  int v8; // edx
  int v9; // ecx
  int v10; // esi
  _WORD *v11; // edx
  int v12; // edi
  int v13; // ecx
  int v14; // [esp+8h] [ebp-Ch]
  unsigned int size; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v1 = animation;
  result = 144 * LOWORD(animation[1].__vftable) + 28;
  size = result;
  if ( LOWORD(animation[1].__vftable) )
  {
    v14 = 0;
    v16 = LOWORD(animation[1].__vftable);
    do
    {
      v3 = 0;
      v4 = (const vostok::animation::bi_spline_channel_animation_baked **)((char *)&v1[1].type + v14);
      v5 = 9;
      do
      {
        v6 = vostok::animation::poly_knots_count(*v4);
        v4 += 2;
        --v5;
        v3 += 20 * v6;
      }
      while ( v5 );
      size += v3;
      v14 += 72;
      v7 = v16-- == 1;
      v1 = animation;
    }
    while ( !v7 );
    result = size;
  }
  v8 = (int)(&v1[1].type + 18 * LOWORD(v1[1].__vftable));
  if ( (const vostok::animation::bi_spline_skeleton_animation_baked *)((char *)v1 + 72 * LOWORD(v1[1].__vftable)) != (const vostok::animation::bi_spline_skeleton_animation_baked *)-276 )
  {
    v9 = BYTE2(v1[1].__vftable);
    v10 = 44 * v9;
    if ( v9 )
    {
      v11 = (_WORD *)(v8 + 8);
      v12 = v9;
      do
      {
        if ( *v11 )
          v13 = 5 * (unsigned __int16)*v11;
        else
          v13 = 0;
        v10 += v13;
        v11 += 8;
        --v12;
      }
      while ( v12 );
    }
    result += v10;
  }
  return result;
}
