void __thiscall survarium::free_fly_camera::tick(survarium::free_fly_camera *this)
{
  char v2; // bl
  unsigned int m_permanent_time_in_ms; // eax
  float m_prev_delta_sec; // xmm0_4
  float v5; // xmm0_4
  int *M_finish; // esi
  int *M_start; // eax
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int *v10; // ebx
  int *v11; // eax
  int *v12; // eax
  int *v13; // eax
  int *v14; // eax
  int *v15; // eax
  int *v16; // eax
  int *v17; // esi
  int *v18; // eax
  int *v19; // eax
  int *v20; // eax
  int *v21; // eax
  int *v22; // eax
  int *v23; // eax
  survarium::free_fly_camera *v24; // ecx
  int *v25; // eax
  int *v26; // eax
  unsigned int shift_right; // [esp+0h] [ebp-8Ch]
  float factor; // [esp+50h] [ebp-3Ch]
  float up; // [esp+54h] [ebp-38h]
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> right; // [esp+58h] [ebp-34h] BYREF
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> forward; // [esp+5Ch] [ebp-30h] BYREF
  float angle_factor; // [esp+60h] [ebp-2Ch]
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> __val; // [esp+64h] [ebp-28h] BYREF
  float v34; // [esp+68h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+6Ch] [ebp-20h] BYREF

  v2 = 0;
  *(float *)&__val.m_object = 0.0;
  m_permanent_time_in_ms = this->m_game_scene->m_game->m_permanent_time_in_ms;
  __val.m_object = (survarium::flash_movie_resource *)(m_permanent_time_in_ms - this->m_prev_time_ms);
  m_prev_delta_sec = this->m_prev_delta_sec;
  *(float *)&forward.m_object = (float)(unsigned int)__val.m_object;
  if ( m_prev_delta_sec >= 0.0 )
    v5 = (float)(m_prev_delta_sec * 0.89999998) + (float)(*(float *)&forward.m_object * 0.1);
  else
    v5 = *(float *)&forward.m_object;
  M_finish = this->m_keyb_events._M_impl._M_finish;
  this->m_prev_delta_sec = v5;
  factor = v5 * 0.060000002;
  this->m_prev_time_ms = m_permanent_time_in_ms;
  M_start = this->m_keyb_events._M_impl._M_start;
  angle_factor = FLOAT_0_5;
  right.m_object = (survarium::flash_movie_resource *)16;
  if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)M_start,
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)M_finish,
         &right) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)M_finish )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v8 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v8 )
      {
        log_callback.functor.obj_ptr = v8;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      shift_right = counter;
      v2 = 1;
      ++counter;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\free_fly_camera.cpp",
        0xB4u,
        "void __thiscall survarium::free_fly_camera::tick(void)",
        "game:",
        info,
        "timedelta: [%d] %f",
        shift_right,
        *(float *)&forward.m_object);
    }
    if ( (v2 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v9 )
            v9(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  if ( this->m_keyb_events._M_impl._M_start != this->m_keyb_events._M_impl._M_finish
    || this->m_mouse_events._M_impl._M_start != this->m_mouse_events._M_impl._M_finish
    || (forward.m_object = (survarium::flash_movie_resource *)LODWORD(this->m_mouse_move.x),
        forward.m_object = (survarium::flash_movie_resource *)((unsigned int)forward.m_object & 0x7FFFFFFF),
        *(float *)&forward.m_object >= 0.0000099999997)
    || (forward.m_object = (survarium::flash_movie_resource *)LODWORD(this->m_mouse_move.elements[1]),
        forward.m_object = (survarium::flash_movie_resource *)((unsigned int)forward.m_object & 0x7FFFFFFF),
        *(float *)&forward.m_object >= 0.0000099999997)
    || (forward.m_object = (survarium::flash_movie_resource *)LODWORD(this->m_mouse_move.elements[2]),
        forward.m_object = (survarium::flash_movie_resource *)((unsigned int)forward.m_object & 0x7FFFFFFF),
        *(float *)&forward.m_object >= 0.0000099999997) )
  {
    v10 = this->m_keyb_events._M_impl._M_finish;
    v11 = this->m_keyb_events._M_impl._M_start;
    forward.m_object = (survarium::flash_movie_resource *)29;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v11,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10
      || (v12 = this->m_keyb_events._M_impl._M_start,
          forward.m_object = (survarium::flash_movie_resource *)157,
          stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v12,
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
            &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10) )
    {
      factor = factor * 20.0;
    }
    v13 = this->m_keyb_events._M_impl._M_start;
    forward.m_object = (survarium::flash_movie_resource *)42;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v13,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10
      || (v14 = this->m_keyb_events._M_impl._M_start,
          forward.m_object = (survarium::flash_movie_resource *)54,
          stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v14,
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
            &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10) )
    {
      factor = factor * 0.1;
    }
    v15 = this->m_keyb_events._M_impl._M_start;
    forward.m_object = (survarium::flash_movie_resource *)56;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v15,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10
      || (v16 = this->m_keyb_events._M_impl._M_start,
          forward.m_object = (survarium::flash_movie_resource *)184,
          stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v16,
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
            &forward) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10) )
    {
      angle_factor = satisfaction_equality_tolerance;
    }
    v17 = this->m_mouse_events._M_impl._M_finish;
    v18 = this->m_mouse_events._M_impl._M_start;
    *(float *)&forward.m_object = 0.0;
    *(float *)&right.m_object = 0.0;
    up = 0.0;
    __val.m_object = (survarium::flash_movie_resource *)337;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v18,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v17,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v17 )
      *(float *)&forward.m_object = factor * 0.1;
    v19 = this->m_mouse_events._M_impl._M_start;
    __val.m_object = (survarium::flash_movie_resource *)338;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v19,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v17,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v17 )
      *(float *)&forward.m_object = *(float *)&forward.m_object - (float)(factor * 0.1);
    v20 = this->m_keyb_events._M_impl._M_start;
    __val.m_object = (survarium::flash_movie_resource *)32;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v20,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10 )
      *(float *)&right.m_object = factor * 0.1;
    v21 = this->m_keyb_events._M_impl._M_start;
    __val.m_object = (survarium::flash_movie_resource *)30;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v21,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10 )
      *(float *)&right.m_object = *(float *)&right.m_object - (float)(factor * 0.1);
    v22 = this->m_keyb_events._M_impl._M_start;
    __val.m_object = (survarium::flash_movie_resource *)17;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v22,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10 )
      up = factor * 0.1;
    v23 = this->m_keyb_events._M_impl._M_start;
    __val.m_object = (survarium::flash_movie_resource *)31;
    if ( stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v23,
           (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10,
           &__val) != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v10 )
      up = up - (float)(factor * 0.1);
    *(float *)&__val.m_object = angle_factor * this->m_mouse_move.y;
    v34 = (float)(this->m_mouse_move.x * angle_factor) * 0.75;
    survarium::free_fly_camera::build_view_matrix(
      v24,
      this,
      (float *)&__val,
      *(float *)&forward.m_object,
      *(float *)&right.m_object,
      up);
    v25 = this->m_keyb_events._M_impl._M_start;
    if ( v25 != this->m_keyb_events._M_impl._M_finish )
      this->m_keyb_events._M_impl._M_finish = v25;
    v26 = this->m_mouse_events._M_impl._M_start;
    if ( v26 != this->m_mouse_events._M_impl._M_finish )
      this->m_mouse_events._M_impl._M_finish = v26;
    this->m_mouse_move.x = 0.0;
    this->m_mouse_move.y = 0.0;
    this->m_mouse_move.z = 0.0;
  }
}
