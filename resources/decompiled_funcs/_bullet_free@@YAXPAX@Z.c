void __cdecl bullet_free(void *memblock)
{
  if ( memblock )
    vostok::physics::g_ph_allocator->call_free(vostok::physics::g_ph_allocator, memblock);
}
