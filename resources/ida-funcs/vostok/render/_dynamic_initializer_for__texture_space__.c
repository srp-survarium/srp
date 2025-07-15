void vostok::render::_dynamic_initializer_for__texture_space__()
{
  __int64 v0; // [esp+4h] [ebp-3Ch]
  float v1; // [esp+Ch] [ebp-34h]
  __int64 v2; // [esp+14h] [ebp-2Ch]

  *((float *)&v0 + 1) = s_spot_max_distance;
  v1 = s_bm_current_air_resistance;
  texture_space.i.x = c_anim_center;
  texture_space.i.y = 0.0;
  texture_space.i.z = 0.0;
  texture_space.i.w = 0.0;
  *((float *)&v2 + 1) = FLOAT_0_0099999998;
  texture_space.j.x = 0.0;
  *(_QWORD *)&texture_space.lines[1].elements[1] = LODWORD(FLOAT_N0_5);
  texture_space.j.w = 0.0;
  LODWORD(v2) = 0;
  texture_space.k.x = 0.0;
  *(_QWORD *)&texture_space.lines[2].elements[1] = v2;
  texture_space.k.w = 0.0;
  *(float *)&v0 = c_anim_center;
  texture_space.c.x = c_anim_center;
  *(_QWORD *)&texture_space.lines[3].elements[1] = v0;
  texture_space.c.w = v1;
}
