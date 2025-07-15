void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_clear(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this)
{
  char *v1; // [esp-8h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *v2; // [esp-4h] [ebp-54h] BYREF
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *thisa; // [esp+0h] [ebp-50h]
  char **v4; // [esp+38h] [ebp-18h]
  char *M_finish; // [esp+3Ch] [ebp-14h]
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > **v6; // [esp+40h] [ebp-10h]
  char *M_start; // [esp+44h] [ebp-Ch]

  thisa = this;
  v2 = this;
  v6 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *)M_start;
  v1 = M_start;
  v4 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  stlp_std::allocator<char>::deallocate(
    &thisa->_M_end_of_storage,
    thisa->_M_start,
    thisa->_M_end_of_storage._M_data - thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_clear(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v1; // ecx
  survarium::game_camera *v2; // ecx
  boost::_bi::list1<vostok::network_core::packet_reader &> *v3; // [esp-8h] [ebp-40h] BYREF
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *v4; // [esp-4h] [ebp-3Ch] BYREF
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *thisa; // [esp+0h] [ebp-38h]
  int v6; // [esp+4h] [ebp-34h]
  boost::_bi::list1<vostok::network_core::packet_reader &> **v7; // [esp+20h] [ebp-18h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_finish; // [esp+24h] [ebp-14h]
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > **v9; // [esp+28h] [ebp-10h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_start; // [esp+2Ch] [ebp-Ch]

  thisa = this;
  v4 = this;
  v9 = &v4;
  M_start = (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->_M_start;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_start,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v4);
  v3 = v1;
  v7 = &v3;
  M_finish = (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa->_M_finish;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_finish,
    &v3);
  survarium::weapon_user_dead_state::finalize(v2);
  v6 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}


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


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this)
{
  vostok::render::skeleton_model_instance *v1; // eax
  void **v2; // ecx
  survarium::game_camera *v3; // ecx
  stlp_std::reverse_iterator<void * *> v4; // [esp-8h] [ebp-3Ch] BYREF
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *v5; // [esp-4h] [ebp-38h] BYREF
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *thisa; // [esp+0h] [ebp-34h]
  int v7; // [esp+4h] [ebp-30h]
  void *__p; // [esp+8h] [ebp-2Ch]
  stlp_std::reverse_iterator<void * *> *v9; // [esp+20h] [ebp-14h]
  void **__x; // [esp+24h] [ebp-10h]
  stlp_std::reverse_iterator<void * *> *v11; // [esp+28h] [ebp-Ch]

  thisa = this;
  v5 = this;
  v11 = (stlp_std::reverse_iterator<void * *> *)&v5;
  v1 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  stlp_std::reverse_iterator<void * *>::reverse_iterator<void * *>(v11, (void **)&v1->__vftable);
  v4.current = v2;
  v9 = &v4;
  __x = thisa->_M_finish;
  stlp_std::reverse_iterator<void * *>::reverse_iterator<void * *>(&v4, __x);
  survarium::weapon_user_dead_state::finalize(v3);
  v7 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  __p = thisa->_M_start;
  if ( __p )
    stlp_std::__node_alloc::deallocate(__p, 4 * v7);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::_M_clear(
        stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *this)
{
  vostok::sound::propagator_info *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::sound::propagator_info **v5; // [esp+40h] [ebp-18h]
  vostok::sound::propagator_info *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > **v7; // [esp+48h] [ebp-10h]
  vostok::sound::propagator_info *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}


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


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_clear(
        stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *this)
{
  vostok::sound::search::vertex_id_type *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::sound::search::vertex_id_type **v5; // [esp+40h] [ebp-18h]
  vostok::sound::search::vertex_id_type *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > **v7; // [esp+48h] [ebp-10h]
  vostok::sound::search::vertex_id_type *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_clear(
        stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *this)
{
  survarium::zone_group::zone_wrapper *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  survarium::zone_group::zone_wrapper **v5; // [esp+40h] [ebp-18h]
  survarium::zone_group::zone_wrapper *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > **v7; // [esp+48h] [ebp-10h]
  survarium::zone_group::zone_wrapper *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::_M_clear(
        stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > *this)
{
  stlp_std::pair<float,vostok::math::float3> *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  stlp_std::pair<float,vostok::math::float3> **v5; // [esp+40h] [ebp-18h]
  stlp_std::pair<float,vostok::math::float3> *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > **v7; // [esp+48h] [ebp-10h]
  stlp_std::pair<float,vostok::math::float3> *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this)
{
  vostok::ai::planning::operator_pair *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::ai::planning::operator_pair **v5; // [esp+40h] [ebp-18h]
  vostok::ai::planning::operator_pair *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > **v7; // [esp+48h] [ebp-10h]
  vostok::ai::planning::operator_pair *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_M_clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this)
{
  vostok::ai::planning::world_state_property *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::ai::planning::world_state_property **v5; // [esp+40h] [ebp-18h]
  vostok::ai::planning::world_state_property *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > **v7; // [esp+48h] [ebp-10h]
  vostok::ai::planning::world_state_property *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}
