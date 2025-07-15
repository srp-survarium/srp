void __thiscall survarium::game::on_waiting_for_render(survarium::game *this, unsigned int __formal)
{
  vostok::journaling::journal *v3; // ecx
  unsigned int v4; // eax
  vostok::journaling::journal *v5; // ecx
  vostok::fs_new::device_file_system_no_watcher_proxy *v6; // ecx
  vostok::journaling::data_chunk_type_enum v7; // [esp+0h] [ebp-18h]
  unsigned int elapsed_msec; // [esp+10h] [ebp-8h] BYREF
  vostok::journaling::reader *v9; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_network_client )
  {
    if ( vostok::core::journal_usage() == replay_journal )
    {
      while ( 1 )
      {
        vostok::journaling::journal::try_start_reading(
          v3,
          (int)vostok::core::g_journal.m_variable,
          &v9,
          (vostok::journaling::reader_ptr *)2,
          v7);
        if ( !v9 )
          break;
        v4 = vostok::journaling::reader::r<unsigned int>(v9);
        this->m_network_client->on_idle(this->m_network_client, v4);
      }
    }
    else
    {
      elapsed_msec = vostok::timing::floating_timer::get_elapsed_msec(
                       (vostok::timing::floating_timer *)v3,
                       &this->m_timer);
      if ( vostok::core::journal_usage() == record_journal && this->m_active_scene == &this->m_game_world )
      {
        vostok::journaling::journal::start_writing(
          v5,
          (int)vostok::core::g_journal.m_variable,
          &v9,
          (vostok::journaling::writer_ptr *)2,
          v7);
        vostok::fs_new::device_file_system_no_watcher_proxy::write(
          v6,
          &v9->m_device->m_device_file_system,
          v9->m_file,
          &elapsed_msec,
          4u);
      }
      this->m_network_client->on_idle(this->m_network_client, elapsed_msec);
    }
  }
}
