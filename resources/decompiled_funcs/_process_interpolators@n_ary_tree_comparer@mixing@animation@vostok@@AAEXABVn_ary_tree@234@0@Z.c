void __userpurge vostok::animation::mixing::n_ary_tree_comparer::process_interpolators(
        const vostok::animation::mixing::n_ary_tree *from@<ecx>,
        const vostok::animation::mixing::n_ary_tree *to@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this)
{
  unsigned int m_interpolators_count; // edx
  const vostok::animation::base_interpolator **m_interpolators; // ebx
  unsigned int v5; // edi
  void *v6; // esp
  const vostok::animation::base_interpolator **v7; // esi
  const vostok::animation::base_interpolator **v8; // edi
  const vostok::animation::base_interpolator **v9; // eax
  const vostok::animation::base_interpolator **v10; // edi
  vostok::animation::mixing::n_ary_tree_comparer *v11; // eax
  int v12; // ebx
  bool v13; // cl
  const vostok::animation::base_interpolator *v14[3]; // [esp+0h] [ebp-28h] BYREF
  vostok::animation::interpolator_size_calculator size_calculator; // [esp+Ch] [ebp-1Ch] BYREF
  const vostok::animation::base_interpolator *const *to_interpolators_begin; // [esp+18h] [ebp-10h]
  vostok::animation::merge_interpolators_predicate __comp[4]; // [esp+1Ch] [ebp-Ch]
  unsigned int from_interpolators_count; // [esp+20h] [ebp-8h]
  binary_tree_unique_interpolators_predicate __binary_pred[4]; // [esp+24h] [ebp-4h]

  m_interpolators_count = from->m_interpolators_count;
  m_interpolators = from->m_interpolators;
  v5 = to->m_interpolators_count;
  to_interpolators_begin = to->m_interpolators;
  from_interpolators_count = m_interpolators_count;
  v6 = alloca(4 * (v5 + m_interpolators_count));
  v7 = v14;
  __comp[0] = 0;
  __binary_pred[0] = 0;
  v8 = stlp_std::merge<vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * *,vostok::animation::merge_interpolators_predicate>(
         m_interpolators,
         (const vostok::animation::base_interpolator **)to_interpolators_begin,
         &m_interpolators[m_interpolators_count],
         &to_interpolators_begin[v5],
         v14);
  v9 = stlp_std::adjacent_find<vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
         v14,
         v8);
  if ( v9 != v8 )
    v9 = stlp_std::priv::__unique_copy<vostok::animation::base_interpolator const * *,vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
           v9,
           v9,
           v8);
  v10 = v9;
  v11 = this;
  v12 = v10 - v14;
  v13 = this->m_equal && from_interpolators_count == v12;
  this->m_equal = v13;
  size_calculator.__vftable = (vostok::animation::interpolator_size_calculator_vtbl *)&vostok::animation::interpolator_size_calculator::`vftable';
  size_calculator.m_comparer = this;
  size_calculator.m_size = 0;
  if ( v14 != v10 )
  {
    do
    {
      (*v7)->accept(*v7, &size_calculator);
      ++v7;
    }
    while ( v7 != v10 );
    v11 = this;
  }
  v11->m_needed_buffer_size += 4 * v12;
}
