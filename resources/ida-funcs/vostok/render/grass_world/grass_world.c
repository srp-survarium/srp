void __usercall vostok::render::grass_world::grass_world(vostok::render::grass_world *this@<ecx>, int a2@<esi>)
{
  vostok::strings::shared::profile *v2; // eax
  vostok::render::backend *v3; // ecx
  vostok::strings::shared::manager *v4; // edi
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::strings::shared::manager *v7; // edi
  vostok::strings::shared::profile *v8; // eax
  vostok::render::backend *v9; // ecx
  vostok::strings::shared::manager *v10; // edi
  vostok::strings::shared::profile *v11; // eax
  vostok::render::backend *v12; // ecx
  vostok::strings::shared::manager *v13; // edi
  vostok::strings::shared::profile *v14; // eax
  vostok::render::backend *v15; // ecx
  vostok::strings::shared::manager *v16; // edi
  vostok::strings::shared::profile *v17; // eax
  vostok::render::backend *v18; // ecx
  vostok::strings::shared::manager *v19; // edi
  vostok::strings::shared::profile *v20; // eax
  vostok::render::backend *v21; // ecx
  vostok::strings::shared::manager *v22; // edi
  vostok::strings::shared::profile *v23; // eax
  vostok::render::backend *v24; // ecx
  vostok::strings::shared::manager *v25; // edi
  vostok::strings::shared::profile *v26; // eax
  vostok::render::backend *v27; // ecx
  vostok::strings::shared::manager *v28; // edi
  vostok::strings::shared::profile *v29; // eax
  vostok::render::backend *v30; // ecx
  vostok::strings::shared::manager *v31; // edi
  vostok::shared_string name; // [esp+10h] [ebp-4h] BYREF

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &vostok::render::grass_world::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = vostok::collision::new_space_partitioning_tree(
                            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                            1.0,
                            0x400u);
  v2 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v4 = 0;
  name.m_pointer.m_object = 0;
  if ( v2 )
  {
    v4 = (vostok::strings::shared::manager *)v2;
    name.m_pointer.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 316) = vostok::render::backend::register_constant_host(
                            v3,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)v4, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v4, (vostok::strings::shared::profile *)s_manager.m_variable);
  point_random_x.m_seed = GetTickCount();
  point_random_z.m_seed = point_random_x.m_seed;
  model_index_random.m_seed = point_random_x.m_seed;
  model_orientation_random.m_seed = point_random_x.m_seed;
  model_density_random.m_seed = point_random_x.m_seed;
  model_scale_random.m_seed = point_random_x.m_seed;
  v5 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v7 = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    v7 = (vostok::strings::shared::manager *)v5;
    name.m_pointer.m_object = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 320) = vostok::render::backend::register_constant_host(
                            v6,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)v7, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v7, (vostok::strings::shared::profile *)s_manager.m_variable);
  v8 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v10 = 0;
  name.m_pointer.m_object = 0;
  if ( v8 )
  {
    v10 = (vostok::strings::shared::manager *)v8;
    name.m_pointer.m_object = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 324) = vostok::render::backend::register_constant_host(
                            v9,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)v10, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v10, (vostok::strings::shared::profile *)s_manager.m_variable);
  v11 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v13 = 0;
  name.m_pointer.m_object = 0;
  if ( v11 )
  {
    v13 = (vostok::strings::shared::manager *)v11;
    name.m_pointer.m_object = v11;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 328) = vostok::render::backend::register_constant_host(
                            v12,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v13 && !_InterlockedExchangeAdd((volatile signed __int32 *)v13, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v13, (vostok::strings::shared::profile *)s_manager.m_variable);
  v14 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v16 = 0;
  name.m_pointer.m_object = 0;
  if ( v14 )
  {
    v16 = (vostok::strings::shared::manager *)v14;
    name.m_pointer.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 332) = vostok::render::backend::register_constant_host(
                            v15,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v16 && !_InterlockedExchangeAdd((volatile signed __int32 *)v16, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v16, (vostok::strings::shared::profile *)s_manager.m_variable);
  v17 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v19 = 0;
  name.m_pointer.m_object = 0;
  if ( v17 )
  {
    v19 = (vostok::strings::shared::manager *)v17;
    name.m_pointer.m_object = v17;
    _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 336) = vostok::render::backend::register_constant_host(
                            v18,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v19 && !_InterlockedExchangeAdd((volatile signed __int32 *)v19, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v19, (vostok::strings::shared::profile *)s_manager.m_variable);
  v20 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v22 = 0;
  name.m_pointer.m_object = 0;
  if ( v20 )
  {
    v22 = (vostok::strings::shared::manager *)v20;
    name.m_pointer.m_object = v20;
    _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 340) = vostok::render::backend::register_constant_host(
                            v21,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v22 && !_InterlockedExchangeAdd((volatile signed __int32 *)v22, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v22, (vostok::strings::shared::profile *)s_manager.m_variable);
  v23 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v25 = 0;
  name.m_pointer.m_object = 0;
  if ( v23 )
  {
    v25 = (vostok::strings::shared::manager *)v23;
    name.m_pointer.m_object = v23;
    _InterlockedExchangeAdd(&v23->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 344) = vostok::render::backend::register_constant_host(
                            v24,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v25 && !_InterlockedExchangeAdd((volatile signed __int32 *)v25, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v25, (vostok::strings::shared::profile *)s_manager.m_variable);
  v26 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v28 = 0;
  name.m_pointer.m_object = 0;
  if ( v26 )
  {
    v28 = (vostok::strings::shared::manager *)v26;
    name.m_pointer.m_object = v26;
    _InterlockedExchangeAdd(&v26->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 348) = vostok::render::backend::register_constant_host(
                            v27,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_int);
  if ( v28 && !_InterlockedExchangeAdd((volatile signed __int32 *)v28, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v28, (vostok::strings::shared::profile *)s_manager.m_variable);
  v29 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v31 = 0;
  name.m_pointer.m_object = 0;
  if ( v29 )
  {
    v31 = (vostok::strings::shared::manager *)v29;
    name.m_pointer.m_object = v29;
    _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 352) = vostok::render::backend::register_constant_host(
                            v30,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v31 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v31, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v31, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
