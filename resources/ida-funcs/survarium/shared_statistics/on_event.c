void __userpurge survarium::shared_statistics::on_event(
        survarium::shared_statistics *this@<edi>,
        survarium::player_shared_statistics *player_stats@<eax>,
        unsigned __int16 count@<dx>,
        survarium::match_stats_events_dict_enum event)
{
  player_stats->events.elems[event] += count;
  if ( (this->m_on_event_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::operator()(
      &this->m_on_event_callback,
      &this->m_on_event_callback.vtable,
      ((char *)player_stats - (char *)this) / 212,
      event,
      count);
}
