void __thiscall vostok::render::renderer_context::set_p(
        vostok::render::renderer_context *this,
        vostok::render::renderer_context *m,
        const vostok::math::float4x4 *ma)
{
  const void *v4; // edx
  int v5; // eax
  vostok::render::renderer_context *v6; // ecx
  vostok::render::constants_handler<1> *m_conflicted_key_name; // esi
  vostok::render::constants_handler<0> *v8; // edi
  vostok::math::float4x4 result; // [esp+10h] [ebp-C4h] BYREF
  vostok::math::float4x4 v10; // [esp+50h] [ebp-84h] BYREF
  vostok::math::float4x4 v11; // [esp+90h] [ebp-44h] BYREF

  qmemcpy((void *)&m->m_p, ma, sizeof(m->m_p));
  qmemcpy((void *)&m->m_p, ma, sizeof(m->m_p));
  qmemcpy((void *)&m->m_p_transposed, vostok::math::transpose(&result, &m->m_p), sizeof(m->m_p_transposed));
  qmemcpy((void *)&m->m_p, ma, sizeof(m->m_p));
  vostok::math::try_invert4x4(ma, &result);
  qmemcpy((void *)&m->m_p_inverted, v4, sizeof(m->m_p_inverted));
  qmemcpy((void *)&m->m_vp, vostok::math::mul4x4(&m->m_v, &m->m_p), sizeof(m->m_vp));
  qmemcpy((void *)&m->m_vp_transposed, vostok::math::transpose(&v10, &m->m_vp), sizeof(m->m_vp_transposed));
  qmemcpy((void *)&m->m_wvp, vostok::math::mul4x4(&m->m_wv, &m->m_p), sizeof(m->m_wvp));
  qmemcpy((void *)&m->m_wvp_transposed, vostok::math::transpose(&v11, &m->m_wvp), sizeof(m->m_wvp_transposed));
  vostok::render::renderer_context::update_near_far(0, (float *)m);
  vostok::render::renderer_context::update_eye_rays(v6, v5);
  m_conflicted_key_name = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v8 = (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 196);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_p,
    (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                           + 196),
    (const vostok::math::float3 *)&m->m_p_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_vp,
    v8,
    (const vostok::math::float3 *)&m->m_vp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    m->m_c_wvp,
    v8,
    (const vostok::math::float3 *)&m->m_wvp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_p,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_p_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_vp,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_vp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    m->m_c_wvp,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&m->m_wvp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
}
