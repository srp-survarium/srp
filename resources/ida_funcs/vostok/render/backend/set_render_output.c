void __usercall vostok::render::backend::set_render_output(vostok::render::backend *this@<ecx>, _DWORD *a2@<esi>)
{
  vostok::render::backend *v2; // eax
  const vostok::render::res_render_output *v3; // edi
  int v5; // eax
  int v6; // ecx

  v2 = 0;
  if ( this )
  {
    ++this->num_vs_changes;
    v2 = this;
  }
  v3 = (const vostok::render::res_render_output *)a2[540];
  a2[540] = v2;
  if ( v3 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v3);
  }
  v5 = a2[540];
  if ( v5 )
    v6 = *(_DWORD *)(v5 + 208);
  else
    v6 = 0;
  a2[546] = v6;
  if ( v5 )
    a2[547] = *(_DWORD *)(v5 + 212);
  else
    a2[547] = 0;
}
