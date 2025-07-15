void __thiscall vostok::logging::logger::operator()(
        vostok::logging::logger *this,
        vostok::logging::path_parts **format,
        char *const args,
        char *ap)
{
  char string[16388]; // [esp+10h] [ebp-4034h] BYREF
  _DWORD v5[9]; // [esp+4014h] [ebp-30h] BYREF
  vostok::logging::logger_predicate predicate; // [esp+4038h] [ebp-Ch] BYREF

  InterlockedIncrement(&s_log_disable_counter);
  vsnprintf_s(string, 0x4000u, 0x3FFFu, args, ap);
  vostok::logging::path_parts::path_parts(format[141], v5);
  predicate.m_path = (vostok::logging::path_parts *)v5;
  predicate.m_helper = (const vostok::logging::logger *)format;
  vostok::strings::iterate_items<vostok::logging::logger_predicate,char *>(string, strlen(string), &predicate);
  v5[1] = v5[0];
  InterlockedDecrement(&s_log_disable_counter);
}
