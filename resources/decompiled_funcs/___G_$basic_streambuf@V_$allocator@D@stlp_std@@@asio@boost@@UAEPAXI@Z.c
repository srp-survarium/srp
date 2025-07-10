boost::asio::basic_streambuf<stlp_std::allocator<char> > *__thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::`scalar deleting destructor'(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        char a2)
{
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::~_Impl_vector<char,stlp_std::allocator<char>>(&this->buffer_._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->max_size_);
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::~basic_streambuf<char,stlp_std::char_traits<char>>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
