void __thiscall vostok::logging::log_file::~log_file(vostok::logging::log_file *this)
{
  vostok::threading::mutex *v1; // ecx
  survarium::game_camera *v2; // ecx

  vostok::logging::log_file::close(this);
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::destroy(&this->m_line_groups);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_log_mutex);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&this->m_device);
  survarium::weapon_user_dead_state::finalize(v2);
}
