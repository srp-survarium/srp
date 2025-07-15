void __cdecl vostok::sound::play_once_finished_callback(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> last_reference)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v1; // ecx
  boost::function<void __cdecl(void)> v3; // [esp+8h] [ebp-20h] BYREF

  v3.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v3,
    (boost::function1<void,vostok::physics::contact_point const &> *)&last_reference.m_object->m_finished_callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v1,
    (int *)&v3);
  if ( last_reference.m_object )
  {
    if ( last_reference.m_object->m_reference_count-- == 1 )
      last_reference.m_object->free_object(last_reference.m_object);
  }
}
