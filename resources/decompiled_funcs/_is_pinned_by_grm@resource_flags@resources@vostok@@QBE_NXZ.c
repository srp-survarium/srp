bool __usercall vostok::resources::resource_flags::is_pinned_by_grm@<al>(
        vostok::resources::resource_flags *this@<ecx>,
        _DWORD *a2@<eax>)
{
  if ( (a2[2] & 1) != 0 && a2 )
    return (a2[56] & 1) == 1;
  if ( (a2[2] & 4) != 0 && a2 )
    return (a2[53] & 1) == 1;
  return (MEMORY[4] & 1) == 1;
}
