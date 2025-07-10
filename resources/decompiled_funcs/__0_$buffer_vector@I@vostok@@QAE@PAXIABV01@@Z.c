void __thiscall vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int *buffer,
        unsigned int max_count,
        const vostok::buffer_vector<unsigned int> *other)
{
  unsigned int *end; // [esp+18h] [ebp-4h] BYREF

  this->m_begin = buffer;
  this->m_end = buffer;
  end = other->m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    this,
    other->m_begin,
    (const unsigned int *const *)&end);
}
