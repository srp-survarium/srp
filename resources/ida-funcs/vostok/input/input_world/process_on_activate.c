void __usercall vostok::input::input_world::process_on_activate(vostok::input::input_world *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  if ( *(_DWORD *)(a2 + 28) )
    vostok::input::receiver::keyboard::on_activate(
      (vostok::input::receiver::keyboard *)this,
      *(vostok::input::receiver::keyboard **)(a2 + 28));
  v2 = *(_DWORD *)(a2 + 32);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v2 + 40) + 28))(*(_DWORD *)(v2 + 40));
}
