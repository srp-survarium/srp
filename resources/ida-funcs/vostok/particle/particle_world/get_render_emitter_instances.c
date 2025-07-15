void __thiscall vostok::particle::particle_world::get_render_emitter_instances(
        vostok::particle::particle_world *this,
        const vostok::math::float4x4 *view_proj_matrix,
        vostok::vectora<vostok::particle::render_particle_emitter_instance *> *out_particle_emitters)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::physics::bt_collision_shape *v6; // eax
  survarium::game_camera *v7; // ecx
  unsigned int m_current_lod; // eax
  vostok::particle::particle_emitter_instance *m_first; // ecx
  vostok::math::cuboid *m_data_type_action; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v11; // eax
  survarium::game_camera *v12; // ecx
  survarium::game_camera *m_old_lod; // ecx
  survarium::game_camera *v14; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *v15; // eax
  survarium::game_camera *v16; // ecx
  void *const *v17; // [esp+0h] [ebp-120h]
  vostok::particle::particle_system_instance_impl *v19; // [esp+14h] [ebp-10Ch]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v20; // [esp+18h] [ebp-108h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+1Ch] [ebp-104h] BYREF
  char v22; // [esp+23h] [ebp-FDh]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v23; // [esp+24h] [ebp-FCh]
  vostok::particle::render_particle_emitter_instance *v24; // [esp+28h] [ebp-F8h]
  vostok::particle::particle_action_data_type *v25; // [esp+2Ch] [ebp-F4h]
  vostok::particle::particle_system_instance_impl *v26; // [esp+30h] [ebp-F0h]
  char v27; // [esp+37h] [ebp-E9h]
  vostok::particle::particle_system_instance_impl *v28; // [esp+38h] [ebp-E8h]
  char v29; // [esp+3Eh] [ebp-E2h]
  char v30; // [esp+3Fh] [ebp-E1h]
  vostok::particle::particle_system_instance_impl *v31; // [esp+40h] [ebp-E0h]
  char v32; // [esp+47h] [ebp-D9h]
  vostok::particle::render_particle_emitter_instance *m_render_instance; // [esp+48h] [ebp-D8h]
  vostok::math::cuboid *v34; // [esp+4Ch] [ebp-D4h]
  char v35; // [esp+53h] [ebp-CDh]
  vostok::particle::particle_system_instance_impl *v36; // [esp+54h] [ebp-CCh]
  char v37; // [esp+5Bh] [ebp-C5h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object; // [esp+5Ch] [ebp-C4h]
  vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v39; // [esp+60h] [ebp-C0h] BYREF
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v40; // [esp+64h] [ebp-BCh]
  char v41; // [esp+6Bh] [ebp-B5h]
  vostok::particle::particle_system_instance_impl *v42; // [esp+6Ch] [ebp-B4h]
  char v43; // [esp+73h] [ebp-ADh]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+74h] [ebp-ACh]
  char v45; // [esp+7Bh] [ebp-A5h]
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> v47; // [esp+80h] [ebp-A0h] BYREF
  boost::arg<1> v48[4]; // [esp+88h] [ebp-98h] BYREF
  boost::arg<1> result[4]; // [esp+8Ch] [ebp-94h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> v50; // [esp+90h] [ebp-90h] BYREF
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *emm_list; // [esp+98h] [ebp-88h]
  vostok::particle::particle_emitter_instance *em_instance; // [esp+9Ch] [ebp-84h]
  vostok::math::frustum view_frustum; // [esp+A0h] [ebp-80h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> instance; // [esp+11Ch] [ebp-4h] BYREF

  vostok::math::frustum::frustum(&view_frustum, view_proj_matrix);
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&instance,
    (const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&this->m_ticked_instances_list.m_first);
  while ( instance.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    v45 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    m_object = instance.m_object;
    if ( vostok::particle::particle_system_instance_impl::get_ticked(instance.m_object)
      && (v43 = 0,
          survarium::weapon_user_dead_state::finalize(v4),
          v42 = instance.m_object,
          LOBYTE(v5) = instance.m_object->m_visible,
          (v41 = (char)v5) != 0) )
    {
      v37 = 0;
      survarium::weapon_user_dead_state::finalize(v5);
      v36 = instance.m_object;
      v35 = 0;
      survarium::weapon_user_dead_state::finalize(v7);
      m_current_lod = instance.m_object->m_current_lod;
      emm_list = &v36->m_lods[m_current_lod].m_emitter_instance_list;
      m_first = v36->m_lods[m_current_lod].m_emitter_instance_list.m_first;
      em_instance = m_first;
      while ( em_instance )
      {
        if ( vostok::particle::particle_emitter_instance::get_visible(em_instance)
          && (m_data_type_action = (vostok::math::cuboid *)em_instance->m_data_type_action,
              (v34 = m_data_type_action) != 0)
          && vostok::math::cuboid::test_inexact(m_data_type_action, &em_instance->m_aabbox) != intersection_outside )
        {
          m_render_instance = em_instance->m_render_instance;
          *(_DWORD *)result = m_render_instance;
          v11 = (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
          stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(v11, v17);
          m_first = em_instance->m_next;
          em_instance = m_first;
        }
        else
        {
          m_first = em_instance->m_next;
          em_instance = m_first;
        }
      }
      v32 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_first);
      v31 = instance.m_object;
      v30 = 0;
      survarium::weapon_user_dead_state::finalize(v12);
      m_old_lod = (survarium::game_camera *)v31->m_old_lod;
      if ( m_old_lod != (survarium::game_camera *)instance.m_object->m_current_lod )
      {
        v29 = 0;
        survarium::weapon_user_dead_state::finalize(m_old_lod);
        v28 = instance.m_object;
        v27 = 0;
        survarium::weapon_user_dead_state::finalize(v14);
        v26 = instance.m_object;
        em_instance = v28->m_lods[instance.m_object->m_old_lod].m_emitter_instance_list.m_first;
        while ( em_instance )
        {
          if ( vostok::particle::particle_emitter_instance::get_visible(em_instance)
            && (v25 = em_instance->m_data_type_action) != 0 )
          {
            v24 = em_instance->m_render_instance;
            *(_DWORD *)v48 = v24;
            v15 = (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v48);
            stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(v15, v17);
            em_instance = em_instance->m_next;
          }
          else
          {
            em_instance = em_instance->m_next;
          }
        }
      }
      v23 = &v21;
      v16 = (survarium::game_camera *)&v21;
      v21.m_object = 0;
      if ( instance.m_object )
      {
        vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v23);
        v16 = (survarium::game_camera *)v23;
        v23->m_object = (survarium::weapon_user_animations_container *)instance.m_object;
        if ( v23->m_object )
          vostok::threading::interlocked_increment(&v23->m_object->vostok::resources::unmanaged_intrusive_base);
      }
      v22 = 0;
      survarium::weapon_user_dead_state::finalize(v16);
      vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
        &v47,
        (const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&v21.m_object->m_aimed_stand_animations[1][5]);
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
      v20.m_object = 0;
      vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v20,
        (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
      v19 = (vostok::particle::particle_system_instance_impl *)v20.m_object;
      v20.m_object = (vostok::ai::behaviour *)instance.m_object;
      instance.m_object = v19;
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v47);
    }
    else
    {
      v40 = (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v39;
      v39.m_object = 0;
      vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v39,
        (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
      v6 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&v39);
      vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
        &v50,
        (const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&v6[2].m_current_satisfaction_update_tick);
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v39);
      object = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance,
        (const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v50);
    }
  }
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
}
