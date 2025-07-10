void __thiscall vostok::sound::functor_command<vostok::sound::sound_order>::execute(
        vostok::sound::functor_command<vostok::sound::sound_order> *this)
{
  boost::function0<void>::operator()(&this->m_functor);
}
