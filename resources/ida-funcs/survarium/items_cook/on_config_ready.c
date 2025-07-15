void __userpurge survarium::items_cook::on_config_ready(
        survarium::items_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::configs::binary_config *v9; // ecx
  vostok::configs::binary_config_value *root; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  vostok::configs::binary_config *v13; // ecx
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v14; // [esp-8h] [ebp-58h] BYREF
  vostok::resources::query_result_for_cook *v15; // [esp-4h] [ebp-54h]
  survarium::items_cook *thisa; // [esp+4h] [ebp-4Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v17; // [esp+28h] [ebp-28h] BYREF
  char v18; // [esp+2Fh] [ebp-21h]
  survarium::item_types_enum item_type; // [esp+30h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+34h] [ebp-1Ch] BYREF
  vostok::configs::binary_config_value current; // [esp+38h] [ebp-18h] BYREF

  thisa = this;
  v18 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v4 = vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v5,
                         (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v4,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &config);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
  v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&config);
  root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v9, (int)v8);
  current = *vostok::configs::binary_config_value::operator[](root, "data");
  v11 = vostok::configs::binary_config_value::operator[](&current, "type");
  item_type = (survarium::item_types_enum)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                            v12,
                                            (int)v11);
  v15 = parent;
  v14.m_object = v13;
  boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &v14,
    &config);
  survarium::items_cook::create_item_and_finish_query(thisa, a2, item_type, v14, v15);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
}
