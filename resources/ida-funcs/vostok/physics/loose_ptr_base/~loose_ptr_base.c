void __usercall vostok::physics::loose_ptr_base::~loose_ptr_base(
        vostok::physics::loose_ptr_base *this@<ecx>,
        _DWORD **a2@<esi>)
{
  _DWORD *v2; // eax

  --(*a2)[1];
  v2 = *a2;
  if ( (*a2)[1] )
  {
    *v2 = 0;
  }
  else if ( v2 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD *, const char *, const char *, int))(*a2[1] + 24))(
      a2[1],
      v2,
      "vostok::physics::loose_ptr_base::~loose_ptr_base",
      "c:\\survarium.deploy\\sources\\vostok/loose_ptr_base_inline.h",
      29);
    *a2 = 0;
  }
}
