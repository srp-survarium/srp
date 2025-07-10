void __userpurge vostok::resources::queries_result::set_result(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>,
        bool result)
{
  if ( result )
    _InterlockedExchange((volatile __int32 *)(a2 + 64), 1);
  else
    _InterlockedExchange((volatile __int32 *)(a2 + 64), 0);
}
