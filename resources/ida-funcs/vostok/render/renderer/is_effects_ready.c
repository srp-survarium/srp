BOOL __usercall vostok::render::renderer::is_effects_ready@<eax>(vostok::render::renderer *this@<ecx>, int a2@<esi>)
{
  _DWORD *i; // edi

  for ( i = *(_DWORD **)(a2 + 344); i != *(_DWORD **)(a2 + 348); ++i )
  {
    if ( *i && !(*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)*i + 28))(*i) )
      return 0;
  }
  return (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 500) + 28))(*(_DWORD *)(a2 + 500))
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 496) + 28))(*(_DWORD *)(a2 + 496))
      && *(_DWORD *)(a2 + 592)
      && *(_DWORD *)(a2 + 604)
      && *(_DWORD *)(a2 + 596)
      && *(_DWORD *)(a2 + 608)
      && *(_DWORD *)(a2 + 624)
      && *(_DWORD *)(a2 + 628)
      && *(_DWORD *)(a2 + 620)
      && *(_DWORD *)(a2 + 616);
}
