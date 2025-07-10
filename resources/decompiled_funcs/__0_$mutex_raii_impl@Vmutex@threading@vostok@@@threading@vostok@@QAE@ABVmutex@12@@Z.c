void __usercall vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
        vostok::threading::mutex_raii_impl<vostok::threading::mutex> *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = this;
  vostok::threading::mutex::lock((vostok::threading::mutex *)this);
  *(_BYTE *)(a2 + 4) = 1;
}
