void __thiscall survarium::weapon_core_melee_state::register_animations(
        survarium::weapon_core_melee_state *this,
        survarium::animations_registry *registry)
{
  survarium::animations_registry::register_animation(this->m_animations[0], registry, &this->m_animations[0][1]);
}
