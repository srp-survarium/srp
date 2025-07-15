void __userpurge survarium::object_sound::object_sound(
        survarium::object_sound *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::base_game_scene *w)
{
  survarium::game_object_static::game_object_static(this, a2, w);
  *a2 = &survarium::object_sound::`vftable';
  a2[86] = 0;
  a2[87] = 0;
}
