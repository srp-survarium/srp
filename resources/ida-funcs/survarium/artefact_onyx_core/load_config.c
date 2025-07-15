survarium::artefact_onyx_core::config *__cdecl survarium::artefact_onyx_core::load_config(
        survarium::artefact_onyx_core::config *result,
        vostok::configs::binary_config_value *config)
{
  survarium::artefact_onyx_core::config *v2; // ebx
  vostok::fixed_vector<vostok::fixed_string<16>,21>::allign_helper *m_buffer; // eax
  survarium::artefact_base::config *v4; // esi
  vostok::configs::binary_config_value *v5; // eax
  char **pointer; // esi
  const vostok::configs::binary_config_value *v7; // eax
  vostok::fixed_string<16> *v8; // ecx
  int v9; // edi
  vostok::fixed_string<16> *m_end; // esi
  char **v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  __int64 v15; // rax
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  __int64 v20; // rax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  __int64 v25; // rax
  vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // eax
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  __int64 v30; // rax
  vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // eax
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  __int64 v35; // rax
  vostok::configs::binary_config_value *v36; // eax
  vostok::configs::binary_config_value *v37; // eax
  const vostok::configs::binary_config_value *v38; // eax
  float v39; // xmm0_4
  __int64 v40; // rax
  vostok::configs::binary_config_value *v41; // eax
  vostok::configs::binary_config_value *v42; // eax
  const vostok::configs::binary_config_value *v43; // eax
  float v44; // xmm0_4
  __int64 v45; // rax
  vostok::configs::binary_config_value *v46; // eax
  vostok::configs::binary_config_value *v47; // eax
  const vostok::configs::binary_config_value *v48; // eax
  float v49; // xmm0_4
  __int64 v50; // rax
  vostok::configs::binary_config_value *v51; // eax
  vostok::configs::binary_config_value *v52; // eax
  const vostok::configs::binary_config_value *v53; // eax
  float v54; // xmm0_4
  __int64 v55; // rax
  vostok::configs::binary_config_value *v56; // eax
  vostok::configs::binary_config_value *v57; // eax
  const vostok::configs::binary_config_value *v58; // eax
  float v59; // xmm0_4
  __int64 v60; // rax
  vostok::configs::binary_config_value *v62; // [esp-4h] [ebp-3Ch]
  const char *v63; // [esp+0h] [ebp-38h]
  vostok::fixed_string<16> v64; // [esp+10h] [ebp-28h] BYREF
  char **v65; // [esp+34h] [ebp-4h]

  v2 = result;
  m_buffer = result->protected_body_parts.m_buffer;
  v62 = config;
  result->protected_body_parts.m_begin = (vostok::fixed_string<16> *)result->protected_body_parts.m_buffer;
  v2->protected_body_parts.m_end = (vostok::fixed_string<16> *)m_buffer;
  v2->protected_body_parts.m_max_end = (vostok::fixed_string<16> *)&m_buffer[21];
  v4 = survarium::artefact_base::load_config((int)&v64.m_max_end, v62);
  v5 = config;
  qmemcpy(v2, v4, 0x14u);
  pointer = (char **)vostok::configs::binary_config_value::operator[](v5, "protected_body_parts")->data.pointer;
  v65 = pointer;
  v7 = vostok::configs::binary_config_value::operator[](config, "protected_body_parts");
  v8 = (vostok::fixed_string<16> *)v7->data.pointer;
  v9 = (int)v7->data.pointer + 24 * v7->count;
  if ( pointer != (char **)v9 )
  {
    while ( 1 )
    {
      vostok::fixed_string<16>::fixed_string<16>(v8, &v64, *pointer);
      if ( v2->protected_body_parts.m_end >= v2->protected_body_parts.m_max_end
        && !`vostok::buffer_vector<vostok::fixed_string<16>>::push_back'::`11'::debug_macro_helper_ignore_always )
      {
        HIBYTE(result) = 0;
        vostok::debug::on_error(
          (bool *)&result + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_string<16> >::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v63);
        if ( vostok::debug::is_debugger_present() || HIBYTE(result) )
          __debugbreak();
      }
      m_end = v2->protected_body_parts.m_end;
      if ( m_end )
        vostok::fixed_string<16>::fixed_string<16>(m_end, &v64);
      v65 += 6;
      ++v2->protected_body_parts.m_end;
      if ( v65 == (char **)v9 )
        break;
      pointer = v65;
    }
  }
  v11 = (char **)vostok::configs::binary_config_value::operator[](config, "hit_type");
  v2->hit_type = survarium::hit_type(*v11);
  v12 = vostok::configs::binary_config_value::operator[](config, "passive");
  v13 = vostok::configs::binary_config_value::operator[](v12, "damage_add");
  if ( v13->type == 2 )
  {
    v14 = *(float *)&v13->data.pointer;
  }
  else
  {
    v15 = (int)v13->data.pointer;
    v65 = (char **)HIDWORD(v15);
    v14 = (float)(int)v15;
  }
  v16 = config;
  v2->passive.damage_add = v14;
  v17 = vostok::configs::binary_config_value::operator[](v16, "passive");
  v18 = vostok::configs::binary_config_value::operator[](v17, "damage_mul");
  if ( v18->type == 2 )
  {
    v19 = *(float *)&v18->data.pointer;
  }
  else
  {
    v20 = (int)v18->data.pointer;
    v65 = (char **)HIDWORD(v20);
    v19 = (float)(int)v20;
  }
  v21 = config;
  v2->passive.damage_mul = v19;
  v22 = vostok::configs::binary_config_value::operator[](v21, "passive");
  v23 = vostok::configs::binary_config_value::operator[](v22, "armor_piercing_add");
  if ( v23->type == 2 )
  {
    v24 = *(float *)&v23->data.pointer;
  }
  else
  {
    v25 = (int)v23->data.pointer;
    v65 = (char **)HIDWORD(v25);
    v24 = (float)(int)v25;
  }
  v26 = config;
  v2->passive.armor_piercing_add = v24;
  v27 = vostok::configs::binary_config_value::operator[](v26, "passive");
  v28 = vostok::configs::binary_config_value::operator[](v27, "armor_piercing_mul");
  if ( v28->type == 2 )
  {
    v29 = *(float *)&v28->data.pointer;
  }
  else
  {
    v30 = (int)v28->data.pointer;
    v65 = (char **)HIDWORD(v30);
    v29 = (float)(int)v30;
  }
  v31 = config;
  v2->passive.armor_piercing_mul = v29;
  v32 = vostok::configs::binary_config_value::operator[](v31, "active");
  v33 = vostok::configs::binary_config_value::operator[](v32, "damage_add");
  if ( v33->type == 2 )
  {
    v34 = *(float *)&v33->data.pointer;
  }
  else
  {
    v35 = (int)v33->data.pointer;
    v65 = (char **)HIDWORD(v35);
    v34 = (float)(int)v35;
  }
  v36 = config;
  v2->active.damage_add = v34;
  v37 = vostok::configs::binary_config_value::operator[](v36, "active");
  v38 = vostok::configs::binary_config_value::operator[](v37, "damage_mul");
  if ( v38->type == 2 )
  {
    v39 = *(float *)&v38->data.pointer;
  }
  else
  {
    v40 = (int)v38->data.pointer;
    v65 = (char **)HIDWORD(v40);
    v39 = (float)(int)v40;
  }
  v41 = config;
  v2->active.damage_mul = v39;
  v42 = vostok::configs::binary_config_value::operator[](v41, "active");
  v43 = vostok::configs::binary_config_value::operator[](v42, "armor_piercing_add");
  if ( v43->type == 2 )
  {
    v44 = *(float *)&v43->data.pointer;
  }
  else
  {
    v45 = (int)v43->data.pointer;
    v65 = (char **)HIDWORD(v45);
    v44 = (float)(int)v45;
  }
  v46 = config;
  v2->active.armor_piercing_add = v44;
  v47 = vostok::configs::binary_config_value::operator[](v46, "active");
  v48 = vostok::configs::binary_config_value::operator[](v47, "armor_piercing_mul");
  if ( v48->type == 2 )
  {
    v49 = *(float *)&v48->data.pointer;
  }
  else
  {
    v50 = (int)v48->data.pointer;
    v65 = (char **)HIDWORD(v50);
    v49 = (float)(int)v50;
  }
  v51 = config;
  v2->active.armor_piercing_mul = v49;
  v52 = vostok::configs::binary_config_value::operator[](v51, "active");
  v53 = vostok::configs::binary_config_value::operator[](v52, "absorb_total");
  if ( v53->type == 2 )
  {
    v54 = *(float *)&v53->data.pointer;
  }
  else
  {
    v55 = (int)v53->data.pointer;
    v65 = (char **)HIDWORD(v55);
    v54 = (float)(int)v55;
  }
  v56 = config;
  v2->active.absorb_total = v54;
  v57 = vostok::configs::binary_config_value::operator[](v56, "active");
  v58 = vostok::configs::binary_config_value::operator[](v57, "duration");
  if ( v58->type == 2 )
  {
    v59 = *(float *)&v58->data.pointer;
  }
  else
  {
    v60 = (int)v58->data.pointer;
    v65 = (char **)HIDWORD(v60);
    v59 = (float)(int)v60;
  }
  v2->active.duration_ms = (unsigned __int64)(v59 * 1000.0);
  return v2;
}
