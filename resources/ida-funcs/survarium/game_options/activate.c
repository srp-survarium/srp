void __userpurge survarium::game_options::activate(
        survarium::game_options *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene *parent_scene)
{
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // edi
  survarium::swf_input_translator *v7; // ecx
  int v8; // ebx
  survarium::swf_input_translator *v9; // ecx
  survarium::game_options *v10; // ecx
  float v11; // [esp+10h] [ebp-14h]
  float v12; // [esp+10h] [ebp-14h]
  struct survarium::flash_movie *v13; // [esp+14h] [ebp-10h]
  struct survarium::flash_movie *v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  float v17; // [esp+1Ch] [ebp-8h]
  float v18; // [esp+20h] [ebp-4h]

  if ( !*(_BYTE *)(a2 + 68) )
  {
    *(_DWORD *)(a2 + 48) = parent_scene;
    survarium::base_game_scene::show_movie(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 12),
      parent_scene);
    survarium::base_game_scene::show_movie(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 16),
      *(survarium::base_game_scene **)(a2 + 48));
    v3 = *(_DWORD *)(a2 + 52);
    *(_BYTE *)(a2 + 68) = 1;
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 48))(v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 16))(v4, a2);
    v5 = *(_DWORD *)(a2 + 48);
    v6 = *(_DWORD *)(a2 + 12);
    v15 = *(_DWORD *)(v5 + 140);
    v16 = *(_DWORD *)(v5 + 144);
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 52) + 48))(*(_DWORD *)(a2 + 52));
    v18 = (float)v16;
    v17 = (float)v15;
    survarium::swf_input_translator::process_mouse_move(
      v7,
      0.0,
      (struct vostok::input::world *)LODWORD(v17),
      v18,
      *(float *)(v6 + 264),
      v11,
      v13);
    v8 = *(_DWORD *)(a2 + 16);
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 52) + 48))(*(_DWORD *)(a2 + 52));
    survarium::swf_input_translator::process_mouse_move(
      v9,
      0.0,
      (struct vostok::input::world *)LODWORD(v17),
      v18,
      *(float *)(v8 + 264),
      v12,
      v14);
    survarium::game_options::fill_menu_buttons(
      v10,
      a2,
      parent_scene == (survarium::base_game_scene *)(*(_DWORD *)(a2 + 52) + 192));
  }
}
