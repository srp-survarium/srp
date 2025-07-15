// bad sp value at call has been detected, the output may be wrong!
void __thiscall survarium::object_skeleton_visual::insert(survarium::object_skeleton_visual *this)
{
  vostok::timing::timer *v2; // ecx
  survarium::base_game_object *v3; // eax
  vostok::animation::skeleton *v4; // ecx
  survarium::object_skeleton_visual *v5; // eax
  vostok::animation::skeleton *m_object; // eax
  vostok::animation::hand_to_weapon_ik_solver *v7; // ecx
  vostok::animation::hand_to_weapon_ik_solver *v8; // ecx
  vostok::animation::fingers_to_weapon_corrector *v9; // ecx
  vostok::animation::fingers_to_weapon_corrector *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  vostok::animation::animation_player *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::animation::animation_player *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  vostok::animation::animation_player *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  survarium::base_game_object *v18; // eax
  survarium::object_skeleton_visual *v19; // eax
  vostok::timing::timer *v20; // ecx
  LARGE_INTEGER QPC; // rax
  vostok::resources::managed_resource *v22; // xmm0_4
  vostok::timing::timer *m_reconstruction_info_actuality_tick; // ecx
  void *v24; // esp
  vostok::animation::skeleton_animation_scene_target *m_current_target; // ecx
  vostok::timing::timer *v26; // ecx
  vostok::animation::subscribed_channel **elapsed_msec; // eax
  vostok::animation::animation_player *v28; // ecx
  survarium::scheduler::record *v29; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v30; // ecx
  int v32; // [esp-8000h] [ebp-8040h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::object_skeleton_visual,vostok::animation::animation_callback_params &,enum vostok::animation::hand_to_weapon_ik_solver::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::hand_to_weapon_ik_solver::hands_enum> > > v33; // [esp-14h] [ebp-54h]
  char *p_m_transform; // [esp-4h] [ebp-44h]
  const void *v35; // [esp+0h] [ebp-40h]
  survarium::scheduler f; // [esp+Ch] [ebp-34h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+3Ch] [ebp-4h] BYREF

  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    &this->m_transform,
    &this->m_transform);
  if ( this->m_animation_scene.m_object )
  {
    if ( this->m_bind_weapon )
    {
      v3 = this->m_project->get_object_by_name(this->m_project, this->m_bind_weapon);
      if ( v3 )
        v5 = (survarium::object_skeleton_visual *)&v3[-336];
      else
        v5 = 0;
      this->m_bind_weapon_resolved = v5;
      m_object = this->m_model.m_object->m_skeleton.m_object;
      p_m_transform = "Weapon";
      this->m_hand_solver.m_user_skeleton = m_object;
      this->m_hand_solver.m_weapon_bone_index = vostok::animation::skeleton::get_bone_index(
                                                  v4,
                                                  (int)m_object,
                                                  p_m_transform);
      vostok::animation::hand_to_weapon_ik_solver::activate(
        v7,
        &this->m_hand_solver,
        this->m_bind_weapon_resolved->m_model.m_object->m_skeleton.m_object);
      vostok::animation::hand_to_weapon_ik_solver::initialize_locators(
        v8,
        (vostok::render::model_locator_item *)&this->m_hand_solver,
        this->m_bind_weapon_resolved->m_model.m_object->m_render_model.m_object);
      vostok::animation::fingers_to_weapon_corrector::initialize_locators(
        v9,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_fingers_corrector,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_bind_weapon_resolved->m_model.m_object->m_render_model,
        1);
      vostok::animation::fingers_to_weapon_corrector::initialize_bones_indices(
        v10,
        (int)&this->m_fingers_corrector,
        this->m_model.m_object->m_skeleton.m_object);
      f.m_active_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
      f.m_active_objects._M_impl._M_end_of_storage._M_data = 0;
      f.m_active_objects._M_impl._M_start = (survarium::scheduler::record *)survarium::object_skeleton_visual::on_hand_ik_event;
      f.m_active_objects._M_impl._M_finish = 0;
      HIDWORD(v33.f_.f_) = survarium::object_skeleton_visual::on_hand_ik_event;
      v33.l_.a1_.t_ = 0;
      v33.l_.a3_.t_ = (vostok::animation::hand_to_weapon_ik_solver::hands_enum)this;
      LODWORD(v33.f_.f_) = &f;
      animation.m_object = 0;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        v33,
        0);
      vostok::animation::animation_player::subscribe(
        (vostok::animation::animation_player *)&f,
        (int)&this->m_animation_player,
        "left_hand_ik",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        this,
        &animation,
        0,
        v35);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v11,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
      animation.m_object = 0;
      f.m_active_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
      f.m_active_objects._M_impl._M_start = (survarium::scheduler::record *)survarium::object_skeleton_visual::on_hand_ik_event;
      f.m_active_objects._M_impl._M_finish = 0;
      f.m_active_objects._M_impl._M_end_of_storage._M_data = (survarium::scheduler::record *)1;
      HIDWORD(v33.f_.f_) = survarium::object_skeleton_visual::on_hand_ik_event;
      v33.l_.a1_.t_ = 0;
      v33.l_.a3_.t_ = (vostok::animation::hand_to_weapon_ik_solver::hands_enum)this;
      LODWORD(v33.f_.f_) = &f;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        v33,
        1);
      vostok::animation::animation_player::subscribe(
        v12,
        (int)&this->m_animation_player,
        "right_hand_ik",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        this,
        &animation,
        0,
        v35);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v13,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
      animation.m_object = 0;
      f.m_active_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
      f.m_active_objects._M_impl._M_start = (survarium::scheduler::record *)survarium::object_skeleton_visual::on_fingers_event;
      f.m_active_objects._M_impl._M_finish = 0;
      f.m_active_objects._M_impl._M_end_of_storage._M_data = 0;
      HIDWORD(v33.f_.f_) = survarium::object_skeleton_visual::on_fingers_event;
      v33.l_.a1_.t_ = 0;
      v33.l_.a3_.t_ = (vostok::animation::hand_to_weapon_ik_solver::hands_enum)this;
      LODWORD(v33.f_.f_) = &f;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::object_skeleton_visual,vostok::animation::animation_callback_params &,enum vostok::animation::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> > >)v33,
        0);
      vostok::animation::animation_player::subscribe(
        v14,
        (int)&this->m_animation_player,
        "left_hand_corrector",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        this,
        &animation,
        0,
        v35);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v15,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
      animation.m_object = 0;
      f.m_active_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
      f.m_active_objects._M_impl._M_start = (survarium::scheduler::record *)survarium::object_skeleton_visual::on_fingers_event;
      f.m_active_objects._M_impl._M_finish = 0;
      f.m_active_objects._M_impl._M_end_of_storage._M_data = (survarium::scheduler::record *)1;
      HIDWORD(v33.f_.f_) = survarium::object_skeleton_visual::on_fingers_event;
      v33.l_.a1_.t_ = 0;
      v33.l_.a3_.t_ = (vostok::animation::hand_to_weapon_ik_solver::hands_enum)this;
      LODWORD(v33.f_.f_) = &f;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf2<enum vostok::animation::callback_return_type_enum,survarium::object_skeleton_visual,vostok::animation::animation_callback_params &,enum vostok::animation::fingers_to_weapon_corrector::hands_enum>,boost::_bi::list3<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>,boost::_bi::value<enum vostok::animation::fingers_to_weapon_corrector::hands_enum> > >)v33,
        1);
      vostok::animation::animation_player::subscribe(
        v16,
        (int)&this->m_animation_player,
        "right_hand_corrector",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        this,
        &animation,
        0,
        v35);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v17,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
    }
    if ( this->m_bind_as_weapon_to )
    {
      v18 = this->m_project->get_object_by_name(this->m_project, this->m_bind_as_weapon_to);
      if ( v18 )
        v19 = (survarium::object_skeleton_visual *)&v18[-336];
      else
        v19 = 0;
      this->m_bind_as_weapon_to_resolved = v19;
    }
    vostok::timing::timer::start(v2, (LARGE_INTEGER *)&this->m_animation_timer);
    animation.m_object = (vostok::resources::managed_resource *)LODWORD(this->m_animation_timescale);
    this->m_animation_timer.m_current_time = vostok::timing::timer::get_elapsed_ticks(
                                               v20,
                                               (int)&this->m_animation_timer);
    QPC = vostok::timing::get_QPC();
    v22 = animation.m_object;
    this->m_animation_timer.m_start_time = QPC.QuadPart;
    LODWORD(this->m_animation_timer.m_time_factor) = v22;
    m_reconstruction_info_actuality_tick = (vostok::timing::timer *)this->m_animation_scene.m_object[1].m_reconstruction_info_actuality_tick;
    QPC.LowPart = *((_DWORD *)&m_reconstruction_info_actuality_tick->m_current_time + this->m_animation_target_id);
    this->m_current_target = (vostok::animation::skeleton_animation_scene_target *)QPC.LowPart;
    this->m_start_target = (vostok::animation::skeleton_animation_scene_target *)QPC.LowPart;
    this->m_current_target_start_time = vostok::timing::timer::get_elapsed_msec(
                                          m_reconstruction_info_actuality_tick,
                                          (int)&this->m_animation_timer);
    v24 = alloca(0x8000);
    m_current_target = this->m_current_target;
    f.m_objects[0] = (vostok::vectora<survarium::scheduler::record> *)&v32;
    f.m_objects[1] = (vostok::vectora<survarium::scheduler::record> *)0x8000;
    m_current_target->make_animation_expression(
      m_current_target,
      (vostok::animation::mixing::expression *)&f.m_current_index,
      (vostok::mutable_buffer *)f.m_objects);
    p_m_transform = (char *)&this->m_transform;
    elapsed_msec = (vostok::animation::subscribed_channel **)vostok::timing::timer::get_elapsed_msec(
                                                               v26,
                                                               (int)&this->m_animation_timer);
    vostok::animation::animation_player::set_target_and_tick(
      v28,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_animation_player,
      (vostok::animation::mixing::expression *)&f.m_current_index,
      elapsed_msec,
      (int)p_m_transform);
    f.m_active_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)this;
    f.m_active_objects._M_impl._M_start = (survarium::scheduler::record *)survarium::object_skeleton_visual::tick;
    f.m_active_objects._M_impl._M_finish = 0;
    HIDWORD(v33.f_.f_) = survarium::object_skeleton_visual::tick;
    v33.l_.a1_.t_ = 0;
    v33.l_.a3_.t_ = (vostok::animation::hand_to_weapon_ik_solver::hands_enum)this;
    LODWORD(v33.f_.f_) = &f;
    boost::function<void __cdecl (unsigned int,unsigned int)>::function<void __cdecl (unsigned int,unsigned int)>(
      0,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_skeleton_visual,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>,boost::arg<2> > >)v33,
      (int)f.m_active_objects._M_impl._M_end_of_storage._M_data);
    v29 = survarium::scheduler::register_object(
            &f,
            (int)&this->m_game_scene->m_scheduler,
            &this->m_scheduler_identifier,
            (boost::function<void __cdecl(unsigned int,unsigned int)> *)&f,
            (const bool)v35);
    *(_DWORD *)&v29->survarium::scheduler::scheduler_record = 0x7FFFFFFF;
    v29->m_max_update_count = 0;
    v29->m_last_update_time = 0;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v30,
      (int *)&f);
    if ( f.m_current_index )
    {
      if ( (*(_DWORD *)(f.m_current_index + 16))-- == 1 )
        (**(void (__thiscall ***)(unsigned int, _DWORD))f.m_current_index)(f.m_current_index, 0);
    }
  }
}
