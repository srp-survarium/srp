void __userpurge survarium::game_world_core::assign_physics_transforms(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>,
        survarium::base_player *time_in_ms)
{
  long double v3; // rdi
  survarium::base_player *v4; // ecx

  HIDWORD(v3) = *(_DWORD *)(a2 + 49412);
  LODWORD(v3) = *(_DWORD *)(a2 + 49416);
  while ( HIDWORD(v3) != LODWORD(v3) )
  {
    v4 = *(survarium::base_player **)(*(_DWORD *)HIDWORD(v3) + 740);
    if ( v4 != time_in_ms )
      survarium::base_player::assign_physics_transform(v4, v3, *(void **)HIDWORD(v3));
    HIDWORD(v3) += 4;
  }
}
