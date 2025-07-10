void __thiscall stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this,
        unsigned __int16 *__pos,
        unsigned int __n,
        unsigned __int16 *__x,
        const stlp_std::__false_type *__formal)
{
  unsigned __int16 *v6; // ecx
  unsigned __int16 *v7; // ebx
  unsigned __int16 *M_finish; // esi
  unsigned int v9; // edi
  signed int v10; // eax
  int j; // eax
  unsigned __int16 *v12; // edx
  int v13; // eax
  unsigned __int16 *v14; // ecx
  int v15; // esi
  unsigned __int16 *i; // eax
  int __x_copy; // [esp+4h] [ebp-4h] BYREF

  v6 = __x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    v7 = __pos;
    M_finish = this->_M_finish;
    v9 = M_finish - __pos;
    if ( v9 <= __n )
    {
      v12 = &M_finish[__n - v9];
      v13 = (int)(2 * (__n - v9)) >> 1;
      v14 = this->_M_finish;
      if ( v13 > 0 )
      {
        do
        {
          *v14 = *__x;
          --v13;
          ++v14;
        }
        while ( v13 > 0 );
        v12 = &M_finish[__n - v9];
      }
      this->_M_finish = v12;
      if ( M_finish != __pos )
        memcpy((unsigned __int8 *)v12, (unsigned __int8 *)__pos, (char *)M_finish - (char *)__pos);
      this->_M_finish += v9;
      v15 = M_finish - __pos;
      for ( i = __pos; v15 > 0; ++i )
      {
        *i = *__x;
        --v15;
      }
    }
    else
    {
      v10 = 2 * __n;
      if ( M_finish != &M_finish[-__n] )
      {
        memcpy((unsigned __int8 *)M_finish, (unsigned __int8 *)&M_finish[v10 / 0xFFFFFFFE], v10);
        v10 = 2 * __n;
        v6 = __x;
      }
      this->_M_finish = (unsigned __int16 *)((char *)this->_M_finish + v10);
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
      {
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
        v10 = 2 * __n;
        v6 = __x;
      }
      for ( j = v10 >> 1; j > 0; ++v7 )
      {
        *v7 = *v6;
        --j;
      }
    }
  }
  else
  {
    __x_copy = *__x;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      (const unsigned __int16 *)&__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}
