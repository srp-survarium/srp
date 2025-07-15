void __thiscall survarium::victory_item_core_animation_end_aware_state::finalize(
        survarium::victory_item_core_animation_end_aware_state *this)
{
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (vostok::animation::reserved_channel_ids_enum)this->m_item->m_user,
    (const void *)1,
    (int)this);
  this->m_index_of_animation_to_wait = -1;
}
