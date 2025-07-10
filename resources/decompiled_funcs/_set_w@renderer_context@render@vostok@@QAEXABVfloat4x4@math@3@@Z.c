void __fastcall vostok::render::renderer_context::set_w(
        int a1,
        const vostok::math::float4x4 *m,
        vostok::render::renderer_context *this)
{
  vostok::render::constants_handler<1> *m_conflicted_key_name; // esi
  vostok::render::constants_handler<0> *v5; // edi
  vostok::math::float4x4 result; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v7; // [esp+50h] [ebp-40h] BYREF

  qmemcpy((void *)&this->m_w, m, sizeof(this->m_w));
  vostok::math::mul4x3(&result, &this->m_w, &this->m_v);
  qmemcpy((void *)&this->m_wv, &result, sizeof(this->m_wv));
  qmemcpy((void *)&this->m_wvp, vostok::math::mul4x4(&this->m_wv, &this->m_p), sizeof(this->m_wvp));
  qmemcpy((void *)&this->m_wv_inverted_transposed, &result, sizeof(this->m_wv_inverted_transposed));
  vostok::math::float4x4::try_invert(&this->m_wv_inverted_transposed, &this->m_wv_inverted_transposed);
  qmemcpy(
    (void *)&this->m_wv_inverted_transposed,
    vostok::math::transpose(&v7, &this->m_wv_inverted_transposed),
    sizeof(this->m_wv_inverted_transposed));
  qmemcpy((void *)&this->m_w_transposed, vostok::math::transpose(&v7, &this->m_w), sizeof(this->m_w_transposed));
  qmemcpy((void *)&this->m_wv_transposed, vostok::math::transpose(&v7, &this->m_wv), sizeof(this->m_wv_transposed));
  qmemcpy((void *)&this->m_wvp_transposed, vostok::math::transpose(&v7, &this->m_wvp), sizeof(this->m_wvp_transposed));
  m_conflicted_key_name = (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v5 = (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                              + 196);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    this->m_c_w,
    (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                           + 196),
    (const vostok::math::float3 *)&this->m_w_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    this->m_c_wv_inv,
    v5,
    (const vostok::math::float3 *)&this->m_wv_inverted_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    this->m_c_wv,
    v5,
    (const vostok::math::float3 *)&this->m_wv_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    this->m_c_wvp,
    v5,
    (const vostok::math::float3 *)&this->m_wvp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_w,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&this->m_w_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_wv,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&this->m_wv_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_c_wvp,
    m_conflicted_key_name + 123,
    (const vostok::math::float3 *)&this->m_wvp_transposed);
  ++m_conflicted_key_name[7].m_current.m_object;
}
