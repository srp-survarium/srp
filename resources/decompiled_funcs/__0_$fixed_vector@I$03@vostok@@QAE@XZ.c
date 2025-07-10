void __thiscall vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(
        vostok::fixed_vector<unsigned int,4> *this)
{
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(this, (unsigned int *)this->m_buffer, 4u, 0);
}
