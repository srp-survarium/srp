void __userpurge survarium::inventory_item::inventory_item(
        survarium::inventory_item *this@<ecx>,
        int a2@<esi>,
        survarium::inventory_item::action_behaviour_type type,
        bool need_to_serialize)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 268) = type;
  *(_WORD *)(a2 + 280) = 0;
  *(_WORD *)(a2 + 282) = 0;
  *(_BYTE *)(a2 + 284) = need_to_serialize;
  *(_DWORD *)a2 = &survarium::inventory_item::`vftable';
  *(_DWORD *)(a2 + 276) = 23;
}
