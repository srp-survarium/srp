boost::asio::io_service::service *__userpurge boost::asio::detail::service_registry::do_use_service@<eax>(
        boost::asio::detail::service_registry *this@<edi>,
        const boost::asio::io_service::service::key *key@<eax>,
        boost::asio::io_service::service *(__cdecl *factory)(boost::asio::io_service *))
{
  boost::asio::io_service::service *i; // ebx
  boost::asio::io_service::service *j; // ebp

  EnterCriticalSection(&this->mutex_.crit_section_);
  for ( i = this->first_service_; i; i = i->next_ )
  {
    if ( boost::asio::detail::service_registry::keys_match(&i->key_, key) )
      goto LABEL_6;
  }
  LeaveCriticalSection(&this->mutex_.crit_section_);
  i = factory(this->owner_);
  i->key_.type_info_ = key->type_info_;
  i->key_.id_ = key->id_;
  EnterCriticalSection(&this->mutex_.crit_section_);
  for ( j = this->first_service_; ; j = j->next_ )
  {
    if ( !j )
    {
      i->next_ = this->first_service_;
      this->first_service_ = i;
      goto LABEL_6;
    }
    if ( boost::asio::detail::service_registry::keys_match(&j->key_, key) )
      break;
  }
  ((void (__thiscall *)(boost::asio::io_service::service *, int))i->~boost::asio::io_service::service)(i, 1);
  i = j;
LABEL_6:
  LeaveCriticalSection(&this->mutex_.crit_section_);
  return i;
}
