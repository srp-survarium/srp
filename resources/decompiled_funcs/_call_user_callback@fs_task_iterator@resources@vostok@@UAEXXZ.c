void __thiscall vostok::resources::fs_task_iterator::call_user_callback(vostok::resources::fs_task_iterator *this)
{
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)this,
    &this->m_callback.vtable,
    (const char *)&this->m_iterator);
}
