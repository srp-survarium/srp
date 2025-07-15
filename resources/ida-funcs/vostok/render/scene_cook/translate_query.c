void __thiscall vostok::render::scene_cook::translate_query(
        vostok::render::scene_cook *this,
        const vostok::variant<32> **in_out_query)
{
  vostok::variant<32> *v2; // esi
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  char *v6; // eax
  vostok::buffer_vector<vostok::render::scene *> *v7; // ecx
  survarium::pure_game_effect_emitter_base *v8; // eax
  survarium::pure_game_effect_emitter_base *v9; // edi
  vostok::variant<32> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  vostok::variant<32> *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::query_result_for_cook *v14; // ecx
  _BYTE v15[28]; // [esp-1Ch] [ebp-94h] BYREF
  const char *v16; // [esp+0h] [ebp-78h]
  const char *v17; // [esp+4h] [ebp-74h]
  unsigned int v18; // [esp+8h] [ebp-70h]
  vostok::render::scene_configuration out_value; // [esp+13h] [ebp-65h] BYREF
  int __formal; // [esp+14h] [ebp-64h] BYREF
  vostok::render::scene_cook *v21; // [esp+18h] [ebp-60h]
  vostok::render::scene_cook *v22; // [esp+1Ch] [ebp-5Ch]
  survarium::pure_game_effect_emitter_base *v23; // [esp+20h] [ebp-58h]
  const vostok::variant<32> **v24; // [esp+24h] [ebp-54h]
  int f[8]; // [esp+28h] [ebp-50h] BYREF
  _DWORD v26[10]; // [esp+48h] [ebp-30h] BYREF
  _DWORD *v27; // [esp+70h] [ebp-8h]
  int v28; // [esp+74h] [ebp-4h]

  out_value = (vostok::render::scene_configuration)(*(_BYTE *)&out_value & 0xC0);
  v2 = (vostok::variant<32> *)in_out_query[66];
  v21 = this;
  if ( v2 )
    vostok::variant<32>::try_get<vostok::render::scene_configuration>((vostok::variant<32> *)this, (int)v2, &out_value);
  v3 = vostok::render::g_allocator;
  v4 = type_info::raw_name(&vostok::render::scene `RTTI Type Descriptor');
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, (unsigned int)&a003Bi3BiBoost[4], v4, v16, v17, v18);
  if ( v6 )
  {
    vostok::render::scene::scene(
      (vostok::render::scene *)&out_value,
      (vostok::render::scene_configuration *)v6,
      &out_value);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  __formal = (int)v9;
  vostok::buffer_vector<vostok::render::scene *>::push_back(
    v7,
    (int)vostok::quasi_singleton<vostok::render::scene_manager>::pinst,
    (vostok::render::scene **)&__formal);
  if ( (*(_BYTE *)&out_value & 2) != 0 )
  {
    v27 = 0;
    v28 = 0;
    vostok::variant<32>::destroy_previous_variable_if_needed(v10, (int)v26);
    v28 = vostok::detail::type_to_int<vostok::particle::engine *>::get();
    v26[2] = (char *)&loc_5534B0 + (_DWORD)v9;
    v23 = v9;
    v27 = v26;
    f[1] = 0;
    f[0] = (int)vostok::render::scene_cook::on_particle_world_created;
    v22 = v21;
    v24 = in_out_query;
    f[2] = (int)v21;
    f[3] = (int)v9;
    f[4] = (int)in_out_query;
    *(_DWORD *)v15 = f;
    v26[0] = &vostok::detail::concrete_type_helper<vostok::particle::engine *>::`vftable';
    qmemcpy(&v15[4], f, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::scene_cook,vostok::resources::queries_result &,vostok::render::scene *,vostok::resources::query_result_for_cook *>,boost::_bi::list4<boost::_bi::value<vostok::render::scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::scene *>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > *)v15,
      *(int *)&v15[24]);
    *(_DWORD *)&v15[8] = vostok::render::g_allocator;
    *(_DWORD *)&v15[4] = 58;
    vostok::resources::query_create_resource(
      uri,
      *(vostok::const_buffer *)&v15[4],
      (const char *)v26,
      in_out_query,
      (const vostok::variant<32> *)uri,
      (vostok::resources::query_result_for_cook *)&garbage_buffer[31912]);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v11, f);
    vostok::variant<32>::destroy_previous_variable_if_needed(v12, (int)v26);
  }
  else
  {
    *(_DWORD *)&v15[24] = &a003Bi3BiBoost[4];
    *(_DWORD *)&v15[20] = &vostok::resources::nocache_memory;
    *(_DWORD *)&v15[16] = v10;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v15[16],
      v9);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v13,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)in_out_query,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15[16],
      *(const vostok::resources::memory_type **)&v15[20],
      *(unsigned int *)&v15[24]);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
