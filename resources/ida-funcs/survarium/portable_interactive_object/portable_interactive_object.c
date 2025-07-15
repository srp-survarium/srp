void __userpurge survarium::portable_interactive_object::portable_interactive_object(
        survarium::portable_interactive_object *this@<ecx>,
        int a2@<edi>,
        survarium::base_game_scene *game_scene,
        vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum default_locator_id)
{
  vostok::animation::hand_to_weapon_ik_solver *v4; // ecx

  survarium::portable_interactive_object_core::portable_interactive_object_core(this, a2);
  *(_DWORD *)a2 = &survarium::portable_interactive_object::`vftable';
  vostok::animation::hand_to_weapon_ik_solver::hand_to_weapon_ik_solver(v4, a2 + 496);
  *(_DWORD *)(a2 + 1832) = 0;
  *(_DWORD *)(a2 + 1828) = a2;
  *(_DWORD *)(a2 + 1836) = game_scene;
  *(_BYTE *)(a2 + 1840) = 0;
  *(_DWORD *)(a2 + 1844) = default_locator_id;
}
