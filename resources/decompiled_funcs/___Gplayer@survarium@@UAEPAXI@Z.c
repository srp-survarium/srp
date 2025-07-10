survarium::player *__thiscall survarium::player::`scalar deleting destructor'(survarium::player *this, char a2)
{
  survarium::player::~player(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
