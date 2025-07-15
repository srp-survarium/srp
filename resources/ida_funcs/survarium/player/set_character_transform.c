void __userpurge survarium::player::set_character_transform(
        const vostok::math::float3 *position@<eax>,
        survarium::player *this,
        vostok::math::float4x4 *orientation,
        float look_pitch)
{
  const vostok::math::float4x4 *v4; // edi
  vostok::math::float4x4 *rotation_y; // eax
  vostok::math::float4x4 v6; // [esp+14h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+54h] [ebp-80h] BYREF
  _QWORD v8[8]; // [esp+94h] [ebp-40h] BYREF

  v4 = vostok::math::create_translation(&result, position);
  rotation_y = vostok::math::create_rotation_y(v8, orientation);
  vostok::math::mul4x3(&v6, rotation_y, v4);
  qmemcpy((void *)&this->m_current.transform, &v6, sizeof(this->m_current.transform));
  qmemcpy((void *)&this->m_current.previous_transform, &v6, sizeof(this->m_current.previous_transform));
  qmemcpy(&byte_10D44[(_DWORD)this], &v6, 0x40u);
  qmemcpy((char *)&unk_10D84 + (_DWORD)this, &v6, 0x40u);
  this->m_current.look_pitch = look_pitch;
  *(float *)((char *)&dword_10DCC + (_DWORD)this) = look_pitch;
}
