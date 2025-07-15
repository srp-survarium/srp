void __thiscall survarium::hit_info::hit_info(
        survarium::hit_info *this,
        const unsigned int current_time_in_ms,
        int hit_initiator,
        const unsigned __int8 being_hit,
        const char *body_part_name,
        char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet,
        const vostok::math::float3 *hit_position,
        _DWORD *orientation,
        int dict_id,
        __int16 a13)
{
  vostok::fixed_string<16>::fixed_string<16>(
    &this->body_part_name,
    (vostok::buffer_string *)current_time_in_ms,
    damage_type);
  *(float *)(current_time_in_ms + 28) = amount;
  *(_DWORD *)(current_time_in_ms + 32) = hit_position;
  *(_DWORD *)(current_time_in_ms + 36) = *orientation;
  *(_DWORD *)(current_time_in_ms + 40) = orientation[1];
  *(_DWORD *)(current_time_in_ms + 44) = orientation[2];
  *(_DWORD *)(current_time_in_ms + 48) = dict_id;
  *(_DWORD *)(current_time_in_ms + 60) = hit_initiator;
  *(_WORD *)(current_time_in_ms + 64) = a13;
  *(_BYTE *)(current_time_in_ms + 66) = being_hit;
  *(float *)(current_time_in_ms + 52) = armor_piercing;
  *(_BYTE *)(current_time_in_ms + 68) = hit_position != 0;
  *(_DWORD *)(current_time_in_ms + 56) = bullet;
  *(_BYTE *)(current_time_in_ms + 67) = (_BYTE)body_part_name;
}
