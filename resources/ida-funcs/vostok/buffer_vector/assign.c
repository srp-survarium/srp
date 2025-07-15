void __thiscall vostok::buffer_vector<unsigned int>::assign(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int count,
        const unsigned int *value)
{
  unsigned int *I; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_end = &this->m_begin[count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( I = this->m_begin; I != this->m_end; ++I )
    vostok::buffer_vector<vostok::variant<32> const *>::construct(
      (const vostok::variant<32> **)I,
      (const vostok::variant<32> *const *)value);
}


void __thiscall vostok::buffer_vector<void const *>::assign(
        vostok::buffer_vector<void const *> *this,
        survarium::game_camera *count,
        const void **value)
{
  const void **v4; // [esp+8h] [ebp-10h]
  const void **i; // [esp+Ch] [ebp-Ch]
  const void **I; // [esp+14h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[(_DWORD)count];
  survarium::weapon_user_dead_state::finalize(count);
  for ( I = this->m_begin; I != this->m_end; ++I )
  {
    v4 = (const void **)operator new(4u, I);
    if ( v4 )
      *v4 = *value;
  }
}


void __thiscall vostok::buffer_vector<vostok::variant<32>>::assign(
        vostok::buffer_vector<vostok::variant<32> > *this,
        unsigned int count,
        const vostok::variant<32> *value)
{
  vostok::variant<32> *v3; // ecx
  vostok::variant<32> *I; // [esp+10h] [ebp-4h]

  vostok::buffer_vector<vostok::variant<32>>::destroy(this->m_begin, &this->m_end);
  v3 = &this->m_begin[count];
  this->m_end = v3;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  for ( I = this->m_begin; I != this->m_end; ++I )
    vostok::buffer_vector<vostok::variant<32>>::construct(I, value);
}


void __thiscall vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
        vostok::buffer_vector<vostok::physics::base_physics_object *> *this,
        vostok::physics::base_physics_object **begin,
        vostok::physics::base_physics_object **const *end)
{
  _DWORD *v4; // [esp+8h] [ebp-10h]
  vostok::physics::base_physics_object **i; // [esp+Ch] [ebp-Ch]
  vostok::physics::base_physics_object **I; // [esp+14h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
  {
    v4 = operator new(4u, I);
    if ( v4 )
      *v4 = *begin;
    ++begin;
    ++I;
  }
}


void __thiscall vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
        vostok::buffer_vector<unsigned int> *this,
        const unsigned int *begin,
        const unsigned int *const *end)
{
  unsigned int *v3; // ecx
  unsigned int *I; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = &this->m_begin[*end - begin];
  this->m_end = v3;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  I = this->m_begin;
  while ( begin != *end )
    vostok::buffer_vector<vostok::variant<32> const *>::construct(
      (const vostok::variant<32> **)I++,
      (const vostok::variant<32> *const *)begin++);
}


void __userpurge vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        const vostok::render::ray *begin@<ecx>,
        const vostok::render::ray *const *end@<edi>,
        vostok::buffer_vector<vostok::render::ray> *this)
{
  vostok::render::ray *m_begin; // esi
  vostok::render::ray *i; // eax

  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  for ( i = m_begin; begin != *end; ++i )
  {
    if ( i )
      *i = *begin;
    ++begin;
  }
}


void __thiscall vostok::buffer_vector<vostok::ai::planning::object_instance>::assign<vostok::ai::planning::object_instance const *>(
        vostok::buffer_vector<vostok::ai::planning::object_instance> *this,
        const vostok::ai::planning::object_instance *begin,
        const vostok::ai::planning::object_instance *const *end)
{
  vostok::ai::planning::object_instance *i; // [esp+20h] [ebp-Ch]
  vostok::ai::planning::object_instance *I; // [esp+28h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
    vostok::buffer_vector<vostok::ai::planning::object_instance>::construct(I++, begin++);
}


void __userpurge vostok::buffer_vector<vostok::render::sampler_slot>::assign<vostok::render::sampler_slot const *>(
        const vostok::render::sampler_slot *begin@<eax>,
        vostok::buffer_vector<vostok::render::sampler_slot> *this,
        const vostok::render::sampler_slot *const *end)
{
  const vostok::render::sampler_slot *const *v3; // ebx
  const vostok::render::sampler_slot *v4; // edi
  vostok::render::sampler_slot *m_begin; // esi
  vostok::render::sampler_slot *v6; // edx
  char *m_buffer; // esi
  unsigned int v8; // ebp
  unsigned __int8 *v9; // [esp-8h] [ebp-18h]
  vostok::render::sampler_slot *I; // [esp+14h] [ebp+4h]

  v3 = end;
  v4 = begin;
  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  v6 = m_begin;
  I = m_begin;
  if ( begin != *end )
  {
    m_buffer = m_begin->name.m_buffer;
    do
    {
      if ( v6 )
      {
        v8 = v4->name.m_end - v4->name.m_begin;
        v9 = (unsigned __int8 *)v4->name.m_begin;
        v6->name.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        memcpy((unsigned __int8 *)m_buffer, v9, v8);
        *((_DWORD *)m_buffer - 2) += v8;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 16) = v4->slot_id;
        v3 = end;
        *((_DWORD *)m_buffer + 17) = v4->state;
        v6 = I;
      }
      ++v4;
      ++v6;
      m_buffer += 84;
      I = v6;
    }
    while ( v4 != *v3 );
  }
}


void __userpurge vostok::buffer_vector<vostok::render::texture_slot>::assign<vostok::render::texture_slot const *>(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<ecx>,
        const vostok::render::texture_slot *begin@<eax>,
        const vostok::render::texture_slot *const *end)
{
  vostok::render::texture_slot **p_m_end; // ebx
  vostok::render::texture_slot *m_begin; // esi
  vostok::render::texture_slot *v7; // edx
  char *m_buffer; // esi
  unsigned int v9; // ebx
  vostok::render::res_texture *m_object; // eax
  unsigned __int8 *v11; // [esp-8h] [ebp-1Ch]
  vostok::render::texture_slot *I; // [esp+10h] [ebp-4h]

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::render::texture_slot>::destroy(this->m_begin, &this->m_end);
  m_begin = this->m_begin;
  *p_m_end = &m_begin[*end - begin];
  v7 = m_begin;
  I = m_begin;
  if ( begin != *end )
  {
    m_buffer = m_begin->name.m_buffer;
    do
    {
      if ( v7 )
      {
        v9 = begin->name.m_end - begin->name.m_begin;
        v11 = (unsigned __int8 *)begin->name.m_begin;
        v7->name.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        memcpy((unsigned __int8 *)m_buffer, v11, v9);
        *((_DWORD *)m_buffer - 2) += v9;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 16) = begin->slot_id;
        v7 = I;
        *((_DWORD *)m_buffer + 17) = 0;
        m_object = begin->texture.m_object;
        if ( m_object )
        {
          *((_DWORD *)m_buffer + 17) = m_object;
          ++m_object->m_reference_count;
        }
      }
      ++begin;
      ++v7;
      m_buffer += 84;
      I = v7;
    }
    while ( begin != *end );
  }
}


void __thiscall vostok::buffer_vector<vostok::fixed_string<46>>::assign<vostok::fixed_string<46> const *>(
        vostok::buffer_vector<vostok::fixed_string<46> > *this,
        const vostok::fixed_string<46> *begin,
        const vostok::fixed_string<46> *const *end)
{
  vostok::fixed_string<46> *v4; // [esp+20h] [ebp-Ch]
  vostok::fixed_string<46> *I; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
  {
    v4 = (vostok::fixed_string<46> *)operator new(0x3Cu, I);
    if ( v4 )
      vostok::fixed_string<46>::fixed_string<46>(v4, begin);
    ++begin;
    ++I;
  }
}
