void __thiscall vostok::fs_new::path_part_iterator::append_to_string<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::path_part_iterator *this,
        vostok::fs_new::virtual_path_string *out_string)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_cur_str != this->m_cur_end )
    vostok::buffer_string::append(
      &out_string->m_string,
      (char *)&this->m_cur_str[*this->m_cur_str == this->m_separator],
      this->m_cur_end);
}
