survarium::base_project *__thiscall survarium::base_project::`vector deleting destructor'(
        survarium::base_project *this,
        char a2)
{
  survarium::base_project::~base_project(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
