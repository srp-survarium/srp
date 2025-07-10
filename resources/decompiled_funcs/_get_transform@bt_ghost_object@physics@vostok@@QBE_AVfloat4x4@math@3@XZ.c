vostok::physics::bt_ghost_object *__usercall vostok::physics::bt_ghost_object::get_transform@<eax>(
        vostok::physics::bt_ghost_object *this@<ecx>,
        int a2@<eax>)
{
  vostok::physics::from_bullet((const btTransform *)(*(_DWORD *)(a2 + 16) + 16));
  return this;
}
