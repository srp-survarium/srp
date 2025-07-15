void __usercall vostok::particle::particle_beam_emitter_instance::free_dynamic_data(
        vostok::particle::particle_beam_emitter_instance *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebp
  unsigned int i; // ebx
  int v4; // eax
  int v5; // eax

  v2 = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 628); v2 += 48 )
  {
    vostok::math::curve_line_points<vostok::math::float3_pod,0>::free_memory(
      *(vostok::math::curve_line_points<vostok::math::float3_pod,0> **)(a2 + 372),
      v2 + *(_DWORD *)(a2 + 620));
    ++i;
  }
  v4 = *(_DWORD *)(a2 + 620);
  if ( v4 )
  {
    (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 372) + 24))(
      *(_DWORD *)(a2 + 372),
      v4,
      "vostok::particle::particle_beam_emitter_instance::free_dynamic_data",
      ".\\particle_beam_emitter_instance.cpp",
      117);
    *(_DWORD *)(a2 + 620) = 0;
  }
  v5 = *(_DWORD *)(a2 + 624);
  if ( v5 )
  {
    (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 372) + 24))(
      *(_DWORD *)(a2 + 372),
      v5,
      "vostok::particle::particle_beam_emitter_instance::free_dynamic_data",
      ".\\particle_beam_emitter_instance.cpp",
      118);
    *(_DWORD *)(a2 + 624) = 0;
  }
}
