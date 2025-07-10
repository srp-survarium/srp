const vostok::fixed_string<260> *__usercall vostok::fixed_string<260>::operator=<vostok::configs::binary_config_value>@<eax>(
        vostok::fixed_string<260> *this@<esi>,
        const vostok::configs::binary_config_value *src@<eax>)
{
  const char *pointer; // ecx
  char *m_begin; // eax

  pointer = (const char *)src->data.pointer;
  m_begin = this->m_begin;
  this->m_end = this->m_begin;
  *m_begin = 0;
  vostok::buffer_string::operator+=(this, pointer);
  return this;
}
