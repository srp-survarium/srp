void __usercall vostok::resources::sorting_functionality::sorting_functionality(
        vostok::resources::sorting_functionality *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 1;
  a2[1] = 0;
  a2[2] = this;
}
