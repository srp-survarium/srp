char __thiscall vostok::ai::planning::sound_filter::contains_object(
        vostok::ai::planning::sound_filter *this,
        const vostok::fs_new::virtual_path_string *item)
{
  vostok::ai::list<vostok::fs_new::virtual_path_string> *iter; // [esp+3Ch] [ebp-4h]

  for ( iter = (vostok::ai::list<vostok::fs_new::virtual_path_string> *)this->m_filtered_items._M_impl._M_node._M_data._M_next;
        iter != &this->m_filtered_items;
        iter = (vostok::ai::list<vostok::fs_new::virtual_path_string> *)iter->_M_impl._M_node._M_data._M_next )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(iter != &this->m_filtered_items));
    if ( vostok::operator==((vostok::fs_new::path_string_impl *)&iter[1], &item->vostok::fs_new::path_string_impl) )
      return 1;
  }
  return 0;
}
