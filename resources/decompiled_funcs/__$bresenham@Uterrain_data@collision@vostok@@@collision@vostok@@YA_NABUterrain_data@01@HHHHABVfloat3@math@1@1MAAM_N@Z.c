char __usercall vostok::collision::bresenham<vostok::collision::terrain_data>@<al>(
        int Yd@<ecx>,
        int Xd@<eax>,
        bool a3@<dil>,
        vostok::collision::terrain_data *terrain_data,
        int Yf,
        int Xf,
        const vostok::math::float3 *ray_point,
        const vostok::math::float3 *ray_dir,
        float max_distance,
        float *range)
{
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // edi
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // edi
  int v22; // eax
  bool v24; // [esp+8h] [ebp-38h]
  bool v25; // [esp+8h] [ebp-38h]
  bool v26; // [esp+8h] [ebp-38h]
  bool v27; // [esp+8h] [ebp-38h]
  bool v28; // [esp+8h] [ebp-38h]
  bool v29; // [esp+8h] [ebp-38h]
  bool v30; // [esp+8h] [ebp-38h]
  bool v31; // [esp+8h] [ebp-38h]
  bool v32; // [esp+8h] [ebp-38h]
  int y; // [esp+18h] [ebp-28h]
  int ya; // [esp+18h] [ebp-28h]
  int dY2; // [esp+1Ch] [ebp-24h]
  int dX2; // [esp+24h] [ebp-1Ch]
  int v37; // [esp+28h] [ebp-18h]
  int XInc; // [esp+2Ch] [ebp-14h]
  int YInc; // [esp+30h] [ebp-10h]
  int dY; // [esp+34h] [ebp-Ch]
  int i; // [esp+48h] [ebp+8h]
  int S; // [esp+4Ch] [ebp+Ch]
  int Sa; // [esp+4Ch] [ebp+Ch]
  int Sb; // [esp+4Ch] [ebp+Ch]

  dY = ((Yd - Yf) >> 31) ^ (((Yd - Yf) >> 31) + Yd - Yf);
  v37 = ((Xd - Xf) >> 31) ^ (((Xd - Xf) >> 31) + Xd - Xf);
  dX2 = 2 * v37;
  dY2 = 2 * dY;
  XInc = 2 * (Xd < Xf) - 1;
  YInc = 2 * (Yd < Yf) - 1;
  if ( vostok::collision::terrain_data::ray_test_quad(terrain_data, Yd, Xd, ray_point, ray_dir, max_distance, range, a3) )
    return 1;
  if ( vostok::collision::terrain_data::ray_test_quad(
         terrain_data,
         Yd - 1,
         Xd,
         ray_point,
         ray_dir,
         max_distance,
         range,
         v24) )
  {
    return 1;
  }
  S = Yd + 1;
  if ( vostok::collision::terrain_data::ray_test_quad(
         terrain_data,
         Yd + 1,
         Xd,
         ray_point,
         ray_dir,
         max_distance,
         range,
         v25) )
  {
    return 1;
  }
  if ( vostok::collision::terrain_data::ray_test_quad(
         terrain_data,
         Yd,
         Xd - 1,
         ray_point,
         ray_dir,
         max_distance,
         range,
         v26) )
  {
    return 1;
  }
  y = Xd + 1;
  if ( vostok::collision::terrain_data::ray_test_quad(
         terrain_data,
         Yd,
         Xd + 1,
         ray_point,
         ray_dir,
         max_distance,
         range,
         v27) )
  {
    return 1;
  }
  i = 1;
  if ( v37 <= dY )
  {
    v18 = dX2 - dY2;
    v19 = dX2 - dY;
    if ( dY >= 1 )
    {
      v20 = Xd + 1;
      v21 = Yd;
      while ( 1 )
      {
        if ( v19 < 0 )
        {
          v22 = dX2 + v19;
        }
        else
        {
          v20 += XInc;
          v22 = v18 + v19;
          y = v20;
        }
        v21 += YInc;
        Sb = v22;
        if ( vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               v21,
               v20 - 1,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v28)
          || vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               v21,
               y - 2,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v31)
          || vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               v21,
               y,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v32) )
        {
          break;
        }
        if ( ++i > dY )
          return 0;
        v20 = y;
        v18 = dX2 - dY2;
        v19 = Sb;
      }
      return 1;
    }
  }
  else
  {
    v13 = dY2 - dX2;
    v14 = dY2 - v37;
    if ( v37 >= 1 )
    {
      v15 = Yd + 1;
      v16 = Xd;
      ya = S;
      while ( 1 )
      {
        if ( v14 < 0 )
        {
          v17 = dY2 + v14;
        }
        else
        {
          v15 += YInc;
          v17 = v13 + v14;
          ya = v15;
        }
        v16 += XInc;
        Sa = v17;
        if ( vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               v15 - 1,
               v16,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v28)
          || vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               ya - 2,
               v16,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v29)
          || vostok::collision::terrain_data::ray_test_quad(
               terrain_data,
               ya,
               v16,
               ray_point,
               ray_dir,
               max_distance,
               range,
               v30) )
        {
          break;
        }
        if ( ++i > v37 )
          return 0;
        v15 = ya;
        v13 = dY2 - dX2;
        v14 = Sa;
      }
      return 1;
    }
  }
  return 0;
}
