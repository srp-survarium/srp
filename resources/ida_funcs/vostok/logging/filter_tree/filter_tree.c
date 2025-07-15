void __thiscall vostok::logging::filter_tree::filter_tree(
        vostok::logging::filter_tree *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::memory::base_allocator *v2; // eax
  vostok::logging::node *v3; // eax
  vostok::logging::node *v4; // [esp+0h] [ebp-2Ch]
  void *_Where; // [esp+18h] [ebp-14h]
  vostok::logging::node *v7; // [esp+28h] [ebp-4h]

  this->lock.m_readers_writers_counter.whole = 0;
  this->lock.m_readers_writers_counter.whole = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::base_allocator::malloc_impl(v2, 0x54u);
  v7 = (vostok::logging::node *)operator new(0x54u, _Where);
  if ( v7 )
  {
    vostok::logging::node::node(v7, (const char *)&buf, trace);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  this->initiator_tree = v4;
  this->allocator = allocator;
  this->filter_stack.m_first = 0;
  this->filter_stack.m_last = 0;
  vostok::threading::mutex::mutex(&this->filter_stack.m_policy);
}
