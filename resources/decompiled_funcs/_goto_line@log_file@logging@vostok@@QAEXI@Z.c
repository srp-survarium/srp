void __thiscall vostok::logging::log_file::goto_line(vostok::logging::log_file *this, unsigned int line)
{
  survarium::game_camera *v2; // ecx
  unsigned int v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  _BYTE *v6; // eax
  vostok::fixed_vector<int,4096> *v8; // [esp+4h] [ebp-24h]
  vostok::fixed_vector<int,4096> *v9; // [esp+Ch] [ebp-1Ch]
  vostok::fixed_vector<int,4096> *v10; // [esp+14h] [ebp-14h]
  unsigned int num2skip; // [esp+1Ch] [ebp-Ch]
  unsigned int group; // [esp+20h] [ebp-8h]

  vostok::logging::log_file::assert_transaction_in_current_thread(this);
  survarium::weapon_user_dead_state::finalize(v2);
  group = line >> 8;
  v10 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
          (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)(line >> 8),
          (int)this->m_line_groups.m_static_memory);
  v3 = v10->m_end - v10->m_begin;
  if ( line >> 8 >= v3 )
  {
    v9 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
           (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)v3,
           (int)this->m_line_groups.m_static_memory);
    v3 = v9->m_end - v9->m_begin - 1;
    group = v3;
  }
  v8 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
         (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)v3,
         (int)this->m_line_groups.m_static_memory);
  survarium::weapon_user_dead_state::finalize(v4);
  this->m_current_pos = v8->m_begin[group];
  vostok::fs_new::device_file_system_proxy_base::seek(
    &this->m_device.m_device,
    this->m_file,
    this->m_current_pos,
    seek_file_begin);
  survarium::weapon_user_dead_state::finalize(v5);
  if ( *v6 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v6);
  for ( num2skip = line - (group << 8); num2skip; --num2skip )
    vostok::logging::log_file::skip_next_line(this);
}
