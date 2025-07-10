void __userpurge vostok::render::stage_light_propagation_volumes::render_to_point_rms(
        const unsigned int face_index@<eax>,
        float a2@<edi>,
        float a3@<esi>,
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::light *l,
        vostok::render::vector<vostok::math::float4x4> transforms)
{
  unsigned int v6; // eax
  unsigned int v7; // xmm0_4
  unsigned int v8; // xmm1_4
  float v9; // xmm2_4
  unsigned int v10; // xmm0_4
  unsigned int v11; // xmm1_4
  float v12; // xmm2_4
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *v13; // ecx
  vostok::math::float4x4 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v16; // [esp+8h] [ebp-BCh] BYREF
  unsigned int cascade_index; // [esp+14h] [ebp-B0h]
  unsigned int far_plane; // [esp+18h] [ebp-ACh]
  float v19; // [esp+1Ch] [ebp-A8h]
  float v20; // [esp+20h] [ebp-A4h]
  float v21; // [esp+24h] [ebp-A0h]
  vostok::math::float3 from; // [esp+2Ch] [ebp-98h] BYREF
  vostok::math::float3 at; // [esp+38h] [ebp-8Ch] BYREF
  vostok::math::float4x4 face_projection_matrix; // [esp+44h] [ebp-80h] BYREF
  vostok::math::float4x4 face_view_matrix; // [esp+84h] [ebp-40h] BYREF

  v6 = 18 * face_index;
  *(float *)&v7 = l->position.x + *(float *)((char *)&dword_A57A6C + 2 * v6);
  *(float *)&v8 = l->position.y + *(float *)((char *)&dword_A57A70 + 2 * v6);
  v9 = l->position.z + *(float *)((char *)&dword_A57A74 + 2 * v6);
  v6 *= 2;
  *(_QWORD *)&at.x = __PAIR64__(v8, v7);
  *(float *)&v10 = l->position.x + *(float *)((char *)&view_matrix_parameters_0[0][0].x + v6);
  *(float *)&v11 = l->position.y + *(float *)((char *)&dword_A57A64 + v6);
  at.z = v9;
  v12 = l->position.z + *(float *)((char *)&dword_A57A68 + v6);
  v20 = a3;
  v19 = a2;
  far_plane = (unsigned int)&unk_A57A78 + v6;
  *(_QWORD *)&from.x = __PAIR64__(v11, v10);
  from.z = v12;
  vostok::math::create_camera_at(&from, &at, (const vostok::math::float3 *)&face_view_matrix);
  vostok::math::create_perspective_projection(
    COERCE_VOSTOK_MATH_(1.0),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(0.1),
    l->range,
    a2,
    a3,
    v21);
  far_plane = 0;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
    v13,
    (unsigned __int8 **)&v16._M_impl._M_finish,
    &transforms._M_impl);
  v16._M_impl._M_start = &face_projection_matrix;
  vostok::render::stage_light_propagation_volumes::render_to_rms(
    (vostok::render::stage_light_propagation_volumes *)&face_view_matrix,
    this,
    &l->color,
    COERCE_VOSTOK_RENDER_RENDER_SURFACE_INSTANCE_(l->intensity),
    (vostok::render::renderer_context *)&face_view_matrix,
    v16,
    cascade_index,
    far_plane);
  M_start = transforms._M_impl._M_start;
  if ( transforms._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_start);
  }
}
