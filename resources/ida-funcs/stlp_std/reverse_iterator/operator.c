unsigned int *__usercall stlp_std::reverse_iterator<unsigned int *>::operator*@<eax>(
        stlp_std::reverse_iterator<unsigned int *> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return (unsigned int *)(*a2 - 4);
}


vostok::variant<32> *__thiscall stlp_std::reverse_iterator<vostok::variant<32> *>::operator*(
        stlp_std::reverse_iterator<vostok::variant<32> *> *this)
{
  return this->current - 1;
}


stlp_std::reverse_iterator<unsigned int *> *__usercall stlp_std::reverse_iterator<unsigned int *>::operator++@<eax>(
        stlp_std::reverse_iterator<unsigned int *> *this@<ecx>,
        stlp_std::reverse_iterator<unsigned int *> *result@<eax>)
{
  --result->current;
  return result;
}
