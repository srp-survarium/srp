void __userpurge vostok::threading::event::set(vostok::threading::event *this@<ecx>, HANDLE *a2@<eax>, bool value)
{
  if ( value )
    SetEvent(*a2);
  else
    ResetEvent(*a2);
}
