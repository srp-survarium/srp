void __usercall vostok::resources::quality_increase_functionality::quality_increase_functionality(
        vostok::resources::quality_increase_functionality *this@<esi>,
        vostok::resources::game_resources_manager_data *data@<eax>)
{
  bool v2; // zf
  LARGE_INTEGER QPC; // rax

  v2 = !vostok::resources::quality_increase_functionality::s_started_tick_timer;
  this->m_data = data;
  if ( v2 )
  {
    vostok::resources::quality_increase_functionality::s_started_tick_timer = 1;
    QPC = vostok::timing::get_QPC();
    vostok::resources::quality_increase_functionality::s_tick_timer.m_current_time = 0;
    vostok::resources::quality_increase_functionality::s_tick_timer.m_start_time = QPC.QuadPart;
  }
}
