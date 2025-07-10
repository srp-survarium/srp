void __usercall vostok::render::res_xs_hw<vostok::render::vs_data>::~res_xs_hw<vostok::render::vs_data>(
        vostok::render::res_xs_hw<vostok::render::vs_data> *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  volatile signed __int32 *v4; // eax

  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
    *(_DWORD *)(a2 + 8) = 0;
  }
  v4 = *(volatile signed __int32 **)(a2 + 12160);
  if ( v4 )
  {
    this = (vostok::render::res_xs_hw<vostok::render::vs_data> *)_InterlockedExchangeAdd(v4, 0xFFFFFFFF);
    if ( !this )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::render::vs_data::~vs_data((vostok::render::vs_data *)this, a2 + 4);
}
