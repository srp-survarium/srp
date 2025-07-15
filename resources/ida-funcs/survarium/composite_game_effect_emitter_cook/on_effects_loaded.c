void __thiscall survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::on_effects_loaded(
        survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *emitters_count)
{
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  void *v4; // esp
  vostok::resources::queries_result *v5; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *i; // esi
  _DWORD v8[3]; // [esp+0h] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > v9; // [esp+Ch] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+18h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v11; // [esp+1Ch] [ebp-4h]

  v3 = emitters_count;
  v4 = alloca(4 * (_DWORD)emitters_count);
  v5 = data;
  v9.m_begin = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v8;
  v9.m_end = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v8;
  v9.m_max_end = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)&v8[(_DWORD)emitters_count];
  if ( emitters_count )
  {
    emitters_count = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource;
    v11 = v3;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
        emitters_count);
      v6 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
             (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data,
             &v10);
      vostok::buffer_vector<vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base>>::push_back(
        v6,
        &v9);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      emitters_count += 184;
      v11 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)v11 - 1);
    }
    while ( v11 );
  }
  survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::finish_query(
    this,
    v5->m_parent_query,
    v9.m_begin,
    v9.m_end - v9.m_begin);
  for ( i = v9.m_begin; i != v9.m_end; ++i )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)i);
}


void __thiscall survarium::composite_game_effect_emitter_cook<survarium::random_permutation_game_effect_emitter>::on_effects_loaded(
        survarium::composite_game_effect_emitter_cook<survarium::random_permutation_game_effect_emitter> *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *emitters_count)
{
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  void *v4; // esp
  vostok::resources::queries_result *v5; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *i; // esi
  _DWORD v8[3]; // [esp+0h] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > v9; // [esp+Ch] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+18h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v11; // [esp+1Ch] [ebp-4h]

  v3 = emitters_count;
  v4 = alloca(4 * (_DWORD)emitters_count);
  v5 = data;
  v9.m_begin = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v8;
  v9.m_end = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)v8;
  v9.m_max_end = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)&v8[(_DWORD)emitters_count];
  if ( emitters_count )
  {
    emitters_count = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource;
    v11 = v3;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
        emitters_count);
      v6 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
             (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data,
             &v10);
      vostok::buffer_vector<vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base>>::push_back(
        v6,
        &v9);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      emitters_count += 184;
      v11 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)v11 - 1);
    }
    while ( v11 );
  }
  survarium::composite_game_effect_emitter_cook<survarium::random_permutation_game_effect_emitter>::finish_query(
    this,
    v5->m_parent_query,
    v9.m_begin,
    v9.m_end - v9.m_begin);
  for ( i = v9.m_begin; i != v9.m_end; ++i )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)i);
}
