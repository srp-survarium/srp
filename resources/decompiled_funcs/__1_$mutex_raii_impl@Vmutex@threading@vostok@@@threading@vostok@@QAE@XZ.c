void __usercall vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
        vostok::threading::mutex_raii_impl<vostok::threading::mutex> *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_BYTE *)(a2 + 4) )
  {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)a2);
    *(_BYTE *)(a2 + 4) = 0;
  }
}
