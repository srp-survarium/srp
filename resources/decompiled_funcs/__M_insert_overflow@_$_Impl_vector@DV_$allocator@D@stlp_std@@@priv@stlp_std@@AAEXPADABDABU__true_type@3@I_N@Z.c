void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        const char *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  char *v7; // [esp+4h] [ebp-88h]
  unsigned __int8 *__new_finisha; // [esp+80h] [ebp-Ch]
  unsigned __int8 *__new_finish; // [esp+80h] [ebp-Ch]
  char *__new_start; // [esp+84h] [ebp-8h]
  unsigned int __len; // [esp+88h] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  __new_finisha = stlp_std::priv::__copy_trivial(
                    (unsigned __int8 *)this->_M_start,
                    (unsigned __int8 *)__pos,
                    (unsigned __int8 *)__new_start);
  memset(__new_finisha, *__x, __fill_len);
  __new_finish = &__new_finisha[__fill_len];
  if ( !__atend )
    __new_finish = stlp_std::priv::__copy_trivial(
                     (unsigned __int8 *)__pos,
                     (unsigned __int8 *)this->_M_finish,
                     __new_finish);
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_clear(this);
  v7 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = (char *)__new_finish;
  this->_M_end_of_storage._M_data = v7;
}
