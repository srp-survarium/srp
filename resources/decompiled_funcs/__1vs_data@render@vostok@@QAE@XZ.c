void __usercall vostok::render::vs_data::~vs_data(vostok::render::vs_data *this@<ecx>, int a2@<esi>)
{
  _DWORD *v2; // eax
  vostok::render::shader_constant_table *v4; // ecx

  v2 = *(_DWORD **)(a2 + 12152);
  if ( v2 )
  {
    if ( (*v2)-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_signature **)(a2 + 12152));
  }
  vostok::buffer_vector<vostok::render::texture_slot>::destroy(
    *(vostok::render::texture_slot **)(a2 + 1392),
    (vostok::render::texture_slot *const *)(a2 + 1396));
  *(_DWORD *)(a2 + 1396) = *(_DWORD *)(a2 + 1392);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a2 + 40);
  vostok::render::shader_constant_table::~shader_constant_table(v4);
}
