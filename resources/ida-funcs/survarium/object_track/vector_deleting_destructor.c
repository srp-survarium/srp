survarium::object_track *__thiscall survarium::object_track::`vector deleting destructor'(
        survarium::object_track *this,
        char a2)
{
  survarium::object_track::~object_track(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
