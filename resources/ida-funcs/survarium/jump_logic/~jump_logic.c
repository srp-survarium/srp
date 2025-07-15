void __usercall survarium::jump_logic::~jump_logic(survarium::jump_logic *this@<ecx>, int a2@<eax>)
{
  survarium::jump_logic_state_start *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx

  vostok::ai::fsm::clear_transitions(&this->m_logic, a2);
  survarium::jump_logic_base_state::~jump_logic_base_state((survarium::jump_logic_base_state *)(a2 + 256));
  survarium::jump_logic_state_start::~jump_logic_state_start(v3, a2 + 200);
  survarium::jump_logic_base_state::~jump_logic_base_state((survarium::jump_logic_base_state *)(a2 + 148));
  survarium::jump_logic_base_state::~jump_logic_base_state((survarium::jump_logic_base_state *)(a2 + 104));
  survarium::jump_logic_base_state::~jump_logic_base_state((survarium::jump_logic_base_state *)(a2 + 56));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)(a2 + 24));
}
