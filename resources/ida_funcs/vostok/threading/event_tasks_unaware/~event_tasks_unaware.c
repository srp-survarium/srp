void __usercall vostok::threading::event_tasks_unaware::~event_tasks_unaware(
        vostok::threading::event_tasks_unaware *this@<ecx>,
        HANDLE *a2@<eax>)
{
  CloseHandle(*a2);
}
