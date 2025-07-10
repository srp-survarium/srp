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
