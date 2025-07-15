char __thiscall vostok::logging::log_file::skip_next_line(vostok::logging::log_file *this)
{
  void (__cdecl *processor)(char); // [esp+Ch] [ebp-4h] BYREF

  processor = (void (__cdecl *)(char))vostok::logging::log_file::skip_next_line_::_2_::processor::dummy;
  return vostok::logging::log_file::process_next_line<void (__cdecl *)(char)>(this, 0, &processor);
}
