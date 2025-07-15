void __thiscall vostok::render::scene::particle_engine::update_light(
        vostok::render::scene::particle_engine *this,
        unsigned int id,
        float range,
        vostok::math::float4 color,
        vostok::math::float4x4 transform,
        float attenuation_power,
        float intensity,
        float diffuse_influence_factor,
        float specular_influence_factor,
        bool enable_shadows,
        bool static_shadows,
        float shadow_transparency,
        unsigned int shadow_map_size_index)
{
  vostok::math::color *v14; // ecx
  vostok::render::scene *m_scene; // eax
  float v16; // [esp+Ch] [ebp-100h]
  int v17; // [esp+18h] [ebp-F4h] BYREF
  vostok::render::light_props props; // [esp+1Ch] [ebp-F0h] BYREF

  vostok::render::light_props::light_props((vostok::render::light_props *)this, (int)&props);
  vostok::render::initialize_base_particle_light_properties(
    &props,
    enable_shadows,
    static_shadows,
    shadow_transparency,
    shadow_map_size_index);
  props.range = range;
  props.color = *vostok::math::color::color(v14, &v17, color.z, (vostok::math *)LODWORD(color.x), color.y, color.w, v16);
  qmemcpy(&props, &transform, 0x40u);
  props.type = light_type_point;
  props.attenuation_power = attenuation_power;
  props.intensity = intensity;
  m_scene = this->m_scene;
  props.diffuse_influence_factor = diffuse_influence_factor;
  props.specular_influence_factor = specular_influence_factor;
  props.enabled = 1;
  vostok::render::scene::update_light(0, (int)m_scene, id, &props);
}
