void __thiscall vostok::render::skeleton_render_model_instance::update(
        vostok::render::skeleton_render_model_instance *this)
{
  vostok::render::skeleton_render_model *m_object; // esi
  bool v3; // zf
  vostok::render::render_surface *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  vostok::render::render_surface_instance *v7; // ecx
  vostok::render::skeleton_render_model *v8; // eax
  const vostok::math::float4x4 *m_begin; // edx
  float *p_x; // eax
  const vostok::math::float4x4 *v11; // esi
  vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // edx
  vostok::math::float4x4 *v14; // eax
  unsigned int m_instances_count; // eax
  pix_event_wrapper_dx11 wszName[5]; // [esp+Fh] [ebp-F1h] BYREF
  unsigned int v17; // [esp+14h] [ebp-ECh]
  unsigned int v18; // [esp+18h] [ebp-E8h]
  vostok::math::float4x4 *m_end; // [esp+1Ch] [ebp-E4h]
  const vostok::math::float4x4 *v20; // [esp+20h] [ebp-E0h]
  vostok::render::render_surface_instance *v21; // [esp+24h] [ebp-DCh]
  float v22; // [esp+28h] [ebp-D8h]
  float v23; // [esp+2Ch] [ebp-D4h]
  float v24; // [esp+30h] [ebp-D0h]
  float v25; // [esp+34h] [ebp-CCh]
  float v26; // [esp+38h] [ebp-C8h]
  float v27; // [esp+3Ch] [ebp-C4h]
  vostok::math::float4x4 v28; // [esp+40h] [ebp-C0h] BYREF
  vostok::math::float4x4 v29; // [esp+80h] [ebp-80h] BYREF
  vostok::math::float4x4 v30; // [esp+C0h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    wszName,
    (int)L"skeleton_render_model_instance");
  m_object = this->m_original.m_object;
  v3 = m_object->m_childs_count == 0;
  wszName[0] = 0;
  if ( !v3 )
  {
    do
    {
      v4 = m_object->m_childs[*(_BYTE *)wszName];
      ((void (__thiscall *)(vostok::render::render_surface *, vostok::fixed_vector<vostok::math::float4x4,128> *))v4->__vftable[1].~vostok::render::render_surface)(
        v4,
        &this->m_bones_matrices);
      ++*(_BYTE *)wszName;
    }
    while ( *(_BYTE *)wszName < m_object->m_childs_count );
  }
  v18 = 0;
  if ( this->m_instances_count )
  {
    v17 = 0;
    v5 = FLOAT_N0_5;
    v6 = c_anim_center;
    do
    {
      v7 = &this->m_surface_instances[v17 / 0x38];
      v3 = (v7->m_flags & 1) == 0;
      v21 = v7;
      if ( !v3 )
      {
        v8 = this->m_original.m_object;
        m_begin = v8->m_inverted_bones_matrices_in_bind_pose.m_begin;
        m_end = v8->m_inverted_bones_matrices_in_bind_pose.m_end;
        *(_DWORD *)&wszName[1] = this->m_bones_matrices.m_begin;
        p_x = &v7->m_render_surface->m_aabbox.min.x;
        v25 = v5;
        v26 = v5;
        v27 = v5;
        *p_x = v5;
        p_x[1] = v26;
        p_x[2] = v27;
        v22 = v6;
        v23 = v6;
        v24 = v6;
        p_x[3] = v6;
        p_x[4] = v23;
        v20 = m_begin;
        p_x[5] = v24;
        if ( m_begin != m_end )
        {
          do
          {
            vostok::math::transpose(*(const vostok::math::float4x4 **)&wszName[1], &v28);
            v11 = v20;
            v12 = vostok::math::invert4x3(v20, &v29);
            v14 = vostok::math::mul4x4(v13, v12, &v30);
            vostok::math::aabb::modify((vostok::math::aabb *)&v14->lines[3], &v21->m_render_surface->m_aabbox);
            *(_DWORD *)&wszName[1] += 64;
            v20 = v11 + 1;
          }
          while ( &v11[1] != m_end );
          v6 = c_anim_center;
          v5 = FLOAT_N0_5;
        }
      }
      m_instances_count = this->m_instances_count;
      ++v18;
      v17 += 56;
    }
    while ( v18 < m_instances_count );
  }
  D3DPERF_EndEvent();
}
