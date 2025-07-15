void __userpurge survarium::base_player::tick_animations(
        unsigned int previous_time_in_ms@<eax>,
        survarium::base_player *a2@<ecx>,
        float a3@<xmm0>,
        signed int this,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  _BYTE *v8; // eax
  bool v9; // al
  unsigned int v10; // edi
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // eax
  char *v12; // esi
  unsigned int v13; // eax
  vostok::animation::subscribed_channel **v14; // edi
  bool v15; // al
  survarium::base_player *v16; // ecx
  bool v17; // zf
  float v18; // xmm0_4
  unsigned int v19; // eax
  survarium::player_stamina *v20; // esi
  survarium::player_stamina *v21; // ecx
  bool v22; // al
  vostok::animation::animation_player *v23; // esi
  vostok::math::float4x4 *v24; // ecx
  survarium::interactive_object *v25; // ebx
  vostok::math::float4x4 *v26; // eax
  vostok::animation::animation_player *value; // [esp+0h] [ebp-78h]
  unsigned int v28; // [esp+8h] [ebp-70h]
  bool v29; // [esp+Ch] [ebp-6Ch]
  vostok::math::float4x4 result; // [esp+18h] [ebp-60h] BYREF
  bool is_in_past[4]; // [esp+58h] [ebp-20h]
  float v32; // [esp+5Ch] [ebp-1Ch]
  float v33; // [esp+60h] [ebp-18h]
  float v34; // [esp+64h] [ebp-14h]
  float v35; // [esp+68h] [ebp-10h]
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp+6Ch] [ebp-Ch] BYREF
  int v37; // [esp+70h] [ebp-8h]
  unsigned int v38; // [esp+74h] [ebp-4h]
  float current_time_in_msa; // [esp+80h] [ebp+8h]
  bool current_time_in_ms_3; // [esp+83h] [ebp+Bh]

  v37 = 0;
  v9 = 1;
  if ( !*(_BYTE *)(this + 766)
    && !(*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(this + 320) + 124))(*(_DWORD *)(this + 320)) )
  {
    v8 = **(_BYTE ***)((char *)&dword_10E74 + this);
    if ( !v8[497] || v8[496] || !v8[498] )
      v9 = 0;
  }
  *(_BYTE *)(this + 766) = v9;
  if ( v9 )
  {
    survarium::base_player::select_animations(a2, (_DWORD *)this, previous_time_in_ms);
    *(_BYTE *)(this + 766) = 0;
  }
  if ( (vostok::animation::subscribed_channel **)previous_time_in_ms != current_time_in_ms )
  {
    do
    {
      v10 = 0;
      if ( *(_DWORD *)((char *)&unk_10410 + this)
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v37 |= 1u;
        m_object = vostok::animation::tree(
                     (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&unk_10410 + this),
                     &v36)->m_object;
        if ( m_object[1].m_reference_count )
          v10 = *(_DWORD *)(*(_DWORD *)m_object[5].m_reference_count + 160);
        else
          v10 = -1;
      }
      if ( (v37 & 1) != 0 )
      {
        v37 &= ~1u;
        vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v36);
      }
      current_time_in_ms_3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 320) + 68))(*(_DWORD *)(this + 320));
      if ( current_time_in_ms_3
        && (v12 = (char *)&loc_1106F + this + 1,
            a3 = *(float *)((char *)&loc_1106F + this + 65),
            v35 = *(float *)((char *)&loc_1106F + this + 141),
            v34 = a3,
            a3 <= v35)
        && (a3 = survarium::player_params_modifiers_container::apply_modifier(
                   *((survarium::player_params_modifiers_container **)v12 + 30),
                   stamina_spending_speed_modifier,
                   a3,
                   *((float *)v12 + 13),
                   1.0),
            v33 = a3,
            a3 > 0.0) )
      {
        v38 = *((_DWORD *)v12 + 36) - (unsigned __int64)((v35 - v34) / v33 * -1000.0);
      }
      else
      {
        v38 = -1;
      }
      v13 = v38 + (v10 < v38 ? v10 - v38 : 0);
      v14 = (vostok::animation::subscribed_channel **)(v13
                                                     + ((unsigned int)current_time_in_ms < v13
                                                      ? (unsigned int)current_time_in_ms - v13
                                                      : 0));
      v15 = vostok::animation::animation_player::tick_impl(
              (vostok::animation::animation_player *)((char *)current_time_in_ms - v13),
              this + 848,
              v14,
              v28,
              v29);
      v17 = *(_BYTE *)(this + 764) == 0;
      *(_BYTE *)(this + 766) = v15;
      if ( !v17 )
      {
        if ( current_time_in_ms_3 )
        {
          v18 = survarium::player_params_modifiers_container::apply_modifier(
                  *(survarium::player_params_modifiers_container **)((char *)&loc_1106F + this + 121),
                  stamina_spending_speed_modifier,
                  a3,
                  *(float *)((char *)&loc_1106F + this + 53),
                  1.0);
          v19 = (unsigned int)v14 - *(_DWORD *)((char *)&loc_1106F + this + 145);
          v32 = v18;
          current_time_in_msa = v18 * ((double)v19 * 0.001);
          survarium::player_stamina::spend(
            (survarium::player_stamina *)((char *)&loc_1106F + this + 1),
            current_time_in_msa);
        }
        v20 = (survarium::player_stamina *)((char *)&loc_1106F + this + 1);
        a3 = *(float *)((char *)&loc_1106F + this + 141);
        if ( *(float *)((char *)&loc_1106F + this + 49) > a3
          && (a3 == 0.0 || v20->m_last_spending_time_in_ms + 1000 < (unsigned int)v14) )
        {
          survarium::player_stamina::regenerate(v20, (const unsigned int)v14, a3);
        }
        v20->m_current_time_in_ms = (unsigned int)v14;
        if ( (vostok::animation::subscribed_channel **)v38 == v14 )
        {
          is_in_past[0] = survarium::base_player::is_in_past(v16, this, *(_DWORD *)(this + 736));
          v22 = survarium::player_stamina::deplete(v21, (int)&loc_1106F + this + 1, *(int *)is_in_past)
             || *(_BYTE *)(this + 766);
          *(_BYTE *)(this + 766) = v22;
        }
      }
      if ( *(_BYTE *)(this + 766) )
      {
        survarium::base_player::select_animations(v16, (_DWORD *)this, (unsigned int)v14);
        *(_BYTE *)(this + 766) = 0;
      }
    }
    while ( v14 != current_time_in_ms );
  }
  qmemcpy(
    &byte_10E2C[this],
    vostok::animation::animation_player::get_object_transform(
      (vostok::animation::animation_player *)&result,
      (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(this + 848),
      &result,
      (void *)this),
    0x40u);
  v23 = (vostok::animation::animation_player *)(this + 848);
  vostok::animation::animation_player::set_object_transform(
    0,
    (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)(this + 848),
    (const vostok::math::float4x4 *)&byte_10E2C[this],
    (void *)this);
  v25 = *(survarium::interactive_object **)(this + 320);
  if ( v25 )
  {
    if ( v25->m_has_animated_object )
    {
      value = (vostok::animation::animation_player *)v24;
      v26 = vostok::math::float4x4::identity(v24, &result);
      vostok::animation::animation_player::set_object_transform(
        value,
        (const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)v23,
        v26,
        v25);
    }
  }
}
