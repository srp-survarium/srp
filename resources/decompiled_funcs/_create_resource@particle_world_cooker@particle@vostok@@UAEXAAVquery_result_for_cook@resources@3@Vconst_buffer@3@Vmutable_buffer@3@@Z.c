void __thiscall vostok::particle::particle_world_cooker::create_resource(
        vostok::particle::particle_world_cooker *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::const_buffer raw_file_data,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  vostok::variant<32> *v4; // eax
  survarium::game_camera *v5; // ecx
  _BYTE *v6; // eax
  survarium::game_camera *v7; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // eax
  vostok::particle::particle_world *v10; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  const vostok::variant<32> **v12; // eax
  unsigned int v13; // ecx
  unsigned __int64 v14; // [esp-Ch] [ebp-34h] BYREF
  unsigned int v15; // [esp-4h] [ebp-2Ch]
  vostok::particle::particle_world *v16; // [esp+0h] [ebp-28h]
  vostok::particle::particle_world_cooker *thisa; // [esp+4h] [ebp-24h]
  unsigned __int64 value; // [esp+Ch] [ebp-1Ch]
  vostok::particle::particle_world *v19; // [esp+18h] [ebp-10h]
  char v20; // [esp+1Dh] [ebp-Bh]
  char v21; // [esp+1Eh] [ebp-Ah]
  bool result; // [esp+1Fh] [ebp-9h]
  vostok::particle::engine *engine; // [esp+20h] [ebp-8h] BYREF
  vostok::particle::particle_world *new_particle_world; // [esp+24h] [ebp-4h]

  thisa = this;
  engine = 0;
  v4 = vostok::resources::query_result_for_cook::user_data(
         (vostok::resources::query_result_for_cook *)this,
         (int)in_out_query);
  result = vostok::variant<32>::try_get<vostok::particle::engine *>(v4, &engine);
  v21 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  v7 = (survarium::game_camera *)(unsigned __int8)*v6;
  if ( *v6 )
  {
    v15 = result;
    HIDWORD(v14) = 0;
    survarium::weapon_user_dead_state::finalize(v7);
  }
  v20 = 0;
  survarium::weapon_user_dead_state::finalize(v7);
  v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         v8,
         (int)&in_out_unmanaged_resource_buffer);
  v19 = (vostok::particle::particle_world *)operator new(0x188u, v9);
  if ( v19 )
  {
    vostok::particle::particle_world::particle_world(v19, engine);
    v16 = v10;
  }
  else
  {
    v16 = 0;
  }
  new_particle_world = v16;
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x188, &in_out_unmanaged_resource_buffer);
  LODWORD(value) = in_out_unmanaged_resource_buffer.m_size;
  v14 = vostok::math::align_down<unsigned __int64>(in_out_unmanaged_resource_buffer.m_size, 0xD0u);
  v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          v11,
          (int)&in_out_unmanaged_resource_buffer);
  ((void (__thiscall *)(vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *, const vostok::variant<32> **, _DWORD, _DWORD, const char *))new_particle_world->m_allocator.initialize)(
    &new_particle_world->m_allocator,
    v12,
    v14,
    HIDWORD(v14),
    "particle_world");
  v15 = 392;
  v14 = __PAIR64__(&vostok::resources::nocache_memory, v13);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v14,
    (vostok::configs::binary_config *)new_particle_world);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    in_out_query,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v14,
    (const vostok::resources::memory_type *)HIDWORD(v14),
    v15);
  vostok::resources::query_result_for_cook::finish_query(in_out_query, result_success, assert_on_fail_true);
}
