void __usercall vostok::resources::query_result::do_create_resource_impl(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  volatile int *v3; // edi
  vostok::resources::managed_cook *cook; // eax
  vostok::resources::query_result *v5; // ecx
  vostok::resources::inplace_managed_cook *v6; // eax
  vostok::resources::query_result *v7; // ecx
  vostok::resources::cook_base *v8; // eax
  vostok::resources::query_result *v9; // ecx
  vostok::resources::inplace_unmanaged_cook *v10; // eax
  unsigned int m_flags; // ecx

  v3 = (volatile int *)(a2 + 688);
  vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFDFFFFF);
  vostok::threading::interlocked_or(v3, 0x100000u);
  cook = (vostok::resources::managed_cook *)vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook
    && (v5 = (vostok::resources::query_result *)cook->m_flags.m_flags, ((unsigned __int8)v5 & 0x20) != 0)
    && ((unsigned __int8)v5 & 0x18) == 0 )
  {
    vostok::resources::query_result::do_managed_create_resource(v5, a2, cook);
    vostok::threading::interlocked_and(v3, 0xFFEFFFFF);
  }
  else
  {
    v6 = (vostok::resources::inplace_managed_cook *)vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
    if ( v6
      && (v7 = (vostok::resources::query_result *)v6->m_flags.m_flags, ((unsigned __int8)v7 & 0x20) != 0)
      && ((unsigned __int8)v7 & 0x10) != 0
      && ((unsigned __int8)v7 & 8) == 0 )
    {
      vostok::resources::query_result::do_inplace_managed_create_resource(v7, a2, v6);
      vostok::threading::interlocked_and(v3, 0xFFEFFFFF);
    }
    else
    {
      v8 = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
      if ( !v8 || (v8->m_flags.m_flags & 0x38) != 0 )
      {
        v10 = (vostok::resources::inplace_unmanaged_cook *)vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
        if ( !v10
          || (m_flags = v10->m_flags.m_flags, (m_flags & 0x20) != 0)
          || (m_flags & 0x10) == 0
          || (m_flags & 8) != 0 )
        {
          *(_DWORD *)(a2 + 256) = 0;
          *(_DWORD *)(a2 + 260) = 3;
          vostok::threading::interlocked_and(v3, 0xFFEFFFFF);
        }
        else
        {
          vostok::resources::query_result::do_inplace_unmanaged_create_resource(
            (vostok::resources::query_result *)a2,
            v10);
          vostok::threading::interlocked_and(v3, 0xFFEFFFFF);
        }
      }
      else
      {
        vostok::resources::query_result::do_unmanaged_create_resource(
          v9,
          (_DWORD *)a2,
          (vostok::resources::unmanaged_cook *)v8);
        vostok::threading::interlocked_and(v3, 0xFFEFFFFF);
      }
    }
  }
}
