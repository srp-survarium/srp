void __usercall survarium::lobby_character::clear_resources(
        survarium::lobby_character *this@<ecx>,
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *a2@<eax>)
{
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *v2; // esi
  survarium::player *m_object; // ecx

  v2 = a2 + 1141;
  m_object = a2[1141].m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_object->remove(m_object, 1);
      v2->m_object->clear(v2->m_object);
      vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
        v2,
        0);
    }
  }
}
