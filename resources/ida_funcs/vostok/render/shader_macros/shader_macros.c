void __usercall vostok::render::shader_macros::shader_macros(vostok::render::shader_macros *this@<ecx>, int a2@<esi>)
{
  vostok::render::shader_macros *v2; // ecx

  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[2] = (survarium::options_tab *)a2;
  vostok::buffer_vector<void const *>::buffer_vector<void const *>(
    (vostok::buffer_vector<void const *> *)a2,
    (const void **)(a2 + 8),
    0x80u,
    0);
  *(_DWORD *)(a2 + 520) = a2 + 528;
  *(_DWORD *)(a2 + 524) = a2 + 528;
  vostok::render::shader_macros::register_available_macros(v2, (vostok::buffer_vector<void const *> *)a2);
}
