void __usercall vostok::animation::mixing::n_ary_tree_cloner::initialize(
        vostok::animation::mixing::n_ary_tree_cloner *this@<edi>,
        const vostok::animation::mixing::n_ary_tree *from@<ecx>,
        const vostok::animation::mixing::n_ary_tree *to@<eax>)
{
  unsigned int m_interpolators_count; // edx
  unsigned int v4; // ebx
  const vostok::animation::base_interpolator **m_interpolators; // ecx
  void *v6; // esp
  const vostok::animation::base_interpolator **v7; // esi
  const vostok::animation::base_interpolator **v8; // ebx
  const vostok::animation::base_interpolator **v9; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // ecx
  const vostok::animation::base_interpolator **v11; // ebx
  unsigned int v12; // eax
  int v13; // edx
  vostok::mutable_buffer *m_buffer; // eax
  const vostok::animation::base_interpolator *v15; // eax
  const vostok::animation::base_interpolator **v16; // ecx
  const vostok::animation::base_interpolator *v17[2]; // [esp+0h] [ebp-1Ch] BYREF
  const vostok::animation::base_interpolator *const *from_interpolators_begin; // [esp+8h] [ebp-14h]
  unsigned int to_interpolators_count; // [esp+Ch] [ebp-10h]
  const vostok::animation::base_interpolator *const *to_interpolators_begin; // [esp+10h] [ebp-Ch]
  vostok::animation::merge_interpolators_predicate __comp[4]; // [esp+14h] [ebp-8h]
  const vostok::animation::base_interpolator **j; // [esp+18h] [ebp-4h]

  m_interpolators_count = to->m_interpolators_count;
  v4 = from->m_interpolators_count;
  m_interpolators = from->m_interpolators;
  to_interpolators_begin = to->m_interpolators;
  to_interpolators_count = m_interpolators_count;
  from_interpolators_begin = m_interpolators;
  v6 = alloca(4 * (m_interpolators_count + v4));
  __comp[0] = 0;
  v7 = v17;
  LOBYTE(j) = 0;
  v8 = stlp_std::merge<vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * *,vostok::animation::merge_interpolators_predicate>(
         (const vostok::animation::base_interpolator **)from_interpolators_begin,
         (const vostok::animation::base_interpolator **)to_interpolators_begin,
         &from_interpolators_begin[v4],
         &to_interpolators_begin[m_interpolators_count],
         v17);
  v9 = stlp_std::adjacent_find<vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
         v17,
         v8);
  if ( v9 != v8 )
    v9 = stlp_std::priv::__unique_copy<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
           v9,
           v9,
           v8);
  m_constructor = this->m_constructor;
  v11 = v9;
  v12 = v9 - v17;
  this->m_interpolators_count = v12;
  this->m_interpolators = (const vostok::animation::base_interpolator **)m_constructor->m_buffer->m_data;
  v13 = 4 * v12;
  m_buffer = m_constructor->m_buffer;
  m_buffer->m_data += v13;
  m_buffer->m_size -= v13;
  j = this->m_interpolators;
  if ( v17 != v11 )
  {
    do
    {
      v15 = (*v7)->clone(*v7, this->m_constructor);
      v16 = j;
      *j = v15;
      ++v7;
      j = v16 + 1;
    }
    while ( v7 != v11 );
  }
}
