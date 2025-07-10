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
