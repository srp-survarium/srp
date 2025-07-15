void __usercall survarium::game_world_ui::on_unload(survarium::game_world_ui *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)(v2 + 264) + 4) + 88))(
        *(_DWORD *)(*(_DWORD *)(v2 + 264) + 4),
        1);
    *(_WORD *)(a2 + 48) = 0;
  }
  else
  {
    *(_WORD *)(a2 + 48) = 0;
  }
}
