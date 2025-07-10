void __userpurge survarium::player::apply_input(
        survarium::player *this@<ecx>,
        float *a2@<eax>,
        vostok::math::float3 *a3@<edi>,
        float a4@<xmm0>,
        struct survarium::client_player_state *player_state,
        const struct vostok::math::float2 *a6,
        const struct vostok::math::float2 *a7,
        float a8)
{
  vostok::math::float2 rotation_to_apply; // [esp+0h] [ebp-8h] BYREF

  rotation_to_apply.x = (float)((float)((float)(*a2 * a4) * 0.5)
                              + *(float *)&this->survarium::base_player::survarium::inventory_holder::__vftable)
                      * a4;
  rotation_to_apply.y = (float)((float)((float)(a2[1] * a4) * 0.5) + *(float *)&this->m_scheduler) * a4;
  survarium::player::apply_input((survarium::player *)player_state, a3, player_state, &rotation_to_apply);
}
