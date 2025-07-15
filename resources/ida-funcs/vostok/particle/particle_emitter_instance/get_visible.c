BOOL __usercall vostok::particle::particle_emitter_instance::get_visible@<eax>(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)(a2 + 559) && *(_BYTE *)(*(_DWORD *)(a2 + 488) + 370);
}
