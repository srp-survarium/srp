char *__thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::erase(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__first,
        char *__last)
{
  if ( __first != __last )
    this->_M_finish = (char *)stlp_std::priv::__copy_trivial(
                                (unsigned __int8 *)__last,
                                (unsigned __int8 *)this->_M_finish,
                                (unsigned __int8 *)__first);
  return __first;
}


unsigned int *__thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::erase(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__first,
        unsigned int *__last)
{
  survarium::game_camera *v4; // ecx
  unsigned __int8 *v6; // [esp+10h] [ebp-8h]

  if ( __first != __last )
  {
    v6 = stlp_std::priv::__copy_ptrs<unsigned int *,unsigned int *>(
           (char *)this->_M_finish,
           (unsigned __int8 *)__first,
           __last);
    survarium::weapon_user_dead_state::finalize(v4);
    this->_M_finish = (unsigned int *)v6;
  }
  return __first;
}
