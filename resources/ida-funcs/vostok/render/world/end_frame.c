void __usercall vostok::render::world::end_frame(vostok::render::world *this@<ecx>, int a2@<eax>)
{
  ++*(_DWORD *)(*(_DWORD *)(a2 + 368) + 4);
  if ( *(_DWORD *)(a2 + 384) )
    *(_DWORD *)(a2 + 388) = 0;
  if ( *(_BYTE *)(a2 + 393) )
    *(_BYTE *)(a2 + 392) = 0;
}
