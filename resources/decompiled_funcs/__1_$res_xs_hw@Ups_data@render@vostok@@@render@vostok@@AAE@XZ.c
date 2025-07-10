void __usercall vostok::render::res_xs_hw<vostok::render::ps_data>::~res_xs_hw<vostok::render::ps_data>(
        vostok::render::res_xs_hw<vostok::render::ps_data> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  volatile signed __int32 *v3; // eax
  vostok::render::shader_constant_table *v4; // ecx

  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 8));
    *(_DWORD *)(a2 + 8) = 0;
  }
  v3 = *(volatile signed __int32 **)(a2 + 12156);
  if ( v3 && !_InterlockedExchangeAdd(v3, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::buffer_vector<vostok::render::texture_slot>::destroy(
    *(vostok::render::texture_slot **)(a2 + 1396),
    (vostok::render::texture_slot *const *)(a2 + 1400));
  *(_DWORD *)(a2 + 1400) = *(_DWORD *)(a2 + 1396);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a2 + 44);
  vostok::render::shader_constant_table::~shader_constant_table(v4);
}
