void __userpurge survarium::weapon_ammunition_cook::on_config_ready(
        survarium::weapon_ammunition_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  survarium::game_camera *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  survarium::weapon_ammunition *v10; // eax
  const vostok::variant<32> **v11; // eax
  vostok::configs::binary_config *v12; // ecx
  vostok::configs::binary_config_value *root; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::resources::memory_usage_type *v15; // eax
  vostok::resources::unmanaged_resource *v16; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v17[2]; // [esp-4h] [ebp-44h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-3Ch]
  survarium::weapon_ammunition *v19; // [esp+8h] [ebp-38h]
  survarium::weapon_ammunition_cook *thisa; // [esp+Ch] [ebp-34h]
  void *_Where; // [esp+14h] [ebp-2Ch]
  vostok::memory::doug_lea_allocator *v22; // [esp+18h] [ebp-28h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v23; // [esp+24h] [ebp-1Ch] BYREF
  survarium::weapon_ammunition *v24; // [esp+2Ch] [ebp-14h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v25; // [esp+30h] [ebp-10h] BYREF
  char v26; // [esp+37h] [ebp-9h]
  survarium::weapon_ammunition *wa; // [esp+38h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+3Ch] [ebp-4h] BYREF

  thisa = this;
  v26 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v4 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v5,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &config);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v25);
  survarium::weapon_user_dead_state::finalize(v7);
  v22 = v8;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v8, 0x148u);
  v24 = (survarium::weapon_ammunition *)operator new(0x148u, _Where);
  if ( v24 )
  {
    survarium::weapon_ammunition::weapon_ammunition(v24);
    v19 = v10;
  }
  else
  {
    v19 = 0;
  }
  wa = v19;
  v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)&config);
  root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v12, (int)v11);
  v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](root, "data");
  survarium::weapon_ammunition::load(wa, a2, v14);
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v23,
    (vostok::network_core::packet_reader *)0x148,
    (vostok::network_core::packet_reader *)v17[1].m_object);
  memory_usage = v15;
  v17[0].m_object = v16;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v17,
    (vostok::configs::binary_config *)wa);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(memory_usage, parent, v17[0]);
  vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
}
