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


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::~_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(
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
  if ( thisa->_M_start )
  {
    v6 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::~_Impl_vector<float,vostok::vectora_allocator<float>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::~_Impl_vector<void *,stlp_std::allocator<void *>>(
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
  if ( thisa->_M_start )
  {
    v7 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    __p = thisa->_M_start;
    if ( __p )
      stlp_std::__node_alloc::deallocate(__p, 4 * v7);
  }
}


void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::~_Impl_vector<void *,survarium::std_allocator<void *>>(
        survarium::vector<vostok::resources::request> *this@<ecx>,
        void **a2@<eax>)
{
  void *v2; // eax
  void *v3; // esi

  v2 = *a2;
  if ( v2 )
  {
    v3 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v3, v2);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
        vostok::vectora<vostok::resources::request> *this)
{
  if ( this->_M_impl._M_start )
    this->_M_impl._M_end_of_storage.m_allocator->call_free(
      this->_M_impl._M_end_of_storage.m_allocator,
      (void *)this->_M_impl._M_start);
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::~_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this)
{
  survarium::hit_receiver_info *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  survarium::hit_receiver_info **v5; // [esp+40h] [ebp-18h]
  survarium::hit_receiver_info *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > **v7; // [esp+48h] [ebp-10h]
  survarium::hit_receiver_info *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::~_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>(
        stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this)
{
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *thisa; // [esp+0h] [ebp-58h]
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>::~_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>(
        stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects> > *this,
        stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects> > *thisa)
{
  vostok::render::material_effects *M_finish; // eax
  vostok::render::material_effects *M_start; // edi
  vostok::render::material_effects *v4; // esi
  vostok::render::material_effects *v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  M_finish = thisa->_M_finish;
  M_start = thisa->_M_start;
  if ( M_finish != thisa->_M_start )
  {
    do
    {
      v4 = M_finish - 1;
      vostok::render::material_effects::~material_effects((vostok::render::material_effects *)this, (int)&M_finish[-1]);
      M_finish = v4;
    }
    while ( v4 != M_start );
  }
  v5 = thisa->_M_start;
  if ( thisa->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::~_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::~_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>(
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *this)
{
  survarium::base_project::resolve_link_object *v1; // ecx
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v2; // [esp-8h] [ebp-28h] BYREF
  stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> v3; // [esp-4h] [ebp-24h] BYREF
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *thisa; // [esp+0h] [ebp-20h]

  thisa = this;
  v3.current = (survarium::base_project::resolve_link_object *)this;
  boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>(
    this,
    &v3);
  v2.current = v1;
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::rbegin(
    thisa,
    &v2);
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *>>(v2, v3);
  if ( thisa->_M_start )
    survarium::std_allocator<survarium::base_project::resolve_link_object>::deallocate(
      thisa->_M_start,
      (survarium::std_allocator<survarium::base_project::resolve_link_object> *)thisa);
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::~_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::~_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this)
{
  vostok::sound::unique_propagator_info *v1; // [esp-8h] [ebp-B0h] BYREF
  void *current; // [esp-4h] [ebp-ACh] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *thisa; // [esp+0h] [ebp-A8h]
  int v4; // [esp+4h] [ebp-A4h]
  vostok::sound::unique_propagator_info **v5; // [esp+90h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v6; // [esp+94h] [ebp-14h]
  void **v7; // [esp+98h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *> v8; // [esp+9Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Moved_Range<stlp_std::reverse_iterator<vostok::sound::unique_propagator_info *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::~_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
      thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::~_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::~_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this)
{
  vostok::ai::planning::pddl_world_state_property_impl *v1; // [esp-8h] [ebp-5Ch] BYREF
  void *current; // [esp-4h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *thisa; // [esp+0h] [ebp-54h]
  int v4; // [esp+4h] [ebp-50h]
  vostok::ai::planning::pddl_world_state_property_impl **v5; // [esp+3Ch] [ebp-18h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v6; // [esp+40h] [ebp-14h]
  void **v7; // [esp+44h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v8; // [esp+48h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::~_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this)
{
  vostok::ai::planning::specified_action *v1; // [esp-8h] [ebp-A4h] BYREF
  void *current; // [esp-4h] [ebp-A0h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *thisa; // [esp+0h] [ebp-9Ch]
  int v4; // [esp+4h] [ebp-98h]
  vostok::ai::planning::specified_action **v5; // [esp+84h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> v6; // [esp+88h] [ebp-14h]
  void **v7; // [esp+8Ch] [ebp-10h]
  stlp_std::reverse_iterator<vostok::ai::planning::specified_action *> v8; // [esp+90h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::specified_action *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
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
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>::~_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>(
        stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *this)
{
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *v1; // [esp-8h] [ebp-5Ch] BYREF
  void *current; // [esp-4h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *thisa; // [esp+0h] [ebp-54h]
  int v4; // [esp+4h] [ebp-50h]
  void *__p; // [esp+8h] [ebp-4Ch]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> **v6; // [esp+3Ch] [ebp-18h]
  stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *> v7; // [esp+40h] [ebp-14h]
  void **v8; // [esp+44h] [ebp-10h]
  stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *> v9; // [esp+48h] [ebp-Ch]

  thisa = this;
  current = this;
  v8 = &current;
  v9.current = this->_M_start;
  current = v9.current;
  v1 = v9.current;
  v6 = &v1;
  v7.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> *>>(
    v7,
    v9);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    __p = thisa->_M_start;
    if ( __p )
      stlp_std::__node_alloc::deallocate(__p, 76 * v4);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::~_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this)
{
  vostok::fixed_string<16> *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::fixed_string<16> **v5; // [esp+40h] [ebp-18h]
  vostok::fixed_string<16> *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > **v7; // [esp+48h] [ebp-10h]
  vostok::fixed_string<16> *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      (void *)thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::~_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this)
{
  vostok::fixed_vector<unsigned int,32> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  vostok::fixed_vector<unsigned int,32> **v5; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v6; // [esp+44h] [ebp-14h]
  void **v7; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *> v8; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::fixed_vector<unsigned int,32> *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>::~_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex>>>(
        stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *this)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v1; // [esp-8h] [ebp-60h] BYREF
  void *current; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<boost::shared_ptr<boost::asio::detail::win_mutex>,stlp_std::allocator<boost::shared_ptr<boost::asio::detail::win_mutex> > > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  void *__p; // [esp+8h] [ebp-50h]
  boost::shared_ptr<boost::asio::detail::win_mutex> **v6; // [esp+40h] [ebp-18h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v7; // [esp+44h] [ebp-14h]
  void **v8; // [esp+48h] [ebp-10h]
  stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *> v9; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  current = this;
  v8 = &current;
  v9.current = this->_M_start;
  current = v9.current;
  v1 = v9.current;
  v6 = &v1;
  v7.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<boost::shared_ptr<boost::asio::detail::win_mutex> *>>(v7, v9);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    __p = thisa->_M_start;
    if ( __p )
      stlp_std::__node_alloc::deallocate(__p, 8 * v4);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::~_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this)
{
  vostok::variant<32> *v1; // [esp-8h] [ebp-64h] BYREF
  void *current; // [esp-4h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *thisa; // [esp+0h] [ebp-5Ch]
  int v4; // [esp+4h] [ebp-58h]
  vostok::variant<32> **v5; // [esp+44h] [ebp-18h]
  stlp_std::reverse_iterator<vostok::variant<32> *> v6; // [esp+48h] [ebp-14h]
  void **v7; // [esp+4Ch] [ebp-10h]
  stlp_std::reverse_iterator<vostok::variant<32> *> v8; // [esp+50h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::variant<32> *>>(v6, v8);
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      thisa->_M_start);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>(
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this)
{
  unsigned __int64 *v1; // [esp-8h] [ebp-60h] BYREF
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *v2; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *thisa; // [esp+0h] [ebp-58h]
  int v4; // [esp+4h] [ebp-54h]
  unsigned __int64 **v5; // [esp+40h] [ebp-18h]
  unsigned __int64 *M_finish; // [esp+44h] [ebp-14h]
  stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > **v7; // [esp+48h] [ebp-10h]
  unsigned __int64 *M_start; // [esp+4Ch] [ebp-Ch]

  thisa = this;
  v2 = this;
  v7 = &v2;
  M_start = this->_M_start;
  v2 = (stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)M_start;
  v1 = M_start;
  v5 = &v1;
  M_finish = this->_M_finish;
  v1 = M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::logging::initiator_filter *>>();
  if ( thisa->_M_start )
  {
    v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
    vostok::memory::base_allocator::free_impl(thisa->_M_end_of_storage.m_allocator, thisa->_M_start);
  }
}
