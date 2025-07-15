void __thiscall survarium::network_client::unload(survarium::network_client *this)
{
  survarium::network_client *v2; // ecx
  bool v3; // bl
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> id; // [esp+10h] [ebp-8h]
  vostok::resources::unmanaged_intrusive_base *v6; // [esp+14h] [ebp-4h] BYREF

  LOBYTE(id.m_object) = 0;
  do
  {
    v3 = (this->get_player(this, &v6, id.m_object)->m_object != 0
        ? (unsigned int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        : 0) != 0;
    if ( v6 )
    {
      v2 = (survarium::network_client *)_InterlockedExchangeAdd(&v6[62].m_reference_count, 0xFFFFFFFF);
      if ( !v2 )
      {
        if ( v6 )
          v4 = (vostok::resources::unmanaged_resource *)&v6[36];
        else
          v4 = 0;
        vostok::resources::unmanaged_intrusive_base::destroy(v6 + 62, v4);
      }
    }
    if ( v3 )
      survarium::network_client::destroy_player_impl(v2, this, id);
    ++LOBYTE(id.m_object);
  }
  while ( LOBYTE(id.m_object) < 0x14u );
}
