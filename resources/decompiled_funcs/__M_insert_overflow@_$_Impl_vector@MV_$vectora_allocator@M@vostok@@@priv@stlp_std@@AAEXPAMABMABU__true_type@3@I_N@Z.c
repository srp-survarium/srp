void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        float *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  int v6; // eax
  int v7; // eax
  float *v8; // [esp+0h] [ebp-B0h]
  float *v9; // [esp+4h] [ebp-ACh]
  float *v11; // [esp+Ch] [ebp-A4h]
  float *M_finish; // [esp+64h] [ebp-4Ch]
  unsigned int v13; // [esp+68h] [ebp-48h]
  int count; // [esp+78h] [ebp-38h]
  float *__new_finish; // [esp+A4h] [ebp-Ch]
  float *__new_start; // [esp+A8h] [ebp-8h]
  unsigned int __len; // [esp+ACh] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  count = (char *)__pos - (char *)this->_M_start;
  if ( __pos == this->_M_start )
  {
    v9 = __new_start;
  }
  else
  {
    memmove((unsigned __int8 *)__new_start, (unsigned __int8 *)this->_M_start, count);
    v9 = (float *)(count + v6);
  }
  memset32(v9, COERCE_INT(*__x), __fill_len);
  __new_finish = &v9[__fill_len];
  if ( !__atend )
  {
    M_finish = this->_M_finish;
    v13 = (char *)M_finish - (char *)__pos;
    if ( M_finish == __pos )
    {
      v8 = &v9[__fill_len];
    }
    else
    {
      memmove((unsigned __int8 *)&v9[__fill_len], (unsigned __int8 *)__pos, v13);
      v8 = (float *)(v13 + v7);
    }
    __new_finish = v8;
  }
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_clear(this);
  v11 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v11;
}
