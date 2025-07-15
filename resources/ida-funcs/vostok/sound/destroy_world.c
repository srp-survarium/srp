void __cdecl vostok::sound::destroy_world(vostok::sound::world **world)
{
  (*(void (__thiscall **)(vostok::sound::engine *, _DWORD))(*(_DWORD *)&s_sound_world_buffer + 20))(
    &s_sound_world_buffer,
    0);
  *world = 0;
}
