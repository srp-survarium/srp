void __thiscall survarium::player::mt_draw(survarium::player *this)
{
  int v2; // edx
  vostok::animation::animation_player *v3; // ecx
  bool v4; // zf
  vostok::animation::subscribed_channel **m_current_time_in_ms; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  vostok::render::skeleton_model_instance *m_object; // eax
  unsigned int v10; // edi
  void *v11; // esp
  void *v12; // esp
  survarium::interactive_object *m_current_active_object; // ecx
  survarium::interactive_object_vtbl *v14; // eax
  survarium::interactive_object *v15; // ecx
  survarium::interactive_object_vtbl *v16; // eax
  int v17; // eax
  int v18; // esi
  void *v19; // esp
  void *v20; // esp
  vostok::render::skeleton_model_instance *v21; // eax
  survarium::interactive_object_vtbl *v22; // esi
  survarium::player *v23; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *v24; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v25; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v26; // ecx
  survarium::player *v27; // ecx
  survarium::player *v28; // ecx
  vostok::render::skeleton_model_instance *v29; // eax
  void (__thiscall **p_compute_bones_matrices)(survarium::interactive_object *, const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float4x4 *const, const unsigned int, vostok::math::float4x4 *, vostok::math::float4x4 *, const unsigned int, vostok::math::float4x4 *const, const vostok::animation::animation_player *, const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *, const boost::function<void __cdecl(vostok::math::float4x4 *,unsigned int)> *, const unsigned __int8); // esi
  boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,boost::_mfi::mf1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,survarium::animations_registry,unsigned short>,boost::_bi::list2<boost::_bi::value<survarium::animations_registry *>,boost::arg<1> > > *v31; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v33; // ecx
  vostok::animation::skeleton *v34; // ecx
  vostok::animation::skeleton *v35; // eax
  int v36; // esi
  survarium::hud_object_state *v37; // eax
  survarium::base_player *v38; // ecx
  vostok::math::float4x4 *v39; // eax
  survarium::player *v40; // ecx
  survarium::player *v41; // ecx
  vostok::sound::sound_instance_proxy *v42; // esi
  const vostok::math::float3 *v43; // edx
  unsigned int v44; // [esp+0h] [ebp-1FCh]
  unsigned int v45; // [esp+4h] [ebp-1F8h] BYREF
  bool v46; // [esp+8h] [ebp-1F4h]
  vostok::math::float4x4 result; // [esp+14h] [ebp-1E8h] BYREF
  vostok::math::float4x4 v48; // [esp+54h] [ebp-1A8h] BYREF
  vostok::math::float4x4 v49; // [esp+94h] [ebp-168h] BYREF
  vostok::math::float4x4 v50; // [esp+D4h] [ebp-128h] BYREF
  vostok::math::float4x4 v51; // [esp+114h] [ebp-E8h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v52; // [esp+154h] [ebp-A8h] BYREF
  int v53[8]; // [esp+174h] [ebp-88h] BYREF
  boost::function<void __cdecl(vostok::math::float4x4 *,unsigned int)> v54; // [esp+194h] [ebp-68h] BYREF
  boost::function<void __cdecl(vostok::math::float4x4 *,unsigned int)> v55; // [esp+1B4h] [ebp-48h] BYREF
  unsigned int v56; // [esp+1D4h] [ebp-28h]
  unsigned int count; // [esp+1D8h] [ebp-24h]
  survarium::game_effect_player *p_m_effect_player; // [esp+1DCh] [ebp-20h]
  unsigned __int8 *dst; // [esp+1E0h] [ebp-1Ch]
  unsigned __int8 *src; // [esp+1E4h] [ebp-18h]
  unsigned int v61; // [esp+1E8h] [ebp-14h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v62; // [esp+1ECh] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v63; // [esp+1F0h] [ebp-Ch] BYREF
  unsigned __int8 *v64; // [esp+1F4h] [ebp-8h]
  bool is_player_current; // [esp+1FBh] [ebp-1h]

  v64 = 0;
  is_player_current = survarium::base_network_client::is_player_current(
                        (survarium::base_network_client *)this,
                        *(_DWORD *)(*(int *)((char *)&dword_11414 + (_DWORD)this) + 13912),
                        this->id);
  v3 = *(vostok::animation::animation_player **)(**(_DWORD **)(*(_DWORD *)(v2 + 152) + 356) + 40);
  v4 = !this->m_is_alive;
  *((_BYTE *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
  + (_DWORD)&loc_11439
  + 1) = this->m_model.m_object->m_render_model.m_object->m_render_frame_id < (unsigned int)v3;
  if ( v4 )
  {
    m_current_time_in_ms = (vostok::animation::subscribed_channel **)this->m_current_time_in_ms;
    if ( vostok::animation::animation_player::last_tick_time_in_ms(
           v3,
           (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_animation_player) < (unsigned int)m_current_time_in_ms )
      vostok::animation::animation_player::tick_impl(v3, (int)&this->m_animation_player, m_current_time_in_ms, v45, v46);
  }
  v44 = this->m_current_time_in_ms;
  p_m_effect_player = &this->m_effect_player;
  survarium::game_effect_player::tick(
    (survarium::game_effect_player *)v3,
    &this->m_effect_player.survarium::base_player::m_current_time_in_ms,
    v44);
  v6 = *(float *)&byte_10E5C[(_DWORD)this] - this->m_previous_frame_transform.c.x;
  v7 = *(float *)&byte_10E5C[(_DWORD)this + 4] - this->m_previous_frame_transform.c.y;
  v8 = *(float *)&byte_10E5C[(_DWORD)this + 8] - this->m_previous_frame_transform.c.z;
  survarium::player::render_model(
    (survarium::player *)&byte_10E5C[(_DWORD)this],
    *(const float *)&this,
    fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)));
  m_object = this->m_model.m_object;
  if ( m_object->m_render_model.m_object->m_in_scene
    && (is_player_current
     || !*((_BYTE *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
         + (_DWORD)&loc_11439
         + 1)) )
  {
    v10 = m_object->m_skeleton.m_object->m_bones_count
        - (signed int)(m_object->m_skeleton.m_object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                     - (unsigned int)&m_object->m_skeleton.m_object[1])
        / 28;
    count = v10 << 6;
    v11 = alloca(v10 << 6);
    src = (unsigned __int8 *)&v45;
    v12 = alloca(v10 << 6);
    m_current_active_object = this->m_current_active_object;
    v14 = m_current_active_object->__vftable;
    dst = (unsigned __int8 *)&v45;
    if ( v14->get_skeleton(
           m_current_active_object,
           (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v63)->m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v15 = this->m_current_active_object;
      v16 = v15->__vftable;
      v64 = (unsigned __int8 *)1;
      v17 = (int)v16->get_skeleton(
                   v15,
                   (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v62);
      v18 = *(_DWORD *)(*(_DWORD *)v17 + 264) - (*(_DWORD *)(*(_DWORD *)v17 + 280) - (*(_DWORD *)v17 + 272)) / 28;
      v61 = v18;
    }
    else
    {
      v61 = 1;
      v18 = 1;
    }
    if ( ((unsigned __int8)v64 & 1) != 0 )
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v62);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
    v56 = v18 << 6;
    v19 = alloca(v18 << 6);
    v64 = (unsigned __int8 *)&v45;
    v20 = alloca(v18 << 6);
    v21 = this->m_model.m_object;
    v55.vtable = 0;
    v63.m_object = (vostok::particle::particle_system_instance_impl *)v21;
    v22 = this->m_current_active_object->survarium::base_player::__vftable;
    v62.m_object = (vostok::particle::particle_system_instance_impl *)&v45;
    v24 = survarium::player::first_third_person_animations_resolver(v23, (int)this, &v52);
    v22->compute_bones_matrices(
      this->m_current_active_object,
      (const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v63.m_object->m_lods[0].m_emitter_instance_list,
      (vostok::math::float4x4 *const)src,
      v10,
      (vostok::math::float4x4 *)((char *)&loc_11160 + (_DWORD)this),
      (vostok::math::float4x4 *)((char *)this + (_DWORD)&locret_1111E + 2),
      v61,
      (vostok::math::float4x4 *const)v64,
      &this->m_animation_player,
      (const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)v24,
      &v55,
      1u);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v25,
      (int *)&v52);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v26,
      (int *)&v55);
    if ( survarium::player::use_third_person_animations_resolver(v27, (int)this)
      || *((_BYTE *)&loc_1143B + (_DWORD)this) )
    {
      memcpy(dst, src, count);
      memcpy((unsigned __int8 *)v62.m_object, v64, v56);
    }
    else
    {
      v29 = this->m_model.m_object;
      v54.vtable = 0;
      v63.m_object = (vostok::particle::particle_system_instance_impl *)v29;
      p_compute_bones_matrices = &this->m_current_active_object->compute_bones_matrices;
      v31 = survarium::player::third_person_animations_resolver(
              v28,
              (boost::_bi::bind_t<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,boost::_mfi::mf1<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,survarium::animations_registry,unsigned short>,boost::_bi::list2<boost::_bi::value<survarium::animations_registry *>,boost::arg<1> > > *)v53);
      (*p_compute_bones_matrices)(
        this->m_current_active_object,
        (const vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&v63.m_object->m_lods[0].m_emitter_instance_list,
        (vostok::math::float4x4 *const)dst,
        v10,
        &v48,
        &v49,
        v61,
        (vostok::math::float4x4 *const)v62.m_object,
        &this->m_animation_player,
        (const boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> *)v31,
        &v54,
        1u);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v32, v53);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v33,
        (int *)&v54);
    }
    v35 = this->m_model.m_object->m_skeleton.m_object;
    v36 = (vostok::animation::skeleton::get_bone_index(v34, (int)v35, "Weapon")
         - (v35[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
          - (int)&v35[1])
         / 28) << 6;
    vostok::math::mul4x3(
      (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)this],
      (const vostok::math::float4x4 *)&src[v36],
      &v51);
    vostok::math::mul4x3(
      (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)this],
      (const vostok::math::float4x4 *)&dst[v36],
      &v50);
    if ( is_player_current )
      v37 = (survarium::hud_object_state *)(*(int *)((char *)&dword_1141C + (_DWORD)this) + 500);
    else
      v37 = 0;
    this->m_current_active_object->draw(
      this->m_current_active_object,
      &v51,
      &v50,
      (const vostok::math::float4x4 *const)v64,
      (const vostok::math::float4x4 *const)v62.m_object,
      v61,
      v37);
    vostok::render::scene_renderer::update_skeleton(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
      *(vostok::memory::base_allocator **)((char *)&dword_200060
                                         + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)this) + 160)
                                                     + 172)),
      (const vostok::math::float4x4 *)src,
      (const vostok::math::float4x4 *)dst,
      v10);
  }
  else
  {
    this->m_current_active_object->on_culled_player_draw(this->m_current_active_object);
  }
  v39 = survarium::base_player::computed_head_transform(v38, this, &result);
  v4 = !is_player_current;
  qmemcpy((char *)&loc_11160 + (_DWORD)this, v39, 0x40u);
  if ( v4
    || (*(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                   + (_DWORD)&loc_11403
                                   + 5))[12].tick )
  {
    survarium::player::set_head_visibility(0, (int)this, 1);
  }
  else
  {
    survarium::player::set_head_visibility(0, (int)this, 0);
  }
  survarium::player::update_camera(v40, (int)this);
  this->m_damage_sound_effect.m_user_head_position.x = this->m_head_transform.c.x;
  this->m_damage_sound_effect.m_user_head_position.y = this->m_head_transform.c.y;
  this->m_damage_sound_effect.m_user_head_position.z = this->m_head_transform.c.z;
  v42 = this->m_damage_sound_effect.m_poisoning_sound_instance.m_object;
  if ( v42
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !survarium::player::is_current(v41, (int)this->m_damage_sound_effect.m_user) )
  {
    v42->set_position(v42, v43);
  }
  v4 = *((_BYTE *)&loc_1143B + (_DWORD)this) == 0;
  this->m_stamina_sound_effect.m_player_head_position.x = this->m_head_transform.c.x;
  this->m_stamina_sound_effect.m_player_head_position.y = this->m_head_transform.c.y;
  this->m_stamina_sound_effect.m_player_head_position.z = this->m_head_transform.c.z;
  if ( v4 )
    survarium::game_effect_player::present(
      (survarium::game_effect_player *)v41,
      (int)p_m_effect_player,
      this->m_effect_presenter,
      this);
}
