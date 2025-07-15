survarium::game *__thiscall survarium::game::`scalar deleting destructor'(survarium::game *this, char a2)
{
  survarium::game::~game(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
