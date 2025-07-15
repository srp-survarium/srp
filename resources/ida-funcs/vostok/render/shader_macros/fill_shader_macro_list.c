void __userpurge vostok::render::shader_macros::fill_shader_macro_list(
        vostok::fixed_vector<vostok::render::shader_macro,128> *macros@<esi>,
        vostok::render::options *a2@<ecx>,
        vostok::render::shader_macros *this,
        vostok::render::shader_configuration shader_config)
{
  vostok::render::shader_configuration v4; // [esp-10h] [ebp-10h]

  HIDWORD(v4.configuration[1]) = a2;
  macros->m_end = macros->m_begin;
  vostok::render::options::fill_global_macros(
    a2,
    (int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
    macros);
  *(_DWORD *)&v4.0 = shader_config.0;
  *(unsigned __int64 *)((char *)v4.configuration + 4) = *(unsigned __int64 *)((char *)shader_config.configuration + 4);
  vostok::render::shader_macros::fill_shader_configuration_macros(macros, this, v4);
}
