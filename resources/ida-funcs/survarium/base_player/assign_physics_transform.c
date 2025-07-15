void __userpurge survarium::base_player::assign_physics_transform(
        survarium::base_player *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *animated_object)
{
  int v3; // eax
  btTransform *transform; // eax
  vostok::physics::bt_character_controller *v5; // ecx
  survarium::base_player *v6; // ecx
  unsigned int v7; // [esp+0h] [ebp-D0h]
  vostok::math::float4x4 v8; // [esp+10h] [ebp-C0h] BYREF
  btTransform v9; // [esp+50h] [ebp-80h] BYREF
  btTransform result; // [esp+90h] [ebp-40h] BYREF

  if ( LOBYTE(animated_object[191].m_object) )
  {
    v3 = *(int *)((char *)&dword_10E74 + (_DWORD)animated_object);
    if ( s_cc_use_old_controller_value )
      transform = vostok::physics::old_bullet_character_controller::get_transform(
                    (vostok::physics::old_bullet_character_controller *)this,
                    &v9,
                    *(btTransform **)(v3 + 4));
    else
      transform = vostok::physics::bullet_character_controller::get_transform(
                    *(vostok::physics::bullet_character_controller **)v3,
                    &result);
    HIDWORD(a2) = transform;
    vostok::physics::from_bullet(a2, &v8);
    qmemcpy(&byte_10E2C[(_DWORD)animated_object], &v8, 0x40u);
    vostok::animation::animation_player::set_object_transform(
      0,
      animated_object + 212,
      (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)animated_object],
      animated_object);
    (*(void (__thiscall **)(vostok::animation::mixing::n_ary_tree_intrusive_base *, _DWORD, char *))(animated_object[195].m_object->m_reference_count + 60))(
      animated_object[195].m_object,
      *(_DWORD *)(*(int *)((char *)&dword_10E78 + (_DWORD)animated_object) + 300),
      &byte_10E2C[(_DWORD)animated_object]);
    vostok::physics::bt_character_controller::set_transform(
      v5,
      *(const btTransform ***)((char *)&dword_10E74 + (_DWORD)animated_object),
      (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)animated_object],
      v7);
    survarium::base_player::update_linear_horizontal_speed(v6, (float *)animated_object);
  }
}
