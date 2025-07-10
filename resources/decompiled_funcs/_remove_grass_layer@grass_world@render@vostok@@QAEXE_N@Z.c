void __thiscall vostok::render::grass_world::remove_grass_layer(
        vostok::render::grass_world *this,
        vostok::render::grass_world *id,
        unsigned __int8 do_populate)
{
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *M_finish; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *M_start; // ebx
  unsigned int *v5; // esi
  unsigned int *v6; // ebp
  vostok::render::grass_instance **m_object; // edi
  vostok::render::grass_instance **v8; // ebp
  const unsigned int *p_m_index; // eax
  vostok::render::grass_world **v10; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__true_type *v12; // [esp+0h] [ebp-24h]
  unsigned int v13; // [esp+4h] [ebp-20h]
  bool v14; // [esp+8h] [ebp-1Ch]
  vostok::render::grass_instance **end_instance; // [esp+10h] [ebp-14h]
  vostok::render::grass_template **end; // [esp+14h] [ebp-10h]
  vostok::render::vector<unsigned int> instances_to_remove; // [esp+18h] [ebp-Ch] BYREF

  M_finish = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)id->m_templates._M_impl._M_finish;
  M_start = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)id->m_templates._M_impl._M_start;
  v5 = 0;
  v6 = 0;
  end = (vostok::render::grass_template **)M_finish;
  memset(&instances_to_remove, 0, sizeof(instances_to_remove));
  if ( M_start != M_finish )
  {
    do
    {
      m_object = (vostok::render::grass_instance **)M_start->_M_start[3].m_object;
      v8 = (vostok::render::grass_instance **)M_start->_M_start[2].m_object;
      end_instance = m_object;
      if ( v8 != m_object )
      {
        do
        {
          LOBYTE(M_finish) = do_populate;
          if ( (*v8)->m_layer_id == do_populate )
          {
            p_m_index = &(*v8)->m_index;
            if ( v5 == instances_to_remove._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int>>::_M_insert_overflow(
                &instances_to_remove._M_impl,
                (char *)v5,
                M_finish,
                p_m_index,
                v12,
                v13,
                v14);
              v5 = instances_to_remove._M_impl._M_finish;
              m_object = end_instance;
            }
            else
            {
              *v5++ = *p_m_index;
              instances_to_remove._M_impl._M_finish = v5;
            }
          }
          ++v8;
        }
        while ( v8 != m_object );
        M_finish = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)end;
      }
      M_start = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)((char *)M_start + 4);
    }
    while ( M_start != M_finish );
    v6 = instances_to_remove._M_impl._M_start;
  }
  v10 = (vostok::render::grass_world **)v6;
  if ( v6 != v5 )
  {
    do
      vostok::render::grass_world::remove_instance(*v10++, (int)id);
    while ( v10 != (vostok::render::grass_world **)v5 );
  }
  if ( v6 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
  }
}
