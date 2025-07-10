void __userpurge survarium::game_world_ui::on_hit_from_pos(
        survarium::game_world_ui *this@<ecx>,
        vostok::math::float3 *a2@<edi>,
        vostok::math::axis_rotation_order a3@<esi>,
        __int128 position)
{
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 *v5; // ecx
  vostok::math::float3 *angles; // eax
  vostok::math::float4x4 *v7; // ecx
  float v8; // xmm0_4
  survarium::flash_value *v9; // eax
  int i; // ecx
  int v11; // edx
  char *v12; // esi
  int j; // edi
  int v14; // ecx
  vostok::math::float3 *v15; // [esp+4h] [ebp-120h]
  vostok::math::axis_rotation_order v16; // [esp+8h] [ebp-11Ch]
  float angle; // [esp+14h] [ebp-110h]
  vostok::math::float3 direction_vector; // [esp+18h] [ebp-10Ch] BYREF
  vostok::math::float3 local_up_in_world_space; // [esp+24h] [ebp-100h] BYREF
  survarium::flash_value args[2]; // [esp+30h] [ebp-F4h] BYREF
  char v21; // [esp+60h] [ebp-C4h] BYREF
  vostok::math::float4x4 actor_camera_matrix; // [esp+64h] [ebp-C0h] BYREF

  qmemcpy(
    (void *)&actor_camera_matrix,
    (const void *)(*(_DWORD *)(*(_DWORD *)(position + 8) + 160) + 4),
    sizeof(actor_camera_matrix));
  direction_vector.z = -(float)(*((float *)&position + 3) - actor_camera_matrix.c.z);
  direction_vector.y = -(float)(*((float *)&position + 2) - actor_camera_matrix.c.y);
  direction_vector.x = -(float)(*((float *)&position + 1) - actor_camera_matrix.c.x);
  angle = 1.0
        / sqrtf(
            (float)((float)(direction_vector.z * direction_vector.z) + (float)(direction_vector.y * direction_vector.y))
          + (float)(direction_vector.x * direction_vector.x));
  direction_vector.x = angle * direction_vector.x;
  direction_vector.y = direction_vector.y * angle;
  direction_vector.z = direction_vector.z * angle;
  local_up_in_world_space.x = 0.0;
  *(_QWORD *)&local_up_in_world_space.elements[1] = (unsigned int)clear_value;
  v4 = vostok::math::create_camera_direction(
         (const vostok::math::float3 *)((char *)&position + 4),
         &direction_vector,
         &local_up_in_world_space);
  invert_impl(
    v4,
    (float)((float)((float)((float)(v4->j.y * v4->k.z) - (float)(v4->j.z * v4->k.y)) * v4->i.x)
          - (float)((float)((float)(v4->j.x * v4->k.z) - (float)(v4->k.x * v4->j.z)) * v4->i.y))
  + (float)((float)((float)(v4->j.x * v4->k.y) - (float)(v4->k.x * v4->j.y)) * v4->i.z));
  angles = vostok::math::float4x4::get_angles(v5, a2, a3);
  v8 = angles->y - vostok::math::float4x4::get_angles(v7, v15, v16)->y;
  v9 = args;
  for ( i = 1; i >= 0; --i )
  {
    if ( v9 )
    {
      *(_DWORD *)v9->body = 0;
      *(_DWORD *)&v9->body[4] = 0;
    }
    ++v9;
  }
  if ( (args[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  *(_DWORD *)&args[0].body[4] = 5;
  *(double *)&args[0].body[8] = (float)((float)-v8 - 1.5707964);
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v11 = *(_DWORD *)(position + 4);
  *(_DWORD *)&args[1].body[4] = 5;
  *(_QWORD *)&args[1].body[8] = 0x4049000000000000LL;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v11 + 264) + 4),
    "root.hit_player",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v12 = &v21;
  for ( j = 1; j >= 0; --j )
  {
    v14 = *((_DWORD *)v12 - 5);
    v12 -= 24;
    if ( (v14 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v12 + 8))(v12, *((_DWORD *)v12 + 2));
      *(_DWORD *)v12 = 0;
    }
    *((_DWORD *)v12 + 1) = 0;
  }
}
