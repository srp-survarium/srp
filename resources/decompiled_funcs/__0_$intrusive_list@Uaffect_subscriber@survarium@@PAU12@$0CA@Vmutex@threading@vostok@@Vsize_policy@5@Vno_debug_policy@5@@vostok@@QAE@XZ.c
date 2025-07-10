void __thiscall vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
        vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    this);
  vostok::threading::mutex::mutex(&this->vostok::threading::mutex);
  this->m_first = 0;
  this->m_last = 0;
}
