void __thiscall vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(
        vostok::fixed_vector<unsigned int,4> *this,
        const vostok::fixed_vector<unsigned int,4> *other)
{
  unsigned int *end; // [esp+18h] [ebp-8h] BYREF
  unsigned int *m_buffer; // [esp+1Ch] [ebp-4h]

  m_buffer = (unsigned int *)this->m_buffer;
  this->m_begin = (unsigned int *)this->m_buffer;
  this->m_end = m_buffer;
  end = other->m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    this,
    other->m_begin,
    (const unsigned int *const *)&end);
}
