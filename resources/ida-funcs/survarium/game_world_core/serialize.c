void __userpurge survarium::game_world_core::serialize(
        survarium::game_world_core *this@<ecx>,
        int a2@<edi>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *item)
{
  survarium::bullet_manager *v3; // ecx
  _DWORD *v4; // esi
  unsigned __int8 v5; // cl
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  int v7; // esi
  int k; // esi
  _DWORD *v9; // esi
  _DWORD *v10; // ebx
  int j; // [esp+Ch] [ebp-8h]
  _DWORD *i; // [esp+10h] [ebp-4h]

  survarium::game_state_history_item::clear_buffers((survarium::game_state_history_item *)this, item);
  *(vostok::animation::mixing::n_ary_tree_intrusive_base **)((char *)&item->m_object + (_DWORD)&loc_B9937 + 1) = *(vostok::animation::mixing::n_ary_tree_intrusive_base **)(a2 + 51188);
  v4 = *(_DWORD **)(a2 + 49412);
  for ( i = *(_DWORD **)(a2 + 49416); v4 != i; ++v4 )
  {
    v5 = *(_BYTE *)(*v4 + 304);
    v6 = &item[9237 * v5];
    LOBYTE(v6[520].m_object) = v5;
    (*(void (__thiscall **)(_DWORD, vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, int))(*(_DWORD *)*v4 + 52))(
      *v4,
      v6 + 516,
      v6 + 1038,
      v6 + 1045,
      v6 + 1044,
      1000000000 - *(_DWORD *)(a2 + 51188));
  }
  survarium::bullet_manager::serialize(
    v3,
    *(_DWORD *)(a2 + 51160),
    (vostok::network_core::buffer_writer *)((char *)&loc_B6AA0 + (_DWORD)item),
    1000000000 - *(_DWORD *)(a2 + 51188));
  if ( *(_DWORD *)(a2 + 51168) )
    (*(void (__thiscall **)(_DWORD, char *, int))(**(_DWORD **)(a2 + 51168) + 40))(
      *(_DWORD *)(a2 + 51168),
      (char *)item + (_DWORD)&loc_B76C4 + 4,
      1000000000 - *(_DWORD *)(a2 + 51188));
  v7 = *(_DWORD *)(a2 + 49504);
  for ( j = *(_DWORD *)(a2 + 49508); v7 != j; v7 += 4 )
    (*(void (__stdcall **)(char *, int))(**(_DWORD **)v7 + 60))(
      (char *)item + (_DWORD)&loc_B78EE + 2,
      1000000000 - *(_DWORD *)(a2 + 51188));
  for ( k = *(_DWORD *)(a2 + 49552); k; k = *(_DWORD *)(k + 8) )
    (**(void (__thiscall ***)(int, char *, int))k)(
      k,
      (char *)&loc_B9918 + (_DWORD)item,
      1000000000 - *(_DWORD *)(a2 + 51188));
  *((_BYTE *)&item->m_object + (_DWORD)&loc_B993F + 3) = 0;
  v9 = *(_DWORD **)(a2 + 49504);
  v10 = *(_DWORD **)(a2 + 49508);
  while ( v9 != v10 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v9 + 72))(*v9, *(_DWORD *)(a2 + 51188)) )
    {
      *((_BYTE *)&item->m_object + (_DWORD)&loc_B993F + 3) = 1;
      return;
    }
    ++v9;
  }
}
