void __cdecl survarium::fill_damage_model(
        survarium::damage_model *const model,
        vostok::memory::stack_allocator *allocator,
        vostok::configs::binary_config_value **model_value,
        const vostok::configs::binary_config_value *damage_groups,
        const vostok::configs::binary_config_value *affect_duration,
        vostok::configs::binary_config_value *data)
{
  vostok::configs::binary_config_value **v6; // esi
  int v7; // ebx
  vostok::configs::binary_config_value *v8; // ebx
  int v9; // edi
  void *v10; // esp
  void *v11; // esp
  char *v12; // eax
  int v13; // esi
  const char **v14; // eax
  int v15; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v16; // edi
  vostok::configs::binary_config_value *v17; // ecx
  int v18; // eax
  int v19; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // ecx
  char **v23; // esi
  const vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v26; // eax
  survarium::body_part_parameters *v27; // eax
  char **v28; // eax
  survarium::body_part_parameters *body_part; // eax
  vostok::configs::binary_config_value *v30; // ecx
  const vostok::configs::binary_config_value *v31; // eax
  const vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // ecx
  int pointer; // edi
  int v35; // esi
  unsigned int *m_affect_duration; // esi
  unsigned int k; // ebx
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *m; // esi
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *n; // esi
  const vostok::configs::binary_config_value *v40; // [esp-Ch] [ebp-7Ch]
  survarium::damage_model *v41; // [esp-8h] [ebp-78h]
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *v42; // [esp-4h] [ebp-74h]
  _BYTE v43[16]; // [esp+0h] [ebp-70h] BYREF
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > v44; // [esp+10h] [ebp-60h] BYREF
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > v45; // [esp+1Ch] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v46; // [esp+28h] [ebp-48h] BYREF
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *v47; // [esp+2Ch] [ebp-44h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v48; // [esp+30h] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v49; // [esp+34h] [ebp-3Ch] BYREF
  vostok::configs::binary_config_value *v50; // [esp+38h] [ebp-38h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v51; // [esp+3Ch] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v52; // [esp+40h] [ebp-30h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v53; // [esp+44h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v54; // [esp+48h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v55; // [esp+4Ch] [ebp-24h] BYREF
  int v56; // [esp+50h] [ebp-20h]
  int v57; // [esp+54h] [ebp-1Ch]
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v58; // [esp+58h] [ebp-18h]
  const char **v59; // [esp+5Ch] [ebp-14h]
  int v60; // [esp+60h] [ebp-10h]
  int v61; // [esp+64h] [ebp-Ch]
  vostok::configs::binary_config_value *j; // [esp+68h] [ebp-8h]
  unsigned __int8 i; // [esp+6Fh] [ebp-1h]

  v61 = 0;
  v60 = 0;
  v6 = model_value;
  v7 = *((unsigned __int16 *)model_value + 11);
  j = *model_value;
  v8 = &j[v7];
  v9 = 4 * (int)data[2].id.pointer;
  v10 = alloca(v9);
  v44.m_begin = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v43;
  v44.m_end = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v43;
  v44.m_max_end = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)&v43[v9];
  v11 = alloca(v9);
  v57 = 0;
  v56 = 0;
  v45.m_begin = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v43;
  v45.m_end = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v43;
  v45.m_max_end = (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)&v43[v9];
  if ( j != v8 )
  {
    do
    {
      LOBYTE(v47) = -1;
      for ( i = 0; i != 24 * damage_groups->count / 24; ++i )
      {
        v12 = (char *)damage_groups->data.pointer + 24 * i;
        v13 = *(_DWORD *)v12 + 24 * *((unsigned __int16 *)v12 + 11);
        v59 = *(const char ***)v12;
        if ( v59 != (const char **)v13 )
        {
          while ( 1 )
          {
            v14 = (const char **)vostok::configs::binary_config_value::operator[](j, "name");
            if ( !vostok::strings::compare(*v59, *v14) )
              break;
            v59 += 6;
            if ( v59 == (const char **)v13 )
              goto LABEL_9;
          }
          LOBYTE(v47) = i;
        }
LABEL_9:
        ;
      }
      if ( vostok::configs::binary_config_value::value_exists(
             (vostok::configs::binary_config_value *)i,
             (int)j,
             (unsigned int)"effect") )
      {
        v15 = 736 * v60++;
        v61 |= 3u;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v53,
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)&data[12].id.max_storage + v15 + 4));
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
          &v54,
          (vostok::particle::particle_system_instance_impl *)v53.m_object);
        v16 = &v54;
      }
      else
      {
        v61 |= 4u;
        v55.m_object = 0;
        v16 = &v55;
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v46,
        v16);
      if ( (v61 & 4) != 0 )
      {
        v61 &= ~4u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v55);
      }
      if ( (v61 & 2) != 0 )
      {
        v61 &= ~2u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
      }
      if ( (v61 & 1) != 0 )
      {
        v61 &= ~1u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v53);
      }
      if ( vostok::configs::binary_config_value::value_exists(v17, (int)j, (unsigned int)"threshold_effects") )
      {
        v18 = 24 * vostok::configs::binary_config_value::operator[](j, "threshold_effects")->count / 24;
        if ( v18 )
        {
          v19 = 736 * v60;
          v60 += v18;
          v59 = (const char **)((char *)&data[3].id.pointer + v19);
          v58 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v18;
          do
          {
            v20 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v59;
            v59 += 184;
            vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
              &v51,
              v20 + 55);
            vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
              &v52,
              (vostok::particle::particle_system_instance_impl *)v51.m_object);
            vostok::buffer_vector<vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>>::push_back(
              &v52,
              &v44);
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v52);
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v51);
            v58 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)v58 - 1);
          }
          while ( v58 );
        }
      }
      v21 = vostok::configs::binary_config_value::operator[](j, "hit_types");
      v22 = data;
      v50 = v21;
      v59 = 0;
      v58 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(&data[3].id + 92 * v60);
      do
      {
        v23 = (char **)((char *)hit_type_names_37 + (_DWORD)v59);
        if ( vostok::configs::binary_config_value::value_exists(
               v22,
               (int)v50,
               *(unsigned int *)((char *)hit_type_names_37 + (_DWORD)v59)) )
        {
          v24 = vostok::configs::binary_config_value::operator[](v50, *v23);
          if ( vostok::configs::binary_config_value::value_exists(v25, (int)v24, (unsigned int)"effect") )
          {
            v26 = v58;
            ++v60;
            v58 += 184;
            vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
              &v48,
              v26 + 55);
            vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
              &v49,
              (vostok::particle::particle_system_instance_impl *)v48.m_object);
            vostok::buffer_vector<vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>>::push_back(
              &v49,
              &v45);
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v49);
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v48);
          }
        }
        ++v59;
      }
      while ( (unsigned int)v59 < 0x20 );
      survarium::create_body_part_parameters(allocator, j, model, v47, &v46);
      v27->next = 0;
      ++model->m_body_parts.m_size;
      if ( model->m_body_parts.m_first )
        model->m_body_parts.m_last->next = v27;
      else
        model->m_body_parts.m_first = v27;
      model->m_body_parts.m_last = v27;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v46);
      ++j;
    }
    while ( j != v8 );
    v6 = model_value;
  }
  for ( j = *v6; j != v8; ++j )
  {
    v28 = (char **)vostok::configs::binary_config_value::operator[](j, "name");
    v42 = &v45.m_begin[v56];
    v41 = (survarium::damage_model *)&v44.m_begin[v57];
    v40 = j;
    body_part = survarium::damage_model::get_body_part(v41, (int)model, *v28);
    survarium::fill_body_part_parameters(
      body_part,
      model,
      allocator,
      v40,
      (vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *const)v41,
      v42);
    if ( vostok::configs::binary_config_value::value_exists(v30, (int)j, (unsigned int)"threshold_effects") )
    {
      v31 = vostok::configs::binary_config_value::operator[](j, "threshold_effects");
      v57 += 24 * v31->count / 24;
    }
    v32 = vostok::configs::binary_config_value::operator[](j, "hit_types");
    pointer = (int)v32->data.pointer;
    v35 = (int)v32->data.pointer + 24 * v32->count;
    while ( pointer != v35 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v33, pointer, (unsigned int)"effect") )
        ++v56;
      pointer += 24;
    }
  }
  m_affect_duration = model->m_affect_duration;
  for ( k = 0; k < 9; ++k )
    *m_affect_duration++ = (unsigned int)vostok::configs::binary_config_value::operator[](
                                           affect_duration,
                                           (char *)affects_captions_36[k])->data.pointer;
  for ( m = v45.m_begin; m != v45.m_end; ++m )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)m);
  for ( n = v44.m_begin; n != v44.m_end; ++n )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)n);
}
