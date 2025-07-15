void __cdecl survarium::on_sound_finished(
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *instances,
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *instance)
{
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *v2; // ebx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *m_begin; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *m_end; // esi
  signed int i; // ecx

  v2 = instances;
  m_begin = instances->m_begin;
  m_end = instances->m_end;
  for ( i = ((char *)m_end - (char *)instances->m_begin) >> 4; i > 0; --i )
  {
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object == instance )
      goto LABEL_17;
    ++m_begin;
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object == instance )
      goto LABEL_17;
    ++m_begin;
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object == instance )
      goto LABEL_17;
    ++m_begin;
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object == instance )
      goto LABEL_17;
    ++m_begin;
  }
  i = m_end - m_begin - 1;
  if ( m_end - m_begin == 1 )
  {
LABEL_15:
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object != instance )
      goto LABEL_16;
    goto LABEL_17;
  }
  i = m_end - m_begin - 2;
  if ( m_end - m_begin == 2 )
  {
LABEL_13:
    if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object == instance )
      goto LABEL_17;
    ++m_begin;
    goto LABEL_15;
  }
  i = m_end - m_begin - 3;
  if ( m_end - m_begin != 3 )
  {
LABEL_16:
    m_begin = instances->m_end;
    goto LABEL_17;
  }
  if ( (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)m_begin->m_object != instance )
  {
    ++m_begin;
    goto LABEL_13;
  }
LABEL_17:
  instance = m_begin;
  instances = (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)&m_begin[1];
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>::erase(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > *)i,
    (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)&v2->m_begin,
    &instance,
    (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> **)&instances);
}
