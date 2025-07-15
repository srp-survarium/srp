void __thiscall vostok::particle::particle_domain_complex::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_domain_complex *this,
        const vostok::configs::binary_config_value *prop,
        vostok::configs::binary_config_value *default_value)
{
  const vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // ecx
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // esi
  vostok::configs::binary_config_value *v10; // ecx
  char **v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // ebx
  vostok::configs::binary_config_value *v14; // ecx
  int v15; // xmm0_4
  const vostok::configs::binary_config_value *v16; // edi
  vostok::configs::binary_config_value *v17; // ecx
  unsigned int *p_id_crc; // esi
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // ecx
  int v21; // xmm0_4
  char *v22; // eax
  const vostok::configs::binary_config_value *v23; // edi
  const vostok::configs::binary_config_value *v24; // esi
  vostok::configs::binary_config_value *v25; // ecx
  vostok::configs::binary_config_value *v26; // ecx
  int v27; // xmm0_4
  char *v28; // eax
  unsigned __int8 *v29; // edi
  vostok::configs::binary_config_value *v30; // ecx
  vostok::configs::binary_config_value *v31; // ecx
  vostok::configs::binary_config_value *v32; // ecx
  vostok::configs::binary_config_value *v33; // ecx
  const vostok::configs::binary_config_value *v34; // eax
  vostok::configs::binary_config_value *v35; // ecx
  const vostok::configs::binary_config_value *v36; // eax
  vostok::configs::binary_config_value *v37; // ecx
  const vostok::configs::binary_config_value *v38; // eax
  vostok::configs::binary_config_value config_value; // [esp+Ch] [ebp-30h] BYREF
  vostok::configs::binary_config_value v40; // [esp+24h] [ebp-18h] BYREF
  vostok::configs::binary_config_value *default_valuea; // [esp+48h] [ebp+Ch]

  *(vostok::platform_pointer_selector<char const ,1>::helper *)((char *)&v40.id.max_storage + 4) = (vostok::platform_pointer_selector<char const ,1>::helper)prop[5].id.max_storage;
  *(_DWORD *)&v40.type = prop[5].id_crc;
  v3 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
         "Translate",
         (vostok::configs::binary_config_value *)this,
         &v40,
         default_value,
         (const void **)&v40.id.max_storage + 1);
  prop[5].id = (vostok::platform_pointer_selector<char const ,1>::helper)v3->data.max_storage;
  prop[5].id_crc = (unsigned int)v3->id.pointer;
  HIDWORD(v40.id.max_storage) = *(_DWORD *)&prop[5].type;
  v40.id_crc = (unsigned int)prop[6].data.pointer;
  *(_DWORD *)&v40.type = HIDWORD(prop[6].data.max_storage);
  v5 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
         "Rotate",
         v4,
         &v40,
         default_value,
         (const void **)&v40.id.max_storage + 1);
  *(_DWORD *)&prop[5].type = v5->data.pointer;
  prop[6].data.pointer = (const void *)HIDWORD(v5->data.max_storage);
  HIDWORD(prop[6].data.max_storage) = v5->id.pointer;
  *(vostok::platform_pointer_selector<char const ,1>::helper *)((char *)&v40.id.max_storage + 4) = (vostok::platform_pointer_selector<char const ,1>::helper)prop[6].id.max_storage;
  *(_DWORD *)&v40.type = prop[6].id_crc;
  v7 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
         "Scale",
         v6,
         &v40,
         default_value,
         (const void **)&v40.id.max_storage + 1);
  prop[6].id = (vostok::platform_pointer_selector<char const ,1>::helper)v7->data.max_storage;
  prop[6].id_crc = (unsigned int)v7->id.pointer;
  BYTE4(prop[9].id.max_storage) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                    "AffectVelocity",
                                    v8,
                                    default_value,
                                    (const bool *)&prop[9].id.max_storage + 4);
  v9 = vostok::configs::binary_config_value::operator[](default_value, "DomainType");
  if ( vostok::configs::binary_config_value::value_exists(v10, (int)v9, (unsigned int)"selected_value") )
  {
    v11 = (char **)vostok::configs::binary_config_value::operator[](v9, "selected_value");
    BYTE6(prop[9].id.max_storage) = vostok::particle::domain_type_from_string(*v11);
  }
  switch ( BYTE6(prop[9].id.max_storage) )
  {
    case 1:
      v12 = vostok::configs::binary_config_value::operator[](v9, "Line");
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 200);
      v15 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "Length",
              v14,
              v12,
              (const vostok::configs::binary_config_value *)((char *)prop + 200));
      goto LABEL_5;
    case 2:
      default_valuea = vostok::configs::binary_config_value::operator[](v9, "Triangle");
      HIDWORD(v40.id.max_storage) = *(_DWORD *)&prop[6].type;
      v40.id_crc = (unsigned int)prop[7].data.pointer;
      *(_DWORD *)&v40.type = HIDWORD(prop[7].data.max_storage);
      v34 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
              "PointA",
              (vostok::configs::binary_config_value *)((char *)&v40.id.max_storage + 4),
              &v40,
              default_valuea,
              (const void **)&v40.id.max_storage + 1);
      *(_DWORD *)&prop[6].type = v34->data.pointer;
      prop[7].data.pointer = (const void *)HIDWORD(v34->data.max_storage);
      HIDWORD(prop[7].data.max_storage) = v34->id.pointer;
      *(vostok::platform_pointer_selector<char const ,1>::helper *)((char *)&v40.id.max_storage + 4) = (vostok::platform_pointer_selector<char const ,1>::helper)prop[7].id.max_storage;
      *(_DWORD *)&v40.type = prop[7].id_crc;
      v36 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
              "PointB",
              v35,
              (const vostok::configs::binary_config_value *)((char *)&config_value.id.max_storage + 4),
              default_valuea,
              (const void **)&v40.id.max_storage + 1);
      prop[7].id = (vostok::platform_pointer_selector<char const ,1>::helper)v36->data.max_storage;
      prop[7].id_crc = (unsigned int)v36->id.pointer;
      HIDWORD(v40.id.max_storage) = *(_DWORD *)&prop[7].type;
      v40.id_crc = (unsigned int)prop[8].data.pointer;
      *(_DWORD *)&v40.type = HIDWORD(prop[8].data.max_storage);
      v38 = vostok::particle::read_config_value<vostok::math::float3,vostok::configs::binary_config_value>(
              "PointC",
              v37,
              &config_value,
              default_valuea,
              (const void **)&v40.id.max_storage + 1);
      *(_DWORD *)&prop[7].type = v38->data.pointer;
      prop[8].data.pointer = (const void *)HIDWORD(v38->data.max_storage);
      HIDWORD(prop[8].data.max_storage) = v38->id.pointer;
      return;
    case 4:
      v16 = vostok::configs::binary_config_value::operator[](v9, "Box");
      HIDWORD(prop[8].id.max_storage) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                          "Width",
                                          v17,
                                          v16,
                                          (const vostok::configs::binary_config_value *)((char *)prop + 204));
      p_id_crc = &prop[8].id_crc;
      v21 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "Height",
              v19,
              v16,
              (const vostok::configs::binary_config_value *)((char *)prop + 208));
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 212);
      v22 = "Depth";
      goto LABEL_7;
    case 5:
      v29 = "Sphere";
      goto LABEL_12;
    case 6:
      v16 = vostok::configs::binary_config_value::operator[](v9, "Cylinder");
      prop[9].data.pointer = (const void *)vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                             "RadiusInner",
                                             v31,
                                             v16,
                                             prop + 9);
      p_id_crc = (unsigned int *)&prop[9].data.max_storage + 1;
      v21 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "RadiusOuter",
              v32,
              v16,
              (const vostok::configs::binary_config_value *)((char *)prop + 220));
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 224);
      v22 = "Height";
LABEL_7:
      *p_id_crc = v21;
      v15 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(v22, v20, v16, v13);
      goto LABEL_5;
    case 7:
      v23 = vostok::configs::binary_config_value::operator[](v9, "Cone");
      v24 = (const vostok::configs::binary_config_value *)((char *)prop + 220);
      v27 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "Radius",
              v33,
              v23,
              (const vostok::configs::binary_config_value *)((char *)prop + 220));
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 224);
      goto LABEL_9;
    case 9:
      v29 = "Disc";
LABEL_12:
      v23 = vostok::configs::binary_config_value::operator[](v9, (char *)v29);
      v24 = prop + 9;
      v27 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "RadiusInner",
              v30,
              v23,
              prop + 9);
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 220);
      v28 = "RadiusOuter";
      goto LABEL_10;
    case 0xA:
      v23 = vostok::configs::binary_config_value::operator[](v9, "Rectangle");
      v24 = (const vostok::configs::binary_config_value *)((char *)prop + 204);
      v27 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
              "Width",
              v25,
              v23,
              (const vostok::configs::binary_config_value *)((char *)prop + 204));
      v13 = (const vostok::configs::binary_config_value *)((char *)prop + 208);
LABEL_9:
      v28 = "Height";
LABEL_10:
      v24->data.pointer = (const void *)v27;
      v15 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(v28, v26, v23, v13);
LABEL_5:
      v13->data.pointer = (const void *)v15;
      break;
    default:
      return;
  }
}
