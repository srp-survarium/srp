survarium::lobby_menu_external_handler *__thiscall survarium::lobby_menu_external_handler::`scalar deleting destructor'(
        survarium::lobby_menu_external_handler *this,
        char a2)
{
  survarium::flash_external_handler_impl *impl; // ecx

  impl = this->impl;
  this->__vftable = (survarium::lobby_menu_external_handler_vtbl *)&survarium::flash_external_handler::`vftable';
  if ( impl )
    ((void (__thiscall *)(survarium::flash_external_handler_impl *, int))impl->~survarium::flash_external_handler_impl)(
      impl,
      1);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
