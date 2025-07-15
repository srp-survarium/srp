void __userpurge vostok::particle::particle_system::load_from_config<vostok::configs::binary_config_value>(
        vostok::particle::particle_system *this@<ecx>,
        const vostok::configs::binary_config_value *a2@<esi>,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *config,
        bool mt_alloc)
{
  char *v5; // eax
  _DWORD *pointer; // eax
  _DWORD *v7; // eax
  int v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  vostok::particle::particle_system *v10; // ecx

  a2[11].id.pointer = (const char *)1;
  v5 = type_info::raw_name(&vostok::particle::particle_system_lod `RTTI Type Descriptor');
  a2[11].data.pointer = allocator->call_malloc(
                          allocator,
                          32,
                          v5,
                          "vostok::particle::particle_system::load_from_config",
                          "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_system_inline.h",
                          76);
  memset((void *)a2[11].data.pointer, 0, 0x20u);
  pointer = a2[11].data.pointer;
  if ( pointer )
  {
    *pointer = 0;
    pointer[1] = 0;
    pointer[2] = 0;
    pointer[3] = 0;
  }
  v7 = a2[11].data.pointer;
  v8 = LODWORD(s_bm_current_air_resistance);
  v7[2] = 0;
  v7[4] = 0;
  *((_BYTE *)v7 + 24) = 1;
  v7[5] = v8;
  *v7 = 0;
  if ( vostok::configs::binary_config_value::value_exists(0, (int)config, (unsigned int)"LOD 0") )
  {
    v9 = vostok::configs::binary_config_value::operator[](config, "LOD 0");
    vostok::particle::particle_system::load_lod_from_config<vostok::configs::binary_config_value>(
      v10,
      v8,
      a2,
      (vostok::particle::particle_system_lod *)allocator,
      (vostok::particle::particle_emitter *)a2[11].data.pointer,
      v9);
  }
}
