void __userpurge survarium::game_world::set_game_project(
        const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *project@<eax>,
        survarium::game_world *this)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  survarium::vector<vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > *p_m_game_effects; // edi
  char *v4; // eax
  char *v5; // eax
  unsigned int v6; // esi
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  vostok::math::float3 *pointer; // esi
  vostok::configs::binary_config_value *m_root; // eax
  vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  _DWORD *v13; // esi
  survarium::game_world *v14; // ecx
  vostok::sound::world_user *v15; // eax
  survarium::flash_value *v16; // eax
  survarium::game_world_ui *v17; // ecx
  survarium::simple_game_project *m_object; // edi
  vostok::variant<32> *v19; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  survarium::game_world_ui *v21; // ecx
  vostok::variant<32> *v22; // ecx
  survarium::camera_director *m_camera_director; // [esp-8h] [ebp-78h]
  const char *v24; // [esp+0h] [ebp-70h]
  const char *v25; // [esp+4h] [ebp-6Ch]
  unsigned int v26; // [esp+8h] [ebp-68h]
  vostok::math::float3 p; // [esp+10h] [ebp-60h] BYREF
  int v28; // [esp+1Ch] [ebp-54h]
  _BYTE d[32]; // [esp+20h] [ebp-50h] BYREF
  vostok::variant<32> v30; // [esp+40h] [ebp-30h] BYREF

  vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base>::operator=(
    project,
    &this->m_game_project);
  v2 = survarium::g_allocator;
  p_m_game_effects = &this->m_game_project.m_object->m_game_effects;
  this->m_game_effects_count = this->m_game_project.m_object->m_game_effects._M_impl._M_finish
                             - p_m_game_effects->_M_impl._M_start;
  v4 = type_info::raw_name(&vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)(4 * this->m_game_effects_count),
         (int)v2,
         4 * this->m_game_effects_count,
         v4,
         v24,
         v25,
         v26);
  v6 = 0;
  for ( this->m_game_effects = (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)v5;
        v6 < this->m_game_effects_count;
        ++v6 )
  {
    v7 = &this->m_game_effects[v6];
    if ( v7 )
      p_m_game_effects->_M_impl._M_start[v6].m_object->emit(p_m_game_effects->_M_impl._M_start[v6].m_object, v7);
  }
  this->show_ui(this, 1);
  v8 = vostok::configs::binary_config_value::operator[](
         this->m_game_project.m_object->m_config.m_object->m_root,
         "camera");
  pointer = (vostok::math::float3 *)vostok::configs::binary_config_value::operator[](v8, "position")->data.pointer;
  m_root = this->m_game_project.m_object->m_config.m_object->m_root;
  p = *pointer;
  v11 = vostok::configs::binary_config_value::operator[](m_root, "camera");
  v12 = vostok::configs::binary_config_value::operator[](v11, "direction");
  v13 = v12->data.pointer;
  *(_DWORD *)d = *(_DWORD *)v12->data.pointer;
  *(_DWORD *)&d[4] = *++v13;
  m_camera_director = this->m_camera_director;
  *(_DWORD *)&d[8] = v13[1];
  survarium::camera_director::set_position_direction((const vostok::math::float3 *)d, m_camera_director, &p);
  survarium::game_camera::set_position_direction((const vostok::math::float3 *)d, this->m_free_fly_camera, &p);
  survarium::game_world::switch_to_free_fly_camera(v14, this);
  if ( this->m_is_active )
  {
    v15 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
    vostok::sound::world_user::set_active_sound_scene(&this->m_sound_scene, v15);
  }
  v16 = (survarium::flash_value *)this->m_game->m_network_client->match_options(this->m_game->m_network_client);
  survarium::game_world_ui::initialize_match(v17, (const survarium::match_options *)&this->game_ui, v16);
  v30.m_helper = 0;
  v30.m_type_id = 0;
  m_object = this->m_game_project.m_object;
  vostok::variant<32>::destroy_previous_variable_if_needed(v19, (int)&v30);
  v30.m_type_id = vostok::detail::type_to_int<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::get();
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v30.m_storage,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_config);
  v30.m_helper = (vostok::detail::abstract_type_helper *)&v30;
  *(_DWORD *)d = survarium::game_world::on_portal_system_loaded;
  *(_DWORD *)&d[4] = 0;
  *(_DWORD *)&d[8] = this;
  LODWORD(p.x) = survarium::game_world::on_portal_system_loaded;
  *(_QWORD *)&p.elements[1] = __PAIR64__((unsigned int)this, 0);
  *(_DWORD *)v30.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::`vftable';
  v28 = *(_DWORD *)&d[12];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    *(_DWORD *)d = 0;
  }
  else
  {
    *(vostok::math::float3 *)&d[8] = p;
    *(_DWORD *)&d[20] = v28;
    *(_DWORD *)d = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_world *>,boost::arg<1>>>>'::`2'::stored_vtable
                 + 1;
  }
  vostok::resources::query_resource(
    "unused string",
    (vostok::variant<32> *)0x71,
    survarium::g_allocator,
    &v30,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v20, (int *)d);
  survarium::game_world_ui::initialize_minimap(
    v21,
    (vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)&this->game_ui);
  survarium::game::switch_to_scene(this->m_game, &this->m_game->m_game_world);
  this->m_is_loading = 0;
  vostok::variant<32>::destroy_previous_variable_if_needed(v22, (int)&v30);
}
