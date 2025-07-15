void __thiscall survarium::network_client::process_set_time_request(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *reader)
{
  vostok::network_core::buffer_reader *v2; // ebx
  survarium::player *m_object; // esi
  vostok::network_core::buffer_reader *v4; // edx
  const unsigned __int8 *m_buffer; // edi
  double v6; // st7
  unsigned __int64 v7; // rax
  int v8; // edi
  vostok::timing::floating_timer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  void (__fastcall **v12)(const unsigned __int8 *, _DWORD, _DWORD); // edi
  vostok::timing::timer *v13; // ecx
  unsigned __int64 elapsed_msec; // rax
  vostok::command_line::key *v15; // ecx
  float time_factor_4; // [esp+4h] [ebp-18h]
  vostok::network_core::buffer_reader *v17; // [esp+18h] [ebp-4h] BYREF

  v2 = reader;
  m_object = this->m_current_player.m_object;
  reader = (vostok::network_core::buffer_reader *)m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  v4 = reader;
  this->m_current_player.m_object = (survarium::player *)&m_object->type;
  m_object = (survarium::player *)((char *)m_object + 4);
  reader = (vostok::network_core::buffer_reader *)m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  this->m_current_player.m_object = (survarium::player *)&m_object->type;
  m_buffer = v2[2].m_buffer;
  v6 = *((float *)m_buffer + 12);
  v17 = v4;
  time_factor_4 = v6;
  vostok::timing::floating_timer::set_time_factor_impl(
    (vostok::timing::floating_timer *)this,
    (int)(m_buffer + 16),
    *((float *)m_buffer + 10),
    time_factor_4);
  v7 = *(_QWORD *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8)
     * (unsigned __int64)(unsigned int)reader
     / 0x3E8;
  *((_DWORD *)m_buffer + 4) = v7;
  LODWORD(v7) = reader;
  *((_DWORD *)m_buffer + 5) = HIDWORD(v7);
  *((_DWORD *)m_buffer + 3492) = v7;
  v8 = (*(int (__thiscall **)(const unsigned __int8 *, int))(*(_DWORD *)v2[1147].m_pointer + 24))(
         v2[1147].m_pointer,
         68);
  reader = (vostok::network_core::buffer_reader *)vostok::timing::floating_timer::get_elapsed_msec(
                                                    v9,
                                                    (vostok::timing::floating_timer *)(v2[2].m_buffer + 16));
  vostok::network_core::buffer_writer::w(v10, (_DWORD *)(v8 + 1340), (unsigned __int8 *)&v17, 4u);
  vostok::network_core::buffer_writer::w(v11, (_DWORD *)(v8 + 1340), (unsigned __int8 *)&reader, 4u);
  (*(void (__thiscall **)(const unsigned __int8 *, int))(*(_DWORD *)v2[1147].m_pointer + 28))(v2[1147].m_pointer, v8);
  v12 = (void (__fastcall **)(const unsigned __int8 *, _DWORD, _DWORD))(*(_DWORD *)v2[1147].m_pointer + 32);
  elapsed_msec = vostok::timing::timer::get_elapsed_msec(v13, (int)(v2[2].m_buffer + 64));
  (*v12)(v2[1147].m_pointer, HIDWORD(elapsed_msec), elapsed_msec);
  if ( !v2[1724].m_buffer_size && vostok::core::journal_usage() == replay_journal )
  {
    while ( !v2[1724].m_buffer_size )
    {
      vostok::resources::dispatch_callbacks(v15);
      vostok::threading::yield(0xAu);
    }
  }
  survarium::game_world_core::clear((survarium::game_world_core *)v15, *(_DWORD *)(v2[1724].m_buffer_size + 312));
}
