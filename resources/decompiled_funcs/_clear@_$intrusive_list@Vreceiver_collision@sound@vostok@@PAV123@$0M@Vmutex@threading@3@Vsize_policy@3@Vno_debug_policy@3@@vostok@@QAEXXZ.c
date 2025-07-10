void __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::clear(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex *v2; // [esp+4h] [ebp-Ch]

  if ( this )
    v2 = &this->vostok::threading::mutex;
  else
    v2 = 0;
  vostok::threading::mutex::lock(v2);
  this->m_first = 0;
  this->m_last = 0;
  this->m_size = 0;
  vostok::threading::mutex::unlock(v2);
}
