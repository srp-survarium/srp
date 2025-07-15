void __thiscall vostok::particle::particle_system_cook::create_resource(
        vostok::particle::particle_system_cook *this,
        vostok::resources::query_result_for_cook *in_out_query,
        vostok::mutable_buffer in_out_unmanaged_resource_buffer)
{
  const vostok::variant<32> **v3; // eax
  vostok::resources::unmanaged_resource *v4; // edx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v5; // [esp-Ch] [ebp-40h] BYREF
  const vostok::resources::memory_type *v6; // [esp-8h] [ebp-3Ch]
  unsigned int v7; // [esp-4h] [ebp-38h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // [esp+0h] [ebp-34h]
  vostok::particle::particle_system_cook *thisa; // [esp+4h] [ebp-30h]
  unsigned int resource_size; // [esp+Ch] [ebp-28h]
  unsigned int m_size; // [esp+10h] [ebp-24h]
  vostok::resources::unmanaged_resource *v12; // [esp+14h] [ebp-20h]
  vostok::resources::unmanaged_resource *v13; // [esp+1Ch] [ebp-18h]
  unsigned int data_size; // [esp+20h] [ebp-14h]
  vostok::mutable_buffer load_buffer; // [esp+24h] [ebp-10h] BYREF
  vostok::particle::particle_system *system; // [esp+2Ch] [ebp-8h]
  void *data_buffer; // [esp+30h] [ebp-4h]

  thisa = this;
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&in_out_unmanaged_resource_buffer);
  v13 = (vostok::resources::unmanaged_resource *)operator new(0x118u, v3);
  if ( v13 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v13, 1u);
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13[1]);
    v13->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::particle::particle_system::`vftable';
    v12 = v13 + 1;
    v4 = v13 + 1;
    v13[1].__vftable = 0;
    v4->type = 0;
    v8 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v13;
  }
  else
  {
    v8 = 0;
  }
  system = (vostok::particle::particle_system *)v8;
  m_size = in_out_unmanaged_resource_buffer.m_size;
  data_size = in_out_unmanaged_resource_buffer.m_size - 280;
  data_buffer = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v8,
                  (int)&in_out_unmanaged_resource_buffer)
              + 70;
  load_buffer.m_data = (char *)data_buffer;
  load_buffer.m_size = data_size;
  vostok::particle::particle_system::load_binary((vostok::particle::particle_system *)v8, &load_buffer);
  resource_size = in_out_unmanaged_resource_buffer.m_size;
  v7 = in_out_unmanaged_resource_buffer.m_size;
  v6 = &vostok::resources::unmanaged_memory;
  v5.m_object = (vostok::resources::unmanaged_resource *)in_out_unmanaged_resource_buffer.m_size;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v5,
    (vostok::configs::binary_config *)system);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(in_out_query, v5, v6, v7);
  vostok::resources::query_result_for_cook::finish_query(in_out_query, result_success, assert_on_fail_true);
}
