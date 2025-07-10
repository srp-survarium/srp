void __thiscall vostok::ai::working_memory::forget_all(vostok::ai::working_memory *this)
{
  vostok::ai::percept_memory_object *memory_object; // [esp+1Ch] [ebp-8h]
  vostok::ai::working_memory *iter; // [esp+20h] [ebp-4h]

  for ( iter = this;
        iter != (vostok::ai::working_memory *)&this->m_subscription;
        iter = (vostok::ai::working_memory *)((char *)iter + 48) )
  {
    while ( 1 )
    {
      memory_object = vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(iter->m_percept_objects.elems);
      if ( !memory_object )
        break;
      vostok::ai::working_memory::delete_memory_object(this, memory_object);
    }
  }
}
