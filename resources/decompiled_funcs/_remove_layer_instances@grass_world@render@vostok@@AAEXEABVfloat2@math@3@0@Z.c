void __userpurge vostok::render::grass_world::remove_layer_instances(
        vostok::render::grass_world *this@<ecx>,
        bool a2@<bpl>,
        const stlp_std::__true_type *a3@<edi>,
        unsigned int a4@<esi>,
        vostok::render::grass_world *id,
        const vostok::math::float2 *cell_lt,
        const vostok::math::float2 *cell_rb,
        vostok::math::float2 *cell_rba)
{
  const vostok::math::float2 *v8; // edi
  vostok::render::grass_patch *patch; // eax
  unsigned int *v10; // esi
  void **M_start; // ebp
  void **M_finish; // ebx
  char *v13; // eax
  float v14; // edx
  bool v15; // cc
  const unsigned int *v16; // eax
  unsigned int *v17; // ebp
  unsigned int *v18; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__true_type *v20; // [esp-10h] [ebp-28h]
  unsigned int v21; // [esp-Ch] [ebp-24h]
  bool v22; // [esp-8h] [ebp-20h]
  vostok::render::vector<unsigned int> instances_to_remove; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 p; // [esp+Ch] [ebp-Ch]

  v22 = a2;
  v21 = a4;
  v20 = a3;
  v8 = cell_rb;
  *(float *)&instances_to_remove._M_impl._M_start = cell_rb->x + 0.5;
  instances_to_remove._M_impl._M_finish = 0;
  *(float *)&instances_to_remove._M_impl._M_end_of_storage._M_data = cell_rb->y + 0.5;
  patch = vostok::render::grass_world::find_patch(id, (const vostok::math::float3 *)&instances_to_remove);
  v10 = 0;
  if ( patch )
  {
    M_start = patch->m_instances._M_impl._M_start;
    M_finish = patch->m_instances._M_impl._M_finish;
    memset(&instances_to_remove, 0, sizeof(instances_to_remove));
    if ( M_start != M_finish )
    {
      do
      {
        v13 = (char *)*M_start;
        if ( *((_BYTE *)*M_start + 80) == (_BYTE)cell_lt )
        {
          v14 = *((float *)v13 + 16);
          *(_QWORD *)&p.x = *((_QWORD *)v13 + 7);
          v15 = p.x <= v8->x;
          p.z = v14;
          if ( !v15 && p.z > v8->y && cell_rba->x > p.x && cell_rba->y > p.z )
          {
            v16 = (const unsigned int *)(v13 + 76);
            if ( v10 == instances_to_remove._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int>>::_M_insert_overflow(
                &instances_to_remove._M_impl,
                (char *)v10,
                (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)cell_rba,
                v16,
                v20,
                v21,
                v22);
              v10 = instances_to_remove._M_impl._M_finish;
              v8 = cell_rb;
            }
            else
            {
              *v10++ = *v16;
              instances_to_remove._M_impl._M_finish = v10;
            }
          }
        }
        ++M_start;
      }
      while ( M_start != M_finish );
      v17 = instances_to_remove._M_impl._M_start;
      if ( instances_to_remove._M_impl._M_start != v10 )
      {
        v18 = instances_to_remove._M_impl._M_start;
        do
          vostok::render::grass_world::remove_instance((vostok::render::grass_world *)*v18++, (int)id);
        while ( v18 != v10 );
        id->m_need_populate = 1;
      }
      if ( v17 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v17);
      }
    }
  }
}
