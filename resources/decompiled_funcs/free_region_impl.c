void __usercall free_region_impl(void *const buffer@<eax>)
{
  VirtualFree(buffer, 0, 0x8000u);
}
