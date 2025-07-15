void __userpurge vostok::particle::particle_emitter::load<vostok::configs::binary_config_value>(
        vostok::particle::particle_emitter *this@<ecx>,
        const vostok::configs::binary_config_value *allocator,
        vostok::configs::binary_config_value prop_config)
{
  const vostok::configs::binary_config_value *v3; // ebx
  const vostok::configs::binary_config_value *max_storage_high; // edi
  int *v5; // esi
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // ecx
  vostok::configs::binary_config_value *v17; // ecx
  vostok::configs::binary_config_value *v18; // ecx
  char *v19; // eax
  vostok::fixed_string<260> *v20; // ecx
  vostok::configs::binary_config_value *v21; // ecx
  const void *pointer; // esi
  vostok::configs::binary_config_value *v23; // ecx
  const vostok::configs::binary_config_value *v24; // eax
  int v25; // eax
  vostok::buffer_string *v26; // ecx
  int v27; // edi
  _DWORD *v28; // eax
  const char *v29; // ebx
  char *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  vostok::configs::binary_config_value *v33; // eax
  const vostok::configs::binary_config_value *v34; // eax
  float v35; // xmm0_4
  const vostok::configs::binary_config_value *v36; // eax
  int *v37; // edi
  const char *v38; // eax
  const void *v39; // eax
  vostok::configs::binary_config_value *v40; // ecx
  char *v41; // eax
  int v42; // eax
  vostok::buffer_string *v43; // ecx
  int v44; // esi
  char *v45; // edi
  int v46; // eax
  vostok::configs::binary_config_value *v47; // ecx
  const vostok::configs::binary_config_value *v48; // eax
  vostok::configs::binary_config_value *v49; // ecx
  const vostok::configs::binary_config_value *v50; // eax
  const vostok::configs::binary_config_value *v51; // eax
  vostok::configs::binary_config_value *v52; // ecx
  int v53; // xmm0_4
  _BYTE v54[28]; // [esp-1Ch] [ebp-178h] BYREF
  vostok::buffer_string v55[22]; // [esp+Ch] [ebp-150h] BYREF
  char v56; // [esp+11Ch] [ebp-40h]
  char *v57; // [esp+128h] [ebp-34h] BYREF
  _BYTE *v58; // [esp+12Ch] [ebp-30h]
  int *v59; // [esp+130h] [ebp-2Ch]
  _BYTE v60[32]; // [esp+134h] [ebp-28h] BYREF
  int v61; // [esp+154h] [ebp-8h] BYREF
  vostok::configs::binary_config_value *v62; // [esp+158h] [ebp-4h] BYREF

  v3 = allocator;
  max_storage_high = (const vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage);
  v5 = (int *)&allocator[14].id.max_storage + 1;
  *v5 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
          "Delay",
          (vostok::configs::binary_config_value *)this,
          (const vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
          (const vostok::configs::binary_config_value *)((char *)allocator + 348));
  v3[14].id_crc = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                    "Duration",
                    v6,
                    max_storage_high,
                    (const vostok::configs::binary_config_value *)((char *)v3 + 352));
  BYTE4(v3[15].id.max_storage) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                   "UserControlsTheTime",
                                   v7,
                                   max_storage_high,
                                   (const bool *)&v3[15].id.max_storage + 4);
  *(_DWORD *)&v3[14].type = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                              "DurationVariance",
                              v8,
                              max_storage_high,
                              (const vostok::configs::binary_config_value *)((char *)v3 + 356));
  HIDWORD(v3[15].data.max_storage) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                       "EmitterLoops",
                                       v9,
                                       max_storage_high,
                                       (const vostok::configs::binary_config_value *)((char *)v3 + 364));
  HIDWORD(v3[15].data.max_storage) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                       "Loops",
                                       v10,
                                       max_storage_high,
                                       (const vostok::configs::binary_config_value *)((char *)v3 + 364));
  BYTE1(v3[15].id.pointer) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                               "WorldSpace",
                               v11,
                               max_storage_high,
                               (const bool *)&v3[15].id.pointer + 1);
  v3[15].data.pointer = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                          "MaxParticles",
                          v12,
                          max_storage_high,
                          v3 + 15);
  BYTE2(v3[15].id.max_storage) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                   "Enabled",
                                   v13,
                                   max_storage_high,
                                   (const bool *)&v3[15].id.max_storage + 2);
  v3[14].id.pointer = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                        "Priority",
                        v14,
                        max_storage_high,
                        (const vostok::configs::binary_config_value *)((char *)v3 + 344));
  LOBYTE(v3[15].id.pointer) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                "UseSecondTransform",
                                v15,
                                max_storage_high,
                                (const bool *)&v3[15].id);
  BYTE3(v3[15].id.max_storage) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                   "IsEternal",
                                   v16,
                                   max_storage_high,
                                   (const bool *)&v3[15].id.max_storage + 3);
  v3[15].id_crc = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                    "LifetimeCycle",
                    v17,
                    max_storage_high,
                    (const vostok::configs::binary_config_value *)((char *)v3 + 376));
  allocator = v3;
  v19 = (char *)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                  "Material",
                  v18,
                  max_storage_high,
                  (const vostok::configs::binary_config_value *)&allocator);
  vostok::fixed_string<260>::fixed_string<260>(v20, v55, v19);
  v56 = 47;
  vostok::strings::copy<128>((char (*)[128])v3, v55[0].m_begin);
  if ( vostok::configs::binary_config_value::value_exists(
         *(vostok::configs::binary_config_value **)&v54[24],
         (int)max_storage_high,
         (unsigned int)"LifeTime") )
  {
    qmemcpy(
      &v54[4],
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
        "LifeTime"),
      0x18u);
    pointer = prop_config.data.pointer;
    *(_DWORD *)v54 = prop_config.data.pointer;
    vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
      0,
      (vostok::memory::base_allocator *)&v3[5].id,
      *(vostok::configs::binary_config_value *)v54,
      *(int *)&v54[24]);
    max_storage_high = (const vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage);
  }
  else
  {
    pointer = prop_config.data.pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)max_storage_high, (unsigned int)"Rate") )
  {
    v24 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
            "Rate");
    *(_DWORD *)v54 = prop_config.data.pointer;
    qmemcpy(&v54[4], v24, 0x18u);
    vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
      0,
      (vostok::memory::base_allocator *)&v3[8].id,
      *(vostok::configs::binary_config_value *)v54,
      *(int *)&v54[24]);
    max_storage_high = (const vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage);
    pointer = prop_config.data.pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v23, (int)max_storage_high, (unsigned int)"BurstList") )
  {
    HIDWORD(prop_config.data.max_storage) = vostok::configs::binary_config_value::operator[](
                                              (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                                              "BurstList");
    v25 = 24 * *(unsigned __int16 *)(HIDWORD(prop_config.data.max_storage) + 22) / 24;
    v26 = 0;
    v27 = v25;
    allocator = (const vostok::configs::binary_config_value *)v25;
    if ( v25 )
    {
      if ( v25 == 1 )
      {
        if ( HIDWORD(v3[14].data.max_storage) )
        {
          prop_config.data.pointer = 0;
          v61 = 0;
          do
          {
            v57 = v60;
            v58 = v60;
            v59 = &v61;
            v60[0] = 0;
            vostok::fs_new::path_string_impl::assignf(
              &v57,
              v26,
              (vostok::buffer_string *)"Burst[%d]",
              (const char *)prop_config.data.pointer);
            if ( vostok::configs::binary_config_value::value_exists(
                   *(vostok::configs::binary_config_value **)&v54[24],
                   SHIDWORD(prop_config.data.max_storage),
                   (unsigned int)v57) )
            {
              v36 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                      v57);
              v37 = (int *)&v3[13].id.pointer[v61];
              allocator = v36;
              v62 = (vostok::configs::binary_config_value *)((v37[1] >> 31) ^ ((v37[1] >> 31) + v37[1]));
              v38 = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                      "Count",
                      v62,
                      v36,
                      (const vostok::configs::binary_config_value *)&v62);
              *(_DWORD *)&v54[16] = v37 + 2;
              *(_DWORD *)&v54[12] = allocator;
              v37[1] = (int)v38;
              v39 = vostok::particle::read_config_value<int,vostok::configs::binary_config_value>(
                      *(const vostok::configs::binary_config_value **)&v54[12],
                      *(const vostok::configs::binary_config_value **)&v54[16]);
              *(_DWORD *)&v54[8] = v37;
              *(_DWORD *)&v54[4] = allocator;
              v37[2] = (int)v39;
              *v37 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                       "Time",
                       v40,
                       *(const vostok::configs::binary_config_value **)&v54[4],
                       *(const vostok::configs::binary_config_value **)&v54[8]);
            }
            ++prop_config.data.pointer;
            v61 += 12;
          }
          while ( prop_config.data.pointer < (const void *)HIDWORD(v3[14].data.max_storage) );
        }
        else
        {
          v30 = type_info::raw_name(&vostok::particle::burst_entry `RTTI Type Descriptor');
          v3[13].id.pointer = (const char *)(*(int (__thiscall **)(const void *, int, char *, const char *, const char *, int))(*(_DWORD *)pointer + 16))(
                                              pointer,
                                              12,
                                              v30,
                                              "vostok::particle::particle_emitter::load",
                                              "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_emitter_inline.h",
                                              65);
          v31 = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                  "Burst[0]");
          *((_DWORD *)v3[13].id.pointer + 1) = vostok::configs::binary_config_value::operator[](v31, "Count")->data.pointer;
          v32 = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                  "Burst[0]");
          *((_DWORD *)v3[13].id.pointer + 2) = vostok::configs::binary_config_value::operator[](v32, "CountVariance")->data.pointer;
          v33 = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                  "Burst[0]");
          v34 = vostok::configs::binary_config_value::operator[](v33, "Time");
          if ( v34->type == 2 )
            v35 = *(float *)&v34->data.pointer;
          else
            v35 = (float)(int)v34->data.pointer;
          *(float *)v3[13].id.pointer = v35;
          HIDWORD(v3[14].data.max_storage) = 1;
        }
      }
      else
      {
        v41 = type_info::raw_name(&vostok::particle::burst_entry `RTTI Type Descriptor');
        v42 = (*(int (__thiscall **)(const void *, int, char *, const char *, const char *, int))(*(_DWORD *)pointer + 16))(
                pointer,
                12 * v27,
                v41,
                "vostok::particle::particle_emitter::load",
                "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_emitter_inline.h",
                91);
        v44 = 0;
        v3[13].id.pointer = (const char *)v42;
        prop_config.data.pointer = 0;
        if ( v27 )
        {
          do
          {
            v57 = v60;
            v58 = v60;
            v59 = &v61;
            v60[0] = 0;
            vostok::fs_new::path_string_impl::assignf(
              &v57,
              v43,
              (vostok::buffer_string *)"Burst[%d]",
              (const char *)prop_config.data.pointer);
            v45 = v57;
            if ( vostok::configs::binary_config_value::value_exists(
                   *(vostok::configs::binary_config_value **)&v54[24],
                   SHIDWORD(prop_config.data.max_storage),
                   (unsigned int)v57) )
            {
              v46 = *(int *)&v3[13].id.pointer[v44 + 4] >> 31;
              v47 = (vostok::configs::binary_config_value *)(v46 ^ (v46 + *(_DWORD *)&v3[13].id.pointer[v44 + 4]));
              *(_DWORD *)&v54[24] = &v62;
              v62 = v47;
              v48 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                      v45);
              *(_DWORD *)&v3[13].id.pointer[v44 + 4] = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                                         "Count",
                                                         v49,
                                                         v48,
                                                         *(const vostok::configs::binary_config_value **)&v54[24]);
              *(_DWORD *)&v54[24] = &v3[13].id.pointer[v44 + 8];
              v50 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                      v45);
              *(_DWORD *)&v3[13].id.pointer[v44 + 8] = vostok::particle::read_config_value<int,vostok::configs::binary_config_value>(
                                                         v50,
                                                         *(const vostok::configs::binary_config_value **)&v54[24]);
              *(_DWORD *)&v54[24] = &v3[13].id.pointer[v44];
              v51 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)HIDWORD(prop_config.data.max_storage),
                      v45);
              v53 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                      "Time",
                      v52,
                      v51,
                      *(const vostok::configs::binary_config_value **)&v54[24]);
              v43 = *(vostok::buffer_string **)&v54[24];
              *(_DWORD *)&v3[13].id.pointer[v44] = v53;
            }
            ++prop_config.data.pointer;
            v44 += 12;
          }
          while ( prop_config.data.pointer < allocator );
          v27 = (int)allocator;
        }
        HIDWORD(v3[14].data.max_storage) = v27;
      }
    }
    else
    {
      v28 = (_DWORD *)&v3[14].data.max_storage + 1;
      if ( HIDWORD(v3[14].data.max_storage) )
      {
        v29 = v3[13].id.pointer;
        *v28 = 0;
        if ( v29 )
          (*(void (__thiscall **)(const void *, const char *, const char *, const char *, int))(*(_DWORD *)pointer + 24))(
            pointer,
            v29,
            "vostok::particle::particle_emitter::load",
            "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\particle_emitter_inline.h",
            57);
      }
    }
  }
}
