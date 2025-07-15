void __userpurge vostok::physics::bt_ghost_object::remove(
        vostok::physics::world *w@<eax>,
        vostok::physics::bt_ghost_object *this)
{
  (*((void (__thiscall **)(vostok::physics::world_vtbl *, btPairCachingGhostObject *))w[13].~vostok::physics::world + 8))(
    w[13].__vftable,
    this->m_bt_object);
}
