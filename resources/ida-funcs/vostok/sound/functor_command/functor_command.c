void __usercall vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
        vostok::sound::functor_command<vostok::sound::sound_order> *this@<esi>,
        vostok::memory::base_allocator *allocator@<eax>,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor@<ecx>)
{
  this->m_next_for_orders = 0;
  this->m_next_for_postponed_orders = 0;
  this->allocator = allocator;
  this->__vftable = (vostok::sound::functor_command<vostok::sound::sound_order>_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    functor,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_functor);
}
