survarium::hit_receiver_info *__thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this,
        survarium::hit_receiver_info *__pos,
        const stlp_std::__false_type *__formal)
{
  if ( &__pos[1] != this->_M_finish )
    stlp_std::priv::__copy_trivial(
      (unsigned __int8 *)&__pos[1],
      (unsigned __int8 *)this->_M_finish,
      (unsigned __int8 *)__pos);
  --this->_M_finish;
  return __pos;
}
