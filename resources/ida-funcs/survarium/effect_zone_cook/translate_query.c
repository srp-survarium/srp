void __thiscall survarium::effect_zone_cook::translate_query(
        survarium::effect_zone_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::configs::binary_config_value *v4; // eax
  vostok::variant<32> *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  survarium::pure_game_effect_emitter_base *v10; // eax
  survarium::pure_game_effect_emitter_base *v11; // esi
  survarium::pure_game_effect_emitter_base *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp-Ch] [ebp-34h] BYREF
  const vostok::resources::memory_type *v16; // [esp-8h] [ebp-30h]
  unsigned int v17; // [esp-4h] [ebp-2Ch]
  const char *v18; // [esp+0h] [ebp-28h]
  const char *v19; // [esp+4h] [ebp-24h]
  unsigned int v20; // [esp+8h] [ebp-20h]
  survarium::effect_zone_construct_params construct_params; // [esp+Ch] [ebp-1Ch] BYREF
  _BYTE v22[24]; // [esp+10h] [ebp-18h] BYREF

  m_object = parent[66].m_object;
  vostok::configs::binary_config_value::binary_config_value((vostok::configs::binary_config_value *)this, (int)v22);
  vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v5, (int)m_object, v4);
  v6 = survarium::g_allocator;
  construct_params.game_world = this->m_game_world;
  v7 = type_info::raw_name(&survarium::effect_zone `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x1A8u, v7, v18, v19, v20);
  if ( v9 )
  {
    survarium::effect_zone::effect_zone(
      (survarium::effect_zone *)&construct_params,
      (survarium::effect_zone_construct_params *)v9,
      &construct_params);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  ((void (__thiscall *)(survarium::pure_game_effect_emitter_base *, _BYTE *))v11[1].is_increasing_quality)(&v11[1], v22);
  v17 = 424;
  v16 = &vostok::resources::nocache_memory;
  v15.m_object = v12;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v15,
    v11);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v13,
    parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v15.m_object,
    v16,
    v17);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v14,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
