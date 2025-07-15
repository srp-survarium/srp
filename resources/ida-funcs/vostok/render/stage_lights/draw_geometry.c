void __usercall vostok::render::stage_lights::draw_geometry(
        vostok::render::light *l@<eax>,
        vostok::render::backend *a2@<ecx>)
{
  int v2; // eax
  unsigned int v3; // eax
  int v4; // [esp-10h] [ebp-14h]

  v2 = *(_DWORD *)&l->flags & 0xF;
  switch ( v2 )
  {
    case 0:
      goto LABEL_7;
    case 1:
      v4 = 18;
      goto LABEL_5;
    case 5:
LABEL_7:
      v3 = 540;
      goto LABEL_8;
  }
  v4 = 36;
LABEL_5:
  v3 = v4;
LABEL_8:
  vostok::render::backend::render_indexed(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v3,
    a2,
    D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    0,
    0);
}
