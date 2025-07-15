const survarium::game_material *__userpurge survarium::game_material_manager::get_material@<eax>(
        survarium::game_material_manager *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 id)
{
  if ( id == 0xFFFF || !*(_DWORD *)(a2 + 4 * id + 264) )
    return *(const survarium::game_material **)((char *)&dword_10308 + a2);
  else
    return *(const survarium::game_material **)(a2 + 4 * id + 264);
}
