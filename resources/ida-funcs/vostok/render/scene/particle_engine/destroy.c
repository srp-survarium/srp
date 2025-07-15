void __userpurge vostok::render::scene::particle_engine::destroy(
        vostok::render::scene::particle_engine *this@<ecx>,
        const char *a2@<ebp>,
        vostok::particle::render_particle_emitter_instance **instance)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  void **v4; // edi
  char *v5; // ebp
  vostok::memory::doug_lea_allocator *v6; // ecx
  const char *v8; // [esp+0h] [ebp-Ch]
  unsigned int v9; // [esp+4h] [ebp-8h]

  v3 = vostok::render::g_allocator;
  v4 = (void **)*instance;
  if ( *instance )
  {
    v5 = __RTCastToVoid(v4);
    (*((void (__thiscall **)(void **, _DWORD))*v4 + 8))(v4, 0);
    vostok::memory::doug_lea_allocator::free_impl(v6, (int)v3, v5, a2, v8, v9);
  }
  *instance = 0;
}
