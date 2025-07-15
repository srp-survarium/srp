void __thiscall survarium::weapon_preview_state::register_animations(
        survarium::weapon_preview_state *this,
        survarium::animations_registry *registry)
{
  survarium::animations_registry::register_animation(&this->m_preview_animation, registry, &this->m_preview_animation);
}
