bool __userpurge node_predicate::operator()@<al>(
        node_predicate *this@<ecx>,
        int *a2@<eax>,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_base_node *const right)
{
  int v4; // eax
  vostok::animation::mixing::n_ary_tree_base_node *v6; // [esp+0h] [ebp-1Ch]
  _DWORD v7[3]; // [esp+8h] [ebp-14h] BYREF
  char v8; // [esp+14h] [ebp-8h]

  v4 = *a2;
  v7[2] = 0;
  v7[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v7[1] = v4;
  v8 = 0;
  return vostok::animation::mixing::n_ary_tree_node_comparer::compare(
           (vostok::animation::mixing::n_ary_tree_node_comparer *)this,
           (int)v7,
           left,
           v6) == less;
}
