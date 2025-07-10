vostok::variant<32> *__usercall vostok::buffer_vector<vostok::variant<32>>::operator[]@<eax>(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        unsigned int index@<eax>)
{
  return &this->m_begin[index];
}
