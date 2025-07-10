void __usercall survarium::game_options::deactivate(survarium::game_options *this@<ecx>, int a2@<esi>)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // eax

  if ( *(_BYTE *)(a2 + 52) )
  {
    survarium::base_game_scene::hide_movie(
      *(survarium::base_game_scene **)(a2 + 12),
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 16),
      (int)this);
    survarium::base_game_scene::hide_movie(
      *(survarium::base_game_scene **)(a2 + 12),
      (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 20),
      v2);
    v3 = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(a2 + 12) = 0;
    *(_BYTE *)(a2 + 52) = 0;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 40))(v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 20))(v4, a2);
  }
}
