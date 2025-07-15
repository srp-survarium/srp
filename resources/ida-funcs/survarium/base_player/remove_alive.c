void __userpurge survarium::base_player::remove_alive(
        survarium::base_player *this@<ecx>,
        int a2@<eax>,
        const bool real_remove)
{
  survarium::hit_affects_type_enum v4; // ebx
  survarium::affect_subscriber *v5; // edi

  if ( real_remove )
    survarium::base_player::deactivate_physics(this, a2);
  v4 = affects_type_blindness;
  v5 = (survarium::affect_subscriber *)((char *)&unk_10FF8 + a2);
  do
    survarium::damage_model::unsubscribe_from_affect(*(survarium::damage_model **)(a2 + 704), v4--, v5--);
  while ( v4 >= affects_type_death );
  *(_BYTE *)(a2 + 764) = 0;
  *(_DWORD *)(a2 + 744) = 0;
  *(_DWORD *)(a2 + 748) = 0;
  *(_DWORD *)(a2 + 752) = 0;
}
