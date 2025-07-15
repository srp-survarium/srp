void __usercall boost::detail::shared_count::~shared_count(
        boost::detail::shared_count *this@<ecx>,
        volatile signed __int32 **a2@<eax>)
{
  volatile signed __int32 *v2; // esi

  v2 = *a2;
  if ( *a2 && !_InterlockedExchangeAdd(v2 + 1, 0xFFFFFFFF) )
  {
    (*(void (__thiscall **)(volatile signed __int32 *))(*v2 + 4))(v2);
    if ( !_InterlockedExchangeAdd(v2 + 2, 0xFFFFFFFF) )
      (*(void (__thiscall **)(volatile signed __int32 *))(*v2 + 8))(v2);
  }
}
