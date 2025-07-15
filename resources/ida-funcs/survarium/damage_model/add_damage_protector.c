void __thiscall survarium::damage_model::add_damage_protector(
        survarium::damage_model *this,
        const char *damage_type,
        float reduce,
        float absorb)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  survarium::booster_damage_protector *v6; // eax
  survarium::booster_damage_protector *v7; // [esp+Ch] [ebp-9Ch]
  int *_Where; // [esp+70h] [ebp-38h]
  survarium::booster_damage_protector *v10; // [esp+90h] [ebp-18h]
  survarium::find_by_damage_type_predicate destination; // [esp+94h] [ebp-14h] BYREF
  survarium::booster_damage_protector *protector; // [esp+A4h] [ebp-4h]

  vostok::strings::copy(destination.m_damage_type, 0x10u, damage_type);
  protector = vostok::intrusive_list<survarium::booster_damage_protector,survarium::booster_damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::find_if<survarium::find_by_damage_type_predicate>(
                &this->m_damage_protectors,
                &destination);
  if ( protector )
  {
    protector->m_reduce = protector->m_reduce * reduce;
    protector->m_absorb = protector->m_absorb + absorb;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(v4);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x70u);
    v10 = (survarium::booster_damage_protector *)operator new(0x70u, _Where);
    if ( v10 )
    {
      survarium::booster_damage_protector::booster_damage_protector(v10, damage_type, reduce, absorb);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    protector = v7;
    vostok::intrusive_list<survarium::booster_damage_protector,survarium::booster_damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_damage_protectors,
      (survarium::game_camera *)v7,
      0);
  }
}
