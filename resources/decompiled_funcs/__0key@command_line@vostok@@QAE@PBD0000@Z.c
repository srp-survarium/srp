void __thiscall vostok::command_line::key::key(
        vostok::command_line::key *this,
        const char *full_name,
        const char *short_name,
        const char *category,
        const char *description,
        const char *argument_description)
{
  this->m_string_value.m_begin = this->m_string_value.m_buffer;
  this->m_string_value.m_end = this->m_string_value.m_buffer;
  this->m_string_value.m_max_end = (char *)&this->m_number_value;
  this->m_string_value.m_buffer[0] = 0;
  this->m_string_value.m_buffer[0] = 0;
  this->m_full_name = full_name;
  this->m_short_name = short_name;
  this->m_number_value = 0.0;
  this->m_category = category;
  this->m_description = description;
  this->m_argument_description = argument_description;
  this->m_type = type_unset;
  vostok::debug::protected_call((void (__cdecl *)(void *))vostok::command_line::protected_key_construct, this);
}
