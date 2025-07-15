survarium::artefact_onyx_core *__thiscall survarium::artefact_onyx_core::`scalar deleting destructor'(
        survarium::artefact_onyx_core *this,
        char a2)
{
  survarium::artefact_onyx_core::~artefact_onyx_core(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
