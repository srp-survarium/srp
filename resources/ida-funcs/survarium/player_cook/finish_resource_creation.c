void __thiscall survarium::player_cook::finish_resource_creation(
        survarium::player_cook *this,
        survarium::player_creation_params *params,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  survarium::player *v8; // ecx
  survarium::pure_game_effect_emitter_base *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  vostok::memory::doug_lea_allocator *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v13; // [esp-Ch] [ebp-1Ch] BYREF
  assert_on_fail_bool v14; // [esp-8h] [ebp-18h]
  vostok::resources::cook_base::result_enum v15; // [esp-4h] [ebp-14h]
  const char *v16; // [esp+0h] [ebp-10h]
  const char *v17; // [esp+4h] [ebp-Ch]
  unsigned int v18; // [esp+8h] [ebp-8h]
  survarium::pure_game_effect_emitter_base *object; // [esp+1Ch] [ebp+Ch]

  v4 = survarium::g_allocator;
  v5 = type_info::raw_name(&survarium::player `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, (unsigned int)&loc_1147C + 4, v5, v16, v17, v18);
  if ( v7 )
  {
    survarium::player::player(v8, (survarium::player_creation_params *)v7, (int)params);
    object = v9;
  }
  else
  {
    object = 0;
  }
  if ( object )
  {
    v10 = survarium::g_allocator;
    if ( params )
    {
      survarium::player_creation_params::~player_creation_params((survarium::player_creation_params *)v8, (int)params);
      vostok::memory::doug_lea_allocator::free_impl(v11, (int)v10, (char *)params, v16, v17, v18);
    }
    v15 = (vostok::resources::cook_base::result_enum)((char *)&loc_1147C + 4);
    v14 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v13.m_object = (survarium::pure_game_effect_emitter_base *)v8;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v13,
      object);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v12,
      parent,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v13.m_object,
      (const vostok::resources::memory_type *)v14,
      v15);
    v15 = result_fail;
    v14 = assert_on_fail_true;
    v13.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v15 = result_fail;
    v14 = assert_on_fail_true;
    parent[81].m_object = (vostok::resources::unmanaged_resource *)&vostok::resources::unmanaged_memory;
    parent[82].m_object = (vostok::resources::unmanaged_resource *)((char *)&loc_1147C + 4);
    v13.m_object = (survarium::pure_game_effect_emitter_base *)5;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)v8,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    (vostok::resources::cook_base::result_enum)v13.m_object,
    v14,
    v15);
}
