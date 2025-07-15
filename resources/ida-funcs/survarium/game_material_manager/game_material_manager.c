void __usercall survarium::game_material_manager::game_material_manager(
        survarium::game_material_manager *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *(int *)((char *)&dword_10308 + (_DWORD)a2) = 0;
  *(_WORD *)((char *)&off_1030C + (_DWORD)a2) = 11;
  *a2 = &survarium::game_material_manager::`vftable';
  memset((int)(a2 + 66), 0, 0x200u);
  memset((int)(a2 + 194), 0, (unsigned int)&_sbh_sizeHeaderList);
}
