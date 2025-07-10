void __usercall vostok::render::event_query::~event_query(vostok::render::event_query *this@<ecx>, _DWORD *a2@<esi>)
{
  if ( *a2 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*a2 + 8))(*a2);
  *a2 = 0;
}
