vostok::animation::mixing::expression *__userpurge survarium::weapon_core::get_recoil_expression@<eax>(
        survarium::weapon_core *this@<ecx>,
        int a2@<eax>,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        vostok::animation::mixing::animation_lexeme *body_main_lexeme)
{
  unsigned int v8; // eax
  survarium::weapon_core *v9; // ecx
  float v10; // xmm0_4
  vostok::animation::mixing::expression *v11; // ecx
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  unsigned int v13; // edx
  float v14; // xmm0_4
  survarium::weapon_core *v15; // ecx
  vostok::animation::mixing::expression *v16; // ecx
  vostok::animation::mixing::animation_lexeme *v17; // ecx
  unsigned int v18; // edx
  float v19; // xmm0_4
  survarium::weapon_core *v20; // ecx
  vostok::animation::mixing::expression *v21; // ecx
  vostok::animation::mixing::animation_lexeme *v22; // ecx
  vostok::animation::mixing::animation_lexeme v24; // [esp+1Ch] [ebp-1A8h] BYREF
  vostok::animation::mixing::animation_lexeme v25; // [esp+A4h] [ebp-120h] BYREF
  vostok::animation::mixing::animation_lexeme buffera; // [esp+12Ch] [ebp-98h] BYREF
  float recoil_value; // [esp+1B8h] [ebp-Ch]
  int v28; // [esp+1BCh] [ebp-8h] BYREF
  double (__userpurge *v29)@<st0>(survarium::weapon_core *@<ecx>, float@<xmm0>, const float, const float, const unsigned int, const unsigned int, unsigned int, const float); // [esp+1C0h] [ebp-4h]
  float additivity_priority; // [esp+1CCh] [ebp+8h]

  result->m_node.m_object = 0;
  result->m_lexeme = 0;
  v8 = *(_DWORD *)(a2 + 1040);
  v29 = survarium::weapon_core::computed_backward_recoil_time;
  v28 = a2;
  v10 = survarium::weapon_recoil_calculator::get_back_value((survarium::weapon_recoil_calculator *)(a2 + 588), v8).m128_f32[0];
  if ( epsilon < v10 )
  {
    if ( (float)(s_bm_current_air_resistance - epsilon) < v10 )
      additivity_priority = s_bm_current_air_resistance - epsilon;
    else
      additivity_priority = v10;
  }
  else
  {
    additivity_priority = epsilon;
  }
  LOBYTE(recoil_value) = *(_BYTE *)(a2 + 1108);
  survarium::weapon_core::get_recoil_animation_lexeme(
    v9,
    (vostok::animation::mixing::animation_lexeme *)a2,
    &buffera,
    buffer,
    2,
    recoil_value,
    LODWORD(additivity_priority),
    (const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)2,
    (vostok::animation::mixing::animation_lexeme *)&v28);
  vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::animation_lexeme>(v11, result, &buffera);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v12, (int)&buffera);
  v13 = *(_DWORD *)(a2 + 1040);
  LOBYTE(additivity_priority) = *(_BYTE *)(a2 + 1108);
  v29 = survarium::weapon_core::computed_horizontal_recoil_time;
  v28 = a2;
  v14 = survarium::weapon_core::horizontal_recoil_value((survarium::weapon_core *)a2, v13);
  survarium::weapon_core::get_recoil_animation_lexeme(
    v15,
    (vostok::animation::mixing::animation_lexeme *)a2,
    &v25,
    buffer,
    1,
    additivity_priority,
    LODWORD(v14),
    (const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)3,
    (vostok::animation::mixing::animation_lexeme *)&v28);
  vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::animation_lexeme>(v16, result, &v25);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v17, (int)&v25);
  v18 = *(_DWORD *)(a2 + 1040);
  LOBYTE(additivity_priority) = *(_BYTE *)(a2 + 1108);
  v29 = survarium::weapon_core::computed_vertical_recoil_time;
  v28 = a2;
  v19 = survarium::weapon_core::vertical_recoil_value((survarium::weapon_core *)a2, v18);
  survarium::weapon_core::get_recoil_animation_lexeme(
    v20,
    (vostok::animation::mixing::animation_lexeme *)a2,
    &v24,
    buffer,
    0,
    additivity_priority,
    LODWORD(v19),
    (const fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> *)4,
    (vostok::animation::mixing::animation_lexeme *)&v28);
  vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::animation_lexeme>(v21, result, &v24);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v22, (int)&v24);
  return result;
}
