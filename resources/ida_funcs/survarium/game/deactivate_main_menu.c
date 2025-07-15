void __usercall survarium::game::deactivate_main_menu(survarium::game *this@<ecx>, int a2@<edi>)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // eax

  if ( *(_BYTE *)(a2 + 2128) )
  {
    survarium::base_game_scene::hide_movie(
      *(survarium::base_game_scene **)(a2 + 2088),
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 2092),
      (int)this);
    survarium::base_game_scene::hide_movie(
      *(survarium::base_game_scene **)(a2 + 2088),
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 2096),
      v2);
    v3 = *(_DWORD *)(a2 + 2116);
    *(_DWORD *)(a2 + 2088) = 0;
    *(_BYTE *)(a2 + 2128) = 0;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 40))(v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 20))(v4, a2 + 2076);
  }
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 940) + 20))(*(_DWORD *)(a2 + 940), 1);
}
