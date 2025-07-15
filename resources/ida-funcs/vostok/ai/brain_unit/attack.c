void __thiscall vostok::ai::brain_unit::attack(
        vostok::ai::brain_unit *this,
        const vostok::ai::npc *const target,
        const vostok::ai::weapon *const gun)
{
  this->m_npc->attack(this->m_npc, target, gun);
}
