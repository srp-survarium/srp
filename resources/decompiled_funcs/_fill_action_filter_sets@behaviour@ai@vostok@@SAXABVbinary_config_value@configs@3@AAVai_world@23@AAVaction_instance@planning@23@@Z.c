void __cdecl vostok::ai::behaviour::fill_action_filter_sets(
        vostok::configs::binary_config_value *options,
        survarium::weapon_core_animation_end_aware_state *world,
        vostok::ai::planning::action_instance *owner)
{
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *parameters_filters; // [esp+10h] [ebp-14h]
  vostok::configs::binary_config_value *filters; // [esp+18h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+1Ch] [ebp-8h]
  vostok::configs::binary_config_value *it; // [esp+20h] [ebp-4h]

  if ( vostok::configs::binary_config_value::value_exists(options, "filter_sets") )
  {
    filters = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        options,
                                                        "filter_sets");
    it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)filters);
    it_end = vostok::configs::binary_config_value::end(filters);
    while ( it != it_end )
    {
      parameters_filters = vostok::ai::create_parameters_filters(it, world);
      vostok::ai::planning::action_instance::add_filters_list(owner, parameters_filters);
      ++it;
    }
  }
}
