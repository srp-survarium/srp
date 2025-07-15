void __thiscall survarium::flash_external_handler::~flash_external_handler(survarium::flash_external_handler *this)
{
  survarium::flash_external_handler_impl *impl; // ecx

  this->__vftable = (survarium::flash_external_handler_vtbl *)&survarium::flash_external_handler::`vftable';
  impl = this->impl;
  if ( impl )
    ((void (__thiscall *)(survarium::flash_external_handler_impl *, int))impl->~survarium::flash_external_handler_impl)(
      impl,
      1);
}
