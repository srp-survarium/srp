void __userpurge vostok::render::static_render_model_instance::add_sectors_holder(
        vostok::render::static_render_model_instance *this@<ecx>,
        int a2@<edi>,
        vostok::configs::binary_config_value sectotrs_cfg)
{
  _DWORD *v3; // eax
  int v4; // eax
  vostok::render::culling::possible_sectors_holder v5; // [esp-18h] [ebp-1Ch] BYREF

  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         8u);
  if ( v3 )
  {
    vostok::render::culling::possible_sectors_holder::possible_sectors_holder(&v5, v3, sectotrs_cfg);
    *(_DWORD *)(a2 + 264) = v4;
  }
  else
  {
    *(_DWORD *)(a2 + 264) = 0;
  }
}
