BOOL __userpurge survarium::base_network_client::is_player_current@<eax>(
        survarium::base_network_client *this@<ecx>,
        int a2@<eax>,
        const unsigned __int8 id)
{
  int v3; // eax

  v3 = *(_DWORD *)(a2 + 4);
  return v3
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && *(_BYTE *)(v3 + 304) == id;
}
