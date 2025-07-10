void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 24) += 44;
  *(_BYTE *)(a2 + 32) = 0;
}
