void __userpurge boost::_bi::storage2<char const * &,enum survarium::hit_affects_type_enum &>::storage2<char const * &,enum survarium::hit_affects_type_enum &>(
        boost::_bi::storage2<char const * &,enum survarium::hit_affects_type_enum &> *this@<esi>,
        vostok::sound::compare_receivers_predicate *a1@<eax>,
        survarium::hit_affects_type_enum *a2)
{
  boost::_bi::list1<vostok::fs_new::synchronous_device_interface &>::list1<vostok::fs_new::synchronous_device_interface &>(
    (vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> *)this,
    a1);
  this->a2_ = a2;
}


void __thiscall boost::_bi::storage2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>>>::storage2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>>>(
        boost::_bi::storage2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> > > *this,
        const boost::_bi::storage2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> > > *__that)
{
  this->a1_.t_ = __that->a1_.t_;
  this->a2_.t_.vtable = 0;
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&this->a2_,
    (const boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&__that->a2_);
}
