unsigned int __thiscall vostok::logging::log_file::get_lines_count(vostok::logging::log_file *this)
{
  vostok::logging::log_file::assert_transaction_in_current_thread(this);
  return this->m_last_line;
}
