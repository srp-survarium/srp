void __usercall vostok::render::render_target::~render_target(
        vostok::render::render_target *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::render::res_texture *v3; // ecx
  int v4; // eax
  volatile signed __int32 *v6; // eax

  vostok::render::render_target::destroy(this, (int)a2);
  v3 = (vostok::render::res_texture *)a2[11];
  *(_DWORD *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][1].m_options_count -= v3;
  v4 = a2[6];
  if ( v4 )
  {
    if ( (*(_DWORD *)(v4 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(v3);
  }
  v6 = (volatile signed __int32 *)a2[1];
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd(v6, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        s_manager.m_variable,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
