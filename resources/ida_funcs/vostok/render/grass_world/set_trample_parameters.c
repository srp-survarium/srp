void __usercall vostok::render::grass_world::set_trample_parameters(
        vostok::render::grass_world *this@<edx>,
        vostok::render::trample_desc *desc@<eax>)
{
  const char *m_conflicted_key_name; // esi

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
    this->m_trample_parameters,
    (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
  + 123,
    (const vostok::math::float3 *)&desc->multiplier);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
