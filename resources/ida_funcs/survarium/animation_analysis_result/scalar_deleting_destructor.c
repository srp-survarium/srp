survarium::animation_analysis_result *__thiscall survarium::animation_analysis_result::`scalar deleting destructor'(
        survarium::animation_analysis_result *this,
        char a2)
{
  survarium::animation_analysis_result::~animation_analysis_result(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
