void __usercall vostok::threading::mutex::~mutex(vostok::threading::mutex *this@<ecx>, _RTL_CRITICAL_SECTION *a2@<eax>)
{
  DeleteCriticalSection(a2);
}
