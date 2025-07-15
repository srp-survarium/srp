survarium::lobby_menu *__thiscall survarium::lobby_menu::`scalar deleting destructor'(
        survarium::lobby_menu *this,
        char a2)
{
  survarium::lobby_menu::~lobby_menu(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
