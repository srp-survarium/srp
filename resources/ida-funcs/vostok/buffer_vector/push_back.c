void __usercall vostok::buffer_vector<unsigned int>::push_back(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<eax>,
        const vostok::variant<32> **value@<edx>)
{
  const vostok::variant<32> **m_end; // ecx

  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
        vostok::buffer_vector<vostok::ai::planning::expression_parameter> *this,
        const vostok::ai::planning::expression_parameter *value)
{
  vostok::ai::planning::expression_parameter *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::ai::planning::expression_parameter *)operator new(4u, this->m_end);
  if ( v3 )
    v3->instance = value->instance;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back(
        vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage> *this,
        const survarium::booby_trap_set_core::apply_damage *value)
{
  survarium::booby_trap_set_core::apply_damage *v3; // [esp+14h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (survarium::booby_trap_set_core::apply_damage *)operator new(0x28u, this->m_end);
  if ( v3 )
    qmemcpy(v3, value, sizeof(survarium::booby_trap_set_core::apply_damage));
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::console_commands::command_token>::push_back(
        vostok::buffer_vector<vostok::console_commands::command_token> *this,
        const vostok::console_commands::command_token *value)
{
  const char *name; // eax
  unsigned int *v4; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v4 = (unsigned int *)operator new(8u, (void *)this->m_end);
  if ( v4 )
  {
    name = value->name;
    *v4 = value->id;
    v4[1] = (unsigned int)name;
  }
  ++this->m_end;
}


void __fastcall vostok::buffer_vector<vostok::resources::request>::push_back(
        vostok::buffer_vector<vostok::resources::request> *this,
        const vostok::resources::request *value)
{
  vostok::resources::request *m_end; // eax

  m_end = this->m_end;
  if ( m_end )
    *m_end = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::push_back(
        vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float> > *this,
        const stlp_std::pair<vostok::ai::npc const *,float> *value)
{
  stlp_std::pair<vostok::ai::npc const *,float> *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (stlp_std::pair<vostok::ai::npc const *,float> *)operator new(8u, this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
        vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *this,
        const stlp_std::pair<char *,unsigned int> *value)
{
  stlp_std::pair<char *,unsigned int> *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (stlp_std::pair<char *,unsigned int> *)operator new(8u, this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::push_back(
        vostok::buffer_vector<vostok::ai::statistics_item<46,16> > *this,
        const vostok::ai::statistics_item<46,16> *value)
{
  vostok::ai::statistics_item<46,16> *v3; // [esp+60h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::ai::statistics_item<46,16> *)operator new(0x3F4u, this->m_end);
  if ( v3 )
    vostok::ai::statistics_item<46,16>::statistics_item<46,16>(v3, value);
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this,
        const vostok::animation::mixing::animation_interval *value)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(this->m_end, value);
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::push_back(
        vostok::buffer_vector<vostok::resources::creation_request> *this,
        const vostok::resources::creation_request *value)
{
  vostok::resources::creation_request *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::resources::creation_request *)operator new(0x10u, (void *)this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::fixed_string<24>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<24> > *this,
        const vostok::fixed_string<24> *value)
{
  vostok::fixed_string<24> *v3; // [esp+24h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<24> *)operator new(0x24u, this->m_end);
  if ( v3 )
    vostok::fixed_string<24>::fixed_string<24>(v3, value);
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::fixed_string<32>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<32> > *this,
        const vostok::fixed_string<32> *value)
{
  vostok::fixed_string<32> *v3; // [esp+28h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<32> *)operator new(0x2Cu, this->m_end);
  if ( v3 )
    vostok::fixed_string<32>::fixed_string<32>(v3, value);
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<vostok::fixed_string<46>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<46> > *this,
        const vostok::fixed_string<46> *value)
{
  vostok::fixed_string<46> *v3; // [esp+24h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<46> *)operator new(0x3Cu, this->m_end);
  if ( v3 )
    vostok::fixed_string<46>::fixed_string<46>(v3, value);
  ++this->m_end;
}


void __userpurge vostok::buffer_vector<vostok::fixed_string<64>>::push_back(
        const vostok::fixed_string<64> *value@<eax>,
        vostok::buffer_vector<vostok::fixed_string<64> > *this)
{
  vostok::fixed_string<64> *m_end; // esi
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi

  m_end = this->m_end;
  if ( m_end )
  {
    m_begin = (unsigned __int8 *)value->m_begin;
    v4 = value->m_end - value->m_begin;
    m_end->m_max_end = (char *)&m_end[1];
    v5 = v4;
    m_end->m_begin = m_end->m_buffer;
    m_end->m_end = m_end->m_buffer;
    memcpy((unsigned __int8 *)m_end->m_buffer, m_begin, v4);
    m_end->m_end += v5;
    *m_end->m_end = 0;
  }
  ++this->m_end;
}


void __thiscall vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        vostok::buffer_vector<void const *> *this,
        const void **value)
{
  const void **v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (const void **)operator new(4u, this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}
