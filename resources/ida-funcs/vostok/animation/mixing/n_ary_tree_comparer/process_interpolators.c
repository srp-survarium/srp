void __userpurge vostok::animation::mixing::n_ary_tree_comparer::process_interpolators(
        const vostok::animation::mixing::n_ary_tree *from@<ecx>,
        const vostok::animation::mixing::n_ary_tree *to@<eax>,
        vostok::animation::mixing::n_ary_tree_comparer *this)
{
  unsigned int m_interpolators_count; // ebx
  unsigned int v4; // esi
  const vostok::animation::base_interpolator **m_interpolators; // ecx
  void *v6; // esp
  const vostok::animation::base_interpolator **v7; // eax
  const vostok::animation::base_interpolator **v8; // eax
  int v9; // edi
  bool v10; // zf
  bool v11; // cl
  const vostok::animation::base_interpolator **v12; // esi
  const vostok::animation::base_interpolator *v13[3]; // [esp+0h] [ebp-2Ch] BYREF
  _DWORD v14[3]; // [esp+Ch] [ebp-20h] BYREF
  const vostok::animation::base_interpolator **__first1; // [esp+18h] [ebp-14h]
  const vostok::animation::base_interpolator **__first2; // [esp+1Ch] [ebp-10h]
  vostok::animation::merge_interpolators_predicate __comp[4]; // [esp+20h] [ebp-Ch]
  vostok::animation::unique_interpolators_predicate __binary_pred[4]; // [esp+24h] [ebp-8h]
  const vostok::animation::base_interpolator **__result; // [esp+28h] [ebp-4h]

  m_interpolators_count = to->m_interpolators_count;
  v4 = from->m_interpolators_count;
  m_interpolators = from->m_interpolators;
  __first2 = to->m_interpolators;
  __first1 = m_interpolators;
  v6 = alloca(4 * (m_interpolators_count + v4));
  __result = v13;
  __binary_pred[0] = 0;
  __comp[0] = 0;
  v7 = stlp_std::merge<vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * *,vostok::animation::merge_interpolators_predicate>(
         __first1,
         __first2,
         &__first1[v4],
         &__first2[m_interpolators_count],
         v13);
  v8 = stlp_std::unique<vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
         __result,
         v7);
  v9 = v8 - __result;
  v10 = !this->m_equal;
  __first1 = v8;
  v11 = !v10 && v4 == v9;
  v12 = __result;
  v14[2] = 0;
  this->m_equal = v11;
  v14[0] = &vostok::animation::interpolator_size_calculator::`vftable';
  v14[1] = this;
  if ( v12 != v8 )
  {
    do
    {
      (*v12)->accept(*v12, (vostok::animation::interpolator_visitor *)v14);
      ++v12;
    }
    while ( v12 != __first1 );
  }
  this->m_needed_buffer_size += 4 * v9;
}
