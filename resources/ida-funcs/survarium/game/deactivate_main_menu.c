void __usercall survarium::game::deactivate_main_menu(survarium::game *this@<ecx>, int a2@<edi>)
{
  vostok::particle::particle_system_instance_impl *v2; // ecx
  int v3; // ecx
  int v4; // eax

  if ( *(_BYTE *)(a2 + 15140) )
  {
    survarium::base_game_scene::hide_movie(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 15084),
      (vostok::particle::particle_system_instance_impl *)this,
      *(survarium::base_game_scene **)(a2 + 15120));
    survarium::base_game_scene::hide_movie(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 15088),
      v2,
      *(survarium::base_game_scene **)(a2 + 15120));
    v3 = *(_DWORD *)(a2 + 15124);
    *(_DWORD *)(a2 + 15120) = 0;
    *(_BYTE *)(a2 + 15140) = 0;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 48))(v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 20))(v4, a2 + 15072);
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 13900) + 32))(*(_DWORD *)(a2 + 13900), 1);
  }
}
