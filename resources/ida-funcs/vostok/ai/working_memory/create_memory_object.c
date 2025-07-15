vostok::ai::percept_memory_object *__userpurge vostok::ai::working_memory::create_memory_object@<eax>(
        vostok::ai::working_memory *this@<ecx>,
        float a2@<xmm0>,
        vostok::ai::percept_memory_object_types knowledge_type)
{
  void *v3; // eax
  vostok::ai::percept_memory_object *v4; // eax
  vostok::ai::percept_memory_object *v6; // [esp+0h] [ebp-84h]
  vostok::ai::percept_memory_object *v8; // [esp+7Ch] [ebp-8h]

  if ( 44 * this->m_allocator.m_max_count == 44 * this->m_allocator.m_allocated_count )
    vostok::ai::working_memory::displace_memory_object(this);
  v3 = vostok::memory::new_helper<vostok::ai::percept_memory_object>::call<vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>>(&this->m_allocator);
  v8 = (vostok::ai::percept_memory_object *)operator new(0x2Cu, v3);
  if ( v8 )
  {
    vostok::ai::percept_memory_object::percept_memory_object(v8, a2, knowledge_type);
    v6 = v4;
  }
  else
  {
    v6 = 0;
  }
  vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_percept_objects.elems[knowledge_type],
    v6,
    0);
  return v6;
}
