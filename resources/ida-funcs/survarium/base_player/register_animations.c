void __userpurge survarium::base_player::register_animations(
        survarium::base_player *this@<ecx>,
        int a2@<esi>,
        survarium::animations_registry *animations_registry)
{
  const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *v6; // eax
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+8h] [ebp-4h] BYREF

  v3 = *(const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> **)(a2 + 268);
  if ( v3[75].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v4 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>,survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
           v3 + 75,
           (vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *)&v7);
    v4->m_object->register_animations(&v4->m_object->survarium::interactive_object, animations_registry);
    vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  }
  v5 = *(const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> **)(a2 + 268);
  if ( v5[78].m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>,survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
             v5 + 78,
             (vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *)&v7);
      v6->m_object->register_animations(&v6->m_object->survarium::interactive_object, animations_registry);
      vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
    }
  }
}
