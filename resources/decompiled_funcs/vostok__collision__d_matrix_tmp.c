void __usercall vostok::collision::d_matrix_tmp(
        float *out_ode_position@<edx>,
        const vostok::math::float4x4 *in_m@<eax>,
        float *out_ode_rotation)
{
  double y; // st7
  double z; // st7

  *out_ode_rotation = in_m->i.x;
  y = in_m->i.y;
  out_ode_rotation[11] = 0.0;
  out_ode_rotation[4] = y;
  out_ode_rotation[7] = 0.0;
  z = in_m->i.z;
  out_ode_rotation[3] = 0.0;
  out_ode_rotation[8] = z;
  out_ode_position[3] = 0.0;
  out_ode_rotation[1] = in_m->j.x;
  out_ode_rotation[5] = in_m->j.y;
  out_ode_rotation[9] = in_m->j.z;
  out_ode_rotation[2] = in_m->k.x;
  out_ode_rotation[6] = in_m->k.y;
  out_ode_rotation[10] = in_m->k.z;
  *out_ode_position = in_m->c.x;
  out_ode_position[1] = in_m->c.y;
  out_ode_position[2] = in_m->c.z;
}
