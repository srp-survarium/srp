char __usercall survarium::inventory::update_weight@<al>(survarium::inventory *this@<ecx>, int a2@<esi>)
{
  _DWORD *v3; // edi
  unsigned __int16 v4; // bx
  int v5; // eax
  unsigned __int16 v6; // bx
  int v7; // [esp+8h] [ebp-4h]

  if ( !*(_BYTE *)(a2 + 396) )
    return 0;
  *(_DWORD *)(a2 + 392) = 0;
  v3 = (_DWORD *)(a2 + 272);
  v7 = 23;
  do
  {
    if ( *v3 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v4 = *(_WORD *)(*v3 + 280);
        *(float *)(a2 + 392) = (float)((float)v4
                                     * survarium::items_dictionary::item_by_id(
                                         *(survarium::items_dictionary **)(a2 + 268),
                                         (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(*v3 + 282))->weight)
                             + *(float *)(a2 + 392);
        v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v3 + 60))(*v3);
        if ( v5 )
        {
          if ( *(_BYTE *)(v5 + 1048) )
          {
            v6 = *(_WORD *)(v5 + 1102) + (*(_BYTE *)(v5 + 1112) != 0);
            *(float *)(a2 + 392) = (float)((float)v6
                                         * survarium::items_dictionary::item_by_id(
                                             *(survarium::items_dictionary **)(a2 + 268),
                                             (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(*(_DWORD *)(a2 + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 1044) + 4 * *(unsigned __int8 *)(v5 + 1049)) + 272) + 282))->weight)
                                 + *(float *)(a2 + 392);
          }
        }
      }
    }
    ++v3;
    --v7;
  }
  while ( v7 );
  *(_BYTE *)(a2 + 396) = 0;
  return 1;
}
