void __userpurge survarium::player::hit(
        survarium::player *this@<ecx>,
        int a2@<esi>,
        const survarium::hit_initiator *const initiator,
        const vostok::collision::bone_collision_data *bone_data,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  survarium::hit_info info; // [esp+14h] [ebp-48h] BYREF

  survarium::hit_info::hit_info(
    &info,
    initiator->id,
    *(&this[-1].m_force_bones_recompute + 3),
    bone_data->body_part_name.m_begin,
    damage_type,
    amount,
    armor_piercing,
    bullet);
  (*(void (__thiscall **)(_DWORD, survarium::hit_info *, int))(**(_DWORD **)(*(int *)((char *)&dword_10ECC + (_DWORD)this)
                                                                           + 952)
                                                             + 48))(
    *(_DWORD *)(*(int *)((char *)&dword_10ECC + (_DWORD)this) + 952),
    &info,
    a2);
}


void __userpurge survarium::player::hit(
        survarium::player *this@<ecx>,
        int a2@<esi>,
        const survarium::hit_initiator *const initiator,
        unsigned int bone_index,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  survarium::hit_info info; // [esp+14h] [ebp-48h] BYREF

  survarium::hit_info::hit_info(
    &info,
    initiator->id,
    *(&this[-1].m_force_bones_recompute + 3),
    *(const char *const *)(**(_DWORD **)((char *)&dword_10EB8 + (_DWORD)this) + 112 * bone_index + 76),
    damage_type,
    amount,
    armor_piercing,
    bullet);
  (*(void (__thiscall **)(_DWORD, survarium::hit_info *, int))(**(_DWORD **)(*(int *)((char *)&dword_10ECC + (_DWORD)this)
                                                                           + 952)
                                                             + 48))(
    *(_DWORD *)(*(int *)((char *)&dword_10ECC + (_DWORD)this) + 952),
    &info,
    a2);
}
