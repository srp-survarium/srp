void vostok::logging::append(
        const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *log_callback,
        void *const user_data,
        const vostok::logging::log_format *log_format,
        const char *file,
        unsigned int line,
        const char *function_signature,
        char *initiator_raw,
        vostok::logging::verbosity verbosity,
        char *format,
        ...)
{
  unsigned int v9; // kr00_4
  void *v10; // esp
  vostok::logging::path_parts **v11; // eax
  vostok::logging::logger *v12; // ecx
  char v13[8]; // [esp+0h] [ebp-254h] BYREF
  vostok::logging::logger v14; // [esp+8h] [ebp-24Ch] BYREF
  va_list va; // [esp+280h] [ebp+2Ch] BYREF

  va_start(va, format);
  v9 = strlen(initiator_raw);
  v10 = alloca(v9 + 2);
  vostok::strings::copy(v13, v9 + 2, initiator_raw);
  strcat_s(v13, v9 + 2, ":");
  vostok::logging::logger::logger(
    log_callback,
    log_format,
    &v14,
    user_data,
    file,
    line,
    function_signature,
    v13,
    verbosity);
  vostok::logging::logger::operator()(v12, v11, format, va);
}
