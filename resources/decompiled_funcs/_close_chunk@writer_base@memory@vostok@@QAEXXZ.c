void __usercall vostok::memory::writer_base::close_chunk(vostok::memory::writer_base *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // edi
  int v3; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD *))(*a2 + 8))(a2);
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*a2 + 4))(a2, *(_DWORD *)(a2[3] - 4));
  v3 = *a2;
  v4 = v2 - *(_DWORD *)(a2[3] - 4) - 4;
  (*(void (__thiscall **)(_DWORD *, int *, int))(v3 + 12))(a2, &v4, 4);
  (*(void (__thiscall **)(_DWORD *, int))(*a2 + 4))(a2, v2);
  a2[3] -= 4;
}
