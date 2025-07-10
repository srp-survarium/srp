void __thiscall vostok::render::renderer_context::set_v(
        vostok::render::renderer_context *this,
        vostok::render::renderer_context *m,
        const vostok::math::float4x4 *ma)
{
  vostok::math::float4x4 *v4; // eax
  const vostok::math::float4x4 *v5; // xmm6_4
  float y; // xmm4_4
  float z; // xmm3_4
  float x; // xmm5_4
  const char *m_conflicted_key_name; // esi
  float v10; // eax
  unsigned int v11; // xmm2_4
  __int64 v12; // [esp+18h] [ebp-CCh]
  __int64 z_low; // [esp+18h] [ebp-CCh]
  vostok::math::float4x4 result; // [esp+20h] [ebp-C4h] BYREF
  vostok::math::float4x4 v15; // [esp+60h] [ebp-84h] BYREF
  vostok::math::float4x4 v16; // [esp+A0h] [ebp-44h] BYREF

  qmemcpy((void *)&m->m_v, ma, sizeof(m->m_v));
  qmemcpy((void *)&m->m_v_transposed, vostok::math::transpose(&result, &m->m_v), sizeof(m->m_v_transposed));
  vostok::math::float4x4::try_invert(&m->m_v_inverted, ma);
  qmemcpy(
    (void *)&m->m_v_inverted_transposed,
    vostok::math::transpose(&result, &m->m_v_inverted),
    sizeof(m->m_v_inverted_transposed));
  vostok::math::mul4x3(&result, &m->m_w, &m->m_v);
  qmemcpy((void *)&m->m_wv, &result, sizeof(m->m_wv));
  qmemcpy((void *)&m->m_wv_transposed, vostok::math::transpose(&result, &m->m_wv), sizeof(m->m_wv_transposed));
  qmemcpy((void *)&m->m_vp, vostok::math::mul4x4(&m->m_v, &m->m_p), sizeof(m->m_vp));
  qmemcpy((void *)&m->m_vp_transposed, vostok::math::transpose(&v15, &m->m_vp), sizeof(m->m_vp_transposed));
  qmemcpy((void *)&m->m_wvp, vostok::math::mul4x4(&m->m_wv, &m->m_p), sizeof(m->m_wvp));
  v4 = vostok::math::transpose(&v16, &m->m_wvp);
  v5 = clear_value;
  qmemcpy((void *)&m->m_wvp_transposed, v4, sizeof(m->m_wvp_transposed));
  *(float *)&v12 = m->m_v_inverted.c.z;
  *(_QWORD *)&m->m_view_pos.x = *(_QWORD *)&m->m_v_inverted.lines[3].x;
  HIDWORD(v12) = v5;
  *(_QWORD *)&m->m_view_pos.elements[2] = v12;
  z_low = LODWORD(m->m_v_inverted.k.z);
  *(_QWORD *)&m->m_view_dir.x = *(_QWORD *)&m->m_v_inverted.lines[2].x;
  *(_QWORD *)&m->m_view_dir.elements[2] = z_low;
  y = m->m_view_pos.y;
  z = m->m_view_pos.z;
  x = m->m_view_pos.x;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v10 = *(float *)&m->m_c_view_pos;
  *(float *)&v11 = (float)((float)((float)(m->m_v.i.z * x) + (float)(m->m_v.j.z * y)) + (float)(m->m_v.k.z * z))
                 + m->m_v.c.z;
  *(_QWORD *)&m->m_eye_pos_view_space.x = __PAIR64__(
                                            (float)((float)((float)(m->m_v.i.y * x) + (float)(m->m_v.j.y * y))
                                                  + (float)(m->m_v.k.y * z))
                                          + m->m_v.c.y,
                                            (float)((float)((float)(m->m_v.j.x * y) + (float)(m->m_v.k.x * z))
                                                  + (float)(m->m_v.i.x * x))
                                          + m->m_v.c.x);
  *(_QWORD *)&m->m_eye_pos_view_space.elements[2] = __PAIR64__((unsigned int)v5, v11);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    (const vostok::render::shader_constant_host *)LODWORD(v10),
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_view_pos);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_view_pos,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_view_pos);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_eye_pos_view_space,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_eye_pos_view_space);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_eye_pos_view_space,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_eye_pos_view_space);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_view_dir,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_view_dir);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_view_dir,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_view_dir);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_v,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_v_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_vp,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_vp_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_wv,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_wv_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_wvp,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    (const vostok::math::float3 *)&m->m_wvp_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_v,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_v_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_vp,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_vp_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_wv,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_wv_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_wvp,
    (vostok::render::constants_handler<1> *)m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_wvp_transposed);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
