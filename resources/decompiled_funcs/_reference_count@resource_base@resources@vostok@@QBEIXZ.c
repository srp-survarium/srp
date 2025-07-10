unsigned int __usercall vostok::resources::resource_base::reference_count@<eax>(
        vostok::resources::resource_base *this@<ecx>,
        _DWORD *a2@<eax>)
{
  if ( (a2[2] & 1) != 0 && a2 )
    return a2[55];
  if ( (a2[2] & 4) != 0 && a2 )
    return a2[52];
  return MEMORY[0];
}
