survarium::artefact_lifebone_core *__thiscall survarium::artefact_lifebone_core::`vector deleting destructor'(
        survarium::artefact_lifebone_core *this,
        char a2)
{
  survarium::artefact_lifebone_core::~artefact_lifebone_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
