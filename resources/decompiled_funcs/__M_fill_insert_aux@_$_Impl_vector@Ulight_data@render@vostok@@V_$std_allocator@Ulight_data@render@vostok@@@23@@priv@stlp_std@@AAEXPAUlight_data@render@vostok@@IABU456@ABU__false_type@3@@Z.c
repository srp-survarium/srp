void __thiscall stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *this,
        vostok::render::light_data *__pos,
        unsigned int __n,
        unsigned int __x,
        const stlp_std::__false_type *__formal)
{
  const vostok::render::light_data *v5; // esi
  vostok::render::light *v7; // ecx
  vostok::render::light *m_object; // eax
  vostok::render::grass_render_model *v9; // esi
  vostok::render::light *v10; // ebp
  vostok::render::light_data *M_finish; // edi
  unsigned int v13; // eax
  const stlp_std::random_access_iterator_tag *v14; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v15; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v16; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v17; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v18; // [esp+0h] [ebp-1Ch]
  int *v19; // [esp+4h] [ebp-18h]
  int *v20; // [esp+4h] [ebp-18h]
  int *v21; // [esp+4h] [ebp-18h]
  int *v22; // [esp+4h] [ebp-18h]
  int *v23; // [esp+4h] [ebp-18h]
  vostok::render::light_data __x_copy; // [esp+10h] [ebp-Ch] BYREF
  vostok::render::light_data *__posa; // [esp+20h] [ebp+4h]
  vostok::render::light_data *__posb; // [esp+20h] [ebp+4h]
  vostok::render::light_data *__na; // [esp+24h] [ebp+8h]

  v5 = (const vostok::render::light_data *)__x;
  if ( (vostok::render::light_data *)__x < this->_M_start || (vostok::render::light_data *)__x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v13 = M_finish - __pos;
    __x = v13;
    if ( v13 <= __n )
    {
      __posb = &M_finish[__n - v13];
      stlp_std::priv::__ufill<vostok::render::light_data *,vostok::render::light_data,int>(
        M_finish,
        __posb,
        v5,
        v14,
        v19);
      this->_M_finish = __posb;
      stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        __pos,
        M_finish,
        __posb,
        v17,
        v22);
      this->_M_finish += __x;
      stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(__pos, M_finish, v5, v18, v23);
    }
    else
    {
      __posa = (vostok::render::light_data *)(8 * __n);
      __na = &M_finish[-__n];
      stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        __na,
        M_finish,
        M_finish,
        v14,
        v19);
      this->_M_finish = (vostok::render::light_data *)((char *)this->_M_finish + (unsigned int)__posa);
      stlp_std::priv::__copy_backward<vostok::render::light_data *,vostok::render::light_data *,int>(
        __pos,
        __na,
        M_finish,
        v15,
        v20);
      stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(
        __pos,
        (vostok::render::light_data *)((char *)__pos + (_DWORD)__posa),
        v5,
        v16,
        v21);
    }
  }
  else
  {
    __x_copy.light.m_object = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this,
      &__x_copy.light,
      (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__x);
    __x_copy.id = v5->id;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
    m_object = __x_copy.light.m_object;
    if ( __x_copy.light.m_object )
    {
      --__x_copy.light.m_object->m_reference_count;
      if ( !m_object->m_reference_count )
      {
        v9 = vostok::render::g_allocator.m_object;
        v10 = __x_copy.light.m_object;
        if ( __x_copy.light.m_object )
        {
          vostok::render::light::~light(v7);
          BYTE2(v9->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v10);
        }
      }
    }
  }
}
