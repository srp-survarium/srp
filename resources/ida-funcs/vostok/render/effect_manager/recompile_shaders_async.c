void __thiscall vostok::render::effect_manager::recompile_shaders_async(
        vostok::render::effect_manager *this,
        const vostok::buffer_vector<vostok::fs_new::virtual_path_string> *in_changed_defines)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::render::effect_manager::effect_to_recompile_struct *v6; // eax
  vostok::particle::particle_system_instance_impl *v7; // ecx
  const vostok::fs_new::virtual_path_string *v8; // esi
  vostok::render::effect_manager::shader_cache_info *m_begin; // ebx
  const vostok::buffer_vector<vostok::fs_new::virtual_path_string> *v10; // esi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_end; // ebx
  vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct> *v12; // ecx
  vostok::render::effect_descriptor *descriptor; // esi
  vostok::render::res_effect *v14; // edi
  unsigned int v15; // ebx
  vostok::memory::doug_lea_allocator *v16; // esi
  char *v17; // edi
  vostok::memory::doug_lea_allocator *v18; // ecx
  void *v19; // esp
  void *v20; // esp
  void *v21; // esp
  const char **v22; // eax
  vostok::particle::particle_system_instance_impl *v23; // edi
  vostok::particle::particle_system_instance_impl *v24; // ecx
  vostok::render::effect_compile_data *v25; // eax
  const char **v26; // esi
  const vostok::variant<32> **v27; // eax
  const char **v28; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp-10h] [ebp-2314h] BYREF
  vostok::particle::particle_system_instance_impl *v32; // [esp-Ch] [ebp-2310h]
  unsigned int m_reconstruction_info_actuality_tick; // [esp-8h] [ebp-230Ch]
  void (__thiscall **v34)(vostok::render::effect_manager *, vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **, vostok::resources::queries_result *); // [esp-4h] [ebp-2308h]
  const char *v35; // [esp+0h] [ebp-2304h] BYREF
  const char *v36; // [esp+4h] [ebp-2300h]
  unsigned int v37; // [esp+8h] [ebp-22FCh]
  _DWORD v38[3]; // [esp+10h] [ebp-22F4h] BYREF
  _BYTE v39[8832]; // [esp+1Ch] [ebp-22E8h] BYREF
  char v40; // [esp+229Ch] [ebp-68h] BYREF
  void (__thiscall *v41)(vostok::render::effect_manager *, vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **, vostok::resources::queries_result *); // [esp+22A0h] [ebp-64h] BYREF
  const vostok::buffer_vector<vostok::fs_new::virtual_path_string> *v42; // [esp+22A4h] [ebp-60h]
  vostok::render::effect_manager::effect_to_recompile_struct *v43; // [esp+22A8h] [ebp-5Ch]
  void (__thiscall *v44)(vostok::render::effect_manager *, vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **, vostok::resources::queries_result *); // [esp+22ACh] [ebp-58h]
  const vostok::buffer_vector<vostok::fs_new::virtual_path_string> *v45; // [esp+22B0h] [ebp-54h]
  vostok::render::effect_manager::effect_to_recompile_struct *v46; // [esp+22B4h] [ebp-50h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v47; // [esp+22B8h] [ebp-4Ch] BYREF
  const vostok::variant<32> *const *v48; // [esp+22BCh] [ebp-48h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v49; // [esp+22C0h] [ebp-44h] BYREF
  vostok::particle::particle_system_instance_impl *v50; // [esp+22C4h] [ebp-40h]
  void *v51; // [esp+22C8h] [ebp-3Ch]
  vostok::particle::particle_system_instance_impl *v52; // [esp+22CCh] [ebp-38h]
  vostok::particle::particle_system_instance_impl *v53; // [esp+22D0h] [ebp-34h]
  const char **v54; // [esp+22D4h] [ebp-30h]
  const vostok::resources::request *v55; // [esp+22D8h] [ebp-2Ch]
  const vostok::variant<32> *const *v56; // [esp+22DCh] [ebp-28h]
  const char **i; // [esp+22E0h] [ebp-24h]
  vostok::render::effect_compile_data *v58; // [esp+22E4h] [ebp-20h] BYREF
  const char **m_object; // [esp+22E8h] [ebp-1Ch]
  const vostok::variant<32> *const *v60; // [esp+22ECh] [ebp-18h]
  const char **v61; // [esp+22F0h] [ebp-14h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v62; // [esp+22F4h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v63; // [esp+22F8h] [ebp-Ch] BYREF
  vostok::render::effect_manager::effect_to_recompile_struct *value; // [esp+22FCh] [ebp-8h]

  v2 = vostok::render::g_allocator;
  v4 = type_info::raw_name(&vostok::fixed_vector<vostok::render::effect_manager::effect_to_recompile_struct,2048> `RTTI Type Descriptor');
  v6 = (vostok::render::effect_manager::effect_to_recompile_struct *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                       v5,
                                                                       (int)v2,
                                                                       (unsigned int)&unk_1000C,
                                                                       v4,
                                                                       v35,
                                                                       v36,
                                                                       v37);
  if ( v6 )
  {
    v6->effect.m_object = (vostok::render::res_effect *)&v6->parameters;
    v6->descriptor = (vostok::render::effect_descriptor *)&v6->parameters;
    v7 = (vostok::particle::particle_system_instance_impl *)((char *)&_sbh_sizeHeaderList + (_DWORD)&v6->parameters);
    v6->config.m_object = (vostok::configs::binary_config *)v7;
    value = v6;
  }
  else
  {
    value = 0;
  }
  v8 = *(const vostok::fs_new::virtual_path_string **)&this->force_sync;
  m_begin = this->m_shader_cache_info.m_begin;
  v38[0] = v39;
  v38[1] = v39;
  v38[2] = &v40;
  while ( v8 != (const vostok::fs_new::virtual_path_string *)m_begin )
    vostok::buffer_vector<vostok::fs_new::virtual_path_string>::push_back(
      (vostok::buffer_vector<vostok::fs_new::virtual_path_string> *)v7,
      (int)v38,
      v8++);
  v10 = in_changed_defines;
  m_end = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)in_changed_defines[1522].m_end;
  if ( m_end != (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)in_changed_defines[1522].m_max_end )
  {
    do
    {
      if ( m_end->m_object->log_string(m_end->m_object, (vostok::fixed_string<512> *)v38) )
      {
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v63,
          m_end + 1);
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
          &v62,
          m_end[6].m_object);
        m_object = (const char **)m_end[7].m_object;
        v60 = (const vostok::variant<32> *const *)m_end->m_object;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v47,
          &v62);
        v48 = v60;
        vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v49,
          &v63);
        v50 = m_end[2].m_object;
        v51 = m_end[3].m_object;
        v52 = m_end[4].m_object;
        v53 = m_end[5].m_object;
        v54 = m_object;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v62);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
        vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>::push_back(v12, value, &v47);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v47);
        v10 = in_changed_defines;
      }
      m_end += 8;
    }
    while ( m_end != (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v10[1522].m_max_end );
  }
  descriptor = value->descriptor;
  v14 = value->effect.m_object;
  v15 = ((char *)descriptor - (char *)value->effect.m_object) >> 5;
  if ( v15 )
  {
    v19 = alloca(4 * v15);
    v60 = (const vostok::variant<32> *const *)&v35;
    v20 = alloca(48 * v15);
    v61 = &v35;
    v21 = alloca(8 * v15);
    v55 = (const vostok::resources::request *)&v35;
    v62.m_object = (vostok::particle::particle_system_instance_impl *)v14;
    if ( v14 != (vostok::render::res_effect *)descriptor )
    {
      m_object = &v35;
      v56 = v60;
      v22 = v61;
      v23 = (vostok::particle::particle_system_instance_impl *)(&v14->vostok::resources::resource_flags + 1);
      v63.m_object = v23;
      for ( i = v61; ; v22 = i )
      {
        if ( v22 )
        {
          v22[10] = 0;
          v22[11] = 0;
          v61 = v22;
        }
        else
        {
          v61 = 0;
        }
        v58 = (vostok::render::effect_compile_data *)vostok::memory::new_helper<vostok::render::effect_compile_data>::call<vostok::memory::doug_lea_allocator>(
                                                       vostok::render::g_allocator,
                                                       v35,
                                                       v36,
                                                       v37);
        if ( v58 )
        {
          v34 = 0;
          m_reconstruction_info_actuality_tick = v23->m_reconstruction_info_actuality_tick;
          v32 = v23;
          v31.m_object = v24;
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v31,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v23[-1].m_time_to_finish
          + 1);
          vostok::render::effect_compile_data::effect_compile_data(
            (vostok::render::effect_descriptor *)LODWORD(v63.m_object[-1].m_time_to_finish),
            v58,
            v31,
            (const vostok::render::surface_effect_parameters *)v32,
            m_reconstruction_info_actuality_tick,
            (bool)v34);
          v23 = v63.m_object;
          v58 = v25;
        }
        else
        {
          v58 = 0;
        }
        v26 = v61;
        vostok::variant<32>::set<vostok::render::effect_compile_data *>((vostok::variant<32> *)v24, v61, &v58);
        v27 = (const vostok::variant<32> **)v56;
        v62.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v62.m_object + 32);
        v7 = v62.m_object;
        i += 12;
        ++v56;
        *v27 = (const vostok::variant<32> *)v26;
        v28 = m_object;
        *m_object = uri;
        v28[1] = (const char *)13;
        m_object = v28 + 2;
        v23 = (vostok::particle::particle_system_instance_impl *)((char *)v23 + 32);
        v63.m_object = v23;
        if ( v7 == (vostok::particle::particle_system_instance_impl *)value->descriptor )
          break;
      }
    }
    v45 = in_changed_defines;
    BYTE1(in_changed_defines->m_begin) = 1;
    v46 = value;
    v44 = vostok::render::effect_manager::on_effects_recompiled;
    v41 = vostok::render::effect_manager::on_effects_recompiled;
    v42 = v45;
    v34 = &v41;
    v43 = value;
    if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)v7) )
    {
      v47.m_object = 0;
    }
    else
    {
      v49.m_object = (vostok::particle::particle_system_instance_impl *)v41;
      v50 = (vostok::particle::particle_system_instance_impl *)v42;
      v51 = v43;
      v47.m_object = (vostok::particle::particle_system_instance_impl *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::effect_manager,vostok::fixed_vector<vostok::render::effect_manager::effect_to_recompile_struct,2048> *,vostok::resources::queries_result &>,boost::_bi::list3<boost::_bi::value<vostok::render::effect_manager *>,boost::_bi::value<vostok::fixed_vector<vostok::render::effect_manager::effect_to_recompile_struct,2048> *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                       + 1);
    }
    vostok::resources::query_resources(v55, v15, vostok::render::g_allocator, v60, 0, assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v29,
      (int *)&v47);
    while ( BYTE1(in_changed_defines->m_begin) )
    {
      vostok::resources::dispatch_callbacks(v30);
      vostok::threading::yield(1u);
    }
  }
  else
  {
    v16 = vostok::render::g_allocator;
    v17 = (char *)value;
    vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>::~buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>(
      (vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct> *)v7,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)value);
    vostok::memory::doug_lea_allocator::free_impl(v18, (int)v16, v17, v35, v36, v37);
  }
}
