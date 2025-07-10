boost::asio::io_service::service *__thiscall boost::asio::detail::service_registry::do_use_service(
        boost::asio::detail::service_registry *this,
        const boost::asio::io_service::service::key *key,
        boost::asio::io_service::service *(__cdecl *factory)(boost::asio::io_service *))
{
  const boost::asio::io_service::id *id; // ecx
  type_info **v7; // [esp+30h] [ebp-38h]
  type_info **p_type_info; // [esp+44h] [ebp-24h]
  boost::asio::io_service::service *first_service; // [esp+4Ch] [ebp-1Ch]
  boost::asio::io_service::service *service; // [esp+58h] [ebp-10h]
  boost::asio::io_service::service *new_service; // [esp+5Ch] [ebp-Ch]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_mutex> lock; // [esp+60h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = (boost::asio::detail::win_mutex *)this;
  EnterCriticalSection(&this->mutex_.crit_section_);
  lock.locked_ = 1;
  for ( service = this->first_service_; service; service = service->next_ )
  {
    p_type_info = &service->key_.type_info_;
    if ( service->key_.id_ && key->id_ && service->key_.id_ == key->id_
      || *p_type_info && key->type_info_ && type_info::operator==(*p_type_info, key->type_info_) )
    {
      if ( lock.locked_ )
        LeaveCriticalSection(&lock.mutex_->crit_section_);
LABEL_15:
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
      return service;
    }
  }
  if ( lock.locked_ )
  {
    LeaveCriticalSection(&lock.mutex_->crit_section_);
    lock.locked_ = 0;
  }
  new_service = factory(this->owner_);
  id = key->id_;
  new_service->key_.type_info_ = key->type_info_;
  new_service->key_.id_ = id;
  if ( !lock.locked_ )
  {
    EnterCriticalSection(&lock.mutex_->crit_section_);
    lock.locked_ = 1;
  }
  for ( service = this->first_service_; service; service = service->next_ )
  {
    v7 = &service->key_.type_info_;
    if ( service->key_.id_ && key->id_ && service->key_.id_ == key->id_
      || *v7 && key->type_info_ && type_info::operator==(*v7, key->type_info_) )
    {
      if ( new_service )
        ((void (__thiscall *)(boost::asio::io_service::service *, int))new_service->~boost::asio::io_service::service)(
          new_service,
          1);
      if ( lock.locked_ )
        LeaveCriticalSection(&lock.mutex_->crit_section_);
      goto LABEL_15;
    }
  }
  new_service->next_ = this->first_service_;
  this->first_service_ = new_service;
  first_service = this->first_service_;
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
  return first_service;
}
