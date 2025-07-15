void __userpurge vostok::threading::event_tasks_unaware::set(
        vostok::threading::event_tasks_unaware *this@<ecx>,
        HANDLE *a2@<eax>,
        bool value)
{
  if ( value )
    SetEvent(*a2);
  else
    ResetEvent(*a2);
}
