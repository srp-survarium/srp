void __thiscall survarium::generate_shaders_world::generate_materials_shaders(
        survarium::generate_shaders_world *this,
        survarium::generate_shaders_world *thisa)
{
  vostok::console_commands::console_command *v2; // edi
  vostok::console_commands::console_command *v3; // eax
  unsigned int *v4; // edi
  unsigned int *v5; // eax
  vostok::render::scene_renderer *v6; // ecx
  vostok::render::game::renderer *m_renderer; // eax
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v10; // ecx
  unsigned int v11; // ecx
  vostok::resources::resources_manager *m_variable; // ecx
  vostok::command_line::key::type_enum v13; // eax
  vostok::resources::resources_manager *v14; // ecx
  volatile int m_pending_queries_count; // edi
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::scene_renderer *m_scene; // [esp-18h] [ebp-88h]
  int waiting_for; // [esp+10h] [ebp-60h] BYREF
  int v20; // [esp+14h] [ebp-5Ch]
  unsigned int shading_quality; // [esp+18h] [ebp-58h]
  unsigned int shadow_quality; // [esp+1Ch] [ebp-54h]
  vostok::command_line::key_initializator predicate[4]; // [esp+20h] [ebp-50h]
  vostok::command_line::key_initializator v24[4]; // [esp+24h] [ebp-4Ch]
  unsigned int v25; // [esp+28h] [ebp-48h]
  unsigned int *shadow_quality_command_value; // [esp+2Ch] [ebp-44h]
  unsigned int *shading_quality_command_value; // [esp+30h] [ebp-40h]
  vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> output_window; // [esp+34h] [ebp-3Ch] BYREF
  vostok::command_line::key_initializator v29[4]; // [esp+38h] [ebp-38h]
  vostok::command_line::key_initializator v30[4]; // [esp+3Ch] [ebp-34h]
  unsigned int shadow_quality_values[2]; // [esp+40h] [ebp-30h]
  unsigned int shading_quality_values[2]; // [esp+48h] [ebp-28h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+50h] [ebp-20h] BYREF

  v20 = 0;
  v2 = vostok::console_commands::find("r_shadow_quality");
  v3 = vostok::console_commands::find("r_shading_quality");
  v4 = (unsigned int *)v2[1].__vftable;
  v5 = (unsigned int *)v3[1].__vftable;
  *v4 = -1;
  shading_quality_command_value = v5;
  *v5 = -1;
  shadow_quality_command_value = v4;
  shadow_quality_values[0] = 0;
  shadow_quality_values[1] = 3;
  shading_quality_values[0] = 0;
  shading_quality_values[1] = 3;
  for ( shadow_quality = 0; shadow_quality < 2; ++shadow_quality )
  {
    v6 = (vostok::render::scene_renderer *)shadow_quality_values[shadow_quality];
    shading_quality = 0;
    v25 = (unsigned int)v6;
    do
    {
      m_renderer = thisa->m_renderer;
      waiting_for = 1;
      vostok::render::scene_renderer::begin_render_options_changing(v6, m_renderer->m_scene, &waiting_for);
      while ( waiting_for )
      {
        m_initialized = (vostok::resources::resources_manager *)vostok::resources::g_resources_manager.m_initialized;
        if ( vostok::resources::g_resources_manager.m_initialized )
        {
          m_type = vostok::threading::g_debug_single_thread.m_type;
          if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
          {
            predicate[0] = 0;
            vostok::threading::g_debug_single_thread.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            m_type = vostok::threading::g_debug_single_thread.m_type;
          }
          if ( m_type != type_recursive )
          {
            if ( m_type == type_unset )
            {
              v24[0] = 0;
              vostok::threading::g_debug_single_thread.m_type = type_recursive;
              vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
              m_type = vostok::threading::g_debug_single_thread.m_type;
            }
            if ( m_type != type_recursive )
            {
              vostok::resources::resources_manager::resources_thread_tick(m_initialized);
              vostok::resources::resources_manager::cooker_thread_tick(
                v10,
                vostok::resources::g_resources_manager.m_variable);
            }
          }
          vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
        }
        if ( !SwitchToThread() )
          Sleep(0);
      }
      v11 = shading_quality;
      *shadow_quality_command_value = v25;
      *shading_quality_command_value = shading_quality_values[v11];
      waiting_for = 1;
      m_scene = thisa->m_renderer->m_scene;
      output_window.m_object = 0;
      vostok::render::scene_renderer::end_render_options_changing(
        (vostok::render::scene_renderer *)&output_window,
        m_scene,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&output_window,
        0,
        1,
        0,
        &waiting_for);
      while ( 1 )
      {
        if ( !waiting_for )
        {
          if ( !vostok::resources::g_resources_manager.m_initialized )
            break;
          m_variable = vostok::resources::g_resources_manager.m_variable;
          if ( !vostok::resources::g_resources_manager.m_variable->m_pending_queries_count )
            break;
        }
        if ( vostok::resources::g_resources_manager.m_initialized )
        {
          v13 = vostok::threading::g_debug_single_thread.m_type;
          if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
          {
            v29[0] = 0;
            vostok::threading::g_debug_single_thread.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            v13 = vostok::threading::g_debug_single_thread.m_type;
          }
          if ( v13 != type_recursive )
          {
            if ( v13 == type_unset )
            {
              v30[0] = 0;
              vostok::threading::g_debug_single_thread.m_type = type_recursive;
              vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
              v13 = vostok::threading::g_debug_single_thread.m_type;
            }
            if ( v13 != type_recursive )
            {
              vostok::resources::resources_manager::resources_thread_tick(m_variable);
              vostok::resources::resources_manager::cooker_thread_tick(
                v14,
                vostok::resources::g_resources_manager.m_variable);
            }
          }
          vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
        }
        if ( !SwitchToThread() )
          Sleep(0);
      }
      if ( vostok::resources::g_resources_manager.m_initialized )
        m_pending_queries_count = vostok::resources::g_resources_manager.m_variable->m_pending_queries_count;
      else
        m_pending_queries_count = 0;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v16 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v16 )
        {
          log_callback.functor.obj_ptr = v16;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v20 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_generate_shaders.cpp",
          0x81u,
          "void __thiscall survarium::generate_shaders_world::generate_materials_shaders(void)",
          "game:",
          error,
          "pending_queries_count:%d",
          m_pending_queries_count);
      }
      if ( (v20 & 1) != 0 )
      {
        v20 &= ~1u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v17 )
              v17(&log_callback.functor, &log_callback.functor, 2);
          }
          log_callback.vtable = 0;
        }
      }
      ++shading_quality;
    }
    while ( shading_quality < 2 );
  }
}
