void __thiscall vostok::resources::query_resources_and_wait_callback_proxy_pred::callback(
        vostok::resources::query_resources_and_wait_callback_proxy_pred *this,
        vostok::resources::queries_result *result)
{
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)this,
    &this->callback_.vtable,
    (const char *)result);
  this->receieved_callback_ = 1;
}
