void __thiscall survarium::base_player::hit(
        survarium::base_player *this,
        int current_time_in_ms,
        const survarium::hit_initiator *const initiator,
        const vostok::collision::bone_collision_data *bone_data,
        float damage_type,
        float amount,
        survarium::bullet *armor_piercing,
        vostok::math::float3 *bullet,
        __int16 dict_id)
{
  survarium::base_player *v10; // ecx
  survarium::triangle_orientation orientation[3]; // [esp+1Ch] [ebp-54h] BYREF
  unsigned int current_time_in_msa[18]; // [esp+28h] [ebp-48h] BYREF

  survarium::hit_info::hit_info(
    (survarium::hit_info *)this,
    (const unsigned int)current_time_in_msa,
    current_time_in_ms,
    initiator->id,
    (const char *)LOBYTE(this[-1].m_temp_delta_time_in_ms),
    bone_data->body_part_name.m_begin,
    damage_type,
    amount,
    armor_piercing,
    bullet,
    orientation,
    0,
    dict_id);
  survarium::base_player::hit_impl(v10, (survarium::base_player *)((char *)this - 308), (int)current_time_in_msa);
}


void __thiscall survarium::base_player::hit(
        survarium::base_player *this,
        int current_time_in_ms,
        const survarium::hit_initiator *const initiator,
        const unsigned int bone_index,
        float damage_type,
        float amount,
        survarium::bullet *armor_piercing,
        vostok::math::float3 *bullet,
        vostok::math::float3 *hit_position,
        survarium::triangle_orientation orientation,
        __int16 dict_id)
{
  survarium::base_player *v12; // ecx
  unsigned int current_time_in_msa[18]; // [esp+20h] [ebp-48h] BYREF

  survarium::hit_info::hit_info(
    (survarium::hit_info *)(108 * bone_index),
    (const unsigned int)current_time_in_msa,
    current_time_in_ms,
    initiator->id,
    (const char *)LOBYTE(this[-1].m_temp_delta_time_in_ms),
    *(char **)(*(_DWORD *)(*(int *)((char *)&dword_10D44 + (_DWORD)this) + 288) + 108 * bone_index + 76),
    damage_type,
    amount,
    armor_piercing,
    bullet,
    hit_position,
    orientation,
    dict_id);
  survarium::base_player::hit_impl(v12, (survarium::base_player *)((char *)this - 308), (int)current_time_in_msa);
}
