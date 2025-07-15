void __cdecl bullet_free(void *memblock)
{
  if ( memblock )
    vostok::physics::g_allocator->call_free(
      vostok::physics::g_allocator,
      memblock,
      "bullet_free",
      ".\\bullet_physics_world.cpp",
      47u);
}
