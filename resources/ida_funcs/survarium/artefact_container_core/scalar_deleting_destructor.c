survarium::artefact_container_core *__thiscall survarium::artefact_container_core::`scalar deleting destructor'(
        survarium::artefact_container_core *this,
        char a2)
{
  survarium::artefact_container_core::~artefact_container_core(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
