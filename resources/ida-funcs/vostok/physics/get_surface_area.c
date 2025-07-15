double __usercall vostok::physics::get_surface_area@<st0>(const btCollisionShape *shape@<eax>, btBoxShape *a2@<ecx>)
{
  btVector3 *getBoundingSphere; // esi
  int v3; // eax
  int v4; // eax
  btBoxShape *v5; // ecx
  btVector3 *HalfExtentsWithMargin; // eax
  int v8; // ecx
  double v9; // st7
  float v10; // [esp+Ch] [ebp-24h]
  float v11; // [esp+Ch] [ebp-24h]
  btVector3 v12; // [esp+10h] [ebp-20h] BYREF
  btVector3 v13; // [esp+20h] [ebp-10h] BYREF

  getBoundingSphere = (btVector3 *)shape[2].__vftable[1].getBoundingSphere;
  v3 = getBoundingSphere->mVec128.m128_i32[1];
  if ( v3 )
  {
    v4 = v3 - 8;
    if ( v4 )
    {
      if ( v4 != 2 )
      {
        v10 = ((double (__thiscall *)(btVector3 *))*(_DWORD *)(getBoundingSphere->mVec128.m128_i32[0] + 84))(getBoundingSphere);
        HalfExtentsWithMargin = btBoxShape::getHalfExtentsWithMargin(v5, getBoundingSphere, &v13);
        return (HalfExtentsWithMargin->mVec128.m128_f32[1] + HalfExtentsWithMargin->mVec128.m128_f32[1] + v10)
             * v10
             * 6.2831855;
      }
      v8 = getBoundingSphere[4].mVec128.m128_i32[0];
      v11 = getBoundingSphere[2].mVec128.m128_f32[(v8 + 2) % 3];
      v9 = getBoundingSphere[2].mVec128.m128_f32[v8] + v11;
    }
    else
    {
      v11 = getBoundingSphere[2].mVec128.m128_f32[0] * getBoundingSphere[1].mVec128.m128_f32[0];
      v9 = v11;
    }
    return v9 * v11 * 12.566371;
  }
  else
  {
    btBoxShape::getHalfExtentsWithMargin(a2, getBoundingSphere, &v12);
    return ((v12.mVec128.m128_f32[2] + v12.mVec128.m128_f32[0]) * v12.mVec128.m128_f32[1]
          + v12.mVec128.m128_f32[2] * v12.mVec128.m128_f32[0])
         * gran1;
  }
}
