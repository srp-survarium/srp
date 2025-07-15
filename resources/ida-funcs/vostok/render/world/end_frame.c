void __usercall vostok::render::world::end_frame(vostok::render::world *this@<ecx>, int a2@<eax>)
{
  ++*(_DWORD *)(*(_DWORD *)(a2 + 352) + 40);
  if ( *(_DWORD *)(a2 + 368) )
    *(_DWORD *)(a2 + 372) = 0;
  if ( *(_BYTE *)(a2 + 377) )
    *(_BYTE *)(a2 + 376) = 0;
}
