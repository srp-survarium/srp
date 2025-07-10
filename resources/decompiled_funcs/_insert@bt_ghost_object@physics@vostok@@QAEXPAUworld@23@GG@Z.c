void __userpurge vostok::physics::bt_ghost_object::insert(
        vostok::physics::world *w@<eax>,
        vostok::physics::bt_ghost_object *this,
        int group,
        int mask)
{
  (*((void (__thiscall **)(vostok::physics::world_vtbl *, btPairCachingGhostObject *, int, int))w[13].~vostok::physics::world
   + 7))(
    w[13].__vftable,
    this->m_bt_object,
    group,
    mask);
}
