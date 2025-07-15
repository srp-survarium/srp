LARGE_INTEGER dynamic_initializer_for__vostok::resources::quality_increase_functionality::s_tick_timer__()
{
  LARGE_INTEGER result; // rax

  result = vostok::timing::get_QPC();
  vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = result.QuadPart;
  vostok::resources::quality_increase_functionality::s_tick_timer.m_time_factor = s_bm_current_air_resistance;
  vostok::resources::quality_increase_functionality::s_tick_timer.m_backup_time_factor = s_bm_current_air_resistance;
  return result;
}
