survarium::login_menu_external_handler *__thiscall survarium::flash_external_handler::`scalar deleting destructor'(
        survarium::login_menu_external_handler *this,
        char a2)
{
  survarium::flash_external_handler::~flash_external_handler(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
