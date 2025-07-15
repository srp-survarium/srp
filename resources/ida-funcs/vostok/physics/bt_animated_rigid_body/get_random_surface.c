unsigned int __userpurge vostok::physics::bt_animated_rigid_body::get_random_surface@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        int a2@<esi>,
        float seed,
        unsigned int mask)
{
  int v4; // eax
  int v5; // ebx
  unsigned int v6; // edi
  const btCollisionShape *v7; // eax
  btBoxShape *v8; // ecx
  double v9; // st7
  int v10; // eax
  int v11; // ebx
  unsigned int j; // edi
  const btCollisionShape *v13; // eax
  btBoxShape *v14; // ecx
  double surface_area; // st7
  float i; // [esp+Ch] [ebp-8h]
  unsigned int v18; // [esp+10h] [ebp-4h]
  unsigned int v19; // [esp+10h] [ebp-4h]

  v18 = mask;
  v4 = *(_DWORD *)(a2 + 52);
  v5 = 0;
  v6 = 0;
  for ( i = 0.0; v6 < *(_DWORD *)(v4 + 16); v5 += 80 )
  {
    v7 = *(const btCollisionShape **)(*(_DWORD *)(v4 + 24) + v5 + 64);
    if ( v7->m_shapeType == 31 )
    {
      v8 = (btBoxShape *)v18;
      LOBYTE(v8) = -((v18 & 1) != 1);
      v18 >>= 1;
      LOBYTE(v8) = (_BYTE)v8 + 1;
      if ( (_BYTE)v8 )
        i = vostok::physics::get_surface_area(v7, v8) + i;
    }
    v4 = *(_DWORD *)(a2 + 52);
    ++v6;
  }
  v9 = vostok::math::random32::random_f((vostok::math::random32 *)&seed, 1.0);
  v19 = mask;
  v10 = *(_DWORD *)(a2 + 52);
  seed = v9 * i;
  v11 = 0;
  for ( j = 0; j < *(_DWORD *)(v10 + 16); v11 += 80 )
  {
    v13 = *(const btCollisionShape **)(*(_DWORD *)(v10 + 24) + v11 + 64);
    if ( v13->m_shapeType == 31 )
    {
      v14 = (btBoxShape *)v19;
      LOBYTE(v14) = -((v19 & 1) != 1);
      v19 >>= 1;
      LOBYTE(v14) = (_BYTE)v14 + 1;
      if ( (_BYTE)v14 )
      {
        surface_area = vostok::physics::get_surface_area(v13, v14);
        seed = seed - surface_area;
        if ( seed < 0.0 )
          break;
      }
    }
    v10 = *(_DWORD *)(a2 + 52);
    ++j;
  }
  return j;
}
