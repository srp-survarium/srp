void __thiscall vostok::render::res_texture_list::res_texture_list(
        vostok::render::res_texture_list *this,
        vostok::render::res_texture_list *slots,
        const vostok::fixed_vector<vostok::render::texture_slot,128> *slotsa)
{
  const vostok::fixed_vector<vostok::render::texture_slot,128> *v3; // esi
  unsigned int v4; // edi
  vostok::render::texture_slot **p_m_container; // ebp
  unsigned int v6; // eax
  int v7; // ebx
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v9; // eax
  const vostok::render::res_texture **v10; // edx
  const vostok::render::res_texture *v11; // esi
  unsigned int size; // [esp+10h] [ebp-8h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> __x; // [esp+14h] [ebp-4h] BYREF

  v3 = slotsa;
  v4 = 0;
  slots->m_reference_count = 0;
  p_m_container = (vostok::render::texture_slot **)&slots->m_container;
  slots->m_container._M_impl._M_start = 0;
  slots->m_container._M_impl._M_finish = 0;
  slots->m_container._M_impl._M_end_of_storage._M_data = 0;
  slots->m_is_registered = 0;
  v6 = v3->m_end - v3->m_begin;
  size = v6;
  if ( v6 )
  {
    v7 = 0;
    while ( 1 )
    {
      if ( v3->m_begin[v7].slot_id != -1 )
      {
        __x.m_object = 0;
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::resize(
          (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)p_m_container,
          v4 + 1,
          &__x);
        m_object = slotsa->m_begin[v7].texture.m_object;
        v9 = 0;
        v10 = (const vostok::render::res_texture **)(&(*p_m_container)->name.m_begin + v4);
        if ( m_object )
        {
          v9 = slotsa->m_begin[v7].texture.m_object;
          ++m_object->m_reference_count;
        }
        v11 = *v10;
        *v10 = v9;
        if ( v11 )
        {
          if ( v11->m_reference_count-- == 1 )
            vostok::render::res_texture::destroy_impl(m_object, v11);
        }
        v6 = size;
      }
      ++v4;
      ++v7;
      if ( v4 >= v6 )
        break;
      v3 = slotsa;
    }
  }
}
