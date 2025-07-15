void __userpurge vostok::animation::cubic_spline_skeleton_animation::cubic_spline_skeleton_animation(
        vostok::animation::cubic_spline_skeleton_animation *this@<ecx>,
        int a2@<esi>,
        const vostok::animation::bi_spline_skeleton_animation_baked *animation)
{
  const vostok::animation::bi_spline_skeleton_animation_baked *v3; // edi
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  int v6; // ecx
  _BYTE *v7; // ebx
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // ebp
  unsigned int i; // ebx
  unsigned int v12; // eax
  int v13; // eax
  vostok::animation::animation_event_channels *v14; // ecx
  int v15; // eax
  void *v16; // [esp+0h] [ebp-1Ch]
  vostok::animation::bi_spline_bone_animation_baked *bd; // [esp+Ch] [ebp-10h]
  void *mem_ptr; // [esp+10h] [ebp-Ch] BYREF
  int v19; // [esp+14h] [ebp-8h]
  unsigned int bone; // [esp+18h] [ebp-4h]

  *(_DWORD *)a2 = -1;
  *(_DWORD *)(a2 + 4) = -1;
  v3 = animation;
  *(_DWORD *)(a2 + 8) = -1;
  *(_DWORD *)(a2 + 12) = -1;
  *(_DWORD *)(a2 + 24) = HIBYTE(animation[1].__vftable);
  *(_DWORD *)(a2 + 16) = LOWORD(animation[1].__vftable);
  mem_ptr = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&mem_ptr,
    &animation->m_bones_names);
  vostok::animation::bone_names::create_internals_in_place(
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&mem_ptr,
    (vostok::animation::bone_names *)a2,
    (_BYTE *)(a2 + 28));
  v4 = (vostok::resources::unmanaged_resource *)mem_ptr;
  if ( mem_ptr )
  {
    v5 = (vostok::resources::unmanaged_intrusive_base *)((char *)mem_ptr + 208);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)mem_ptr + 52, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
  }
  v6 = *(_DWORD *)(a2 + 16);
  v7 = (_BYTE *)(72 * v6 + 72 * v6 + a2 + 28);
  *(_DWORD *)(a2 + 20) = 72 * v6 + 28;
  mem_ptr = v7;
  bone = 0;
  if ( v6 )
  {
    v8 = 0;
    v19 = 0;
    bd = (vostok::animation::bi_spline_bone_animation_baked *)&animation[1].type;
    while ( 1 )
    {
      v9 = (_DWORD *)(*(_DWORD *)(a2 + 20) + v8 + a2);
      if ( v9 )
      {
        *v9 = -1;
        v9[1] = -1;
        v9[2] = -1;
        v9[3] = -1;
        v9[4] = -1;
        v9[5] = -1;
        v9[6] = -1;
        v9[7] = -1;
        v9[8] = -1;
        v9[9] = -1;
        v9[10] = -1;
        v9[11] = -1;
        v9[12] = -1;
        v9[13] = -1;
        v9[14] = -1;
        v9[15] = -1;
        v9[16] = -1;
        v9[17] = -1;
      }
      vostok::animation::bone_animation::create_internals_in_place(
        (vostok::animation::bone_animation *)(*(_DWORD *)(a2 + 20) + a2 + v8),
        bd,
        v7);
      v10 = 0;
      for ( i = 0; i < 9; ++i )
      {
        v12 = vostok::animation::poly_knots_count(bd->m_channel_animations[i].pointer);
        v10 += 20 * v12;
      }
      mem_ptr = (char *)mem_ptr + v10;
      v7 = mem_ptr;
      v19 += 72;
      ++bd;
      if ( ++bone >= *(_DWORD *)(a2 + 16) )
        break;
      v8 = v19;
    }
    v3 = animation;
  }
  v13 = LOWORD(v3[1].__vftable);
  v14 = (vostok::animation::animation_event_channels *)(&v3[1].type + 18 * v13);
  if ( (const vostok::animation::bi_spline_skeleton_animation_baked *)((char *)v3 + 72 * v13) != (const vostok::animation::bi_spline_skeleton_animation_baked *)-276 )
  {
    v15 = BYTE2(v3[1].__vftable);
    *(_DWORD *)(a2 + 8) = v15;
    if ( v15 )
      vostok::animation::animation_event_channels::create_in_place_internals(
        v14,
        (unsigned int *)(a2 + 8),
        (const vostok::animation::bi_spline_event_channel_baked *)v14,
        v7,
        v16);
  }
}
