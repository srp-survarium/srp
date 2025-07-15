void __userpurge survarium::victory_items_container::victory_items_container(
        survarium::victory_items_container *this@<ecx>,
        unsigned int transforms_count@<eax>,
        vostok::physics::world *physics_world,
        survarium::gather_victory_items_rule *rule,
        const vostok::configs::binary_config_value *cfg,
        const survarium::victory_items_container::victory_item_transform *victory_item_transforms)
{
  survarium::gather_victory_items_rule *v8; // edi
  const survarium::victory_items_container::victory_item_transform *v9; // [esp-4h] [ebp-Ch]

  survarium::victory_items_container_core::victory_items_container_core(this, (int)this, physics_world, rule, cfg);
  v9 = victory_item_transforms;
  v8 = (survarium::gather_victory_items_rule *)&victory_item_transforms[transforms_count];
  this->survarium::victory_items_container_core::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_items_container_vtbl *)&survarium::victory_items_container::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::victory_items_container_core::survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_items_container::`vftable'{for `survarium::link_resolver'};
  this->survarium::victory_items_container_core::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::victory_items_container::`vftable';
  this->m_victory_item_transforms.m_begin = (survarium::victory_items_container::victory_item_transform *)this->m_victory_item_transforms.m_buffer;
  this->m_victory_item_transforms.m_end = (survarium::victory_items_container::victory_item_transform *)this->m_victory_item_transforms.m_buffer;
  this->m_victory_item_transforms.m_max_end = (survarium::victory_items_container::victory_item_transform *)(&this->m_victory_item_transforms + 1);
  cfg = (const vostok::configs::binary_config_value *)this->m_victory_item_transforms.m_end;
  rule = v8;
  vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::insert<survarium::victory_items_container::victory_item_transform const *>(
    (const survarium::victory_items_container::victory_item_transform *const *)&rule,
    &this->m_victory_item_transforms,
    (survarium::victory_items_container::victory_item_transform **)&cfg,
    v9);
}
