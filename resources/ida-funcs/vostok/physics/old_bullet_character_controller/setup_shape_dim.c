void __usercall vostok::physics::old_bullet_character_controller::setup_shape_dim(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // [esp+Ch] [ebp-Ch]
  float v4; // [esp+10h] [ebp-8h]

  v4 = *(float *)&this->btActionInterface::__vftable * 0.5;
  v3 = (float)(*(float *)&this->vostok::physics::base_physics_object::__vftable
             - *(float *)&this->btActionInterface::__vftable)
     * 0.5;
  *(float *)(a2 + 512) = v4;
  *(float *)(a2 + 516) = v3;
  *(float *)(a2 + 520) = v4;
  *(_DWORD *)(a2 + 524) = 0;
  v2 = *(float *)&this->vostok::physics::base_physics_object::__vftable * 0.5;
  *(_DWORD *)(a2 + 112) = 0;
  *(float *)(a2 + 116) = v2;
  *(_DWORD *)(a2 + 120) = 0;
  *(_DWORD *)(a2 + 124) = 0;
}
