void __userpurge vostok::render::stage_light_propagation_volumes::render_to_spot_rms(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        float a2@<edi>,
        float a3@<esi>,
        vostok::render::stage_light_propagation_volumes *l,
        vostok::render::vector<vostok::math::float4x4> transforms,
        int transforms_8)
{
  const vostok::math::float3 *M_start; // ebx
  float z; // xmm5_4
  float w; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float y; // xmm6_4
  unsigned int v13; // xmm1_4
  unsigned int v14; // xmm2_4
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *v15; // ecx
  vostok::math::float4x4 *M_finish; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::math::float4x4> v18; // [esp+8h] [ebp-BCh] BYREF
  struct vostok::math::float4x4 *v19; // [esp+14h] [ebp-B0h]
  unsigned int _X; // [esp+18h] [ebp-ACh]
  float v21; // [esp+1Ch] [ebp-A8h]
  float v22; // [esp+20h] [ebp-A4h]
  float v23; // [esp+24h] [ebp-A0h]
  float x; // [esp+28h] [ebp-9Ch]
  float v25; // [esp+2Ch] [ebp-98h]
  float v26; // [esp+30h] [ebp-94h]
  float v27; // [esp+34h] [ebp-90h]
  vostok::math::float3 at; // [esp+38h] [ebp-8Ch] BYREF
  vostok::math::float4x4 projection_matrix; // [esp+44h] [ebp-80h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+84h] [ebp-40h] BYREF

  M_start = (const vostok::math::float3 *)transforms._M_impl._M_start;
  v22 = a3;
  v21 = a2;
  x = transforms._M_impl._M_start[3].k.x;
  vostok::math::create_perspective_projection(
    COERCE_VOSTOK_MATH_(1.0),
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(x * 0.001),
    x,
    a2,
    a3,
    v23);
  z = transforms._M_impl._M_start[3].i.z;
  w = transforms._M_impl._M_start[2].k.w;
  v9 = transforms._M_impl._M_start[2].k.z;
  v10 = (float)(M_start[16].z * v9) - (float)(M_start[16].y * w);
  v11 = transforms._M_impl._M_start[3].i.x * w;
  y = transforms._M_impl._M_start[2].k.y;
  v27 = (float)(y * M_start[16].y) - (float)(M_start[16].x * v9);
  v26 = v11 - (float)(y * z);
  x = sqrtf((float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v10 * v10));
  v25 = (float)(*(float *)&clear_value / x) * v10;
  *(float *)&v13 = M_start[12].z + M_start[14].x;
  v26 = (float)(*(float *)&clear_value / x) * v26;
  *(float *)&v14 = M_start[13].x + M_start[14].y;
  v27 = (float)(*(float *)&clear_value / x) * v27;
  at.x = M_start[12].y + M_start[13].z;
  *(_QWORD *)&at.elements[1] = __PAIR64__(v14, v13);
  vostok::math::create_camera_at(
    (const vostok::math::float3 *)&transforms._M_impl._M_start[2].lines[1].elements[1],
    &at,
    (const vostok::math::float3 *)&view_matrix);
  _X = 0;
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
    v15,
    (unsigned __int8 **)&v18._M_impl._M_finish,
    (const stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)&transforms._M_impl._M_finish);
  v18._M_impl._M_start = &projection_matrix;
  vostok::render::stage_light_propagation_volumes::render_to_rms(
    (vostok::render::stage_light_propagation_volumes *)&projection_matrix,
    l,
    M_start + 11,
    COERCE_VOSTOK_RENDER_RENDER_SURFACE_INSTANCE_(M_start[12].x),
    (vostok::render::renderer_context *)&view_matrix,
    v18,
    (const unsigned int)v19,
    _X);
  M_finish = transforms._M_impl._M_finish;
  if ( transforms._M_impl._M_finish )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)M_finish);
  }
}
