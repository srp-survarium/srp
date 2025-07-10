void __thiscall vostok::ai::selectors::pickup_item_target_selector::pickup_item_target_selector(
        vostok::ai::selectors::pickup_item_target_selector *this,
        vostok::ai::ai_world *world,
        const vostok::ai::working_memory *memory,
        vostok::ai::blackboard *board,
        const char *name)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_world = world;
  this->m_working_memory = memory;
  this->m_blackboard = board;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_name, name);
  this->__vftable = (vostok::ai::selectors::pickup_item_target_selector_vtbl *)&vostok::ai::selectors::pickup_item_target_selector::`vftable';
}
