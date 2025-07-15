void __usercall vostok::render::geometry_batch::~geometry_batch(
        vostok::render::geometry_batch *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v3; // eax
  int v5; // eax

  v3 = *(_DWORD **)(a2 + 28);
  if ( v3 )
  {
    if ( (*v3)-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 28));
  }
  v5 = *(_DWORD *)(a2 + 24);
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 24) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 24));
  }
}
