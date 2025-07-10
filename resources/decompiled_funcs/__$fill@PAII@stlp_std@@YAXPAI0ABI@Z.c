void __usercall stlp_std::fill<unsigned int *,unsigned int>(
        unsigned int *__last@<eax>,
        unsigned int *__val@<edx>,
        unsigned int *__first)
{
  unsigned int *v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}
