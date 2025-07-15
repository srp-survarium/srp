void __thiscall survarium::victory_item::put(
        survarium::victory_item *this,
        vostok::physics::world *world,
        const vostok::math::float4x4 *transform,
        survarium::scheduler *scheduler)
{
  __int64 v5; // xmm0_8
  survarium::scheduler *v6; // ecx
  survarium::scheduler::record *v7; // eax
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::static_model_instance *m_object; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::victory_item,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::victory_item *>,boost::arg<1>,boost::arg<2> > > v10; // [esp-10h] [ebp-40h]
  int v11; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(unsigned int,unsigned int)> active; // [esp+10h] [ebp-20h] BYREF

  survarium::victory_item_core::put(this, world, transform);
  active.vtable = (boost::detail::function::vtable_base *)survarium::victory_item::tick;
  (&active.vtable)[1] = 0;
  v10.f_.f_ = (void (__thiscall *__ptr64)(survarium::victory_item *, unsigned int, unsigned int))(unsigned int)survarium::victory_item::tick;
  active.functor.obj_ptr = this;
  v5 = *(_QWORD *)&active.functor.obj_ptr;
  this->m_scheduler = scheduler;
  *(_QWORD *)&v10.l_.a1_.t_ = v5;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    0,
    (int)&active,
    (int)this,
    v10,
    v11);
  v7 = survarium::scheduler::register_object(v6, scheduler, &this->m_scheduler_identifier, &active, 1);
  *(_DWORD *)&v7->survarium::scheduler::scheduler_record = 0x7FFFFFFF;
  v7->m_max_update_count = 0;
  v7->m_last_update_time = 0;
  if ( active.vtable )
  {
    if ( ((int)active.vtable & 1) == 0 )
    {
      v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)active.vtable & 0xFFFFFFFE);
      if ( v8 )
        v8(&active.functor, &active.functor, 2);
    }
  }
  m_object = this->m_model.m_object;
  if ( m_object )
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      &this->m_game_world->m_render_scene,
      &m_object->m_render_model,
      &this->m_transform);
}
