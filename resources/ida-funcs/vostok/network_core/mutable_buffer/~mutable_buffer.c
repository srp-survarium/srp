void __usercall vostok::network_core::mutable_buffer::~mutable_buffer(
        vostok::network_core::mutable_buffer *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // eax

  if ( *a2 )
  {
    v2 = a2[1];
    if ( v2 )
    {
      (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(*(_DWORD *)*a2 + 24))(
        *a2,
        v2,
        "vostok::network_core::mutable_buffer::~mutable_buffer",
        "c:\\survarium.deploy\\sources\\vostok/network_core/mutable_buffer_inline.h",
        40);
      a2[1] = 0;
    }
  }
}
