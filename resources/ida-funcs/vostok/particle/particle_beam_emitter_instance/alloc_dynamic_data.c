void __userpurge vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(
        vostok::particle::particle_beam_emitter_instance *this@<ecx>,
        int a2@<edi>,
        unsigned int num_curves,
        unsigned int num_points)
{
  unsigned int v4; // ebx
  int v5; // esi
  char *v6; // eax
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // [esp+8h] [ebp-4h]
  int v13; // [esp+14h] [ebp+8h]

  v4 = num_curves;
  v5 = *(_DWORD *)(a2 + 372);
  v6 = type_info::raw_name(&vostok::math::curve_line_points<vostok::math::float3_pod,0> `RTTI Type Descriptor');
  *(_DWORD *)(a2 + 620) = (*(int (__thiscall **)(int, unsigned int, char *, const char *, const char *, int))(*(_DWORD *)v5 + 16))(
                            v5,
                            48 * num_curves,
                            v6,
                            "vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data",
                            ".\\particle_beam_emitter_instance.cpp",
                            91);
  *(_DWORD *)(a2 + 628) = num_curves;
  if ( num_curves )
  {
    v13 = 0;
    v12 = v4;
    do
    {
      v7 = v13 + *(_DWORD *)(a2 + 620);
      if ( v7 )
      {
        *(_DWORD *)(v7 + 32) = 0;
        *(_DWORD *)(v7 + 36) = 0;
      }
      vostok::math::curve_line_points<vostok::math::float3_pod,0>::free_memory(
        *(vostok::math::curve_line_points<vostok::math::float3_pod,0> **)(a2 + 372),
        v13 + *(_DWORD *)(a2 + 620));
      v13 += 48;
      --v12;
    }
    while ( v12 );
  }
  v8 = *(_DWORD *)(a2 + 372);
  v9 = type_info::raw_name(&vostok::math::float3 [15] `RTTI Type Descriptor');
  *(_DWORD *)(a2 + 624) = (*(int (__thiscall **)(int, unsigned int, char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
                            v8,
                            180 * v4,
                            v9,
                            "vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data",
                            ".\\particle_beam_emitter_instance.cpp",
                            100);
  if ( v4 )
  {
    v10 = 0;
    do
    {
      v11 = v10 + *(_DWORD *)(a2 + 624);
      if ( v11 )
      {
        *(_DWORD *)(v11 + 32) = 0;
        *(_DWORD *)(v11 + 36) = 0;
      }
      v10 += 180;
      --v4;
    }
    while ( v4 );
  }
}
