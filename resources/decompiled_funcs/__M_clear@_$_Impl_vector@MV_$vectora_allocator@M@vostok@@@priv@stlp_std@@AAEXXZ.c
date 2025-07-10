void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_clear(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this)
{
  survarium::game_camera *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  survarium::game_camera **v5; // [esp+40h] [ebp-18h]
  survarium::game_camera *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > **v7; // [esp+48h] [ebp-10h]
  float *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *)M_start;
  v1 = (survarium::game_camera *)M_start;
  v5 = &v1;
  M_finish = (survarium::game_camera *)this->_M_finish;
  v1 = M_finish;
  survarium::weapon_user_dead_state::finalize(M_finish);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}
