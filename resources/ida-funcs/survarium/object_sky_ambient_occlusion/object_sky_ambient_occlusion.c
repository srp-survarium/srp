void __userpurge survarium::object_sky_ambient_occlusion::object_sky_ambient_occlusion(
        survarium::object_sky_ambient_occlusion *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *w)
{
  unsigned int v3; // eax

  survarium::game_object_static::game_object_static(this, (_DWORD *)a2, w);
  *(_DWORD *)a2 = &survarium::object_sky_ambient_occlusion::`vftable';
  *(_DWORD *)(a2 + 336) = a2 + 348;
  *(_DWORD *)(a2 + 340) = a2 + 348;
  *(_DWORD *)(a2 + 344) = a2 + 608;
  *(_BYTE *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 612) = 512;
  *(_DWORD *)(a2 + 616) = 512;
  *(_DWORD *)(a2 + 620) = 512;
  *(_DWORD *)(a2 + 624) = 256;
  *(_DWORD *)(a2 + 628) = 256;
  v3 = sky_ao_volume_ids++;
  *(_DWORD *)(a2 + 632) = v3;
  *(_BYTE *)(a2 + 608) = 1;
  *(_BYTE *)(a2 + 609) = 0;
}
