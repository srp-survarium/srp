void __thiscall vostok::ai::working_memory::displace_memory_object(vostok::ai::working_memory *this)
{
  vostok::ai::percept_memory_object *oldest_object; // eax

  oldest_object = vostok::ai::working_memory::get_oldest_object(this);
  vostok::ai::working_memory::delete_memory_object(this, oldest_object);
}
