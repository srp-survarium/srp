void __thiscall vostok::render::functor_command::defer_execution(vostok::render::functor_command *this)
{
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)this,
    &this->m_on_defer_execution.vtable,
    (const char *)this);
}
