void __thiscall survarium::sound_game_effect_presenter::present(
        survarium::sound_game_effect_presenter *this,
        survarium::sound_game_effect_presenter::effect_data *player)
{
  survarium::base_game_scene *m_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // ecx
  survarium::game *m_game; // eax
  vostok::sound::sound_type v6; // eax
  survarium::sound_game_effect_presenter::effect_data *m_end; // edi
  vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16> *p_m_new_effects; // ebx
  survarium::sound_game_effect_presenter::effect_data *m_begin; // ecx
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v13; // edx
  survarium::sound_game_effect_presenter::effect_data *v14; // ecx
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *v15; // ecx
  _DWORD *v16; // eax
  survarium::sound_game_effect_presenter::effect_data *v17; // edi
  vostok::sound::sound_instance_proxy *v18; // eax
  survarium::sound_game_effect_presenter::effect_data *v19; // ecx
  int m_object; // ecx
  int v21; // eax
  survarium::sound_game_effect_presenter::effect_data *v22; // esi
  survarium::loose_ptr_base *m_pointer; // eax
  survarium::loose_ptr_base *v24; // eax
  vostok::sound::world_user *v25; // edi
  bool v26; // zf
  vostok::sound::atomic_half3 *v27; // ecx
  stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v28; // esi
  int v29; // eax
  int v30; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v31; // edi
  survarium::loose_ptr_data *v32; // edi
  int v33; // eax
  vostok::math::half *v34; // ecx
  vostok::sound::atomic_half3 *v35; // ecx
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **v36; // esi
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *v37; // ecx
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *v38; // ecx
  const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *v39; // [esp+0h] [ebp-18Ch]
  survarium::sound_game_effect_presenter::effect_data *begin; // [esp+Ch] [ebp-180h] BYREF
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v41[2]; // [esp+10h] [ebp-17Ch] BYREF
  _BYTE v42[192]; // [esp+18h] [ebp-174h] BYREF
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> v43; // [esp+D8h] [ebp-B4h] BYREF
  _BYTE v44[192]; // [esp+E4h] [ebp-A8h] BYREF
  char v45; // [esp+1A4h] [ebp+18h] BYREF
  vostok::math::float3 v46; // [esp+1A8h] [ebp+1Ch] BYREF
  vostok::math::half3 v47; // [esp+1B4h] [ebp+28h] BYREF
  vostok::math::half3 v48; // [esp+1BAh] [ebp+2Eh] BYREF
  vostok::math::float3 v49; // [esp+1C0h] [ebp+34h] BYREF
  survarium::sound_game_effect_presenter::effect_data *v50; // [esp+1CCh] [ebp+40h] BYREF
  survarium::sound_game_effect_presenter::effect_data *end; // [esp+1D0h] [ebp+44h] BYREF
  survarium::sound_game_effect_presenter::effect_data *v52; // [esp+1D4h] [ebp+48h] BYREF
  survarium::sound_game_effect_presenter::effect_data *v53; // [esp+1D8h] [ebp+4Ch] BYREF
  survarium::sound_game_effect_presenter::effect_data *v54; // [esp+1DCh] [ebp+50h] BYREF
  vostok::fixed_vector<survarium::sound_game_effect_presenter::effect_data,16> *p_m_old_effects; // [esp+1E0h] [ebp+54h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v56; // [esp+1E4h] [ebp+58h]
  _DWORD *v57; // [esp+1E8h] [ebp+5Ch] BYREF
  vostok::sound::sound_type v58; // [esp+1ECh] [ebp+60h]
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v59; // [esp+1F0h] [ebp+64h] BYREF
  survarium::sound_game_effect_presenter::effect_data *v60; // [esp+1F4h] [ebp+68h]
  stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *v61; // [esp+1F8h] [ebp+6Ch]
  survarium::sound_game_effect_presenter::effect_data *__first; // [esp+1FCh] [ebp+70h]
  int __comp; // [esp+208h] [ebp+7Ch]

  m_scene = this->m_scene;
  p_m_sound_scene = &m_scene->m_sound_scene;
  m_game = m_scene->m_game;
  v56 = p_m_sound_scene;
  v6 = (vostok::sound::sound_type)m_game->m_sound_world->get_logic_world_user(m_game->m_sound_world);
  m_end = this->m_new_effects.m_end;
  p_m_new_effects = &this->m_new_effects;
  m_begin = this->m_new_effects.m_begin;
  v58 = v6;
  __first = m_begin;
  if ( m_begin != m_end )
  {
    v10 = m_end - m_begin;
    v11 = 0;
    while ( v10 != 1 )
    {
      ++v11;
      v10 >>= 1;
    }
    stlp_std::priv::__introsort_loop<survarium::sound_game_effect_presenter::effect_data *,survarium::sound_game_effect_presenter::effect_data,int,stlp_std::less<survarium::sound_game_effect_presenter::effect_data>>(
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)__first,
      m_end,
      0,
      2 * v11,
      player);
    stlp_std::priv::__final_insertion_sort<survarium::sound_game_effect_presenter::effect_data *,stlp_std::less<survarium::sound_game_effect_presenter::effect_data>>(
      __first,
      m_end,
      player);
  }
  v43.m_begin = (survarium::sound_game_effect_presenter::effect_data *)v44;
  v43.m_end = (survarium::sound_game_effect_presenter::effect_data *)v44;
  v43.m_max_end = (survarium::sound_game_effect_presenter::effect_data *)&v45;
  v12 = this->m_old_effects.m_end - this->m_old_effects.m_begin;
  p_m_old_effects = &this->m_old_effects;
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::resize(v12, &v43);
  v13 = (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)p_m_new_effects->m_begin;
  v14 = this->m_old_effects.m_begin;
  v50 = v43.m_end;
  end = stlp_std::priv::__set_difference<survarium::sound_game_effect_presenter::effect_data *,survarium::sound_game_effect_presenter::effect_data *,survarium::sound_game_effect_presenter::effect_data *,stlp_std::less<survarium::sound_game_effect_presenter::effect_data>>(
          v14,
          v43.m_begin,
          this->m_old_effects.m_end,
          v13,
          (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)this->m_new_effects.m_end);
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::erase(
    v15,
    &v43.m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&end,
    &v50);
  if ( v43.m_end - v43.m_begin )
  {
    __first = 0;
    v61 = (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)(v43.m_end - v43.m_begin);
    do
    {
      v16 = (vostok::sound::sound_instance_proxy **)((char *)&v43.m_begin->sound.m_object + (unsigned int)__first);
      if ( *v16
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v16 + 12))(*v16);
      }
      ++__first;
      --v61;
    }
    while ( v61 );
  }
  v17 = this->m_old_effects.m_begin;
  v18 = (vostok::sound::sound_instance_proxy *)this->m_old_effects.m_end;
  v61 = (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)p_m_new_effects->m_begin;
  v19 = this->m_new_effects.m_end;
  __first = v17;
  v59.m_object = v18;
  v60 = v19;
  while ( v17 != (survarium::sound_game_effect_presenter::effect_data *)v59.m_object )
  {
    if ( v61 == (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v60 )
      break;
    if ( stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
           (const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v17,
           v61,
           v39) )
    {
      __first = ++v17;
    }
    else
    {
      if ( !stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()(
              (const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)v61,
              (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v17,
              v39) )
      {
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
          &v17->sound,
          (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&v61[8]);
        v17 = ++__first;
      }
      v61 += 12;
    }
  }
  m_object = 12;
  v21 = this->m_new_effects.m_end - this->m_new_effects.m_begin;
  if ( this->m_first_person )
  {
    if ( v21 )
    {
      __comp = 0;
      __first = (survarium::sound_game_effect_presenter::effect_data *)(this->m_new_effects.m_end
                                                                      - this->m_new_effects.m_begin);
      do
      {
        v22 = &p_m_new_effects->m_begin[__comp];
        if ( !v22->sound.m_object )
        {
          m_pointer = v22->effect.m_object->m_pointer;
          if ( m_pointer )
            v24 = m_pointer - 1;
          else
            v24 = 0;
          v25 = vostok::sound::sound_emitter::emit_hud_sound(
                  (vostok::sound::sound_emitter *)v24[7].m_pointer,
                  v56,
                  (vostok::sound::world_user *)&v57,
                  v58);
          vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
            (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v25,
            &v22->sound);
          if ( v57 )
          {
            v26 = v57[10]-- == 1;
            if ( v26 )
              (*(void (__thiscall **)(_DWORD *))(*v57 + 32))(v57);
          }
          m_object = (int)v22->sound.m_object;
          if ( m_object
            && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            (**(void (__thiscall ***)(vostok::math::half *, int, _DWORD, _DWORD))m_object)(
              (vostok::math::half *)m_object,
              1,
              0,
              0);
          }
        }
        v60 = (survarium::sound_game_effect_presenter::effect_data *)v22->sound.m_object;
        if ( v60
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          *(_QWORD *)&v46.x = LODWORD(v22->offset);
          v46.z = 0.0;
          vostok::math::half3::half3(&v47, &v46, (vostok::math::half *)m_object);
          vostok::sound::atomic_half3::set(v27, (vostok::math::half3 *)&v60[4].sound, (int)&v47);
        }
        ++__comp;
        __first = (survarium::sound_game_effect_presenter::effect_data *)((char *)__first - 1);
      }
      while ( __first );
    }
  }
  else if ( v21 )
  {
    v61 = 0;
    v60 = (survarium::sound_game_effect_presenter::effect_data *)v21;
    do
    {
      v28 = &v61[(unsigned int)p_m_new_effects->m_begin];
      v26 = *(_DWORD *)&v28[8].gap0 == 0;
      __first = (survarium::sound_game_effect_presenter::effect_data *)&v28[8];
      if ( v26 )
      {
        v29 = **(_DWORD **)&v28->gap0;
        if ( v29 )
          v30 = v29 - 4;
        else
          v30 = 0;
        v31 = vostok::sound::sound_emitter::emit_point_sound(
                *(vostok::sound::sound_emitter **)(v30 + 32),
                v56,
                &v59,
                v58);
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
          v31,
          (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&v28[8]);
        if ( v59.m_object )
        {
          v26 = v59.m_object->m_reference_count-- == 1;
          if ( v26 )
            v59.m_object->free_object(v59.m_object);
        }
        m_object = (int)__first->effect.m_object;
        if ( __first->effect.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          (**(void (__thiscall ***)(vostok::math::half *, int, _DWORD, _DWORD))m_object)(
            (vostok::math::half *)m_object,
            1,
            0,
            0);
        }
      }
      v32 = __first->effect.m_object;
      if ( __first->effect.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v33 = ((int (__thiscall *)(survarium::sound_game_effect_presenter::effect_data *))player->effect.m_object[8].m_pointer)(player);
        ((void (__thiscall *)(survarium::loose_ptr_data *, int))v32->m_pointer[4].m_pointer)(v32, v33 + 48);
        *(_QWORD *)&v49.x = *(unsigned int *)&v28[4].gap0;
        v49.z = 0.0;
        vostok::math::half3::half3(&v48, &v49, v34);
        vostok::sound::atomic_half3::set(v35, (vostok::math::half3 *)&__first->effect.m_object[7], (int)&v48);
      }
      v61 += 12;
      v60 = (survarium::sound_game_effect_presenter::effect_data *)((char *)v60 - 1);
    }
    while ( v60 );
  }
  v36 = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)p_m_old_effects;
  begin = (survarium::sound_game_effect_presenter::effect_data *)v42;
  v41[0] = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v42;
  v41[1] = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&v43;
  v53 = p_m_old_effects->m_end;
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::assign<survarium::sound_game_effect_presenter::effect_data const *>(
    (vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *)m_object,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&begin,
    p_m_old_effects->m_begin,
    (const survarium::sound_game_effect_presenter::effect_data *const *)&v53);
  v52 = p_m_new_effects->m_end;
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::assign<survarium::sound_game_effect_presenter::effect_data const *>(
    v37,
    v36,
    p_m_new_effects->m_begin,
    (const survarium::sound_game_effect_presenter::effect_data *const *)&v52);
  v54 = (survarium::sound_game_effect_presenter::effect_data *)v41[0];
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::assign<survarium::sound_game_effect_presenter::effect_data const *>(
    v38,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)p_m_new_effects,
    begin,
    (const survarium::sound_game_effect_presenter::effect_data *const *)&v54);
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)begin,
    v41);
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)p_m_new_effects->m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&p_m_new_effects->m_end);
  p_m_new_effects->m_end = p_m_new_effects->m_begin;
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)v43.m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&v43.m_end);
}
