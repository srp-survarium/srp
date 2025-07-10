stlp_std::reverse_iterator<unsigned int *> *__usercall stlp_std::reverse_iterator<unsigned int *>::operator++@<eax>(
        stlp_std::reverse_iterator<unsigned int *> *this@<ecx>,
        stlp_std::reverse_iterator<unsigned int *> *result@<eax>)
{
  --result->current;
  return result;
}
