void __userpurge vostok::logging::logger::logger(
        const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *log_callback@<eax>,
        const vostok::logging::log_format *const log_format@<ecx>,
        vostok::logging::logger *this,
        void *const user_data,
        const char *file,
        unsigned int line,
        const char *function_signature,
        const char *initiator,
        vostok::logging::verbosity verbosity)
{
  this->m_log_callback = log_callback;
  this->m_user_data = user_data;
  this->m_initiator = initiator;
  this->m_file = file;
  this->m_function_signature = function_signature;
  this->m_line = line;
  this->m_log_format_ptr = log_format;
  this->m_verbosity = verbosity;
  if ( log_format )
    qmemcpy(this, log_format, 0x228u);
  else
    vostok::logging::log_format::set(
      (vostok::logging::log_format *)&vostok::logging::format_message,
      this->m_log_format.string);
}
