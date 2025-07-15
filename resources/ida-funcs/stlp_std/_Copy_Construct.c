void __usercall stlp_std::_Copy_Construct<unsigned int>(unsigned int *__p@<edx>, unsigned int *__val@<eax>)
{
  *__p = *__val;
}


void __cdecl stlp_std::_Copy_Construct<void *>(void **__p, void *const *__val)
{
  *__p = *__val;
}


void __usercall stlp_std::_Copy_Construct<survarium::account_list_item>(
        survarium::account_list_item *__p@<esi>,
        const survarium::account_list_item *__val@<edi>)
{
  char *m_begin; // edx
  char *v3; // ecx
  char *v4; // ebx

  if ( __p )
  {
    __p->account_id = __val->account_id;
    m_begin = __val->account_name.m_begin;
    v3 = (char *)(__val->account_name.m_end - m_begin);
    __p->account_name.m_max_end = (char *)&__p->online;
    v4 = v3;
    __p->account_name.m_begin = __p->account_name.m_buffer;
    __p->account_name.m_end = __p->account_name.m_buffer;
    memcpy((unsigned __int8 *)__p->account_name.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v3);
    __p->account_name.m_end += (unsigned int)v4;
    *__p->account_name.m_end = 0;
    __p->online = __val->online;
  }
}


void __usercall stlp_std::_Copy_Construct<vostok::render::material_effects_entry>(
        vostok::render::material_effects_entry *__p@<esi>,
        const vostok::render::material_effects_entry *__val@<eax>)
{
  char *m_begin; // edx
  char *v3; // ecx
  char *v4; // edi

  if ( __p )
  {
    __p->m_material_effects_instance_ptr = __val->m_material_effects_instance_ptr;
    m_begin = __val->m_material_name.m_string.m_begin;
    v3 = (char *)(__val->m_material_name.m_string.m_end - m_begin);
    __p->m_material_name.m_string.m_max_end = &__p->m_material_name.m_separator;
    v4 = v3;
    __p->m_material_name.m_string.m_begin = __p->m_material_name.m_string.m_buffer;
    __p->m_material_name.m_string.m_end = __p->m_material_name.m_string.m_buffer;
    memcpy((unsigned __int8 *)__p->m_material_name.m_string.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v3);
    __p->m_material_name.m_string.m_end += (unsigned int)v4;
    *__p->m_material_name.m_string.m_end = 0;
    __p->m_material_name.m_separator = 47;
  }
}


void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::movement_target_wrapper>(
        vostok::ai::planning::movement_target_wrapper *__p,
        const vostok::ai::planning::movement_target_wrapper *__val)
{
  char *v2; // [esp+24h] [ebp-8h]

  v2 = (char *)operator new(0x138u, __p);
  if ( v2 )
  {
    *(_QWORD *)v2 = *(_QWORD *)&__val->position.x;
    *((_DWORD *)v2 + 2) = LODWORD(__val->position.z);
    *((vostok::math::float3 *)v2 + 1) = __val->direction;
    *((vostok::math::float3 *)v2 + 2) = __val->velocity;
    vostok::fs_new::virtual_path_string::virtual_path_string(
      (vostok::fs_new::virtual_path_string *)(v2 + 36),
      &__val->animation_name);
  }
}


void __usercall stlp_std::_Copy_Construct<vostok::render::texture_named_instance>(
        vostok::render::texture_named_instance *__p@<ecx>,
        const vostok::render::texture_named_instance *__val@<eax>)
{
  char *m_begin; // edx
  char *v4; // ecx
  char *v5; // edi

  if ( __p )
  {
    __p->texture = __val->texture;
    m_begin = __val->path.m_begin;
    v4 = (char *)(__val->path.m_end - m_begin);
    __p->path.m_max_end = (char *)&__p[1];
    v5 = v4;
    __p->path.m_begin = __p->path.m_buffer;
    __p->path.m_end = __p->path.m_buffer;
    memcpy((unsigned __int8 *)__p->path.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v4);
    __p->path.m_end += (unsigned int)v5;
    *__p->path.m_end = 0;
  }
}


void __cdecl stlp_std::_Copy_Construct<vostok::sound::unique_propagator_info>(
        vostok::sound::unique_propagator_info *__p,
        const vostok::sound::unique_propagator_info *__val)
{
  if ( __p )
  {
    stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
      &__p->voice_params._M_impl,
      &__val->voice_params._M_impl);
    __p->prop = __val->prop;
  }
}


void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned short const,survarium::material_pair const *>>(
        stlp_std::pair<unsigned short const ,survarium::material_pair const *> *__p,
        const stlp_std::pair<unsigned short const ,survarium::material_pair const *> *__val)
{
  _DWORD *v2; // [esp+4h] [ebp-8h]

  v2 = operator new(8u, __p);
  if ( v2 )
  {
    *(_WORD *)v2 = __val->first;
    v2[1] = __val->second;
  }
}


void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned int const,survarium::dictionary_item>>(
        stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__p,
        const stlp_std::pair<unsigned int const ,survarium::dictionary_item> *__val)
{
  char *v2; // [esp+28h] [ebp-8h]

  v2 = (char *)operator new(0x124u, __p);
  if ( v2 )
  {
    *(_DWORD *)v2 = __val->first;
    survarium::dictionary_item::dictionary_item((survarium::dictionary_item *)(v2 + 4), &__val->second);
  }
}


void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>>(
        stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *__p,
        const stlp_std::pair<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations> *__val)
{
  char *v2; // [esp+8h] [ebp-8h]

  v2 = (char *)operator new(0xCu, __p);
  if ( v2 )
  {
    *(_DWORD *)v2 = __val->first;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v2 + 4));
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
  }
}


void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<float,vostok::math::float3>>(
        stlp_std::pair<float,vostok::math::float3> *__p,
        const stlp_std::pair<float,vostok::math::float3> *__val)
{
  if ( __p )
    *__p = *__val;
}


void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<char const * const,unsigned int>>(
        stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *__p,
        const stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *__val)
{
  stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *v2; // [esp+4h] [ebp-8h]

  v2 = (stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> *)operator new(8u, __p);
  if ( v2 )
    *v2 = *__val;
}


void __usercall stlp_std::_Copy_Construct<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>>(
        stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *__p@<esi>,
        const stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> *__val)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  if ( __p )
  {
    m_begin = (unsigned __int8 *)__val->first.m_begin;
    v3 = __val->first.m_end - __val->first.m_begin;
    __p->first.m_max_end = (char *)&__p->second;
    v4 = v3;
    __p->first.m_begin = __p->first.m_buffer;
    __p->first.m_end = __p->first.m_buffer;
    memcpy((unsigned __int8 *)__p->first.m_buffer, m_begin, v3);
    __p->first.m_end += v4;
    *__p->first.m_end = 0;
    __p->second = __val->second;
  }
}


void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::specified_action>(
        vostok::ai::planning::specified_action *__p,
        const vostok::ai::planning::specified_action *__val)
{
  vostok::ai::planning::specified_action *v2; // [esp+54h] [ebp-8h]

  v2 = (vostok::ai::planning::specified_action *)operator new(0x34u, __p);
  if ( v2 )
    vostok::ai::planning::specified_action::specified_action(v2, __val);
}


void __usercall stlp_std::_Copy_Construct<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *__p@<esi>,
        const vostok::fs_new::virtual_path_string *__val@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  if ( __p )
  {
    m_begin = (unsigned __int8 *)__val->m_string.m_begin;
    v3 = __val->m_string.m_end - __val->m_string.m_begin;
    __p->m_string.m_max_end = &__p->m_separator;
    v4 = v3;
    __p->m_string.m_begin = __p->m_string.m_buffer;
    __p->m_string.m_end = __p->m_string.m_buffer;
    memcpy((unsigned __int8 *)__p->m_string.m_buffer, m_begin, v3);
    __p->m_string.m_end += v4;
    *__p->m_string.m_end = 0;
    __p->m_separator = 47;
  }
}


void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::world_state_property>(
        vostok::ai::planning::world_state_property *__p,
        const vostok::ai::planning::world_state_property *__val)
{
  vostok::ai::planning::world_state_property *v2; // [esp+4h] [ebp-8h]

  v2 = (vostok::ai::planning::world_state_property *)operator new(0xCu, __p);
  if ( v2 )
    *v2 = *__val;
}


void __cdecl stlp_std::_Copy_Construct<vostok::variant<32>>(vostok::variant<32> *__p, const vostok::variant<32> *__val)
{
  vostok::variant<32> *v2; // [esp+4h] [ebp-8h]

  v2 = (vostok::variant<32> *)operator new(0x30u, __p);
  if ( v2 )
    vostok::variant<32>::variant<32>(v2, __val);
}
