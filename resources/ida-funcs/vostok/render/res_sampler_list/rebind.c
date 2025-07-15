void __usercall vostok::render::res_sampler_list::rebind(
        vostok::render::res_sampler_list *this@<ecx>,
        _DWORD *a2@<esi>)
{
  unsigned int v2; // ebx
  int v3; // ebp

  v2 = 0;
  if ( (a2[2] - a2[1]) >> 2 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(a2[1] + 4 * v2++) = vostok::render::resource_manager::find_registered_sampler(
                                        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                        *(const char **)(a2[4] + v3));
      v3 += 44;
    }
    while ( v2 < (a2[2] - a2[1]) >> 2 );
  }
}
