survarium::human_npc *__thiscall survarium::human_npc::`scalar deleting destructor'(
        survarium::human_npc *this,
        char a2)
{
  survarium::human_npc::~human_npc(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
