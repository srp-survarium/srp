void __thiscall survarium::booby_trap_core::hit(
        survarium::booby_trap_core *this,
        const unsigned int current_time_in_ms,
        const survarium::hit_initiator *const initiator,
        const vostok::collision::bone_collision_data *bone_data,
        const survarium::hit_type_enum damage_type,
        const float amount,
        const float armor_piercing,
        survarium::bullet *const bullet,
        const unsigned __int16 dict_id)
{
  survarium::booby_trap_core::switch_to_state(this, booby_trap_state_disarmed, this);
}


void __thiscall survarium::booby_trap_core::hit(
        survarium::booby_trap_core *this,
        const unsigned int current_time_in_ms,
        const survarium::hit_initiator *const initiator,
        const unsigned int bone_index,
        const survarium::hit_type_enum damage_type,
        const float amount,
        const float armor_piercing,
        survarium::bullet *const bullet,
        const vostok::math::float3 *hit_position,
        const survarium::triangle_orientation orientation,
        const unsigned __int16 dict_id)
{
  survarium::booby_trap_core::switch_to_state(this, booby_trap_state_disarmed, this);
}
