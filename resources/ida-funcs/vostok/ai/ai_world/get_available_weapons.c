void __thiscall vostok::ai::ai_world::get_available_weapons(
        vostok::ai::ai_world *this,
        vostok::ai::npc *owner,
        vostok::vectora<vostok::ai::weapon *> *list_to_be_filled)
{
  this->m_engine->get_available_weapons(this->m_engine, owner, list_to_be_filled);
}
