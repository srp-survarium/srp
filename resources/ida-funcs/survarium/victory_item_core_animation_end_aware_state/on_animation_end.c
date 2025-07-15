vostok::animation::callback_return_type_enum __thiscall survarium::victory_item_core_animation_end_aware_state::on_animation_end(
        survarium::victory_item_core_animation_end_aware_state *this,
        vostok::animation::animation_callback_params *params)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation; // edx
  survarium::victory_item_core_animation_end_aware_state_vtbl *v3; // edx

  animation = params->animation;
  params->interrupt_animation_player_tick = 0;
  if ( animation->m_object == this->m_animations_buffer[this->m_index_of_animation_to_wait].m_object )
  {
    v3 = this->__vftable;
    this->m_animation_has_been_ended = 1;
    ((void (__stdcall *)(bool *))v3->on_animation_end_impl)(&params->interrupt_animation_player_tick);
  }
  return 0;
}
