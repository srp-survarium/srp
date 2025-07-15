void __userpurge vostok::render::dof_shader_constants::set(
        vostok::render::dof_shader_constants *this@<edi>,
        const vostok::math::float3 *blurriness_height_lights@<eax>,
        vostok::render::backend *a3@<ecx>,
        __int64 distance,
        __int64 power,
        __int64 far_blur_amout,
        float bokeh_dof_density)
{
  float z; // esi
  vostok::render::backend *v8; // ecx
  vostok::render::backend *v9; // ecx
  vostok::render::backend *v10; // ecx
  vostok::render::shader_constant_host *m_dof_height_lights; // [esp-Ch] [ebp-20h]
  vostok::render::shader_constant_host *m_dof_parameters; // [esp-Ch] [ebp-20h]
  vostok::render::shader_constant_host *m_blurriness_amount; // [esp-Ch] [ebp-20h]
  vostok::render::shader_constant_host *m_bokeh_dof_parameters; // [esp-Ch] [ebp-20h]
  vostok::math::float3 v15; // [esp+4h] [ebp-10h] BYREF
  int v16; // [esp+10h] [ebp-4h]

  *(_QWORD *)&v15.x = *(_QWORD *)&blurriness_height_lights->x;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  m_dof_height_lights = this->m_dof_height_lights;
  v15.z = blurriness_height_lights->z;
  v16 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    a3,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    m_dof_height_lights,
    &v15);
  *(_QWORD *)&v15.x = distance;
  m_dof_parameters = this->m_dof_parameters;
  v15.z = s_bm_current_air_resistance;
  v16 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v8,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_dof_parameters,
    &v15);
  *(_QWORD *)&v15.x = power;
  m_blurriness_amount = this->m_blurriness_amount;
  v15.z = 0.0;
  v16 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v9,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_blurriness_amount,
    &v15);
  *(_QWORD *)&v15.x = far_blur_amout;
  m_bokeh_dof_parameters = this->m_bokeh_dof_parameters;
  v15.z = 0.0;
  v16 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v10,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_bokeh_dof_parameters,
    &v15);
}
