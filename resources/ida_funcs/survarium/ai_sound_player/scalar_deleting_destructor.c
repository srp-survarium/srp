survarium::ai_sound_player *__thiscall survarium::ai_sound_player::`scalar deleting destructor'(
        survarium::ai_sound_player *this,
        char a2)
{
  survarium::ai_sound_player::~ai_sound_player(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
