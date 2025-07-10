void __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::receiver_collision *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // [esp+8h] [ebp-Ch]

  object->m_next = 0;
  if ( this )
    v4 = &this->vostok::threading::mutex;
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
  {
    this->m_last->m_next = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
  else
  {
    this->m_first = object;
    this->m_last = object;
    vostok::threading::mutex::unlock(v4);
  }
}
