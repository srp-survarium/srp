void __userpurge survarium::base_player::apply_rotation(
        survarium::base_player *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::math::float2 *rotation_to_apply,
        vostok::animation::animation_player *a4)
{
  __m128i v4; // xmm0
  float v5; // xmm1_4
  float v6; // xmm0_4
  vostok::math::float4x4 v7; // [esp+14h] [ebp-40h] BYREF

  v4 = (__m128i)*(unsigned int *)&a4->m_tree_buffers[0][0];
  *(float *)v4.m128i_i32 = *(float *)v4.m128i_i32 + *(float *)((char *)&dword_10E70 + (_DWORD)rotation_to_apply);
  *(int *)((char *)&dword_10E70 + (_DWORD)rotation_to_apply) = v4.m128i_i32[0];
  vostok::math::create_rotation_y(a2, v4, &v7, *(float *)v4.m128i_i32);
  v5 = FLOAT_N1_0;
  *(_QWORD *)&v7.lines[3].x = *(_QWORD *)&byte_10E5C[(_DWORD)rotation_to_apply];
  v7.c.z = *(float *)&byte_10E5C[(_DWORD)rotation_to_apply + 8];
  qmemcpy(&byte_10E2C[(_DWORD)rotation_to_apply], &v7, 0x40u);
  v6 = *(float *)&a4->m_tree_buffers[0][4] + *(float *)((char *)&dword_10E6C + (_DWORD)rotation_to_apply);
  if ( v6 > -1.0 )
  {
    v5 = s_bm_current_air_resistance;
    if ( s_bm_current_air_resistance >= v6 )
      v5 = *(float *)&a4->m_tree_buffers[0][4] + *(float *)((char *)&dword_10E6C + (_DWORD)rotation_to_apply);
  }
  *(float *)((char *)&dword_10E6C + (_DWORD)rotation_to_apply) = v5;
  vostok::animation::animation_player::set_object_transform(
    a4,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&rotation_to_apply[106],
    (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)rotation_to_apply],
    rotation_to_apply);
}
