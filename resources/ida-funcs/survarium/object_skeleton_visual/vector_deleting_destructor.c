survarium::object_skeleton_visual *__thiscall survarium::object_skeleton_visual::`vector deleting destructor'(
        survarium::object_skeleton_visual *this,
        char a2)
{
  survarium::object_skeleton_visual::~object_skeleton_visual(this, (const char *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
