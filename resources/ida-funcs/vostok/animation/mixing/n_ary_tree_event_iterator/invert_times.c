void __usercall vostok::animation::mixing::n_ary_tree_event_iterator::invert_times(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_WORD *)(a2 + 48) )
    *(_DWORD *)(a2 + 44) = (char *)this - *(_DWORD *)(a2 + 44);
  if ( *(_WORD *)(a2 + 32) )
    *(_DWORD *)(a2 + 28) = (char *)this - *(_DWORD *)(a2 + 28);
  if ( *(_WORD *)(a2 + 12) )
    *(_DWORD *)(a2 + 8) = (char *)this - *(_DWORD *)(a2 + 8);
}
