void __usercall vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  this[38].m_size = 0;
  ++*a2;
  if ( a2[2] )
    *(_DWORD *)(a2[3] + 608) = this;
  else
    a2[2] = this;
  a2[3] = this;
}
