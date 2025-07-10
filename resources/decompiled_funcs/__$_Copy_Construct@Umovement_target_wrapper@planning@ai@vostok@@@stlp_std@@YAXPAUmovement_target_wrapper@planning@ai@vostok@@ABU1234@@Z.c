void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::movement_target_wrapper>(
        vostok::ai::planning::movement_target_wrapper *__p,
        const vostok::ai::planning::movement_target_wrapper *__val)
{
  char *v2; // [esp+24h] [ebp-8h]

  v2 = (char *)operator new(0x138u, __p);
  if ( v2 )
  {
    *(_QWORD *)v2 = *(_QWORD *)&__val->position.x;
    *((_DWORD *)v2 + 2) = LODWORD(__val->position.z);
    *((vostok::math::float3 *)v2 + 1) = __val->direction;
    *((vostok::math::float3 *)v2 + 2) = __val->velocity;
    vostok::fs_new::virtual_path_string::virtual_path_string(
      (vostok::fs_new::virtual_path_string *)(v2 + 36),
      &__val->animation_name);
  }
}
