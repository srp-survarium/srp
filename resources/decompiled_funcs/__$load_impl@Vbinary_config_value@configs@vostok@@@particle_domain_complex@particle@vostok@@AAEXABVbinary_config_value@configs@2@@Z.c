void __userpurge vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_domain_complex *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *prop)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  vostok::math::float3 v7; // [esp+10h] [ebp-B4h] BYREF
  vostok::math::float3 v8; // [esp+1Ch] [ebp-A8h] BYREF
  vostok::math::float3 v9; // [esp+28h] [ebp-9Ch] BYREF
  vostok::math::float3 v10; // [esp+34h] [ebp-90h] BYREF
  vostok::math::float3 v11; // [esp+40h] [ebp-84h] BYREF
  vostok::math::float3 v12; // [esp+4Ch] [ebp-78h] BYREF
  vostok::math::float3 v13; // [esp+58h] [ebp-6Ch] BYREF
  vostok::math::float3 v14; // [esp+64h] [ebp-60h] BYREF
  vostok::math::float3 v15; // [esp+70h] [ebp-54h] BYREF
  vostok::math::float3 v16; // [esp+7Ch] [ebp-48h] BYREF
  vostok::math::float3 result; // [esp+88h] [ebp-3Ch] BYREF
  vostok::math::float3 default_value; // [esp+94h] [ebp-30h] BYREF
  vostok::configs::binary_config_value *v19; // [esp+A0h] [ebp-24h]
  vostok::configs::binary_config_value *v20; // [esp+A4h] [ebp-20h]
  vostok::configs::binary_config_value *v21; // [esp+A8h] [ebp-1Ch]
  const vostok::configs::binary_config_value *cylinder_config; // [esp+ACh] [ebp-18h]
  const vostok::configs::binary_config_value *sphere_config; // [esp+B0h] [ebp-14h]
  vostok::configs::binary_config_value *config_value; // [esp+B4h] [ebp-10h]
  const vostok::configs::binary_config_value *box_config; // [esp+B8h] [ebp-Ch]
  const vostok::configs::binary_config_value *line_config; // [esp+BCh] [ebp-8h]
  const vostok::configs::binary_config_value *domain_type_config; // [esp+C0h] [ebp-4h]

  vostok::math::float3::float3((vostok::math::float3 *)&this->m_translate, &default_value);
  this->m_translate = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                        &result,
                        prop,
                        "Translate",
                        &default_value)->vostok::math::float3_pod;
  vostok::math::float3::float3((vostok::math::float3 *)&this->m_rotate, &v16);
  this->m_rotate = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                     &v15,
                     prop,
                     "Rotate",
                     &v16)->vostok::math::float3_pod;
  vostok::math::float3::float3((vostok::math::float3 *)&this->m_scale, &v14);
  this->m_scale = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                    &v13,
                    prop,
                    "Scale",
                    &v14)->vostok::math::float3_pod;
  this->m_affect_velocity = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                              prop,
                              "AffectVelocity",
                              &this->m_affect_velocity);
  domain_type_config = vostok::configs::binary_config_value::operator[](prop, "DomainType");
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)domain_type_config,
         "selected_value") )
  {
    v3 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)domain_type_config,
           "selected_value");
    v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3);
    this->m_domain_type = vostok::particle::domain_type_from_string((const char *)v5);
  }
  switch ( this->m_domain_type )
  {
    case 1u:
      line_config = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)domain_type_config,
                      "Line");
      this->m_line_width = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                             a2,
                             (vostok::configs::binary_config_value *)line_config,
                             "Length",
                             &this->m_line_width);
      break;
    case 2u:
      v19 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)domain_type_config,
                                                      "Triangle");
      vostok::math::float3::float3((vostok::math::float3 *)&this->164, &v12);
      this->164 = ($03587BACB216BA0890FE706AD1985887)*vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                                                        &v11,
                                                        v19,
                                                        "PointA",
                                                        &v12);
      vostok::math::float3::float3((vostok::math::float3 *)&this->m_triangle_b, &v10);
      this->m_triangle_b = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                             &v9,
                             v19,
                             "PointB",
                             &v10)->vostok::math::float3_pod;
      vostok::math::float3::float3((vostok::math::float3 *)&this->m_triangle_c, &v8);
      this->m_triangle_c = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
                             &v7,
                             v19,
                             "PointC",
                             &v8)->vostok::math::float3_pod;
      break;
    case 4u:
      box_config = vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)domain_type_config,
                     "Box");
      this->m_box_width = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                            a2,
                            (vostok::configs::binary_config_value *)box_config,
                            "Width",
                            &this->m_box_width);
      this->m_box_height = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                             a2,
                             (vostok::configs::binary_config_value *)box_config,
                             "Height",
                             &this->m_box_height);
      this->m_box_depth = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                            a2,
                            (vostok::configs::binary_config_value *)box_config,
                            "Depth",
                            &this->m_box_depth);
      break;
    case 5u:
      sphere_config = vostok::configs::binary_config_value::operator[](
                        (vostok::configs::binary_config_value *)domain_type_config,
                        "Sphere");
      this->m_inner_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               (vostok::configs::binary_config_value *)sphere_config,
                               "RadiusInner",
                               &this->m_inner_radius);
      this->m_outer_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               (vostok::configs::binary_config_value *)sphere_config,
                               "RadiusOuter",
                               &this->m_outer_radius);
      break;
    case 6u:
      cylinder_config = vostok::configs::binary_config_value::operator[](
                          (vostok::configs::binary_config_value *)domain_type_config,
                          "Cylinder");
      this->m_inner_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               (vostok::configs::binary_config_value *)cylinder_config,
                               "RadiusInner",
                               &this->m_inner_radius);
      this->m_outer_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               (vostok::configs::binary_config_value *)cylinder_config,
                               "RadiusOuter",
                               &this->m_outer_radius);
      this->m_cylinder_height = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                  a2,
                                  (vostok::configs::binary_config_value *)cylinder_config,
                                  "Height",
                                  &this->m_cylinder_height);
      break;
    case 7u:
      v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)domain_type_config,
                                                      "Cone");
      this->m_outer_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               v20,
                               "Radius",
                               &this->m_outer_radius);
      this->m_cylinder_height = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                  a2,
                                  v20,
                                  "Height",
                                  &this->m_cylinder_height);
      break;
    case 9u:
      v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)domain_type_config,
                                                      "Disc");
      this->m_inner_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               v21,
                               "RadiusInner",
                               &this->m_inner_radius);
      this->m_outer_radius = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                               a2,
                               v21,
                               "RadiusOuter",
                               &this->m_outer_radius);
      break;
    case 0xAu:
      config_value = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                               (vostok::configs::binary_config_value *)domain_type_config,
                                                               "Rectangle");
      this->m_box_width = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                            a2,
                            config_value,
                            "Width",
                            &this->m_box_width);
      this->m_box_height = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                             a2,
                             config_value,
                             "Height",
                             &this->m_box_height);
      break;
    default:
      return;
  }
}
