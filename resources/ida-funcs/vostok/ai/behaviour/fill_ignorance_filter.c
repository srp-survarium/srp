void __thiscall vostok::ai::behaviour::fill_ignorance_filter(
        vostok::ai::behaviour *this,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *options,
        survarium::weapon_core_animation_end_aware_state *world)
{
  vostok::ai::planning::base_filter *filter; // eax
  const vostok::configs::binary_config_value *it_end; // [esp+18h] [ebp-8h]
  vostok::configs::binary_config_value *it; // [esp+1Ch] [ebp-4h]

  it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(options);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)options);
  while ( it != it_end )
  {
    filter = vostok::ai::create_filter(it, world);
    vostok::ai::pre_perceptors_filter::add_aux_filter(
      &this->m_ignorance_filter,
      (vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *)filter);
    ++it;
  }
}
