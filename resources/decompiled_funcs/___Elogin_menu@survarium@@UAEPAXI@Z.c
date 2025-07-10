survarium::login_menu *__thiscall survarium::login_menu::`vector deleting destructor'(
        survarium::login_menu *this,
        char a2)
{
  survarium::login_menu::~login_menu(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
