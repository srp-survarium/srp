vostok::math::float3 *__userpurge vostok::sound::sound_instance_proxy_internal::get_volumetric_position@<eax>(
        vostok::sound::sound_instance_proxy_internal *this@<ecx>,
        int a2@<esi>,
        vostok::math::float3 *result,
        const vostok::math::float3 *listener_position)
{
  int v4; // edi
  int v5; // eax

  v4 = **(_DWORD **)(a2 + 116);
  v5 = (*(int (__thiscall **)(_DWORD))(v4 + 8))(*(_DWORD *)(a2 + 116));
  (*(void (__thiscall **)(_DWORD, vostok::math::float3 *, const vostok::math::float3 *, int))(v4 + 124))(
    *(_DWORD *)(a2 + 116),
    result,
    listener_position,
    v5);
  return result;
}
