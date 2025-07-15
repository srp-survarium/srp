void __userpurge survarium::victory_item_core_base_state::victory_item_core_base_state(
        survarium::victory_item_core_base_state *this@<eax>,
        survarium::victory_item_core *item@<edx>,
        survarium::victory_item_state_id_enum id,
        vostok::animation::body_part_masks_enum body_part_mask_for_user)
{
  this->transitions.m_size = 0;
  this->transitions.m_first = 0;
  this->transitions.m_last = 0;
  this->m_item = item;
  this->__vftable = (survarium::victory_item_core_base_state_vtbl *)&survarium::victory_item_core_base_state::`vftable';
  this->m_body_part_mask_for_user = body_part_whole_body_but_hands;
  this->m_id = id;
  this->m_animation_has_been_ended = 0;
}
