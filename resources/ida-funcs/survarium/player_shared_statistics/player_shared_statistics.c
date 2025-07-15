void __thiscall survarium::player_shared_statistics::player_shared_statistics(
        survarium::player_shared_statistics *this)
{
  survarium::intermediate_shared_statistics::clear(
    (survarium::intermediate_shared_statistics *)this,
    (int)&this->intermediate);
  memset(this, 0, 0x28u);
  this->events.elems[20] = 0;
}
