void __usercall vostok::render::additional_material::set_parameters(
        vostok::render::additional_material *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // ebx
  int v3; // edi
  float z; // esi
  int v5; // eax

  v2 = a2[1];
  v3 = *a2;
  if ( *a2 != v2 )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    do
    {
      v5 = *(_DWORD *)(v3 + 64);
      if ( v5 == 4 || v5 == 8 || v5 == 12 || v5 == 16 || v5 == 64 )
      {
        vostok::render::constants_handler<1>::set_constant<float>(
          (vostok::render::constants_handler<1> *)(LODWORD(z) + 3672),
          *(const vostok::render::shader_constant_host **)(v3 + 68),
          (const vostok::math::float3 *)v3,
          1);
        ++*(_DWORD *)(LODWORD(z) + 7420);
      }
      v3 += 72;
    }
    while ( v3 != v2 );
  }
}
