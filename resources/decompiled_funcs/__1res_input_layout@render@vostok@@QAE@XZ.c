void __usercall vostok::render::res_input_layout::~res_input_layout(
        vostok::render::res_input_layout *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  _DWORD *v3; // eax

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 4));
    *(_DWORD *)(a2 + 4) = 0;
  }
  v3 = *(_DWORD **)(a2 + 12);
  if ( v3 )
  {
    if ( (*v3)-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_signature **)(a2 + 12));
  }
}
