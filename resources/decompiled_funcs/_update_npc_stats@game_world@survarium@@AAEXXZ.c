void __usercall survarium::game_world::update_npc_stats(survarium::game_world *this@<ecx>, int a2@<eax>)
{
  int v3; // eax
  int v4; // eax

  if ( *(_BYTE *)(a2 + 705)
    && *(_DWORD *)(a2 + 696)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    *(_BYTE *)(*(_DWORD *)(a2 + 168) + 11) = 1;
    survarium::npc_stats::set_stats(*(survarium::npc_stats **)(a2 + 696), *(_DWORD *)(a2 + 688));
    v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 168) + 36))(*(_DWORD *)(a2 + 168));
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 52))(v3);
    (*(void (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(*(_DWORD *)(a2 + 688) + 4) + 24))(
      *(_DWORD *)(*(_DWORD *)(a2 + 688) + 4),
      v4,
      a2 + 8);
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a2 + 168) + 11) = 0;
  }
}
