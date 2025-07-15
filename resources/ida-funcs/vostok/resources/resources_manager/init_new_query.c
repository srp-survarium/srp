void __thiscall vostok::resources::resources_manager::init_new_query(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *query,
        vostok::resources::query_result::only_try_to_get_associated_resource_bool only_try_to_get_associated_resource)
{
  vostok::fixed_string<260> *v3; // ecx
  char *requested_path; // eax
  vostok::fixed_string<260> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(void)> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function<void __cdecl(void)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  bool v11; // al
  int v12; // eax
  vostok::resources::query_result *v13; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > v14; // [esp-10h] [ebp-170h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > v15; // [esp-10h] [ebp-170h]
  vostok::resources::reallocating_bool v16; // [esp+0h] [ebp-160h]
  vostok::fs_new::virtual_path_string v17; // [esp+10h] [ebp-150h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+128h] [ebp-38h] BYREF
  int v19; // [esp+150h] [ebp-10h]
  void (__thiscall *v20)(vostok::resources::resources_manager *, vostok::resources::allocate_functionality *); // [esp+154h] [ebp-Ch]
  vostok::resources::resources_manager *v21; // [esp+158h] [ebp-8h]
  int v22; // [esp+15Ch] [ebp-4h]

  if ( vostok::resources::query_result::is_translate_query(
         (vostok::resources::query_result *)this,
         only_try_to_get_associated_resource) )
  {
    if ( *(_DWORD *)(only_try_to_get_associated_resource + 260) == 4 )
    {
      if ( !*(_DWORD *)(only_try_to_get_associated_resource + 268)
        && !*(_DWORD *)(only_try_to_get_associated_resource + 272) )
      {
        requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)only_try_to_get_associated_resource);
        vostok::fixed_string<260>::fixed_string<260>(v5, &v17.m_string, requested_path);
        v17.m_separator = 47;
        f.vtable = 0;
        vostok::vfs::query_hot_mount_and_wait(
          (vostok::fs_new::native_path_string *)((char *)&loc_20608 + (_DWORD)query),
          &v17,
          &vostok::memory::g_resources_helper_allocator,
          &f);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v6,
          (int *)&f);
      }
      if ( *(_DWORD *)(only_try_to_get_associated_resource + 268) )
      {
        vostok::fixed_string<260>::fixed_string<260>(
          v3,
          &v17.m_string,
          *(char **)(only_try_to_get_associated_resource + 268));
        v21 = query;
        LOBYTE(v19) = 0;
        v22 = v19;
        v20 = vostok::resources::resources_manager::dispatch_callbacks;
        v14.l_.a1_.t_ = (vostok::resources::resources_manager *)vostok::resources::resources_manager::dispatch_callbacks;
        *(_DWORD *)&v14.l_.a2_.t_ = query;
        v14.f_.f_ = (void (__thiscall *)(vostok::resources::resources_manager *, bool))&f;
        v17.m_separator = 47;
        boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, v14, v19);
        vostok::vfs::query_hot_mount_and_wait(
          (vostok::fs_new::native_path_string *)((char *)&loc_20608 + (_DWORD)query),
          &v17,
          &vostok::memory::g_resources_helper_allocator,
          &f);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v8,
          (int *)&f);
      }
      if ( *(_DWORD *)(only_try_to_get_associated_resource + 272) )
      {
        vostok::fixed_string<260>::fixed_string<260>(
          v3,
          &v17.m_string,
          *(char **)(only_try_to_get_associated_resource + 272));
        v21 = query;
        LOBYTE(v19) = 0;
        v22 = v19;
        v20 = vostok::resources::resources_manager::dispatch_callbacks;
        v15.l_.a1_.t_ = (vostok::resources::resources_manager *)vostok::resources::resources_manager::dispatch_callbacks;
        *(_DWORD *)&v15.l_.a2_.t_ = query;
        v15.f_.f_ = (void (__thiscall *)(vostok::resources::resources_manager *, bool))&f;
        v17.m_separator = 47;
        boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v9, v15, v19);
        vostok::vfs::query_hot_mount_and_wait(
          (vostok::fs_new::native_path_string *)((char *)&loc_20608 + (_DWORD)query),
          &v17,
          &vostok::memory::g_resources_helper_allocator,
          &f);
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          v10,
          (int *)&f);
      }
    }
    vostok::resources::resources_manager::push_to_translate_query(
      (vostok::resources::query_result *)only_try_to_get_associated_resource,
      query);
  }
  else
  {
    v11 = *(_DWORD *)(only_try_to_get_associated_resource + 208)
       || *(_DWORD *)(only_try_to_get_associated_resource + 212);
    v12 = vostok::resources::query_result::consider_with_name_registry(
            (vostok::resources::query_result *)!v11,
            (char *)only_try_to_get_associated_resource,
            !v11);
    if ( !v12 || v12 == 4 )
    {
      vostok::resources::query_result::end_query_might_destroy_this(v13, only_try_to_get_associated_resource);
    }
    else if ( v12 != 2 )
    {
      if ( *(_DWORD *)(only_try_to_get_associated_resource + 208)
        || *(_DWORD *)(only_try_to_get_associated_resource + 212) )
      {
        vostok::resources::allocate_functionality::prepare_raw_resource(
          (vostok::resources::query_result *)only_try_to_get_associated_resource,
          0,
          v16);
      }
      else
      {
        vostok::resources::query_result::process_request_path(
          0,
          (vostok::resources::query_result_for_user *)only_try_to_get_associated_resource,
          0);
      }
    }
  }
}
