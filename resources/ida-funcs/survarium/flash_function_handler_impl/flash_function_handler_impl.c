void __usercall survarium::flash_function_handler_impl::flash_function_handler_impl(
        survarium::flash_function_handler_impl *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = &Scaleform::RefCountImplCore::`vftable';
  a2[1] = 1;
  *a2 = &survarium::flash_function_handler_impl::`vftable';
  a2[2] = this;
}
