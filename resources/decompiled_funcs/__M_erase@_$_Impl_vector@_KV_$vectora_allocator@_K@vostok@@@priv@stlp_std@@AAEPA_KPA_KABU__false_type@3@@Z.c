unsigned __int8 *__thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::_M_erase(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned __int8 *__pos,
        const stlp_std::__false_type *__formal)
{
  unsigned __int64 *M_finish; // [esp+10h] [ebp-14h]

  if ( __pos + 8 != (unsigned __int8 *)this->_M_finish )
  {
    M_finish = this->_M_finish;
    if ( M_finish != (unsigned __int64 *)(__pos + 8) )
      memmove(__pos, __pos + 8, (char *)M_finish - (char *)(__pos + 8));
  }
  --this->_M_finish;
  return __pos;
}
