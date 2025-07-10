void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::~_Impl_vector<char,stlp_std::allocator<char>>(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this)
{
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *v1; // [esp-8h] [ebp-58h] BYREF
  void *current; // [esp-4h] [ebp-54h] BYREF
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *thisa; // [esp+0h] [ebp-50h]
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> **v4; // [esp+38h] [ebp-18h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v5; // [esp+3Ch] [ebp-14h]
  void **v6; // [esp+40h] [ebp-10h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v7; // [esp+44h] [ebp-Ch]

  thisa = this;
  current = this;
  v6 = &current;
  v7.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_start;
  current = v7.current;
  v1 = v7.current;
  v4 = &v1;
  v5.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>(v5, v7);
  stlp_std::priv::_Vector_base<char,stlp_std::allocator<char>>::~_Vector_base<char,stlp_std::allocator<char>>(thisa);
}
