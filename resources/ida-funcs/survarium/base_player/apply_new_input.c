void __thiscall survarium::base_player::apply_new_input(
        survarium::base_player *this,
        unsigned int current_time_in_ms,
        const survarium::player_input *input)
{
  survarium::base_player *actions_mask; // ecx
  float y; // xmm0_4
  long double v6; // rdi
  survarium::base_player *v7; // ecx
  survarium::base_player *v8; // ecx
  vostok::math::float4x4 *v9; // eax
  vostok::physics::world *m_physics_world; // ecx
  int v11; // ecx
  __int16 v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  vostok::memory::base_allocator_vtbl *v16; // esi
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v17; // ecx
  survarium::usable_object *current_object; // ecx
  vostok::math::float4x4 *v19; // eax
  survarium::usable_object *v20; // eax
  unsigned int v21; // [esp+1Ch] [ebp-BCh]
  int v22; // [esp+20h] [ebp-B8h]
  int v23; // [esp+24h] [ebp-B4h] BYREF
  int v24; // [esp+28h] [ebp-B0h]
  vostok::memory::pthreads3_allocator *v25; // [esp+2Ch] [ebp-ACh]
  int v26; // [esp+30h] [ebp-A8h]
  survarium::player_input previous_input; // [esp+34h] [ebp-A4h] BYREF
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > v28; // [esp+40h] [ebp-98h] BYREF
  vostok::memory::pthreads3_allocator *v29; // [esp+48h] [ebp-90h]
  int v30; // [esp+4Ch] [ebp-8Ch]
  int v31; // [esp+50h] [ebp-88h] BYREF
  unsigned int v32; // [esp+54h] [ebp-84h]
  vostok::math::float4x4 v33; // [esp+58h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+98h] [ebp-40h] BYREF

  if ( !this->m_is_alive )
    return;
  actions_mask = (survarium::base_player *)this->m_input.actions_mask;
  previous_input.rotation_delta.x = this->m_input.rotation_delta.x;
  y = this->m_input.rotation_delta.y;
  this->m_input.rotation_delta = input->rotation_delta;
  previous_input.rotation_delta.y = y;
  previous_input.actions_mask = (unsigned int)actions_mask;
  this->m_input.actions_mask = input->actions_mask;
  LODWORD(v6) = &this->m_linear_horizontal_speed;
  survarium::base_player::process_quick_slots(
    actions_mask,
    (int)this,
    (survarium::inventory *)&previous_input,
    &this->m_input,
    current_time_in_ms);
  if ( (this->m_input.actions_mask & 0x40000000) == 0 )
    goto LABEL_23;
  LODWORD(v6) = 0;
  if ( this->m_time_left_to_try_spot_in_ms )
    goto LABEL_23;
  this->m_time_left_to_try_spot_in_ms = 3000;
  HIDWORD(v6) = &survarium::base_player::computed_head_transform(v7, this, &result)->c;
  v9 = survarium::base_player::computed_head_transform(v8, this, &v33);
  m_physics_world = this->m_physics_world;
  v23 = 0;
  v24 = 0;
  v26 = 0;
  LODWORD(v6) = &v23;
  v25 = &vostok::memory::g_mt_allocator;
  ((void (__thiscall *)(vostok::physics::world *, _DWORD, $91D1B2149FAC90180ECB9AC277F76009 *, _DWORD, int *, int, int))m_physics_world->ray_query)(
    m_physics_world,
    HIDWORD(v6),
    &v9->k.0,
    LODWORD(s_spot_max_distance),
    &v23,
    0xFFFF,
    2058);
  v11 = 40;
  v21 = 0;
  v32 = (v24 - v23) / 40;
  if ( !v32 )
    goto LABEL_22;
  v22 = 0;
  while ( 1 )
  {
    HIDWORD(v6) = v23 + v22;
    v12 = (***(int (__thiscall ****)(_DWORD))(v23 + v22))(*(_DWORD *)(v23 + v22));
    if ( (v12 & 0x800) == 0 )
    {
      if ( (v12 & 0xA) != 0 )
        goto LABEL_22;
      goto LABEL_18;
    }
    v13 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)HIDWORD(v6) + 12) + 8))(*(_DWORD *)(*(_DWORD *)HIDWORD(v6) + 12));
    LODWORD(v6) = v13;
    if ( v13
      && (*(unsigned __int8 (__thiscall **)(int, survarium::base_player *))(*(_DWORD *)(v13 + 312) + 4))(
           v13 + 312,
           this) )
    {
      (**(void (__thiscall ***)(int, survarium::base_player *))(LODWORD(v6) + 312))(LODWORD(v6) + 312, this);
      goto LABEL_22;
    }
    v14 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)HIDWORD(v6) + 12) + 4))(*(_DWORD *)(*(_DWORD *)HIDWORD(v6) + 12));
    HIDWORD(v6) = v14;
    if ( v14 )
      break;
LABEL_18:
    ++v21;
    v22 += 40;
    if ( v21 >= v32 )
      goto LABEL_22;
  }
  LODWORD(v6) = 0;
  v15 = (*(_DWORD *)(v14 + 12) - *(_DWORD *)(v14 + 8)) >> 2;
  v28.m_allocator = 0;
  v28._M_data = 0;
  v29 = &vostok::memory::g_mt_allocator;
  v30 = 0;
  if ( v15 )
  {
    do
    {
      v31 =  __thiscall vostok::sound::world::`vcall'{12,{flat}}(*(void **)(*(_DWORD *)(HIDWORD(v6) + 8)
                                                                          + 4 * LODWORD(v6)));
      if ( v31 )
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(
          (stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > *)&v31,
          &v28);
      ++LODWORD(v6);
    }
    while ( LODWORD(v6) < (*(_DWORD *)(HIDWORD(v6) + 12) - *(_DWORD *)(HIDWORD(v6) + 8)) >> 2 );
  }
  v16 = v28.m_allocator->__vftable;
  if ( !v28.m_allocator->__vftable
    || !(*((unsigned __int8 (__thiscall **)(vostok::memory::base_allocator_vtbl *, survarium::base_player *))v16->~vostok::memory::base_allocator
         + 1))(
          v16,
          this) )
  {
    stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
      (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)v11,
      (int)&v28);
    goto LABEL_18;
  }
  (*(void (__thiscall **)(vostok::memory::base_allocator_vtbl *, survarium::base_player *))v16->~vostok::memory::base_allocator)(
    v16,
    this);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v17,
    (int)&v28);
LABEL_22:
  vostok::vectora<vostok::physics::closest_ray_result>::~vectora<vostok::physics::closest_ray_result>(
    (vostok::vectora<vostok::physics::closest_ray_result> *)v11,
    (int)&v23);
LABEL_23:
  current_object = this->m_usable_object_user_data.current_object;
  if ( !current_object || current_object->m_hold_use_button )
  {
    if ( (previous_input.actions_mask & 0x800000) != 0 || (this->m_input.actions_mask & 0x800000) == 0 )
    {
      if ( (previous_input.actions_mask & 0x800000) != 0
        && (this->m_input.actions_mask & 0x800000) == 0
        && current_object )
      {
        this->m_usable_object_user_data.current_time_ms = current_time_in_ms;
        current_object->use_finalize(current_object, &this->m_usable_object_user_data);
      }
    }
    else
    {
      v19 = survarium::base_player::computed_head_transform((survarium::base_player *)current_object, this, &v33);
      v20 = survarium::base_player::detect_usable_object(this, v19);
      LODWORD(v6) = v20;
      if ( v20 && v20->can_use(v20, &this->m_usable_object_user_data) )
      {
        this->m_usable_object_user_data.current_time_ms = current_time_in_ms;
        (*(void (__thiscall **)(_DWORD, survarium::usable_object_user_data *))(*(_DWORD *)LODWORD(v6) + 28))(
          LODWORD(v6),
          &this->m_usable_object_user_data);
      }
    }
  }
  if ( this->m_input.actions_mask != previous_input.actions_mask || (previous_input.actions_mask & 0x60) == 0x60 )
    this->m_need_to_select_animations = 1;
  HIDWORD(v6) = &this->m_usable_object_user_data;
  survarium::base_player::apply_rotation(
    (survarium::base_player *)current_object,
    v6,
    (const vostok::math::float2 *)this,
    (vostok::animation::animation_player *)&this->m_input);
  *(_BYTE *)(**(_DWORD **)((char *)&dword_10E74 + (_DWORD)this) + 496) = (this->m_input.actions_mask & 0x200) != 0;
}
