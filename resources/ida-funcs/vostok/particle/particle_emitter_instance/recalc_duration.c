void __usercall vostok::particle::particle_emitter_instance::recalc_duration(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        int a2@<esi>)
{
  *(float *)(a2 + 544) = vostok::particle::calc_duration(
                           *(float *)(*(_DWORD *)(a2 + 488) + 352),
                           *(float *)(*(_DWORD *)(a2 + 488) + 356));
}
