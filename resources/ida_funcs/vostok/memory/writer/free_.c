void __usercall vostok::memory::writer::free_(vostok::memory::writer *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  if ( !*(_BYTE *)(a2 + 24) )
  {
    if ( *(_DWORD *)(a2 + 28) )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 4) + 24))(*(_DWORD *)(a2 + 4), *(_DWORD *)(a2 + 28));
      *(_DWORD *)(a2 + 28) = 0;
    }
  }
}
