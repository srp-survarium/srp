void __thiscall vostok::fixed_vector<int,4096>::fixed_vector<int,4096>(vostok::fixed_vector<int,4096> *this)
{
  int *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_begin = v1;
  this->m_end = v1;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
}


void __thiscall vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(
        vostok::fixed_vector<unsigned int,4> *this,
        const vostok::fixed_vector<unsigned int,4> *other)
{
  unsigned int *end; // [esp+18h] [ebp-8h] BYREF
  unsigned int *m_buffer; // [esp+1Ch] [ebp-4h]

  m_buffer = (unsigned int *)this->m_buffer;
  this->m_begin = (unsigned int *)this->m_buffer;
  this->m_end = m_buffer;
  end = other->m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    this,
    other->m_begin,
    (const unsigned int *const *)&end);
}


void __thiscall vostok::fixed_vector<unsigned int,4>::fixed_vector<unsigned int,4>(
        vostok::fixed_vector<unsigned int,4> *this)
{
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(this, (unsigned int *)this->m_buffer, 4u, 0);
}


void __thiscall vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(
        vostok::fixed_vector<void const *,4> *this)
{
  this->m_begin = (const void **)this->m_buffer;
  this->m_end = (const void **)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __thiscall vostok::fixed_vector<vostok::console_commands::command_token,12>::fixed_vector<vostok::console_commands::command_token,12>(
        vostok::fixed_vector<stlp_std::pair<char *,unsigned int>,32> *this)
{
  this->m_begin = (stlp_std::pair<char *,unsigned int> *)this->m_buffer;
  this->m_end = (stlp_std::pair<char *,unsigned int> *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __thiscall vostok::fixed_vector<vostok::ai::planning::plan_item,32>::fixed_vector<vostok::ai::planning::plan_item,32>(
        vostok::fixed_vector<vostok::ai::planning::plan_item,32> *this)
{
  this->m_begin = (vostok::ai::planning::plan_item *)this->m_buffer;
  this->m_end = (vostok::ai::planning::plan_item *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __thiscall vostok::fixed_vector<vostok::sound::search::vertex_id_type,4>::fixed_vector<vostok::sound::search::vertex_id_type,4>(
        vostok::fixed_vector<vostok::sound::search::vertex_id_type,4> *this)
{
  this->m_begin = (vostok::sound::search::vertex_id_type *)this->m_buffer;
  this->m_end = (vostok::sound::search::vertex_id_type *)this->m_buffer;
}


void __thiscall vostok::fixed_vector<vostok::ai::planning::object_instance,16>::fixed_vector<vostok::ai::planning::object_instance,16>(
        vostok::fixed_vector<vostok::ai::planning::object_instance,16> *this)
{
  this->m_begin = (vostok::ai::planning::object_instance *)this->m_buffer;
  this->m_end = (vostok::ai::planning::object_instance *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __thiscall vostok::fixed_vector<vostok::fixed_string<24>,12>::fixed_vector<vostok::fixed_string<24>,12>(
        vostok::fixed_vector<vostok::fixed_string<24>,12> *this)
{
  this->m_begin = (vostok::fixed_string<24> *)this->m_buffer;
  this->m_end = (vostok::fixed_string<24> *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __thiscall vostok::fixed_vector<vostok::fixed_string<46>,16>::fixed_vector<vostok::fixed_string<46>,16>(
        vostok::fixed_vector<vostok::fixed_string<46>,16> *this)
{
  this->m_begin = (vostok::fixed_string<46> *)this->m_buffer;
  this->m_end = (vostok::fixed_string<46> *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}


void __usercall vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
        vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = a2 + 2;
  a2[1] = a2 + 2;
}
