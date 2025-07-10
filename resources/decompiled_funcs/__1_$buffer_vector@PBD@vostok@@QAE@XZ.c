void __thiscall vostok::buffer_vector<char const *>::~buffer_vector<char const *>(
        vostok::buffer_vector<void const *> *this)
{
  const void **i; // [esp+4h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = this->m_begin;
}
