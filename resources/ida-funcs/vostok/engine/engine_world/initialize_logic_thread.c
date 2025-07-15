void __thiscall vostok::engine::engine_world::initialize_logic_thread(vostok::engine::engine_world *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::memory::doug_lea_allocator *v2; // ecx

  v1 = this->m_engine_user_module_proxy->allocator(this->m_engine_user_module_proxy);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v2, (int)v1);
}
