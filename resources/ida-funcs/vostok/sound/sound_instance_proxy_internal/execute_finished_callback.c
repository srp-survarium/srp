void __thiscall vostok::sound::sound_instance_proxy_internal::execute_finished_callback(
        vostok::sound::sound_instance_proxy_internal *this,
        unsigned int playback_id)
{
  boost::function<void __cdecl(void)> *p_m_finished_callback; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<void __cdecl(void)> v4; // [esp+8h] [ebp-20h] BYREF

  p_m_finished_callback = &this->m_finished_callback;
  if ( (this->m_finished_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0
    && this->m_playback_id == playback_id )
  {
    boost::function0<void>::operator()((boost::function0<bool> *)this, &this->m_finished_callback.vtable);
    v4.vtable = 0;
    boost::function<void __cdecl (void)>::operator=(
      &v4,
      (boost::function1<void,vostok::physics::contact_point const &> *)p_m_finished_callback);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&v4);
  }
}
