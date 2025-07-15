void __thiscall stlp_std::ios_base::_M_invoke_callbacks(stlp_std::ios_base *this, stlp_std::ios_base::event E)
{
  unsigned int i; // esi

  for ( i = this->_M_callback_index; i; --i )
    this->_M_callbacks[i - 1].first(E, this, this->_M_callbacks[i - 1].second);
}
