void __thiscall survarium::game_world::on_project_loaded(
        survarium::game_world *this,
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *data,
        unsigned int results_offset,
        boost::function<void __cdecl(vostok::resources::queries_result &)> *callback)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v6; // esi
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  vostok::particle::particle_system_instance_impl *v8; // esi
  survarium::game_world::bullet_tracer *M_finish; // ecx
  vostok::render::game::renderer *v10; // ecx
  survarium::flash_text_manager *m_text_manager; // esi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v12; // ecx
  survarium::lobby_menu *v13; // ecx
  const stlp_std::__false_type *v14; // [esp+0h] [ebp-30h]
  unsigned int v15; // [esp+4h] [ebp-2Ch]
  bool v16; // [esp+8h] [ebp-28h]
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v17; // [esp+Ch] [ebp-24h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+10h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+14h] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v20; // [esp+18h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+1Ch] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v22; // [esp+20h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v23; // [esp+24h] [ebp-Ch] BYREF
  survarium::game_world::bullet_tracer __x; // [esp+28h] [ebp-8h] BYREF

  if ( !this->m_render_scene.m_object )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[6].m_on_out_of_memory.functor.bound_memfunc_ptr.memfunc_ptr
    + 184 * results_offset
    + 1);
    m_object = (vostok::particle::particle_system_instance_impl *)v19.m_object;
    v18.m_object = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
      v18.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v18,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[15].m_on_out_of_memory.functor
    + 184 * results_offset
    + 77);
    v6 = (vostok::particle::particle_system_instance_impl *)v19.m_object;
    v18.m_object = 0;
    if ( v19.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
      v18.m_object = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v18,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v19,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[36].m_arena
    + 184 * results_offset);
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      &v19,
      &this->m_sound_scene);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v23,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[52].m_on_out_of_memory.functor.bound_memfunc_ptr.memfunc_ptr
    + 184 * results_offset
    + 1);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v22,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[61].m_on_out_of_memory.functor
    + 184 * results_offset
    + 77);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v21,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[82].m_arena
    + 184 * results_offset);
    survarium::game_world_ui::initialize_resources(
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v23,
      &this->game_ui,
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v22,
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v21);
    v19.m_object = 0;
    if ( s_max_tracers_count )
    {
      v17 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(&data[93].m_free_list_head + 184 * results_offset);
      do
      {
        v7 = v17;
        v17 += 184;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v20,
          v7 + 55);
        v8 = (vostok::particle::particle_system_instance_impl *)v20.m_object;
        v18.m_object = 0;
        if ( v20.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
          v18.m_object = v8;
          _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
        }
        __x.bullet = 0;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__x.tracer,
          &v18);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
        M_finish = this->m_bullet_tracers._M_impl._M_finish;
        if ( M_finish == this->m_bullet_tracers._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<survarium::game_world::bullet_tracer,survarium::std_allocator<survarium::game_world::bullet_tracer>>::_M_insert_overflow_aux(
            &__x,
            &this->m_bullet_tracers._M_impl,
            this->m_bullet_tracers._M_impl._M_finish,
            v14,
            v15,
            v16);
        }
        else
        {
          if ( M_finish )
          {
            M_finish->bullet = __x.bullet;
            vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
              (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&M_finish->tracer,
              (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__x.tracer);
          }
          ++this->m_bullet_tracers._M_impl._M_finish;
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__x.tracer);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
        ++v19.m_object;
      }
      while ( (unsigned int)v19.m_object < s_max_tracers_count );
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v23);
  }
  survarium::flash_text_manager::set_viewport(
    this->m_text_manager,
    this->m_game->m_render_output_window.m_object->m_current_size.x,
    this->m_game->m_render_output_window.m_object->m_current_size.y);
  vostok::render::game::renderer::show_text_manager(
    v10,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,survarium::flash_text_manager *>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::flash_text_manager *> > > *)this->m_game->m_renderer,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view,
    this->m_text_manager);
  m_text_manager = this->m_text_manager;
  if ( m_text_manager->need_capture )
  {
    Scaleform::GFx::DrawTextManager::Capture(m_text_manager->text_manager_impl, 1);
    m_text_manager->need_capture = 0;
  }
  if ( !this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client)
    || this->m_game->m_network_client->lobby_client(this->m_game->m_network_client)->m_status )
  {
    if ( callback->vtable )
      boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(v12, callback, data);
  }
  else
  {
    survarium::game_world::unload(
      (survarium::game_world *)v12,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
    survarium::lobby_menu::show_match_making(v13, (int)this->m_game->m_lobby_menu, 0);
    this->m_is_loading = 0;
  }
}
