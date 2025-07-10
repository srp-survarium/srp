survarium::collision_geometry *__thiscall survarium::collision_geometry::`vector deleting destructor'(
        survarium::collision_geometry *this,
        char a2)
{
  survarium::collision_geometry::~collision_geometry(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
