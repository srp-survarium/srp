void __fastcall vostok::render::lights_db::add_light(
        int a1,
        unsigned int id,
        vostok::render::lights_db *this,
        vostok::render::light_props *props)
{
  vostok::render::light_data *M_start; // esi
  int v5; // eax
  int v6; // ecx
  vostok::render::light *v7; // eax
  vostok::render::light *v8; // eax
  vostok::render::light *m_object; // ebx
  stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *v10; // ecx
  vostok::render::light *flags; // ecx
  vostok::render::grass_render_model *v13; // esi
  const stlp_std::__false_type *v14; // [esp+0h] [ebp-18h]
  unsigned int v15; // [esp+4h] [ebp-14h]
  bool v16; // [esp+8h] [ebp-10h]
  stlp_std::__false_type __formal; // [esp+Fh] [ebp-9h] BYREF
  vostok::render::light_data light_to_add; // [esp+10h] [ebp-8h] BYREF

  M_start = this->m_lights._M_impl._M_start;
  v5 = this->m_lights._M_impl._M_finish - this->m_lights._M_impl._M_start;
  light_to_add.light.m_object = 0;
  light_to_add.id = id;
  while ( v5 > 0 )
  {
    v6 = v5 >> 1;
    if ( M_start[v5 >> 1].id >= id )
    {
      v5 >>= 1;
    }
    else
    {
      M_start += v6 + 1;
      v5 += -1 - v6;
    }
  }
  v7 = (vostok::render::light *)vostok::memory::doug_lea_allocator::malloc_impl(
                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                  0x1A0u);
  if ( v7 )
    vostok::render::light::light(v7, this->m_lights_tree);
  else
    v8 = 0;
  vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v8,
    &light_to_add.light);
  m_object = light_to_add.light.m_object;
  vostok::render::fill_light(light_to_add.light.m_object, props);
  if ( this->m_lights._M_impl._M_end_of_storage._M_data - this->m_lights._M_impl._M_finish )
    stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_fill_insert_aux(
      &this->m_lights._M_impl,
      M_start,
      1u,
      (unsigned int)&light_to_add,
      &__formal);
  else
    stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_insert_overflow_aux(
      v10,
      (stlp_std::reverse_iterator<vostok::render::light_data *> *)this,
      M_start,
      &light_to_add,
      v14,
      v15,
      v16);
  flags = (vostok::render::light *)m_object->flags;
  LOBYTE(flags) = (unsigned __int8)flags & 0xF;
  if ( (_BYTE)flags == 4 )
  {
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &light_to_add.light,
      &this->m_sun);
    *(_DWORD *)&this->m_sun.m_object->flags |= 0x10u;
  }
  if ( m_object->m_reference_count-- == 1 )
  {
    v13 = vostok::render::g_allocator.m_object;
    vostok::render::light::~light(flags, (int)m_object);
    BYTE2(v13->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v13->m_reconstruction_info_actuality_tick), m_object);
  }
}
