void __thiscall vostok::ai::brain_unit::prepare_to_attack(
        vostok::ai::brain_unit *this,
        const vostok::ai::npc *const target,
        const vostok::ai::weapon *const gun)
{
  this->m_npc->prepare_to_attack(this->m_npc, target, gun);
}
