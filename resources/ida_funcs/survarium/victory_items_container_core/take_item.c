survarium::victory_item_core *__thiscall survarium::victory_items_container_core::take_item(
        survarium::victory_items_container_core *this)
{
  boost::arg<1> *result; // [esp+Ch] [ebp-8h]
  survarium::victory_item_core *last_item; // [esp+10h] [ebp-4h]

  result = (boost::arg<1> *)&(&stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                 (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
                                 (int)&this->m_victory_items)[-1].object)[1];
  last_item = *(survarium::victory_item_core **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)--this->m_victory_items._M_impl._M_finish);
  return last_item;
}
