// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::render::culling::portal_sector_structure::load(
        vostok::configs::binary_config_value *value_ptr@<eax>,
        vostok::render::culling::portal_sector_structure *this)
{
  const vostok::configs::binary_config_value *eax1; // eax
  unsigned int *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *pointer; // edi
  unsigned int *v7; // esi
  char v8; // bl
  unsigned __int64 ***v9; // esi
  float *v10; // eax
  float v11; // xmm4_4
  float v12; // xmm6_4
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::collision::object *v14; // eax
  float y; // xmm7_4
  float z; // xmm6_4
  float x; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  unsigned int *v20; // eax
  char *v21; // ecx
  unsigned int *v22; // edx
  __int64 v23; // xmm1_8
  __int64 v24; // xmm2_8
  vostok::render::culling::spatial_sector *m_end; // eax
  __int64 v26; // xmm0_8
  vostok::configs::binary_config_value *v27; // ebx
  vostok::render::culling::portal_sector_structure *v28; // ecx
  unsigned __int64 *v29; // eax
  __int64 *v30; // ecx
  float v31; // edi
  __int64 v32; // xmm0_8
  float *v33; // ecx
  float v34; // esi
  __int64 v35; // xmm0_8
  int v36; // ecx
  float *v37; // eax
  int v38; // edx
  __int64 v39; // xmm0_8
  float v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  unsigned int v42; // ecx
  unsigned int v43; // edx
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  vostok::render::culling::portal *v48; // edi
  float v49; // xmm7_4
  float v50; // xmm6_4
  float v51; // xmm5_4
  float v52; // xmm5_4
  vostok::memory::base_allocator *v53; // ecx
  vostok::collision::object *v54; // eax
  vostok::render::culling::portal *_X; // [esp+Ch] [ebp-1ACh]
  vostok::configs::binary_config_value *portals_cfg_end; // [esp+24h] [ebp-194h]
  const vostok::configs::binary_config_value *portals_cfg_enda; // [esp+24h] [ebp-194h]
  __int64 v1; // [esp+28h] [ebp-190h]
  __int64 v1a; // [esp+28h] [ebp-190h]
  float v1_8; // [esp+30h] [ebp-188h]
  vostok::math::float3 v0; // [esp+34h] [ebp-184h]
  __int64 v0a; // [esp+34h] [ebp-184h]
  float v0_8; // [esp+3Ch] [ebp-17Ch]
  unsigned int sector1; // [esp+40h] [ebp-178h]
  unsigned int sector1a; // [esp+40h] [ebp-178h]
  unsigned int *current_portal_ids; // [esp+44h] [ebp-174h]
  vostok::configs::binary_config_value sectors_cfg; // [esp+48h] [ebp-170h]
  float sectors_cfga; // [esp+48h] [ebp-170h]
  const vostok::configs::binary_config_value *sectors_end; // [esp+60h] [ebp-158h]
  float sectors_enda; // [esp+60h] [ebp-158h]
  char *sector0; // [esp+64h] [ebp-154h]
  unsigned int sector0a; // [esp+64h] [ebp-154h]
  vostok::math::aabb sector_aabb; // [esp+68h] [ebp-150h] BYREF
  vostok::math::float3 v3; // [esp+80h] [ebp-138h] BYREF
  vostok::math::aabb v75; // [esp+8Ch] [ebp-12Ch] BYREF
  vostok::math::float3 epsilon; // [esp+A4h] [ebp-114h] BYREF
  __int128 v2; // [esp+B0h] [ebp-108h] OVERLAPPED
  __int64 v78; // [esp+C0h] [ebp-F8h]
  vostok::math::float3 position; // [esp+CCh] [ebp-ECh] BYREF
  vostok::configs::binary_config_value portal_ids_cfg; // [esp+D8h] [ebp-E0h]
  vostok::configs::binary_config_value points_cfg; // [esp+F0h] [ebp-C8h]
  vostok::render::culling::spatial_sector new_sector; // [esp+108h] [ebp-B0h]
  _BYTE v83[76]; // [esp+12Ch] [ebp-8Ch] BYREF
  vostok::math::float4x4 identity_matrix; // [esp+178h] [ebp-40h] BYREF

  eax1 = vostok::configs::binary_config_value::operator[](value_ptr, "portals");
  *(_QWORD *)&v2 = eax1->data.max_storage;
  *((_QWORD *)&v2 + 1) = eax1->id.max_storage;
  v78 = *(_QWORD *)&eax1->id_crc;
  v4 = (unsigned int *)this->m_allocator->call_malloc(this->m_allocator, 8 * (24 * HIWORD(HIDWORD(v78)) / 24));
  this->m_portal_ids_buffer = v4;
  current_portal_ids = v4;
  portals_cfg_end = 0;
  vostok::math::float4x4::identity(&identity_matrix);
  v5 = vostok::configs::binary_config_value::operator[](value_ptr, "sectors");
  pointer = (vostok::configs::binary_config_value *)v5->data.pointer;
  sectors_end = (const vostok::configs::binary_config_value *)((char *)v5->data.pointer
                                                             + 24 * HIWORD(*(_DWORD *)&v5->type));
  sector1 = (unsigned int)v5->data.pointer;
  if ( v5->data.pointer != sectors_end )
  {
    v7 = current_portal_ids;
    memset(&v75, 0, sizeof(v75));
    do
    {
      sector_aabb = v75;
      v8 = 0;
      if ( vostok::configs::binary_config_value::value_exists(pointer, "volumes") )
      {
        points_cfg = *vostok::configs::binary_config_value::operator[](pointer, "volumes");
        v9 = (unsigned __int64 ***)points_cfg.data.pointer;
        sector0 = (char *)points_cfg.data.pointer + 24 * HIWORD(*(_DWORD *)&points_cfg.type);
        if ( points_cfg.data.pointer != sector0 )
        {
          do
          {
            v10 = (float *)(*v9)[6];
            sectors_cfg.data.max_storage = ***v9;
            *(unsigned __int64 *)((char *)&sectors_cfg.id.max_storage + 4) = *(_QWORD *)v10;
            v11 = *v10;
            v12 = v10[1];
            m_allocator = this->m_allocator;
            sectors_cfg.id.pointer = (const char *)*((_DWORD *)**v9 + 2);
            *(float *)&sectors_cfg.type = v10[2];
            epsilon.x = (float)(*v10 - *(float *)&sectors_cfg.data.pointer) * 0.5;
            epsilon.y = (float)(*(float *)&sectors_cfg.id_crc - *((float *)&sectors_cfg.data.max_storage + 1)) * 0.5;
            epsilon.z = (float)(*(float *)&sectors_cfg.type - *(float *)&sectors_cfg.id.pointer) * 0.5;
            v3.x = (float)(*(float *)&sectors_cfg.data.pointer + v11) * 0.5;
            v3.y = (float)(*((float *)&sectors_cfg.data.max_storage + 1) + v12) * 0.5;
            v3.z = (float)(*(float *)&sectors_cfg.id.pointer + *(float *)&sectors_cfg.type) * 0.5;
            v14 = vostok::collision::new_aabb_object(m_allocator, 1u, &v3, &epsilon, portals_cfg_end);
            this->m_sectors_spatial_tree->insert(this->m_sectors_spatial_tree, v14, &identity_matrix);
            if ( v8 )
            {
              if ( *(float *)&sectors_cfg.data.pointer <= sector_aabb.min.x )
                LODWORD(position.x) = sectors_cfg.data.pointer;
              else
                position.x = sector_aabb.min.x;
              if ( *((float *)&sectors_cfg.data.max_storage + 1) <= sector_aabb.min.y )
                y = *((float *)&sectors_cfg.data.max_storage + 1);
              else
                y = sector_aabb.min.y;
              if ( *(float *)&sectors_cfg.id.pointer <= sector_aabb.min.z )
                z = *(float *)&sectors_cfg.id.pointer;
              else
                z = sector_aabb.min.z;
              if ( sector_aabb.max.x <= *(float *)&sectors_cfg.data.pointer )
                x = *(float *)&sectors_cfg.data.pointer;
              else
                x = sector_aabb.max.x;
              if ( sector_aabb.max.y <= *((float *)&sectors_cfg.data.max_storage + 1) )
                v18 = *((float *)&sectors_cfg.data.max_storage + 1);
              else
                v18 = sector_aabb.max.y;
              v19 = sector_aabb.max.z;
              if ( sector_aabb.max.z <= *(float *)&sectors_cfg.id.pointer )
                v19 = *(float *)&sectors_cfg.id.pointer;
              if ( *((float *)&sectors_cfg.id.max_storage + 1) <= position.x )
                LODWORD(v1) = HIDWORD(sectors_cfg.id.max_storage);
              else
                *(float *)&v1 = position.x;
              if ( *(float *)&sectors_cfg.id_crc <= y )
                HIDWORD(v1) = sectors_cfg.id_crc;
              else
                *((float *)&v1 + 1) = y;
              if ( *(float *)&sectors_cfg.type <= z )
                v1_8 = *(float *)&sectors_cfg.type;
              else
                v1_8 = z;
              *(_QWORD *)&sector_aabb.min.x = v1;
              sector_aabb.min.z = v1_8;
              if ( x <= *((float *)&sectors_cfg.id.max_storage + 1) )
                v0.x = *((float *)&sectors_cfg.id.max_storage + 1);
              else
                v0.x = x;
              if ( v18 <= *(float *)&sectors_cfg.id_crc )
                LODWORD(v0.y) = sectors_cfg.id_crc;
              else
                v0.y = v18;
              if ( v19 <= *(float *)&sectors_cfg.type )
                v0.z = *(float *)&sectors_cfg.type;
              else
                v0.z = v19;
              sector_aabb.max = v0;
            }
            else
            {
              sector_aabb = (vostok::math::aabb)sectors_cfg;
              v8 = 1;
            }
            v9 += 6;
          }
          while ( v9 != (unsigned __int64 ***)sector0 );
          pointer = (vostok::configs::binary_config_value *)sector1;
        }
        v7 = current_portal_ids;
      }
      portal_ids_cfg = *vostok::configs::binary_config_value::operator[](pointer, "portals");
      v20 = (unsigned int *)portal_ids_cfg.data.pointer;
      v21 = (char *)portal_ids_cfg.data.pointer + 24 * HIWORD(*(_DWORD *)&portal_ids_cfg.type);
      v22 = v7;
      if ( portal_ids_cfg.data.pointer != v21 )
      {
        do
        {
          *v7 = *v20;
          v20 += 6;
          ++v7;
        }
        while ( v20 != (unsigned int *)v21 );
        current_portal_ids = v7;
      }
      v23 = *(_QWORD *)&sector_aabb.min.elements[2];
      v24 = *(_QWORD *)&sector_aabb.max.elements[1];
      new_sector.m_portal_ids = v22;
      new_sector.m_portals_count = 24 * portal_ids_cfg.count / 24;
      m_end = this->m_sectors.m_end;
      if ( m_end )
      {
        *(_QWORD *)&m_end->m_aabb.min.x = *(_QWORD *)&sector_aabb.min.x;
        v26 = *(_QWORD *)&new_sector.m_portal_ids;
        *(_QWORD *)&m_end->m_aabb.min.elements[2] = v23;
        *(_QWORD *)&m_end->m_aabb.max.elements[1] = v24;
        *(_QWORD *)&m_end->m_portal_ids = v26;
      }
      ++this->m_sectors.m_end;
      portals_cfg_end = (vostok::configs::binary_config_value *)((char *)portals_cfg_end + 1);
      sector1 = (unsigned int)++pointer;
    }
    while ( pointer != sectors_end );
  }
  v27 = (vostok::configs::binary_config_value *)v2;
  v28 = (vostok::render::culling::portal_sector_structure *)(3 * HIWORD(v78));
  portals_cfg_enda = (const vostok::configs::binary_config_value *)(v2 + 24 * HIWORD(v78));
  if ( (const vostok::configs::binary_config_value *)v2 != portals_cfg_enda )
  {
    do
    {
      v29 = (unsigned __int64 *)vostok::configs::binary_config_value::operator[](v27, "points");
      points_cfg.data.max_storage = *v29;
      points_cfg.id.max_storage = v29[1];
      v30 = *(__int64 **)points_cfg.data.pointer;
      v31 = *(float *)(*(_DWORD *)points_cfg.data.pointer + 8);
      *(_QWORD *)&points_cfg.id_crc = v29[2];
      v32 = *v30;
      v33 = (float *)*((_DWORD *)points_cfg.data.pointer + 6);
      v34 = v33[2];
      v0a = v32;
      v35 = *(_QWORD *)v33;
      v36 = *((_DWORD *)points_cfg.data.pointer + 12);
      v37 = (float *)*((_DWORD *)points_cfg.data.pointer + 18);
      v38 = *(_DWORD *)(v36 + 8);
      v1a = v35;
      *(_QWORD *)&v2 = *(_QWORD *)v36;
      v39 = *(_QWORD *)v37;
      v40 = v37[2];
      v0_8 = v31;
      DWORD2(v2) = v38;
      *(_QWORD *)&v3.x = v39;
      v3.z = v40;
      v41 = vostok::configs::binary_config_value::operator[](v27, "sectors");
      *(_QWORD *)&new_sector.m_aabb.min.x = v41->data.max_storage;
      *(_QWORD *)&new_sector.m_aabb.min.elements[2] = v41->id.max_storage;
      v42 = *(_DWORD *)LODWORD(new_sector.m_aabb.min.x);
      v43 = *(_DWORD *)(LODWORD(new_sector.m_aabb.min.x) + 24);
      *(_QWORD *)&new_sector.m_aabb.max.elements[1] = *(_QWORD *)&v41->id_crc;
      v44 = (float)((float)(*((float *)&v1a + 1) - *((float *)&v0a + 1)) * (float)(*((float *)&v2 + 2) - v0_8))
          - (float)((float)(v34 - v0_8) * (float)(*((float *)&v2 + 1) - *((float *)&v0a + 1)));
      *(float *)&v39 = (float)((float)(*(float *)&v1a - *(float *)&v0a)
                             * (float)(*((float *)&v2 + 1) - *((float *)&v0a + 1)))
                     - (float)((float)(*(float *)&v2 - *(float *)&v0a)
                             * (float)(*((float *)&v1a + 1) - *((float *)&v0a + 1)));
      v75.max.z = *(float *)&v39;
      v45 = (float)((float)(*(float *)&v2 - *(float *)&v0a) * (float)(v34 - v0_8))
          - (float)((float)(*(float *)&v1a - *(float *)&v0a) * (float)(*((float *)&v2 + 2) - v0_8));
      sector0a = v42;
      sector1a = v43;
      v75.max.x = v44;
      v75.max.y = v45;
      sectors_enda = sqrtf((float)((float)(*(float *)&v39 * *(float *)&v39) + (float)(v45 * v45)) + (float)(v44 * v44));
      v46 = v31;
      epsilon.z = (float)(*(float *)&clear_value / sectors_enda) * v75.max.z;
      epsilon.y = (float)(*(float *)&clear_value / sectors_enda) * v75.max.y;
      epsilon.x = v75.max.x * (float)(*(float *)&clear_value / sectors_enda);
      *(_QWORD *)v83 = *(_QWORD *)&epsilon.x;
      v47 = *((float *)&v0a + 1);
      *(float *)&v83[12] = -(float)((float)((float)(epsilon.z * v31) + (float)(epsilon.y * *((float *)&v0a + 1)))
                                  + (float)(epsilon.x * *(float *)&v0a));
      *(_QWORD *)&v83[24] = v0a;
      *(_QWORD *)&v83[36] = v1a;
      *(float *)&v83[32] = v31;
      v48 = this->m_portals.m_end;
      *(float *)&v83[8] = epsilon.z;
      *(_DWORD *)&v83[16] = sector0a;
      *(_QWORD *)&v83[48] = v2;
      v83[72] = 1;
      *(_DWORD *)&v83[20] = sector1a;
      *(float *)&v83[44] = v34;
      *(_DWORD *)&v83[56] = DWORD2(v2);
      *(vostok::math::float3 *)&v83[60] = v3;
      if ( v48 )
        qmemcpy(v48, v83, sizeof(vostok::render::culling::portal));
      ++this->m_portals.m_end;
      if ( *(float *)&v1a <= *(float *)&v0a )
        LODWORD(v75.min.x) = v1a;
      else
        LODWORD(v75.min.x) = v0a;
      if ( *((float *)&v1a + 1) <= *((float *)&v0a + 1) )
        v75.min.y = *((float *)&v1a + 1);
      else
        v75.min.y = *((float *)&v0a + 1);
      if ( v34 <= v46 )
        v49 = v34;
      else
        v49 = v46;
      if ( *(float *)&v0a <= *(float *)&v1a )
        v50 = *(float *)&v1a;
      else
        v50 = *(float *)&v0a;
      if ( *((float *)&v0a + 1) <= *((float *)&v1a + 1) )
        v47 = *((float *)&v1a + 1);
      if ( v46 <= v34 )
        v46 = v34;
      if ( *(float *)&v2 <= v75.min.x )
        sectors_cfga = *(float *)&v2;
      else
        sectors_cfga = v75.min.x;
      v51 = v75.min.y;
      if ( *((float *)&v2 + 1) <= v75.min.y )
        v51 = *((float *)&v2 + 1);
      if ( *((float *)&v2 + 2) <= v49 )
        v49 = *((float *)&v2 + 2);
      if ( v50 <= *(float *)&v2 )
        v50 = *(float *)&v2;
      if ( v47 <= *((float *)&v2 + 1) )
        v47 = *((float *)&v2 + 1);
      if ( v46 <= *((float *)&v2 + 2) )
        v46 = *((float *)&v2 + 2);
      if ( v3.x <= sectors_cfga )
        portal_ids_cfg.data.pointer = (const void *)LODWORD(v3.x);
      else
        *(float *)&portal_ids_cfg.data.pointer = sectors_cfga;
      if ( v3.y <= v51 )
        HIDWORD(portal_ids_cfg.data.max_storage) = LODWORD(v3.y);
      else
        *((float *)&portal_ids_cfg.data.max_storage + 1) = v51;
      if ( v3.z <= v49 )
        v49 = v3.z;
      if ( v50 <= v3.x )
        v50 = v3.x;
      if ( v47 <= v3.y )
        v52 = v3.y;
      else
        v52 = v47;
      if ( v46 <= v3.z )
        v46 = v3.z;
      v53 = this->m_allocator;
      _X = this->m_portals.m_end - 1;
      sector_aabb.min.x = (float)(v50 - *(float *)&portal_ids_cfg.data.pointer) * 0.5;
      sector_aabb.min.y = (float)(v52 - *((float *)&portal_ids_cfg.data.max_storage + 1)) * 0.5;
      sector_aabb.min.z = (float)(v46 - v49) * 0.5;
      position.x = (float)(v50 + *(float *)&portal_ids_cfg.data.pointer) * 0.5;
      position.y = (float)(v52 + *((float *)&portal_ids_cfg.data.max_storage + 1)) * 0.5;
      position.z = (float)(v46 + v49) * 0.5;
      v54 = vostok::collision::new_aabb_object(v53, 2u, &position, &sector_aabb.min, _X);
      this->m_portals_spatial_tree->insert(this->m_portals_spatial_tree, v54, &identity_matrix);
      ++v27;
    }
    while ( v27 != portals_cfg_enda );
  }
  vostok::render::culling::portal_sector_structure::initialize_portals_geometry(v28, this);
}
