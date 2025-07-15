void __userpurge survarium::artefact_container::artefact_container(
        survarium::artefact_container *this@<eax>,
        survarium::usable_object *a2@<ecx>,
        survarium::game_world *w)
{
  int v3; // eax
  char v4; // dl

  survarium::usable_object::usable_object(a2, (int)this, 1);
  *(_DWORD *)(v3 + 68) = &survarium::serializable_object::`vftable';
  *(_DWORD *)(v3 + 80) = 0;
  *(_DWORD *)(v3 + 84) = 0;
  *(_DWORD *)(v3 + 88) = 0;
  *(_BYTE *)(v3 + 97) = 0;
  *(_BYTE *)(v3 + 96) = v4;
  *(_DWORD *)v3 = &survarium::artefact_container::`vftable'{for `survarium::collision_geometry_subscriber'};
  *(_DWORD *)(v3 + 4) = &survarium::artefact_container::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(v3 + 68) = &survarium::artefact_container::`vftable';
  *(_DWORD *)(v3 + 100) = w;
}
