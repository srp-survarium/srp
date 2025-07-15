int __usercall vostok::animation::cubic_spline_skeleton_animation::count_memory_size@<eax>(
        const vostok::animation::bi_spline_skeleton_animation_baked *animation@<edi>)
{
  int v1; // esi
  int v2; // ebx
  int v3; // eax
  unsigned int *v4; // esi
  int v5; // ecx
  _WORD *v6; // edx
  int v7; // esi
  int v8; // eax
  int v10; // [esp+8h] [ebp-8h]
  const vostok::animation::bi_spline_bone_animation_baked *p_type; // [esp+Ch] [ebp-4h]

  v1 = LOWORD(animation[1].__vftable);
  v2 = 144 * v1 + 28;
  if ( LOWORD(animation[1].__vftable) )
  {
    p_type = (const vostok::animation::bi_spline_bone_animation_baked *)&animation[1].type;
    v10 = LOWORD(animation[1].__vftable);
    do
    {
      v3 = vostok::animation::bone_animation::count_internal_memory_size(p_type++);
      v2 += v3;
      --v10;
    }
    while ( v10 );
  }
  v4 = &animation[1].type + 18 * v1;
  if ( v4 )
  {
    v5 = 44 * BYTE2(animation[1].__vftable);
    if ( BYTE2(animation[1].__vftable) )
    {
      v6 = v4 + 2;
      v7 = BYTE2(animation[1].__vftable);
      do
      {
        if ( *v6 )
          v8 = 5 * (unsigned __int16)*v6;
        else
          v8 = 0;
        v5 += v8;
        v6 += 8;
        --v7;
      }
      while ( v7 );
    }
    v2 += v5;
  }
  return v2;
}
