void __thiscall vostok::render::shadow_cascade_volume::compute_planes(
        vostok::render::shadow_cascade_volume *this,
        int a2)
{
  _DWORD *v2; // ebx
  vostok::math::plane *v3; // eax
  _DWORD *v4; // edi
  bool v5; // zf
  vostok::math::plane v6; // [esp+Ch] [ebp-18h] BYREF
  int v7; // [esp+1Ch] [ebp-8h]

  v2 = (_DWORD *)(a2 + 356);
  v7 = 4;
  do
  {
    v3 = vostok::math::create_plane(
           (const vostok::math::float3 *)(a2 + 12 * (*(v2 - 2) + 21)),
           (const vostok::math::float3 *)(a2 + 12 * (*(v2 - 1) + 21)),
           &v6,
           (float *)(a2 + 12 * (*v2 + 21)));
    v2[2] = LODWORD(v3->normal.x);
    v2[3] = LODWORD(v3->normal.y);
    v2[4] = LODWORD(v3->normal.z);
    v4 = v2 + 5;
    v2 += 8;
    v5 = v7-- == 1;
    *v4 = LODWORD(v3->d);
  }
  while ( !v5 );
}
