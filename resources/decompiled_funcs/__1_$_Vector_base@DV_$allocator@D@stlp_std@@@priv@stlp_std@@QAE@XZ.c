void __thiscall stlp_std::priv::_Vector_base<char,stlp_std::allocator<char>>::~_Vector_base<char,stlp_std::allocator<char>>(
        stlp_std::priv::_Vector_base<char,stlp_std::allocator<char> > *this)
{
  if ( this->_M_start )
    stlp_std::allocator<char>::deallocate(
      &this->_M_end_of_storage,
      this->_M_start,
      this->_M_end_of_storage._M_data - this->_M_start);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->_M_end_of_storage);
}
