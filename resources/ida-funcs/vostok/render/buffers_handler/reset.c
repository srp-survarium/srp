void __thiscall vostok::render::buffers_handler<0>::reset(vostok::render::buffers_handler<0> *this, int a2)
{
  _DWORD *v2; // eax
  unsigned int v3; // ebp

  v2 = *(_DWORD **)a2;
  v3 = 0;
  *(_DWORD *)a2 = 0;
  if ( v2 )
    --*v2;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  memset(a2 + 12, 0, 0x200u);
  if ( (*(_DWORD *)(a2 + 536) - *(_DWORD *)(a2 + 532)) >> 2 )
  {
    do
      vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)(a2 + 532) + 4 * v3++),
        0);
    while ( v3 < (*(_DWORD *)(a2 + 536) - *(_DWORD *)(a2 + 532)) >> 2 );
  }
}
