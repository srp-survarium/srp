void __userpurge stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 *__n,
        const unsigned __int8 *__val,
        const stlp_std::allocator<unsigned char> *__a)
{
  int v6; // edx
  unsigned __int8 *v7; // edi
  int i; // eax

  stlp_std::priv::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>(
    &this->_M_impl,
    (unsigned __int8 **)a2);
  v6 = *(_DWORD *)a2 + 17408;
  v7 = *(unsigned __int8 **)a2;
  for ( i = 17408; i > 0; --i )
    *v7++ = *__n;
  *(_DWORD *)(a2 + 4) = v6;
}
