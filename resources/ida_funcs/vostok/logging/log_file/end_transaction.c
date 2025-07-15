void __thiscall vostok::logging::log_file::end_transaction(vostok::logging::log_file *this)
{
  vostok::logging::log_file::assert_transaction_in_current_thread(this);
  this->m_transaction_thread_id = -1;
  vostok::threading::mutex::unlock(&this->m_log_mutex);
}
