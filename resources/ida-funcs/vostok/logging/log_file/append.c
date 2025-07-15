void __thiscall vostok::logging::log_file::append(vostok::logging::log_file *this, char *data, unsigned int length)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  _BYTE *v7; // eax
  survarium::game_camera *v8; // ecx
  const char *v9; // eax
  vostok::fixed_vector<int,4096> *v10; // ecx
  survarium::game_camera *v11; // ecx
  unsigned int v12; // [esp+0h] [ebp-58h]
  vostok::fixed_vector<int,4096> *v14; // [esp+8h] [ebp-50h]
  unsigned int v15; // [esp+14h] [ebp-44h]
  vostok::fixed_vector<int,4096> *v16; // [esp+18h] [ebp-40h]
  int value; // [esp+28h] [ebp-30h] BYREF
  char v18; // [esp+2Fh] [ebp-29h]
  char v19; // [esp+30h] [ebp-28h]
  char v20; // [esp+31h] [ebp-27h]
  char v21; // [esp+32h] [ebp-26h]
  char v22; // [esp+33h] [ebp-25h]
  unsigned int line_groups_needed; // [esp+34h] [ebp-24h]
  const char *next_line; // [esp+38h] [ebp-20h]
  unsigned int line_length; // [esp+3Ch] [ebp-1Ch]
  unsigned __int64 pos; // [esp+40h] [ebp-18h]
  const char *last_symbol; // [esp+48h] [ebp-10h]
  bool seek_res; // [esp+4Fh] [ebp-9h]
  unsigned __int64 num_written; // [esp+50h] [ebp-8h]

  if ( length )
  {
    v22 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    v21 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    v20 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    seek_res = vostok::fs_new::device_file_system_proxy_base::seek(
                 &this->m_device.m_device,
                 this->m_file,
                 0,
                 seek_file_end);
    v19 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    if ( *v7 )
      survarium::weapon_user_dead_state::finalize(v6);
    pos = vostok::fs_new::device_file_system_proxy_base::tell(&this->m_device.m_device, this->m_file);
    num_written = vostok::fs_new::device_file_system_no_watcher_proxy::write(
                    &this->m_device.m_device,
                    this->m_file,
                    data,
                    length);
    v18 = 0;
    survarium::weapon_user_dead_state::finalize(v8);
    this->m_file_size += num_written;
    last_symbol = &data[length];
    while ( *data )
    {
      strchr(data, 0xAu);
      next_line = v9;
      if ( v9 )
        v12 = next_line - data + 1;
      else
        v12 = last_symbol - data;
      line_length = v12;
      pos += v12;
      if ( next_line )
      {
        line_groups_needed = (++this->m_last_line >> 8) + 1;
        v10 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
                (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)this,
                (int)this->m_line_groups.m_static_memory);
        if ( v10->m_end - v10->m_begin < line_groups_needed )
        {
          v16 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
                  (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)v10,
                  (int)this->m_line_groups.m_static_memory);
          v15 = v16->m_end - v16->m_begin;
          vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
            (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)v16,
            (int)this->m_line_groups.m_static_memory);
          if ( v15 < 0x1000 && !(this->m_last_line % 0x100) )
          {
            value = pos;
            v14 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
                    (vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *)0x100,
                    (int)this->m_line_groups.m_static_memory);
            survarium::weapon_user_dead_state::finalize(v11);
            vostok::buffer_vector<int>::construct(v14->m_end, &value);
            ++v14->m_end;
          }
        }
      }
      data += line_length;
    }
  }
}
