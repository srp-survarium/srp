void **__thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_erase(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        const stlp_std::__false_type *__formal)
{
  if ( __pos + 1 != this->_M_finish )
    stlp_std::priv::__copy_trivial(
      (unsigned __int8 *)__pos + 4,
      (unsigned __int8 *)this->_M_finish,
      (unsigned __int8 *)__pos);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)--this->_M_finish);
  return __pos;
}
