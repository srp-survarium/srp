unsigned int __usercall vostok::animation::mixing::n_ary_tree::nearest_event_time_in_ms@<eax>(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 4) )
    return *(_DWORD *)(**(_DWORD **)(a2 + 20) + 164);
  else
    return -1;
}
