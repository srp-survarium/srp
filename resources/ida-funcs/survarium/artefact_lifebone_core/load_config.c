survarium::artefact_lifebone_core::config *__cdecl survarium::artefact_lifebone_core::load_config(
        survarium::artefact_lifebone_core::config *result,
        vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v2; // eax
  const vostok::configs::binary_config_value *v3; // ebx
  int v4; // eax
  int v5; // esi
  const vostok::configs::binary_config_value *v6; // eax
  float v7; // xmm0_4
  __int64 pointer; // rax
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  __int64 v12; // rax
  vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  __int64 v16; // rax
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  __int64 v20; // rax
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  __int64 v24; // rax
  vostok::configs::binary_config_value *v25; // eax
  const vostok::configs::binary_config_value *v26; // eax
  float v27; // xmm0_4
  __int64 v28; // rax
  vostok::configs::binary_config_value *v29; // eax
  char **v30; // eax
  vostok::fixed_string<16> *v31; // ecx
  survarium::artefact_lifebone_core::regeneration_modifier *M_finish; // eax
  vostok::configs::binary_config_value *v33; // eax
  const vostok::configs::binary_config_value *v34; // ebx
  int v35; // eax
  int v36; // esi
  char **v37; // eax
  vostok::fixed_string<16> *v38; // ecx
  vostok::buffer_vector<survarium::artefact_lifebone_core::removed_affect> *v39; // ecx
  vostok::configs::binary_config_value *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  float v42; // xmm0_4
  __int64 v43; // rax
  const stlp_std::__false_type *v45; // [esp+0h] [ebp-78h]
  unsigned int v46; // [esp+4h] [ebp-74h]
  bool v47; // [esp+8h] [ebp-70h]
  survarium::artefact_lifebone_core::regeneration_modifier __x; // [esp+10h] [ebp-68h] BYREF
  int v49; // [esp+4Ch] [ebp-2Ch]
  int v50; // [esp+54h] [ebp-24h]
  __int64 v51; // [esp+58h] [ebp-20h]
  float v52; // [esp+60h] [ebp-18h]
  float v53; // [esp+64h] [ebp-14h]
  float v54; // [esp+68h] [ebp-10h]
  float v55; // [esp+6Ch] [ebp-Ch]
  float v56; // [esp+70h] [ebp-8h]
  int v57; // [esp+74h] [ebp-4h]

  result->passive.regeneration_modifiers._M_impl._M_start = 0;
  result->passive.regeneration_modifiers._M_impl._M_finish = 0;
  result->passive.regeneration_modifiers._M_impl._M_end_of_storage._M_data = 0;
  result->active.removed_affects.m_begin = (survarium::artefact_lifebone_core::removed_affect *)result->active.removed_affects.m_buffer;
  result->active.removed_affects.m_end = (survarium::artefact_lifebone_core::removed_affect *)result->active.removed_affects.m_buffer;
  result->active.removed_affects.m_max_end = (survarium::artefact_lifebone_core::removed_affect *)&result->active.duration_ms;
  qmemcpy(result, survarium::artefact_base::load_config((int)&__x.regen_mul, config), 0x14u);
  v2 = vostok::configs::binary_config_value::operator[](config, "passive");
  v3 = vostok::configs::binary_config_value::operator[](v2, "regeneration_modifiers");
  stlp_std::priv::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier>>::reserve(
    (stlp_std::priv::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier> > *)0x18,
    (int)&result->passive,
    24 * v3->count / 24);
  v4 = 24 * v3->count / 24;
  if ( v4 )
  {
    v5 = 0;
    v57 = 0;
    v50 = v4;
    while ( 1 )
    {
      v6 = vostok::configs::binary_config_value::operator[](
             (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5),
             "threshold_mul");
      if ( v6->type == 2 )
      {
        v7 = *(float *)&v6->data.pointer;
      }
      else
      {
        pointer = (int)v6->data.pointer;
        v49 = HIDWORD(pointer);
        v7 = (float)(int)pointer;
      }
      v9 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      *((float *)&v51 + 1) = v7;
      v10 = vostok::configs::binary_config_value::operator[](v9, "threshold_add");
      if ( v10->type == 2 )
      {
        v11 = *(float *)&v10->data.pointer;
      }
      else
      {
        v12 = (int)v10->data.pointer;
        v49 = HIDWORD(v12);
        v11 = (float)(int)v12;
      }
      v13 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      v52 = v11;
      v14 = vostok::configs::binary_config_value::operator[](v13, "timeout_mul");
      if ( v14->type == 2 )
      {
        v15 = *(float *)&v14->data.pointer;
      }
      else
      {
        v16 = (int)v14->data.pointer;
        v49 = HIDWORD(v16);
        v15 = (float)(int)v16;
      }
      v17 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      v53 = v15;
      v18 = vostok::configs::binary_config_value::operator[](v17, "timeout_add");
      if ( v18->type == 2 )
      {
        v19 = *(float *)&v18->data.pointer;
      }
      else
      {
        v20 = (int)v18->data.pointer;
        v49 = HIDWORD(v20);
        v19 = (float)(int)v20;
      }
      v21 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      v54 = v19;
      v22 = vostok::configs::binary_config_value::operator[](v21, "regen_mul");
      if ( v22->type == 2 )
      {
        v23 = *(float *)&v22->data.pointer;
      }
      else
      {
        v24 = (int)v22->data.pointer;
        v49 = HIDWORD(v24);
        v23 = (float)(int)v24;
      }
      v25 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      v55 = v23;
      v26 = vostok::configs::binary_config_value::operator[](v25, "regen_add");
      if ( v26->type == 2 )
      {
        v27 = *(float *)&v26->data.pointer;
      }
      else
      {
        v28 = (int)v26->data.pointer;
        v49 = HIDWORD(v28);
        v27 = (float)(int)v28;
      }
      v29 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v5);
      v56 = v27;
      v30 = (char **)vostok::configs::binary_config_value::operator[](v29, "body_part");
      vostok::fixed_string<16>::fixed_string<16>(v31, &__x.body_part, *v30);
      M_finish = result->passive.regeneration_modifiers._M_impl._M_finish;
      __x.regen_add = v56;
      __x.regen_mul = v55;
      __x.timeout_add = v54;
      __x.timeout_mul = v53;
      __x.threshold_add = v52;
      __x.threshold_mul = *((float *)&v51 + 1);
      if ( M_finish == result->passive.regeneration_modifiers._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<survarium::artefact_lifebone_core::regeneration_modifier,survarium::std_allocator<survarium::artefact_lifebone_core::regeneration_modifier>>::_M_insert_overflow_aux(
          &__x,
          &result->passive.regeneration_modifiers._M_impl,
          M_finish,
          v45,
          v46,
          v47);
      }
      else
      {
        if ( M_finish )
          survarium::artefact_lifebone_core::regeneration_modifier::regeneration_modifier(M_finish, &__x);
        ++result->passive.regeneration_modifiers._M_impl._M_finish;
      }
      v57 += 24;
      if ( !--v50 )
        break;
      v5 = v57;
    }
  }
  v33 = vostok::configs::binary_config_value::operator[](config, "active");
  v34 = vostok::configs::binary_config_value::operator[](v33, "remove_affects");
  v35 = 24 * v34->count / 24;
  if ( v35 )
  {
    v36 = 0;
    v57 = 0;
    v50 = v35;
    while ( 1 )
    {
      v51 = (int)vostok::configs::binary_config_value::operator[](
                   (vostok::configs::binary_config_value *)((char *)v34->data.pointer + v36),
                   "affect")->data.pointer;
      v37 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)((char *)v34->data.pointer + v36),
                       "body_part");
      vostok::fixed_string<16>::fixed_string<16>(v38, (vostok::buffer_string *)&__x.body_part.m_buffer[8], *v37);
      LODWORD(__x.threshold_mul) = v51;
      vostok::buffer_vector<survarium::artefact_lifebone_core::removed_affect>::push_back(
        v39,
        (int)&result->active,
        (const survarium::artefact_lifebone_core::removed_affect *)&__x.body_part.m_buffer[8]);
      v57 += 24;
      if ( !--v50 )
        break;
      v36 = v57;
    }
  }
  v40 = vostok::configs::binary_config_value::operator[](config, "active");
  v41 = vostok::configs::binary_config_value::operator[](v40, "duration");
  if ( v41->type == 2 )
  {
    v42 = *(float *)&v41->data.pointer;
  }
  else
  {
    v43 = (int)v41->data.pointer;
    v49 = HIDWORD(v43);
    v42 = (float)(int)v43;
  }
  result->active.duration_ms = (unsigned __int64)(v42 * 1000.0);
  return result;
}
