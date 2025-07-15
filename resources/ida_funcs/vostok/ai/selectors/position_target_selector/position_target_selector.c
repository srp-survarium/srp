void __thiscall vostok::ai::selectors::position_target_selector::position_target_selector(
        vostok::ai::selectors::position_target_selector *this,
        vostok::ai::ai_world *world,
        const vostok::ai::working_memory *memory,
        vostok::ai::blackboard *board,
        vostok::ai::brain_unit *brain,
        const char *name)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_world = world;
  this->m_working_memory = memory;
  this->m_blackboard = board;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_name, name);
  this->__vftable = (vostok::ai::selectors::position_target_selector_vtbl *)&vostok::ai::selectors::position_target_selector::`vftable';
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_selected_positions);
  this->m_brain_unit = brain;
}
