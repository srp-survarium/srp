void __thiscall vostok::particle::particle_world_cooker::create_resource(
        vostok::particle::particle_world_cooker *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::particle::particle_world *v4; // ecx
  vostok::particle::engine *v5; // eax
  vostok::particle::engine *v6; // edi
  unsigned __int64 v7; // rax
  survarium::pure_game_effect_emitter_base *v8; // ecx
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-4h] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+4h] [ebp-14h]
  vostok::particle::engine *out_value; // [esp+10h] [ebp-8h] BYREF

  out_value = 0;
  vostok::variant<32>::try_get<vostok::particle::engine *>(
    (vostok::variant<32> *)this,
    (int)in_out_query[66].m_object,
    &out_value);
  if ( in_out_unmanaged_resource_buffer.m_data )
  {
    vostok::particle::particle_world::particle_world(v4, (int)in_out_unmanaged_resource_buffer.m_data, out_value);
    v6 = v5;
    out_value = v5;
  }
  else
  {
    v6 = 0;
    out_value = 0;
  }
  v7 = vostok::math::align_down<unsigned __int64>(in_out_unmanaged_resource_buffer.m_size - 432, 0x124u);
  ((void (__thiscall *)(vostok::particle::engine *, char *, _DWORD, _DWORD, const char *))v6[66].destroy)(
    &v6[66],
    in_out_unmanaged_resource_buffer.m_data + 432,
    v7,
    HIDWORD(v7),
    "particle_world");
  v13 = 432;
  v12 = &vostok::resources::nocache_memory;
  v11.m_object = v8;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v11,
    (survarium::pure_game_effect_emitter_base *)out_value);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v9,
    in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.m_object,
    v12,
    v13);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v10,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
