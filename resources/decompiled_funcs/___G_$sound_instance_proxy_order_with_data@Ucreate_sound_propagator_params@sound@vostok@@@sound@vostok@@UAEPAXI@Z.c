vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *__thiscall vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params>::`scalar deleting destructor'(
        vostok::sound::sound_instance_proxy_order_with_data<vostok::sound::create_sound_propagator_params> *this,
        char a2)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::clear(&this->m_functor);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->vostok::sound::sound_instance_proxy_order::m_functor);
  vostok::sound::sound_order::~sound_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
