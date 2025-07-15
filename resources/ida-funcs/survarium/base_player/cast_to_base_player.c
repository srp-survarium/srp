survarium::base_player *__thiscall survarium::base_player::cast_to_base_player(survarium::base_player *this)
{
  return (survarium::base_player *)((char *)this - 264);
}


const survarium::base_player *__thiscall survarium::base_player::cast_to_base_player(survarium::base_player *this)
{
  return (survarium::base_player *)((char *)this - 272);
}


survarium::base_player *__thiscall survarium::base_player::cast_to_base_player(char *this)
{
  return survarium::base_player::cast_to_base_player((survarium::base_player *)(this - 8));
}


survarium::base_player *__thiscall survarium::base_player::cast_to_base_player(char *this)
{
  return survarium::base_player::cast_to_base_player((survarium::base_player *)(this - 44));
}
