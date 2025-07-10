void __userpurge survarium::damage_zone_cook::on_sub_resources_loaded(
        survarium::damage_zone_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config_value *cfg_val)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebp
  void *v6; // eax
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *v7; // ecx
  survarium::damage_zone *v8; // eax
  survarium::damage_zone *v9; // edi
  unsigned int m_size; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *M_start; // esi
  bool v13; // zf
  unsigned int v14; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v16; // esi
  vostok::resources::query_result_for_cook *v17; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v18; // eax
  void *v19; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v20; // [esp-Ch] [ebp-38h]
  stlp_std::__false_type *v21; // [esp+0h] [ebp-2Ch]
  unsigned int v22; // [esp+4h] [ebp-28h]
  bool v23; // [esp+8h] [ebp-24h]
  survarium::damage_zone *zone; // [esp+14h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> __x; // [esp+18h] [ebp-14h] BYREF
  unsigned int v26; // [esp+1Ch] [ebp-10h]
  survarium::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > resources; // [esp+20h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *dataa; // [esp+30h] [ebp+4h]

  M_finish = 0;
  v26 = 0;
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x228u);
  if ( v6 )
  {
    survarium::damage_zone::damage_zone((survarium::damage_zone *)this->m_game_world, (int)v6, this->m_game_world);
    v9 = v8;
    zone = v8;
  }
  else
  {
    zone = 0;
    v9 = 0;
  }
  m_size = data->m_size;
  M_start = 0;
  v13 = m_size == 1;
  v14 = m_size - 1;
  memset(&resources, 0, sizeof(resources));
  if ( !v13 )
  {
    dataa = &data->m_queries[1].m_unmanaged_resource;
    v26 = v14;
    do
    {
      m_object = dataa->m_object;
      v16 = 0;
      __x.m_object = 0;
      if ( m_object )
      {
        v16 = m_object;
        __x.m_object = m_object;
        v7 = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      if ( M_finish == resources._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          v7,
          (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *> *)&resources,
          M_finish,
          &__x,
          v21,
          v22,
          v23);
        M_finish = resources._M_impl._M_finish;
        v9 = zone;
      }
      else
      {
        if ( M_finish )
        {
          M_finish->m_object = 0;
          if ( v16 )
          {
            M_finish->m_object = v16;
            _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
          }
        }
        resources._M_impl._M_finish = ++M_finish;
      }
      if ( v16 )
      {
        v7 = (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *)&v16->vostok::resources::unmanaged_intrusive_base;
        if ( !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v7, v16);
      }
      dataa += 180;
      --v26;
    }
    while ( v26 );
    M_start = resources._M_impl._M_start;
  }
  survarium::damage_zone::load(v9, cfg_val, a2, &resources, (survarium::vector<vostok::render::light_props> *)v21, v22);
  start_light_id += 64;
  v20.m_object = 0;
  if ( v9 )
  {
    v20.m_object = v9;
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    data->m_parent_query,
    v20,
    &vostok::resources::nocache_memory,
    0x228u);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v17,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::light_props *>,vostok::render::light_props>(
    0,
    0);
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>)M_start);
  if ( M_start )
  {
    v18 = M_start;
    v19 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v19, v18);
  }
}
