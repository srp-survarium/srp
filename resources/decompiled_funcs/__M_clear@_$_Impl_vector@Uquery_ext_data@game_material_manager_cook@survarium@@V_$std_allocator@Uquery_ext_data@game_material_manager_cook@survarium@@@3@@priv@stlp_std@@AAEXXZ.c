void __thiscall stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::_M_clear(
        stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *this)
{
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> **v5; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v6; // [esp+44h] [ebp-14h]
  void **v7; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *> v8; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = (stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *)this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    thisa->_M_start);
}
