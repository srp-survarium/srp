void __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // [esp+8h] [ebp-Ch]

  object->m_next_for_active = 0;
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
    this->m_last->m_next_for_active = object;
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
