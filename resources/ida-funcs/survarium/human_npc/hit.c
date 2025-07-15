void __thiscall survarium::human_npc::hit(
        survarium::human_npc *this,
        const survarium::hit_initiator *const initiator,
        const vostok::collision::bone_collision_data *bone_data,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  survarium::damage_model::hit_body_part(
    (survarium::damage_model *)LODWORD(this->m_game_scene[1].m_projection_matrix.i.x),
    initiator->id,
    bone_data->body_part_name.m_begin,
    damage_type,
    amount,
    armor_piercing,
    LODWORD(this->m_transform.j.w),
    bullet);
}


void __thiscall survarium::human_npc::hit(
        survarium::human_npc *this,
        const survarium::hit_initiator *const initiator,
        unsigned int bone_index,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  survarium::damage_model::hit_body_part(
    (survarium::damage_model *)LODWORD(this->m_game_scene[1].m_projection_matrix.i.x),
    initiator->id,
    *(const char **)(*(_DWORD *)LODWORD(this->m_game_scene[1].m_projection_matrix.i.y) + 112 * bone_index + 76),
    damage_type,
    amount,
    armor_piercing,
    LODWORD(this->m_transform.j.w),
    bullet);
}
