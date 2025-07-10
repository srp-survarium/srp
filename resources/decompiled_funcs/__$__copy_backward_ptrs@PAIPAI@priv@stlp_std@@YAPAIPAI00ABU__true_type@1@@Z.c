void __usercall stlp_std::priv::__copy_backward_ptrs<unsigned int *,unsigned int *>(
        char *__last@<ecx>,
        unsigned __int8 *__result@<eax>,
        unsigned int *__first)
{
  signed int v3; // ecx

  v3 = __last - (char *)__first;
  if ( v3 > 0 )
    memmove(&__result[-v3], (unsigned __int8 *)__first, v3);
}
