int __userpurge vostok::animation::mixing::binary_tree_expression_simplifier::new_weight@<eax>(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>,
        float interpolator,
        const struct vostok::animation::base_interpolator *a5)
{
  int *v5; // ecx
  int result; // eax

  v5 = *(int **)(a2 + 4);
  result = *v5;
  *v5 += 32;
  v5[1] -= 32;
  if ( result )
  {
    *(_DWORD *)(result + 4) = 0;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 0;
    *(_DWORD *)(result + 16) = 0;
    *(_DWORD *)result = &vostok::animation::mixing::binary_tree_weight_node::`vftable';
    *(float *)(result + 20) = interpolator;
    *(_DWORD *)(result + 24) = a3;
    *(_DWORD *)(result + 28) = a3;
  }
  return result;
}
