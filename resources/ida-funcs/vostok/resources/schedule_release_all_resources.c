BOOL vostok::resources::schedule_release_all_resources()
{
  _InterlockedOr(&vostok::resources::g_game_resources_manager.m_variable->m_data.flags.m_flags, 1u);
  return SetEvent(*(HANDLE *)s_resources_manager_buffer.m_resources_wakeup_event.m_event.m_event);
}
