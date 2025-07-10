void __thiscall survarium::generate_shaders_world::generate_renderer_shaders(
        survarium::generate_shaders_world *this,
        survarium::generate_shaders_world *thisa)
{
  vostok::console_commands::console_command *v2; // edi
  vostok::console_commands::console_command *v3; // ebx
  vostok::console_commands::console_command *v4; // eax
  unsigned int *v5; // edi
  unsigned int *v6; // ebx
  unsigned int *v7; // eax
  unsigned int *v8; // ecx
  unsigned int *v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edx
  vostok::render::scene_renderer *v13; // ecx
  vostok::render::game::renderer *m_renderer; // eax
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v17; // ecx
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // ecx
  vostok::resources::resources_manager *m_variable; // ecx
  vostok::command_line::key::type_enum v23; // eax
  vostok::resources::resources_manager *v24; // ecx
  volatile int m_pending_queries_count; // edi
  void (__cdecl *v26)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v27)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::scene_renderer *m_scene; // [esp-18h] [ebp-D0h]
  int waiting_for; // [esp+10h] [ebp-A8h] BYREF
  int v30; // [esp+14h] [ebp-A4h]
  unsigned int antialiasing_method; // [esp+18h] [ebp-A0h]
  unsigned int shadow_quality; // [esp+1Ch] [ebp-9Ch]
  unsigned int post_process_quality; // [esp+20h] [ebp-98h]
  char v34; // [esp+27h] [ebp-91h]
  unsigned int lighting_quality; // [esp+28h] [ebp-90h]
  unsigned int shading_quality; // [esp+2Ch] [ebp-8Ch]
  unsigned int *shadow_quality_command_value; // [esp+30h] [ebp-88h]
  unsigned int *post_process_quality_command_value; // [esp+34h] [ebp-84h]
  vostok::command_line::key_initializator v39[4]; // [esp+38h] [ebp-80h]
  vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> output_window; // [esp+3Ch] [ebp-7Ch] BYREF
  unsigned int *antialiasing_method_command_value; // [esp+40h] [ebp-78h]
  vostok::command_line::key_initializator v42[4]; // [esp+44h] [ebp-74h]
  vostok::command_line::key_initializator predicate[4]; // [esp+48h] [ebp-70h]
  vostok::command_line::key_initializator v44[4]; // [esp+4Ch] [ebp-6Ch]
  unsigned int *lighting_quality_command_value; // [esp+50h] [ebp-68h]
  unsigned int v46; // [esp+54h] [ebp-64h]
  unsigned int *shading_quality_command_value; // [esp+58h] [ebp-60h]
  unsigned int v48; // [esp+5Ch] [ebp-5Ch]
  unsigned int v49; // [esp+60h] [ebp-58h]
  vostok::render::scene_renderer *v50; // [esp+64h] [ebp-54h]
  unsigned int shadow_quality_values[2]; // [esp+68h] [ebp-50h]
  unsigned int post_process_quality_values[2]; // [esp+70h] [ebp-48h]
  unsigned int lighting_quality_values[2]; // [esp+78h] [ebp-40h]
  unsigned int shading_quality_values[2]; // [esp+80h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+88h] [ebp-30h] BYREF
  unsigned int antialiasing_method_values[3]; // [esp+ACh] [ebp-Ch]

  v30 = 0;
  v2 = vostok::console_commands::find("r_antialiasing_method");
  v3 = vostok::console_commands::find("r_shadow_quality");
  antialiasing_method = (unsigned int)vostok::console_commands::find("r_lighting_quality");
  shadow_quality = (unsigned int)vostok::console_commands::find("r_shading_quality");
  v4 = vostok::console_commands::find("r_post_process_quality");
  v5 = (unsigned int *)v2[1].__vftable;
  v6 = (unsigned int *)v3[1].__vftable;
  v7 = (unsigned int *)v4[1].__vftable;
  v8 = *(unsigned int **)(antialiasing_method + 64);
  v9 = *(unsigned int **)(shadow_quality + 64);
  *v5 = -1;
  *v6 = -1;
  *v8 = -1;
  *v9 = -1;
  shadow_quality_command_value = v6;
  post_process_quality_command_value = v7;
  *v7 = -1;
  antialiasing_method_command_value = v5;
  lighting_quality_command_value = v8;
  shading_quality_command_value = v9;
  antialiasing_method_values[0] = 0;
  antialiasing_method_values[1] = 1;
  antialiasing_method_values[2] = 2;
  shadow_quality_values[0] = 0;
  shadow_quality_values[1] = 3;
  lighting_quality_values[0] = 0;
  lighting_quality_values[1] = 3;
  shading_quality_values[0] = 0;
  shading_quality_values[1] = 3;
  post_process_quality_values[0] = 0;
  post_process_quality_values[1] = 3;
  for ( antialiasing_method = 0; antialiasing_method < 3; ++antialiasing_method )
  {
    v10 = antialiasing_method_values[antialiasing_method];
    shadow_quality = 0;
    v49 = v10;
    do
    {
      v11 = shadow_quality_values[shadow_quality];
      lighting_quality = 0;
      v46 = v11;
      do
      {
        v12 = lighting_quality_values[lighting_quality];
        shading_quality = 0;
        v48 = v12;
        do
        {
          v13 = (vostok::render::scene_renderer *)shading_quality_values[shading_quality];
          post_process_quality = 0;
          v50 = v13;
          do
          {
            m_renderer = thisa->m_renderer;
            waiting_for = 1;
            vostok::render::scene_renderer::begin_render_options_changing(v13, m_renderer->m_scene, &waiting_for);
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
                    v39[0] = 0;
                    vostok::threading::g_debug_single_thread.m_type = type_recursive;
                    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
                    m_type = vostok::threading::g_debug_single_thread.m_type;
                  }
                  if ( m_type != type_recursive )
                  {
                    vostok::resources::resources_manager::resources_thread_tick(m_initialized);
                    vostok::resources::resources_manager::cooker_thread_tick(
                      v17,
                      vostok::resources::g_resources_manager.m_variable);
                  }
                }
                vostok::resources::resources_manager::dispatch_callbacks(
                  vostok::resources::g_resources_manager.m_variable,
                  0);
              }
              if ( !SwitchToThread() )
                Sleep(0);
            }
            v18 = v46;
            *antialiasing_method_command_value = v49;
            v19 = v48;
            *shadow_quality_command_value = v18;
            v20 = (unsigned int)v50;
            *lighting_quality_command_value = v19;
            v21 = post_process_quality;
            *shading_quality_command_value = v20;
            *post_process_quality_command_value = post_process_quality_values[v21];
            waiting_for = 1;
            m_scene = thisa->m_renderer->m_scene;
            output_window.m_object = 0;
            vostok::render::scene_renderer::end_render_options_changing(
              (vostok::render::scene_renderer *)&output_window,
              m_scene,
              (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&output_window,
              0,
              0,
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
                v23 = vostok::threading::g_debug_single_thread.m_type;
                if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
                {
                  v42[0] = 0;
                  vostok::threading::g_debug_single_thread.m_type = type_recursive;
                  vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
                  v23 = vostok::threading::g_debug_single_thread.m_type;
                }
                if ( v23 != type_recursive )
                {
                  if ( v23 == type_unset )
                  {
                    v44[0] = 0;
                    vostok::threading::g_debug_single_thread.m_type = type_recursive;
                    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
                    v23 = vostok::threading::g_debug_single_thread.m_type;
                  }
                  if ( v23 != type_recursive )
                  {
                    vostok::resources::resources_manager::resources_thread_tick(m_variable);
                    vostok::resources::resources_manager::cooker_thread_tick(
                      v24,
                      vostok::resources::g_resources_manager.m_variable);
                  }
                }
                vostok::resources::resources_manager::dispatch_callbacks(
                  vostok::resources::g_resources_manager.m_variable,
                  0);
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
              v26 = vostok::core::g_log_callback;
              log_callback.vtable = 0;
              v34 = 0;
              if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                  &log_callback.functor,
                  &log_callback.functor,
                  destroy_functor_tag);
              if ( v26 )
              {
                log_callback.functor.obj_ptr = v26;
                log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                             + 1);
              }
              else
              {
                log_callback.vtable = 0;
              }
              v30 |= 1u;
              vostok::logging::append(
                &log_callback,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\game_generate_shaders.cpp",
                0x54u,
                "void __thiscall survarium::generate_shaders_world::generate_renderer_shaders(void)",
                "game:",
                error,
                "pending_queries_count:%d",
                m_pending_queries_count);
            }
            if ( (v30 & 1) != 0 )
            {
              v30 &= ~1u;
              if ( log_callback.vtable )
              {
                if ( ((int)log_callback.vtable & 1) == 0 )
                {
                  v27 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
                  if ( v27 )
                    v27(&log_callback.functor, &log_callback.functor, 2);
                }
                log_callback.vtable = 0;
              }
            }
            ++post_process_quality;
          }
          while ( post_process_quality < 2 );
          ++shading_quality;
        }
        while ( shading_quality < 2 );
        ++lighting_quality;
      }
      while ( lighting_quality < 2 );
      ++shadow_quality;
    }
    while ( shadow_quality < 2 );
  }
}
