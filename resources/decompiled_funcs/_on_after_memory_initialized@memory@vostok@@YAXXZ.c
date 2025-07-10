// attributes: thunk
void __thiscall vostok::memory::on_after_memory_initialized(void *ecx0)
{
  set_low_fragmentation_heap(ecx0);
}
