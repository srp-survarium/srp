void __thiscall vostok::render::scene::particle_engine::destroy(
        vostok::render::scene::particle_engine *this,
        vostok::particle::render_particle_emitter_instance **instance)
{
  void **v2; // esi
  _BYTE *v3; // edi

  v2 = (void **)*instance;
  if ( *instance )
  {
    v3 = __RTCastToVoid(v2);
    (*((void (__thiscall **)(void **, _DWORD))*v2 + 5))(v2, 0);
    if ( v3 )
      pt3free(v3);
    *instance = 0;
  }
  else
  {
    *instance = 0;
  }
}
