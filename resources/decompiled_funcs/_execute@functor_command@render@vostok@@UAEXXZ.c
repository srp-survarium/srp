void __thiscall vostok::render::functor_command::execute(vostok::render::functor_command *this)
{
  boost::function0<void>::operator()(&this->m_on_execute);
}
