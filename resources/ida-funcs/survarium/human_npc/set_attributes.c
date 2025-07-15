void __usercall survarium::human_npc::set_attributes(
        survarium::human_npc *this@<ecx>,
        survarium::human_npc::npc_game_attributes *attributes@<eax>)
{
  vostok::math::float4x4 *rotation_y; // eax
  const vostok::math::float4x4 *v4; // eax
  float result; // [esp+0h] [ebp-110h]
  vostok::math::float4x4 dst; // [esp+Ch] [ebp-104h] BYREF
  vostok::math::float4x4 left; // [esp+4Ch] [ebp-C4h] BYREF
  _QWORD v8[8]; // [esp+8Ch] [ebp-84h] BYREF
  vostok::math::float4x4 v9; // [esp+CCh] [ebp-44h] BYREF

  survarium::human_npc::npc_game_attributes::operator=(
    (survarium::human_npc::npc_game_attributes *)this,
    &this->m_game_attributes,
    attributes);
  memset((int)&dst, 0, sizeof(dst));
  result = this->m_game_attributes.initial_rotation.y;
  dst.i.x = this->m_game_attributes.initial_scale.x;
  dst.j.y = this->m_game_attributes.initial_scale.y;
  dst.k.z = this->m_game_attributes.initial_scale.z;
  LODWORD(dst.c.w) = clear_value;
  rotation_y = vostok::math::create_rotation_y(v8, (vostok::math::float4x4 *)LODWORD(result));
  vostok::math::mul4x3(&left, &dst, rotation_y);
  v4 = vostok::math::create_translation(&v9, &this->m_game_attributes.initial_position);
  vostok::math::mul4x3(&dst, &left, v4);
  qmemcpy((void *)&this->m_transform, &dst, sizeof(this->m_transform));
}
