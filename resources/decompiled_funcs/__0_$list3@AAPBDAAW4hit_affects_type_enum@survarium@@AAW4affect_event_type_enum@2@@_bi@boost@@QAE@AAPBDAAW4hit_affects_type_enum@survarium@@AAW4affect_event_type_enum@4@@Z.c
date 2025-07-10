void __userpurge boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>(
        boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &> *this@<esi>,
        vostok::sound::compare_receivers_predicate *a1@<eax>,
        survarium::hit_affects_type_enum *a2,
        survarium::affect_event_type_enum *a3)
{
  boost::_bi::list1<vostok::fs_new::synchronous_device_interface &>::list1<vostok::fs_new::synchronous_device_interface &>(
    (vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> *)this,
    a1);
  this->a2_ = a2;
  this->a3_ = a3;
}
