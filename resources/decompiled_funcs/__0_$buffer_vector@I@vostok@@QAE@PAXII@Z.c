void __thiscall vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
}
