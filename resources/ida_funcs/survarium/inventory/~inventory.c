void __thiscall survarium::inventory::~inventory(survarium::inventory *this)
{
  `vector destructor iterator'(
    (char *)this->m_slots,
    4u,
    19,
    (void (__thiscall *)(void *))survarium::inventory_slot::~inventory_slot);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_slots);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
