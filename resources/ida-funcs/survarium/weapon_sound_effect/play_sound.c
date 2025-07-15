void __thiscall survarium::weapon_sound_effect::play_sound(
        survarium::weapon_sound_effect *this,
        int index,
        bool first_view,
        char a4)
{
  int v4; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v6; // esi
  vostok::sound::sound_type v7; // eax
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v8; // eax
  boost::function<void __cdecl(void)> *v9; // ecx
  bool v10; // zf
  vostok::sound::sound_instance_proxy *m_object; // esi
  bool has_passed_filters; // al
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v13; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v15; // eax
  int v16; // ecx
  vostok::sound::sound_instance_proxy *v17; // esi
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > &,vostok::sound::sound_instance_proxy const &),boost::_bi::list2<boost::reference_wrapper<vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > >,boost::reference_wrapper<vostok::sound::sound_instance_proxy const > > > v18; // [esp-10h] [ebp-88h]
  boost::function<void __cdecl(void)> *v19; // [esp-4h] [ebp-7Ch]
  char v20; // [esp+10h] [ebp-68h]
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> value; // [esp+14h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v22; // [esp+18h] [ebp-60h] BYREF
  _DWORD *v23; // [esp+1Ch] [ebp-5Ch] BYREF
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v24; // [esp+20h] [ebp-58h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *end[5]; // [esp+24h] [ebp-54h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v26; // [esp+38h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+58h] [ebp-20h] BYREF

  v4 = index;
  v5 = *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(index + 52);
  v6 = v5 + 37;
  v7 = ((int (__thiscall *)(vostok::resources::resource_base *))v5[40].m_object->m_prev_in_memory_type->link_child_resource)(v5[40].m_object->m_prev_in_memory_type);
  if ( a4 )
  {
    v20 = 1;
    v8 = (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)vostok::sound::sound_emitter::emit_hud_sound(*(vostok::sound::sound_emitter **)(*(_DWORD *)index + 4 * first_view), v6, (vostok::sound::world_user *)&v23, v7);
  }
  else
  {
    v4 = index + 24;
    v20 = 2;
    v8 = vostok::sound::sound_emitter::emit_point_sound(
           *(vostok::sound::sound_emitter **)(*(_DWORD *)(index + 24) + 4 * first_view),
           v6,
           &v22,
           v7);
  }
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
    &value,
    v8);
  if ( (v20 & 2) != 0 )
  {
    v20 &= ~2u;
    if ( v22.m_object )
    {
      v10 = v22.m_object->m_reference_count-- == 1;
      if ( v10 )
        v22.m_object->free_object(v22.m_object);
    }
  }
  if ( (v20 & 1) != 0 )
  {
    v20 &= ~1u;
    if ( v23 )
    {
      v10 = v23[10]-- == 1;
      if ( v10 )
        (*(void (__thiscall **)(_DWORD *))(*v23 + 32))(v23);
    }
  }
  m_object = value.m_object;
  if ( value.m_object )
  {
    if ( !a4 )
      value.m_object->set_position(value.m_object, (const vostok::math::float3 *)(*(_DWORD *)(index + 48) + 1200));
    end[4] = (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_object;
    v13 = (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)(v4 + 12);
    end[2] = (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)survarium::on_sound_finished;
    end[3] = v13;
    v18.l_.a1_.t_ = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)survarium::on_sound_finished;
    v18.l_.a2_.t_ = (const vostok::sound::sound_instance_proxy *)v13;
    v18.f_ = (void (__cdecl *)(vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *, const vostok::sound::sound_instance_proxy *))&f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v9, v18, (int)m_object);
    boost::function<void __cdecl (void)>::operator=(
      &f,
      (boost::function1<void,vostok::physics::contact_point const &> *)&value.m_object->m_finished_callback);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v14,
      (int *)&f);
    v15 = (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v13->m_object;
    v16 = ((char *)v13[1].m_object - (char *)v13->m_object) >> 2;
    if ( v16 == *(unsigned __int8 *)(index + 58) )
    {
      end[0] = (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v13->m_object;
      v24 = v15 + 1;
      vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::erase(
        (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)v16,
        (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)v13,
        end,
        &v24);
    }
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::push_back(
      &value,
      (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)v13);
    v17 = value.m_object;
    value.m_object->play(value.m_object, once, 0, 0);
    v10 = v17->m_reference_count-- == 1;
    if ( v10 )
      value.m_object->free_object(value.m_object);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"weapon_sound_effect",
                                 (const char *)3),
          v9 = v19,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v9,
        &v26);
      v20 |= 4u;
      vostok::logging::append(
        &v26,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\weapon_sound_effect.cpp",
        0x8Cu,
        "void __thiscall survarium::weapon_sound_effect::play_sound(unsigned char,bool)",
        "weapon_sound_effect",
        warning,
        "(%s) Can't allocate sound instance!",
        "<unknown>");
    }
    if ( (v20 & 4) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
        (int *)&v26);
  }
}
