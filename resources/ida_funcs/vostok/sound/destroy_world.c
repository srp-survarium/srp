void __cdecl vostok::sound::destroy_world(vostok::sound::world **world)
{
  vostok::uninitialized_reference<vostok::sound::sound_world>::destroy(&s_world_3);
  *world = 0;
}
