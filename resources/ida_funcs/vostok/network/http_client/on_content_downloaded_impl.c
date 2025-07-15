void __thiscall vostok::network::http_client::on_content_downloaded_impl(
        vostok::network::http_client *this,
        const char *content)
{
  boost::function1<void,char const *> *v2; // ecx

  if ( boost::function1<void,char const *>::operator void (__thiscall boost::function1<void,char const *>::dummy::*)(void)(
         (boost::function1<void,char const *> *)this,
         &this->m_on_content_downloaded.vtable) )
  {
    boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
      v2,
      &this->m_on_content_downloaded.vtable,
      content);
  }
  this->m_busy = 0;
}
