void __thiscall survarium::human_npc::play_animation(
        survarium::human_npc *this,
        const vostok::ai::animation_item *const target)
{
  char v3; // bl
  vostok::animation::animation_expression_emitter *m_object; // eax
  vostok::animation::animation_expression_emitter *v5; // edi
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  vostok::ai::game_object_vtbl *v7; // edx
  const char *v8; // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char *v10[69]; // [esp-114h] [ebp-144h] BYREF
  vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> animation_emitter; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v3 = 0;
  this->m_current_animation = target;
  m_object = (vostok::animation::animation_expression_emitter *)target->animation.m_object;
  v5 = 0;
  animation_emitter.m_object = 0;
  if ( m_object )
  {
    animation_emitter.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    v5 = m_object;
  }
  survarium::animations_selector::set_target(this->m_animations_selector, this->m_current_animation);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
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
    v7 = this->vostok::ai::game_object::__vftable;
    qmemcpy(v10, &this->m_current_animation->name, sizeof(v10));
    v3 = 1;
    v8 = v7->get_name(&this->vostok::ai::game_object);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\human_npc.cpp",
      0x243u,
      "void __thiscall survarium::human_npc::play_animation(const struct vostok::ai::animation_item *const )",
      "game:",
      info,
      "%s: playing animation %s",
      v8,
      v10[0]);
    v5 = animation_emitter.m_object;
  }
  if ( (v3 & 1) != 0 )
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
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  }
}
