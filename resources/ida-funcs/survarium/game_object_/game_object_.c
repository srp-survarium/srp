void __userpurge survarium::game_object_::game_object_(
        survarium::game_object_ *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::base_game_scene *s)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  a2[66] = s;
  *a2 = &survarium::game_object_::`vftable';
}
