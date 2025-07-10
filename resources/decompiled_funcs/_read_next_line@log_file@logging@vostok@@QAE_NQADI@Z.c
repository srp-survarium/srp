char __thiscall vostok::logging::log_file::read_next_line(
        vostok::logging::log_file *this,
        char *const buffer,
        unsigned int buffer_size)
{
  vostok::logging::processor processor; // [esp+Ch] [ebp-4h] BYREF

  vostok::logging::log_file::assert_transaction_in_current_thread(this);
  processor.buffer_ptr = buffer;
  return vostok::logging::log_file::process_next_line<vostok::logging::processor>(this, buffer_size, &processor);
}
