void __usercall vostok::resources::resources_manager::dispatch_decompressed_resources(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  int v3; // ebx
  int v4; // ecx
  int v5; // esi
  int v6; // ebx
  vostok::resources::cook_base *cook; // eax
  int v8; // ecx
  unsigned int m_flags; // eax
  vostok::resources::cook_base *v10; // eax
  vostok::resources::query_result *v11; // ecx

  if ( *(_DWORD *)((char *)&loc_204D3 + a2 + 1) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_204B7 + a2 + 1));
    v3 = *(_DWORD *)((char *)&loc_204D3 + a2 + 1);
    *(_DWORD *)((char *)&loc_204D3 + a2 + 1) = 0;
    *(_DWORD *)((char *)&loc_204D5 + a2 + 3) = 0;
    *(_DWORD *)((char *)&loc_204AD + a2 + 3) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_204B7 + a2 + 1));
    v5 = v3;
    if ( v3 )
    {
      do
      {
        v6 = *(_DWORD *)(v5 + 608);
        *(_DWORD *)(v5 + 608) = 0;
        if ( *(_DWORD *)(v5 + 256) )
        {
          v4 = _InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 684), 0xFFFFFFFF);
          if ( !v4 )
            vostok::resources::query_result::end_query_might_destroy_this_impl(0);
        }
        else
        {
          cook = vostok::resources::resources_manager::find_cook(v4, *(vostok::resources::class_id_enum *)(v5 + 132));
          if ( cook && (m_flags = cook->m_flags.m_flags, (m_flags & 0x20) != 0) && (m_flags & 0x18) == 0
            || (v10 = vostok::resources::resources_manager::find_cook(
                        v8,
                        *(vostok::resources::class_id_enum *)(v5 + 132))) != 0
            && (v10->m_flags.m_flags & 0x38) == 0 )
          {
            vostok::resources::allocate_functionality::prepare_final_resource(
              &vostok::resources::g_resources_manager.m_variable->m_allocate_functionality,
              (vostok::resources::query_result *)v5);
          }
          else
          {
            vostok::resources::query_result::send_to_create_resource(v11, v5);
          }
        }
        v5 = v6;
      }
      while ( v6 );
    }
  }
}
