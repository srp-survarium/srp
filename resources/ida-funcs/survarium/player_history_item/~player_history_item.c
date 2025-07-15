void __thiscall survarium::player_history_item::~player_history_item(survarium::player_history_item *this)
{
  survarium::player_serialized_state *v2; // ecx
  survarium::player_serialized_state *v3; // ecx

  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->animation_tree);
  survarium::player_serialized_state::~player_serialized_state(
    v2,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->client_specific_state);
  survarium::player_serialized_state::~player_serialized_state(
    v3,
    (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)this);
}
