void __usercall vostok::animation::animation_player::destroy_subscriptions(
        const vostok::animation::subscribed_channel *channels_head@<eax>)
{
  const vostok::animation::subscribed_channel *i; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *first_callback; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v3; // esi
  vostok::resources::managed_resource *m_object; // eax
  void (__cdecl *v5)(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *, vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *, int); // eax

  for ( i = channels_head; i; i = i->next )
  {
    first_callback = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)i->first_callback;
    while ( first_callback )
    {
      v3 = first_callback;
      first_callback = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)first_callback[10].m_object;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v3 + 8);
      m_object = v3->m_object;
      if ( v3->m_object )
      {
        if ( ((unsigned __int8)m_object & 1) == 0 )
        {
          v5 = *(void (__cdecl **)(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *, vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *, int))((unsigned int)m_object & 0xFFFFFFFE);
          if ( v5 )
            v5(v3 + 2, v3 + 2, 2);
        }
        v3->m_object = 0;
      }
    }
  }
}
