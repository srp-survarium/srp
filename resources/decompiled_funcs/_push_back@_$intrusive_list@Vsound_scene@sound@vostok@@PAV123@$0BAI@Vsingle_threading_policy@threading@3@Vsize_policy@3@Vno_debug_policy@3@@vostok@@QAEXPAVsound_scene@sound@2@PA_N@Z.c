void __thiscall vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_scene *object,
        bool *out_pushed_first)
{
  object->m_next = 0;
  ++this->m_size;
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->m_next = object;
  else
    this->m_first = object;
  this->m_last = object;
}
