survarium::artefact_base *__thiscall survarium::artefact_rattle_core::`scalar deleting destructor'(
        survarium::artefact_base *this,
        char a2)
{
  survarium::artefact_base::~artefact_base(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
