void __thiscall survarium::profile_character::character_animation_ready(
        survarium::profile_character *this,
        vostok::resources::queries_result *data)
{
  int v2; // ebx
  vostok::resources::queries_result *v3; // esi
  survarium::profile_character *v4; // edx
  char **p_m_requery_path; // edi
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  const char *v7; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::managed_resource *m_object; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  vostok::resources::managed_resource *v12; // eax
  unsigned int v13; // ecx
  vostok::resources::managed_resource *v14; // eax
  vostok::resources::managed_resource *v15; // ecx
  vostok::resources::managed_resource *v16; // eax
  vostok::resources::managed_resource *v17; // edx
  unsigned int i; // [esp+10h] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19; // [esp+14h] [ebp-2Ch] BYREF
  survarium::profile_character *v20; // [esp+18h] [ebp-28h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v21; // [esp+1Ch] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-20h] BYREF

  v2 = 0;
  v3 = data;
  v21.m_object = 0;
  v4 = this;
  v20 = this;
  i = 0;
  if ( data->m_size )
  {
    p_m_requery_path = &data->m_queries[0].m_requery_path;
    do
    {
      if ( p_m_requery_path[1] || p_m_requery_path[2] == (char *)1 )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
        {
          v6 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v6 )
          {
            log_callback.functor.obj_ptr = v6;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v7 = *p_m_requery_path;
          v2 |= 1u;
          if ( !*p_m_requery_path )
            v7 = *(p_m_requery_path - 1);
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\lobby_menu_scene.cpp",
            0x12Eu,
            "void __thiscall survarium::profile_character::character_animation_ready(class vostok::resources::queries_result &)",
            "game:",
            error,
            "Wrong data while querying [%s]",
            v7);
          v3 = data;
        }
        if ( (v2 & 1) != 0 )
        {
          v2 &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v8 )
                v8(&log_callback.functor, &log_callback.functor, 2);
            }
          }
        }
      }
      p_m_requery_path += 180;
      ++i;
    }
    while ( i < v3->m_size );
    v4 = v20;
  }
  m_object = v3->m_queries[0].m_managed_resource.m_object;
  v10 = 0;
  v19.m_object = 0;
  if ( m_object )
  {
    v10 = (unsigned int)m_object;
    v19.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v11 = 0;
  i = 0;
  if ( v10 )
  {
    v11 = v10;
    i = v10;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 220), 1u);
  }
  v12 = 0;
  if ( v11 )
  {
    v12 = (vostok::resources::managed_resource *)v11;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 220), 1u);
  }
  v21.m_object = v4->m_character_animation[0].m_object;
  v4->m_character_animation[0].m_object = v12;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v21);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&i);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v19);
  v13 = (unsigned int)v3->m_queries[1].m_managed_resource.m_object;
  v14 = 0;
  i = 0;
  if ( v13 )
  {
    v14 = (vostok::resources::managed_resource *)v13;
    i = v13;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v13 + 220), 1u);
  }
  v15 = 0;
  v19.m_object = 0;
  if ( v14 )
  {
    v15 = v14;
    v19.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  v16 = 0;
  if ( v15 )
  {
    v16 = v15;
    _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  v17 = v20->m_character_animation[1].m_object;
  v20->m_character_animation[1].m_object = v16;
  v21.m_object = v17;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v21);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v19);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&i);
}
