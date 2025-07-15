void __usercall vostok::threading::event::~event(vostok::threading::event *this@<ecx>, HANDLE *a2@<eax>)
{
  CloseHandle(*a2);
}
