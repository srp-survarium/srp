vostok::animation::callback_return_type_enum __thiscall survarium::weapon_sound_effect::on_sound_event(
        survarium::weapon_sound_effect *this,
        vostok::animation::animation_callback_params *params)
{
  unsigned __int8 domain_data; // al
  survarium::base_game_scene *m_game_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // edi
  vostok::sound::world_user *v6; // eax
  survarium::weapon *m_weapon; // ecx
  survarium::hit_initiator *m_initiator_holder; // edx
  survarium::player *m_object; // ecx
  unsigned __int8 id; // dl
  bool v11; // cl
  bool v12; // zf
  int m_sounds_counter; // ecx
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v14; // eax
  boost::function<void __cdecl(void)> *v15; // ecx
  volatile int *p_m_reference_count; // eax
  vostok::sound::sound_instance_proxy *v17; // ebx
  void (__cdecl *v18)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v19; // eax
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *m_simultaneous_sounds_queue_size; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v21; // eax
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v22; // eax
  boost::function<void __cdecl(void)> *v23; // ecx
  void (__cdecl *v24)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *m_begin; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *m_end; // eax
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > &,vostok::sound::sound_instance_proxy const &),boost::_bi::list2<boost::reference_wrapper<vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > >,boost::reference_wrapper<vostok::sound::sound_instance_proxy const > > > v28; // [esp-8h] [ebp-84h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > &,vostok::sound::sound_instance_proxy const &),boost::_bi::list2<boost::reference_wrapper<vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > >,boost::reference_wrapper<vostok::sound::sound_instance_proxy const > > > v29; // [esp-8h] [ebp-84h]
  int v30; // [esp+4h] [ebp-78h]
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> instance; // [esp+10h] [ebp-6Ch] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> result; // [esp+14h] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v33; // [esp+18h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v34; // [esp+1Ch] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *end; // [esp+20h] [ebp-5Ch] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v36; // [esp+24h] [ebp-58h] BYREF
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > v37; // [esp+28h] [ebp-54h] BYREF
  __int64 v38; // [esp+30h] [ebp-4Ch]
  boost::function<void __cdecl(void)> f; // [esp+3Ch] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> v40; // [esp+5Ch] [ebp-20h] BYREF

  domain_data = params->domain_data;
  if ( domain_data == 0xFF )
    this->m_sounds_counter = (unsigned __int8)(this->m_sounds_counter + 1)
                           % (unsigned int)(this->m_first_view_sounds.sounds_emitters.m_end
                                          - this->m_first_view_sounds.sounds_emitters.m_begin);
  else
    this->m_sounds_counter = domain_data;
  m_game_scene = this->m_weapon->m_game_scene;
  p_m_sound_scene = &m_game_scene->m_sound_scene;
  v6 = m_game_scene->m_game->m_sound_world->get_logic_world_user(m_game_scene->m_game->m_sound_world);
  m_weapon = this->m_weapon;
  m_initiator_holder = m_weapon->m_initiator_holder;
  m_object = m_weapon->m_game_scene->m_game->m_network_client->m_current_player.m_object;
  id = m_initiator_holder->id;
  v11 = m_object
     && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
     && m_object->id == id;
  v12 = !v11;
  m_sounds_counter = this->m_sounds_counter;
  instance.m_object = 0;
  if ( v12 )
  {
    v22 = vostok::sound::sound_emitter::emit_point_sound(
            this->m_third_view_sounds.sounds_emitters.m_begin[m_sounds_counter].m_object,
            &v33,
            p_m_sound_scene,
            v6);
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
      &instance,
      v22);
    if ( v33.m_object )
    {
      v12 = v33.m_object->m_reference_count-- == 1;
      if ( v12 )
        v33.m_object->free_object(v33.m_object);
    }
    v17 = instance.m_object;
    if ( instance.m_object )
    {
      instance.m_object->set_position(
        instance.m_object,
        (const vostok::math::float3 *)&this->m_weapon->m_fire_bullet_transform.lines[3]);
      HIDWORD(v38) = &this->m_third_view_sounds.sounds_instances;
      LODWORD(v38) = survarium::on_sound_finished;
      *(_QWORD *)&v29.f_ = v38;
      v29.l_.a2_.t_ = v17;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v23, (int)&v40, (unsigned int)this, v29, v30);
      boost::function<void __cdecl (void)>::operator=(&v17->m_callback, &v40);
      if ( v40.vtable )
      {
        if ( ((int)v40.vtable & 1) == 0 )
        {
          v24 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v40.vtable & 0xFFFFFFFE);
          if ( v24 )
            v24(&v40.functor, &v40.functor, 2);
        }
        v40.vtable = 0;
      }
      m_begin = this->m_third_view_sounds.sounds_instances.m_begin;
      if ( this->m_third_view_sounds.sounds_instances.m_end - m_begin == this->m_simultaneous_sounds_queue_size )
      {
        v37.m_begin = this->m_third_view_sounds.sounds_instances.m_begin;
        v36 = m_begin + 1;
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::erase(
          &v37,
          &this->m_third_view_sounds.sounds_instances,
          &v37.m_begin,
          &v36);
      }
      m_end = this->m_third_view_sounds.sounds_instances.m_end;
      if ( m_end )
      {
        m_end->m_object = v17;
        ++v17->m_reference_count;
        v17 = instance.m_object;
      }
      ++this->m_third_view_sounds.sounds_instances.m_end;
      v17->play(v17, once, 0, 0);
      goto LABEL_38;
    }
  }
  else
  {
    v14 = vostok::sound::sound_emitter::emit_hud_sound(
            this->m_first_view_sounds.sounds_emitters.m_begin[m_sounds_counter].m_object,
            &result,
            p_m_sound_scene,
            v6);
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
      &instance,
      v14);
    if ( result.m_object )
    {
      p_m_reference_count = &result.m_object->m_reference_count;
      v12 = result.m_object->m_reference_count-- == 1;
      v15 = (boost::function<void __cdecl(void)> *)*p_m_reference_count;
      if ( v12 )
        result.m_object->free_object(result.m_object);
    }
    v17 = instance.m_object;
    if ( instance.m_object )
    {
      HIDWORD(v38) = &this->m_first_view_sounds.sounds_instances;
      LODWORD(v38) = survarium::on_sound_finished;
      *(_QWORD *)&v28.f_ = v38;
      v28.l_.a2_.t_ = instance.m_object;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v15, (int)&f, (unsigned int)this, v28, v30);
      boost::function<void __cdecl (void)>::operator=(&v17->m_callback, &f);
      if ( f.vtable )
      {
        if ( ((int)f.vtable & 1) == 0 )
        {
          v18 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
          if ( v18 )
            v18(&f.functor, &f.functor, 2);
        }
        f.vtable = 0;
      }
      v19 = this->m_first_view_sounds.sounds_instances.m_begin;
      m_simultaneous_sounds_queue_size = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)this->m_simultaneous_sounds_queue_size;
      if ( (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)(this->m_first_view_sounds.sounds_instances.m_end - v19) == m_simultaneous_sounds_queue_size )
      {
        end = this->m_first_view_sounds.sounds_instances.m_begin;
        v34 = v19 + 1;
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::erase(
          m_simultaneous_sounds_queue_size,
          &this->m_first_view_sounds.sounds_instances,
          &end,
          &v34);
      }
      v21 = this->m_first_view_sounds.sounds_instances.m_end;
      if ( v21 )
      {
        v21->m_object = v17;
        ++v17->m_reference_count;
        v17 = instance.m_object;
      }
      ++this->m_first_view_sounds.sounds_instances.m_end;
      v17->play(v17, once, 0, 0);
LABEL_38:
      v12 = v17->m_reference_count-- == 1;
      if ( v12 )
        instance.m_object->free_object(instance.m_object);
    }
  }
  return 0;
}
