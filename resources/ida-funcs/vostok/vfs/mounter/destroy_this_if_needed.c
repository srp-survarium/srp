void __usercall vostok::vfs::mounter::destroy_this_if_needed(vostok::vfs::mounter *this@<ecx>, void **a2@<esi>)
{
  void *v2; // edi
  _BYTE *v3; // ebx

  if ( a2[325] == (void *)2 && !a2[303] )
  {
    v2 = a2[304];
    v3 = __RTCastToVoid(a2);
    (*(void (__thiscall **)(void **, _DWORD))*a2)(a2, 0);
    (*(void (__thiscall **)(void *, _BYTE *, const char *, const char *, int))(*(_DWORD *)v2 + 24))(
      v2,
      v3,
      "vostok::vfs::mounter::destroy_this_if_needed",
      ".\\mounter.cpp",
      110);
  }
}
