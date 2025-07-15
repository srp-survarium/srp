LARGE_INTEGER vostok::render::_dynamic_initializer_for__s_timer__()
{
  LARGE_INTEGER result; // rax

  result = vostok::timing::get_QPC();
  s_timer.m_start_time = result.QuadPart;
  s_timer.m_time_factor = s_bm_current_air_resistance;
  s_timer.m_backup_time_factor = s_bm_current_air_resistance;
  return result;
}
