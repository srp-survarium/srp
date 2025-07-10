void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        vostok::variant<32> *__pos,
        unsigned int __n,
        const vostok::variant<32> *__x,
        const stlp_std::__false_type *__formal)
{
  int k; // [esp+C4h] [ebp-A4h]
  vostok::variant<32> *v6; // [esp+C8h] [ebp-A0h]
  int j; // [esp+CCh] [ebp-9Ch]
  vostok::variant<32> *v8; // [esp+D0h] [ebp-98h]
  vostok::variant<32> *v9; // [esp+D4h] [ebp-94h]
  int i; // [esp+E0h] [ebp-88h]
  vostok::variant<32> *v11; // [esp+E4h] [ebp-84h]
  vostok::variant<32> *v12; // [esp+E8h] [ebp-80h]
  int ii; // [esp+F0h] [ebp-78h]
  vostok::variant<32> *v14; // [esp+F4h] [ebp-74h]
  int n; // [esp+F8h] [ebp-70h]
  vostok::variant<32> *other; // [esp+FCh] [ebp-6Ch]
  vostok::variant<32> *v17; // [esp+100h] [ebp-68h]
  int m; // [esp+108h] [ebp-60h]
  vostok::variant<32> *__p; // [esp+10Ch] [ebp-5Ch]
  vostok::variant<32> *__val; // [esp+110h] [ebp-58h]
  vostok::variant<32> *M_finish; // [esp+124h] [ebp-44h]
  unsigned int v22; // [esp+128h] [ebp-40h]
  stlp_std::__false_type v23; // [esp+12Fh] [ebp-39h] BYREF
  vostok::variant<32> v24; // [esp+130h] [ebp-38h] BYREF
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *v26; // [esp+164h] [ebp-4h]

  v26 = this;
  if ( __x >= this->_M_start && __x < v26->_M_finish )
  {
    vostok::variant<32>::variant<32>(&v24, __x);
    v23 = 0;
    stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert_aux(
      v26,
      __pos,
      __n,
      &v24,
      &v23);
    vostok::variant<32>::~variant<32>(&v24);
  }
  else
  {
    v22 = v26->_M_finish - __pos;
    M_finish = v26->_M_finish;
    if ( v22 <= __n )
    {
      v12 = &v26->_M_finish[__n - v22];
      v11 = v26->_M_finish;
      for ( i = (int)(48 * (__n - v22)) / 48; i > 0; --i )
        stlp_std::_Copy_Construct<vostok::variant<32>>(v11++, __x);
      v26->_M_finish = v12;
      v9 = __pos;
      v8 = v26->_M_finish;
      for ( j = M_finish - __pos; j > 0; --j )
        stlp_std::_Copy_Construct<vostok::variant<32>>(v8++, v9++);
      v26->_M_finish += v22;
      v6 = __pos;
      for ( k = M_finish - __pos; k > 0; --k )
        vostok::variant<32>::operator=(v6++, __x);
    }
    else
    {
      __val = &v26->_M_finish[-__n];
      __p = v26->_M_finish;
      for ( m = __p - __val; m > 0; --m )
        stlp_std::_Copy_Construct<vostok::variant<32>>(__p++, __val++);
      v26->_M_finish += __n;
      v17 = M_finish;
      other = &M_finish[-__n];
      for ( n = other - __pos; n > 0; --n )
        vostok::variant<32>::operator=(--v17, --other);
      v14 = __pos;
      for ( ii = (int)(48 * __n) / 48; ii > 0; --ii )
        vostok::variant<32>::operator=(v14++, __x);
    }
  }
}
