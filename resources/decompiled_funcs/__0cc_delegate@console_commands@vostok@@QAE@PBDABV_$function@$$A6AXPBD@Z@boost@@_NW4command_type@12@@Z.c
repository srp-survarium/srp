void __userpurge vostok::console_commands::cc_delegate::cc_delegate(
        vostok::console_commands::cc_delegate *this@<edi>,
        const char *name@<edx>,
        boost::function4<void,unsigned int,float,float,char const *> *functor,
        bool need_args,
        vostok::console_commands::command_type command_type)
{
  vostok::console_commands::console_command *m_prev; // eax

  this->m_prev = vostok::console_commands::s_console_command_root;
  this->m_command_type = command_type;
  this->m_execution_type = execution_filter_general;
  this->m_serializable = 1;
  this->__vftable = (vostok::console_commands::cc_delegate_vtbl *)stru_95AF78.m_key_bindings[37].m_keyboard;
  this->m_next = 0;
  this->m_name = name;
  this->m_need_args = 0;
  this->m_on_change_event.vtable = 0;
  m_prev = this->m_prev;
  if ( m_prev )
    m_prev->m_next = this;
  vostok::console_commands::s_console_command_root = this;
  this->__vftable = (vostok::console_commands::cc_delegate_vtbl *)&stru_95AF78.m_key_bindings[40];
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    functor,
    (int)&this->m_functor);
  this->m_need_args = need_args;
}
