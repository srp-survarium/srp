void __thiscall survarium::damage_zone_core::post_deserialize_resolve(
        survarium::damage_zone_core *this,
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *game_world_core)
{
  int v3; // esi
  void *v4; // esp
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *v5; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *m_object; // esi
  vostok::physics::loose_ptr_base *m_pointer; // eax
  vostok::physics::loose_ptr_base *v8; // eax
  int v9; // edi
  vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *v10; // eax
  int v11; // eax
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *v12; // ecx
  unsigned __int64 v13; // kr00_8
  int v14; // esi
  void *v15; // esp
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v16; // esi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v17; // edi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v18; // ecx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v19; // esi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v20; // ebx
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v21; // ecx
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v22; // ecx
  survarium::collision_sensor *v23; // [esp-4h] [ebp-38h]
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v24; // [esp-4h] [ebp-38h]
  unsigned int v25; // [esp-4h] [ebp-38h]
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v26; // [esp-4h] [ebp-38h]
  const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v27[3]; // [esp+0h] [ebp-34h] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__result; // [esp+Ch] [ebp-28h] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__last; // [esp+10h] [ebp-24h]
  const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **v30; // [esp+14h] [ebp-20h]
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > objects; // [esp+18h] [ebp-1Ch] BYREF
  survarium::damage_zone_core *v32; // [esp+24h] [ebp-10h]
  const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *m_end; // [esp+28h] [ebp-Ch] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *i; // [esp+2Ch] [ebp-8h] BYREF
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *m_begin; // [esp+30h] [ebp-4h]

  v3 = ((char *)this[-1].m_effects.elems[7].m_object - (char *)this[-1].m_effects.elems[6].m_object) >> 2;
  v4 = alloca(4 * v3);
  v30 = &v27[v3];
  __result = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v27;
  __last = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v27;
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize(
    (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v3,
    (const char *)this,
    (int *)&__result);
  stlp_std::priv::__copy_ptrs<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *,vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *>(
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[7].m_object,
    __result,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[6].m_object);
  survarium::collision_sensor::requery_overlapping_objects(
    v23,
    (const stlp_std::__false_type *)&__result,
    (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>)&this[-1].m_effects.elems[4]);
  if ( HIDWORD(this->m_current_satisfaction_update_tick) )
  {
    stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
      v5,
      (int)&this->vostok::resources::resource_reconstruction_info,
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this->m_reconstruction_info_actuality_tick,
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)HIDWORD(this->m_reconstruction_info_actuality_tick));
    m_object = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[6].m_object;
    for ( i = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[7].m_object;
          m_object != i;
          ++m_object )
    {
      m_pointer = m_object->m_object->m_pointer;
      if ( m_pointer )
        v8 = m_pointer - 1;
      else
        v8 = 0;
      v9 = ((int (__thiscall *)(vostok::physics::loose_ptr_data *))v8[3].m_pointer->m_pointer->m_pointer)(v8[3].m_pointer);
      if ( this == (survarium::damage_zone_core *)328 )
        v10 = 0;
      else
        v10 = &this[-1].m_effects.elems[16];
      (*(void (__thiscall **)(int, vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *))(*(_DWORD *)v9 + 36))(
        v9,
        v10);
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 8))(v9);
      ++*(_BYTE *)(v11 + 708);
      stlp_std::vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::push_back(
        m_object,
        v12,
        (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&this->vostok::resources::resource_reconstruction_info);
    }
  }
  if ( this->grm_satisfaction_tree_hook.left_
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v13 = (unsigned int)(__last - __result)
        - (unsigned __int64)(unsigned int)(((char *)this[-1].m_effects.elems[7].m_object
                                          - (char *)this[-1].m_effects.elems[6].m_object) >> 2);
    v14 = __last - __result - (v13 & HIDWORD(v13));
    v15 = alloca(v14 * 4);
    objects.m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v27;
    objects.m_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v27;
    objects.m_max_end = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)&v27[v14];
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize(
      (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)(__last - __result),
      (const char *)this,
      (int *)&objects);
    v16 = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[6].m_object;
    v17 = __result;
    m_end = objects.m_end;
    i = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[7].m_object;
    m_begin = objects.m_begin;
    while ( v17 != __last && v16 != i )
    {
      if ( stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
             v17,
             (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v16,
             v27[0]) )
      {
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator=(
          v17++,
          v18,
          m_begin++);
      }
      else
      {
        if ( !stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
                v16,
                (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v17,
                v27[0]) )
          ++v17;
        ++v16;
      }
    }
    i = stlp_std::priv::__copy_ptrs<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *,vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *>(
          __last,
          m_begin,
          v17);
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::erase(
      v24,
      &objects.m_begin,
      &i,
      &m_end);
    v25 = (unsigned int)game_world_core[12797].m_object;
    v32 = (survarium::damage_zone_core *)((char *)this - 328);
    survarium::damage_zone_core::remove_effects(
      &objects,
      game_world_core,
      (survarium::damage_zone_core *)((char *)this - 328),
      v25);
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize(
      (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)(((char *)this[-1].m_effects.elems[7].m_object - (char *)this[-1].m_effects.elems[6].m_object) >> 2),
      (const char *)this,
      (int *)&objects);
    v19 = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[7].m_object;
    v20 = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this[-1].m_effects.elems[6].m_object;
    m_end = objects.m_end;
    i = objects.m_begin;
    m_begin = __result;
    while ( v20 != v19 && m_begin != __last )
    {
      if ( stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
             v20,
             (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)m_begin,
             v27[0]) )
      {
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::operator=(
          v20++,
          v21,
          i++);
      }
      else
      {
        if ( !stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
                m_begin,
                (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v20,
                v27[0]) )
          ++v20;
        ++m_begin;
      }
    }
    i = stlp_std::priv::__copy_ptrs<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *,vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *>(
          v19,
          i,
          v20);
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::erase(
      v26,
      &objects.m_begin,
      &i,
      &m_end);
    survarium::damage_zone_core::add_effects(&objects, v32, (unsigned int)game_world_core[12797].m_object);
    vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
      v22,
      (int **)&objects);
  }
  vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
    (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v5,
    (int **)&__result);
}
