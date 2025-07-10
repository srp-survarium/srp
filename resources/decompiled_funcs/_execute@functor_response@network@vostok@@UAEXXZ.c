void __thiscall vostok::network::functor_response::execute(
        vostok::sound::functor_command<vostok::sound::sound_response> *this)
{
  boost::function0<void>::operator()(&this->m_functor);
}
