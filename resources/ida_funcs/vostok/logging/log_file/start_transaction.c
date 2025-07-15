void __thiscall vostok::logging::log_file::start_transaction(vostok::logging::log_file *this)
{
  survarium::game_camera *v1; // ecx

  vostok::threading::mutex::lock(&this->m_log_mutex);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_transaction_thread_id = vostok::threading::current_thread_id();
}
