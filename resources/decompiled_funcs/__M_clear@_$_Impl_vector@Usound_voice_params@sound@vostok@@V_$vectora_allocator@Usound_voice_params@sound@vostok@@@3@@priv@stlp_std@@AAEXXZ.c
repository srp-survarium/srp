void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_M_clear(
        stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *this)
{
  vostok::sound::sound_voice_params *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::sound::sound_voice_params **v5; // [esp+40h] [ebp-18h]
  vostok::sound::sound_voice_params *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > **v7; // [esp+48h] [ebp-10h]
  vostok::sound::sound_voice_params *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}
