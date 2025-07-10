const vostok::animation::base_interpolator *__userpurge vostok::animation::mixing::n_ary_tree_cloner::clone@<eax>(
        vostok::animation::mixing::n_ary_tree_cloner *this@<ecx>,
        int a2@<eax>,
        const vostok::animation::base_interpolator *interpolator,
        bool assert_on_failure)
{
  const vostok::animation::base_interpolator *v4; // ebx
  _DWORD *v5; // esi
  _DWORD *v6; // edi

  v4 = interpolator;
  v5 = *(_DWORD **)(a2 + 16);
  v6 = &v5[*(_DWORD *)(a2 + 28)];
  if ( v5 == v6 )
    return 0;
  while ( 1 )
  {
    v4->accept(
      v4,
      (vostok::animation::interpolator_comparer *)&interpolator,
      (const vostok::animation::base_interpolator *)*v5);
    if ( !interpolator )
      break;
    if ( ++v5 == v6 )
      return 0;
  }
  return (const vostok::animation::base_interpolator *)*v5;
}
