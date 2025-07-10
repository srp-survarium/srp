vostok::sound::functor_command<vostok::sound::sound_order> *__thiscall vostok::sound::functor_command<vostok::sound::sound_order>::`vector deleting destructor'(
        vostok::sound::functor_command<vostok::sound::sound_order> *this,
        char a2)
{
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_functor);
  vostok::sound::sound_order::~sound_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
