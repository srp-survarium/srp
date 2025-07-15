void __usercall vostok::threading::event_tasks_unaware::event_tasks_unaware(
        vostok::threading::event_tasks_unaware *this@<ecx>,
        HANDLE *a2@<esi>)
{
  *a2 = CreateEventA(0, 0, 0, 0);
}
