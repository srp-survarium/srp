void __usercall vostok::render::xs_descriptor<vostok::render::gs_data>::~xs_descriptor<vostok::render::gs_data>(
        vostok::render::xs_descriptor<vostok::render::gs_data> *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::shader_constant_table *v2; // ecx
  vostok::render::res_xs_hw<vostok::render::gs_data> *v3; // eax

  vostok::buffer_vector<vostok::render::texture_slot>::destroy(
    *(vostok::render::texture_slot **)(a2 + 1396),
    (vostok::render::texture_slot *const *)(a2 + 1400));
  v2 = *(vostok::render::shader_constant_table **)(a2 + 1396);
  *(_DWORD *)(a2 + 1400) = v2;
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a2 + 44);
  vostok::render::shader_constant_table::~shader_constant_table(v2);
  v3 = *(vostok::render::res_xs_hw<vostok::render::gs_data> **)a2;
  if ( *(_DWORD *)a2 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs_hw<vostok::render::gs_data> **)a2);
  }
}
