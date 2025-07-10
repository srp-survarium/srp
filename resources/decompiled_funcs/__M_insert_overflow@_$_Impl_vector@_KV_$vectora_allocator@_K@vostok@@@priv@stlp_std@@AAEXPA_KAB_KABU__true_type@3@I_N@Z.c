void __thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned __int64 *__pos,
        const unsigned __int64 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // [esp+0h] [ebp-B0h]
  unsigned __int8 *v9; // [esp+4h] [ebp-ACh]
  unsigned __int64 *v11; // [esp+Ch] [ebp-A4h]
  unsigned __int64 *M_finish; // [esp+64h] [ebp-4Ch]
  unsigned int v13; // [esp+68h] [ebp-48h]
  unsigned int v14; // [esp+6Ch] [ebp-44h]
  unsigned __int8 *v15; // [esp+70h] [ebp-40h]
  int count; // [esp+78h] [ebp-38h]
  unsigned __int64 *__new_finish; // [esp+A4h] [ebp-Ch]
  unsigned __int64 *__new_start; // [esp+A8h] [ebp-8h]
  unsigned int __len; // [esp+ACh] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_compute_next_size(
            this,
            __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<unsigned __int64 *,unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  count = (char *)__pos - (char *)this->_M_start;
  if ( __pos == this->_M_start )
  {
    v9 = (unsigned __int8 *)__new_start;
  }
  else
  {
    memmove((unsigned __int8 *)__new_start, (unsigned __int8 *)this->_M_start, count);
    v9 = (unsigned __int8 *)(count + v6);
  }
  v14 = __fill_len;
  v15 = v9;
  while ( v14 )
  {
    *(_QWORD *)v15 = *__x;
    --v14;
    v15 += 8;
  }
  __new_finish = (unsigned __int64 *)v15;
  if ( !__atend )
  {
    M_finish = this->_M_finish;
    v13 = (char *)M_finish - (char *)__pos;
    if ( M_finish == __pos )
    {
      v8 = v15;
    }
    else
    {
      memmove(v15, (unsigned __int8 *)__pos, v13);
      v8 = (unsigned __int8 *)(v13 + v7);
    }
    __new_finish = (unsigned __int64 *)v8;
  }
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::collision::bone_collision_data *,float>,vostok::vectora_allocator<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>::_M_clear(this);
  v11 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v11;
}
