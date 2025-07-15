void __userpurge vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(
        vostok::resources::vfs_sub_fat_resource *sub_fat@<eax>,
        vostok::threading::simple_lock *a2@<ecx>,
        vostok::resources::resource_freeing_functionality *this)
{
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_parent_resources; // esi
  vostok::threading::simple_lock *v4; // eax
  vostok::resources::resource_link *v5; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  vostok::resources::resource_base *resource; // edi
  bool has_passed_filters; // al
  vostok::resources::resource_base_vtbl *v9; // eax
  const char **v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-8h] [ebp-254h]
  vostok::fixed_string<512> v12; // [esp+Ch] [ebp-240h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+218h] [ebp-34h] BYREF
  vostok::threading::simple_lock::mutex_raii v14; // [esp+238h] [ebp-14h] BYREF
  vostok::resources::resource_link *object; // [esp+240h] [ebp-Ch]
  int v16; // [esp+244h] [ebp-8h]

  v16 = 0;
  p_m_parent_resources = &sub_fat->m_parent_resources;
  if ( sub_fat == (vostok::resources::vfs_sub_fat_resource *)-60 )
    v4 = 0;
  else
    v4 = &sub_fat->m_parent_resources.vostok::threading::simple_lock;
  v14.lock = v4;
  vostok::threading::simple_lock::lock(a2, (int)v4);
  v14.locked = 1;
  for ( object = vostok::resources::resource_link_list_front_no_dying(p_m_parent_resources);
        object;
        object = vostok::resources::resource_link_list_next_no_dying(v5) )
  {
    v5 = object;
    if ( !vostok::resources::resource_freeing_functionality::try_collect_to_free_resource(this, object->resource) )
    {
      resource = v5->resource;
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&stru_7F94B0.m_string.m_buffer[28],
                                   (const char *)3),
            v6 = v11,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v6,
          &log_callback);
        v9 = resource->__vftable;
        v16 |= 1u;
        v10 = (const char **)v9->log_string(resource, &v12);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_resman_free.cpp",
          0x9Eu,
          "void __thiscall vostok::resources::resource_freeing_functionality::release_sub_fat_from_parents(class vostok::"
          "resources::vfs_sub_fat_resource *)",
          &stru_7F94B0.m_string.m_buffer[28],
          warning,
          "LEAK: %s or one of its parents is held by userwhen its sub-fat being unmounted, leak?",
          *v10);
      }
      if ( (v16 & 1) != 0 )
      {
        v16 &= ~1u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
          (int *)&log_callback);
      }
      vostok::resources::resource_base::clean_sub_fat_and_fat_it(resource);
      v5 = object;
    }
  }
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v14);
}
