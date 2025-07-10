void __thiscall boost::_bi::list1<vostok::fs_new::synchronous_device_interface &>::list1<vostok::fs_new::synchronous_device_interface &>(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> *this,
        vostok::sound::compare_receivers_predicate *pred)
{
  this->m_predicate_ref = pred;
}
