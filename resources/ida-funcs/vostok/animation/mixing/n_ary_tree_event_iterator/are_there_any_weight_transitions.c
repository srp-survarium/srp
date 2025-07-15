bool __usercall vostok::animation::mixing::n_ary_tree_event_iterator::are_there_any_weight_transitions@<al>(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<ecx>,
        int a2@<eax>)
{
  bool v2; // al

  v2 = !*(_DWORD *)(a2 + 20) && *(_DWORD *)(a2 + 24) == -1 && !*(_WORD *)(a2 + 28);
  return !v2;
}
