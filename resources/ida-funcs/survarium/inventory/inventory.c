void __userpurge survarium::inventory::inventory(
        survarium::inventory *this@<ecx>,
        int a2@<esi>,
        const survarium::items_dictionary *dict)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)(a2 + 268) = dict;
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)a2 = &survarium::inventory::`vftable';
  memset((void *)(a2 + 272), 0, 0x5Cu);
  *(_DWORD *)(a2 + 364) = 0;
  *(_BYTE *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  *(_BYTE *)(a2 + 396) = 0;
  *(_DWORD *)(a2 + 372) = 23;
  *(_DWORD *)(a2 + 384) = 23;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)(a2 + 392) = 0;
}
