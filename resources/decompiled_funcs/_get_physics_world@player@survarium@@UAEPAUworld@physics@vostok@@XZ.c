vostok::physics::world *__thiscall survarium::player::get_physics_world(survarium::player *this)
{
  return *(vostok::physics::world **)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 176);
}
