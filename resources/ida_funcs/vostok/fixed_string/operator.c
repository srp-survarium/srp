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


const vostok::fixed_string<16> *__usercall vostok::fixed_string<16>::operator=@<eax>(
        vostok::fixed_string<16> *this@<ecx>,
        vostok::buffer_string *a2@<esi>)
{
  char *m_begin; // eax

  m_begin = a2->m_begin;
  if ( (vostok::fixed_string<16> *)a2->m_begin != this )
  {
    a2->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(a2, (const char *)this);
  }
  return (const vostok::fixed_string<16> *)a2;
}


const vostok::fixed_string<260> *__thiscall vostok::fixed_string<260>::operator=(
        vostok::fixed_string<260> *this,
        vostok::fixed_string<260> *src)
{
  if ( this != src )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)src, (vostok::fixed_string<32> *)this);
  return this;
}


const vostok::fixed_string<2048> *__thiscall vostok::fixed_string<2048>::operator=(
        vostok::fixed_string<2048> *this,
        char *src)
{
  char *m_begin; // eax

  m_begin = this->m_begin;
  if ( this->m_begin != src )
  {
    this->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(this, src);
  }
  return this;
}
