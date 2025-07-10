void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        int *a2@<ebx>,
        const stlp_std::random_access_iterator_tag *a3@<edi>,
        vostok::render::ui::vertex *__pos,
        unsigned int __n,
        const vostok::render::ui::vertex *__x,
        const stlp_std::__false_type *__formal)
{
  const D3D11_INPUT_ELEMENT_DESC *v7; // esi
  unsigned int m_color; // eax
  __int64 v10; // xmm0_8
  vostok::render::ui::vertex *M_finish; // edi
  unsigned int v12; // ebx
  const stlp_std::random_access_iterator_tag *v14; // [esp-8h] [ebp-2Ch]
  const stlp_std::random_access_iterator_tag *v15; // [esp-8h] [ebp-2Ch]
  const stlp_std::random_access_iterator_tag *v16; // [esp-8h] [ebp-2Ch]
  int *v18; // [esp-4h] [ebp-28h]
  int *v19; // [esp-4h] [ebp-28h]
  int *v20; // [esp-4h] [ebp-28h]
  vostok::render::ui::vertex __x_copy; // [esp+8h] [ebp-1Ch] BYREF
  vostok::render::ui::vertex *__na; // [esp+2Ch] [ebp+8h]

  v7 = (const D3D11_INPUT_ELEMENT_DESC *)__x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v12 = M_finish - __pos;
    if ( v12 <= __n )
    {
      __na = &M_finish[__n - v12];
      stlp_std::priv::__ufill<vostok::render::ui::vertex *,vostok::render::ui::vertex,int>(M_finish, __na, __x, a3, a2);
      this->_M_finish = __na;
      stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>(
        __pos,
        M_finish,
        __na,
        v15,
        v19);
      this->_M_finish += v12;
      stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        (D3D11_INPUT_ELEMENT_DESC *)__pos,
        (D3D11_INPUT_ELEMENT_DESC *)M_finish,
        v7,
        v16,
        v20);
    }
    else
    {
      stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>(
        &M_finish[-__n],
        M_finish,
        M_finish,
        a3,
        a2);
      this->_M_finish += __n;
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
      stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        (D3D11_INPUT_ELEMENT_DESC *)__pos,
        (D3D11_INPUT_ELEMENT_DESC *)&__pos[__n],
        (const D3D11_INPUT_ELEMENT_DESC *)__x,
        v14,
        v18);
    }
  }
  else
  {
    m_color = __x->m_color;
    *(_QWORD *)&__x_copy.m_position.x = *(_QWORD *)&__x->m_position.x;
    v10 = *(_QWORD *)&__x->m_position.elements[2];
    __x_copy.m_color = m_color;
    *(_QWORD *)&__x_copy.m_position.elements[2] = v10;
    __x_copy.m_uv = __x->m_uv;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}
