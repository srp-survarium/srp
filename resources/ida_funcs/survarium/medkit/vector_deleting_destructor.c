survarium::medkit *__thiscall survarium::medkit::`vector deleting destructor'(survarium::medkit *this, char a2)
{
  survarium::medkit::~medkit(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
