char __thiscall survarium::booby_trap_set::pick_current_ghost_model(
        survarium::booby_trap_set *this,
        const vostok::math::float4x4 *transform,
        bool is_placing_allowed)
{
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_model_ghost_allowed; // eax
  vostok::render::static_model_instance *m_object; // eax
  vostok::render::static_model_instance *v6; // ebx
  vostok::render::static_model_instance *v7; // eax
  survarium::scheduler::record *v8; // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::static_model_instance *v10; // eax
  vostok::render::static_model_instance *v11; // ecx
  vostok::render::static_model_instance *v12; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_set,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_set *>,boost::arg<1>,boost::arg<2> > > v14; // [esp-10h] [ebp-40h]
  int v15; // [esp+0h] [ebp-30h]
  survarium::scheduler *scheduler; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(unsigned int,unsigned int)> active; // [esp+10h] [ebp-20h] BYREF

  p_m_model_ghost_allowed = &this->m_model_ghost_allowed;
  if ( !is_placing_allowed )
    p_m_model_ghost_allowed = &this->m_model_ghost_denied;
  m_object = p_m_model_ghost_allowed->m_object;
  v6 = 0;
  if ( m_object )
  {
    v6 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v7 = this->m_current_rendering_model.m_object;
  if ( v6 == v7 )
  {
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    return 0;
  }
  else
  {
    if ( v7
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model(
        (vostok::render::scene_renderer *)this->m_game_world->m_game,
        this->m_game_world->m_game->m_renderer->m_scene,
        &this->m_game_world->m_render_scene,
        &v7->m_render_model);
    }
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      (int)this->m_game_world->m_game->m_renderer->m_scene,
      &this->m_game_world->m_render_scene,
      &v6->m_render_model,
      transform);
    if ( !this->m_current_rendering_model.m_object )
    {
      scheduler = this->m_inventory->m_holder->m_scheduler;
      active.vtable = (boost::detail::function::vtable_base *)survarium::booby_trap_set::tick;
      (&active.vtable)[1] = 0;
      v14.f_.f_ = (void (__thiscall *__ptr64)(survarium::booby_trap_set *, unsigned int, unsigned int))(unsigned int)survarium::booby_trap_set::tick;
      active.functor.obj_ptr = this;
      *(_QWORD *)&v14.l_.a1_.t_ = *(_QWORD *)&active.functor.obj_ptr;
      boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
        0,
        (int)&active,
        (int)this,
        v14,
        v15);
      v8 = survarium::scheduler::register_object(
             (survarium::scheduler *)&active,
             scheduler,
             &this->m_scheduler_identifier,
             &active,
             1);
      *(_DWORD *)&v8->survarium::scheduler::scheduler_record = 0x7FFFFFFF;
      v8->m_max_update_count = 0;
      v8->m_last_update_time = 0;
      if ( active.vtable )
      {
        if ( ((int)active.vtable & 1) == 0 )
        {
          v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)active.vtable & 0xFFFFFFFE);
          if ( v9 )
            v9(&active.functor, &active.functor, 2);
        }
      }
    }
    v10 = 0;
    if ( v6 )
    {
      v10 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v11 = v10;
    v12 = this->m_current_rendering_model.m_object;
    this->m_current_rendering_model.m_object = v11;
    if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
    if ( v6 )
    {
      if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    }
    return 1;
  }
}
