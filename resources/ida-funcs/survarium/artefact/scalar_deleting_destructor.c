survarium::artefact<survarium::artefact_rattle_core> *__thiscall survarium::artefact<survarium::artefact_rattle_core>::`scalar deleting destructor'(
        survarium::artefact<survarium::artefact_rattle_core> *this,
        char a2)
{
  survarium::artefact<survarium::artefact_rattle_core>::~artefact<survarium::artefact_rattle_core>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
