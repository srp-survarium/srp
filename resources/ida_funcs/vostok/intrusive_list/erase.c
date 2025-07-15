char __thiscall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::particle::base_particle *object)
{
  vostok::size_policy *v3; // ecx
  vostok::particle::base_particle *next_of_object; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v5; // ecx
  vostok::particle::base_particle *m_first; // [esp+4h] [ebp-24h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+18h] [ebp-10h] BYREF
  vostok::particle::base_particle *i; // [esp+20h] [ebp-8h]
  vostok::particle::base_particle *previous_i; // [esp+24h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  previous_i = 0;
  v3 = this;
  for ( i = this->m_first;
        i;
        i = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i) )
  {
    v3 = (vostok::size_policy *)i;
    if ( i == object )
      break;
    previous_i = i;
  }
  if ( i == object )
  {
    vostok::size_policy::decrement_size(v3, this);
    if ( previous_i )
    {
      next_of_object = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i);
      previous_i->next = next_of_object;
    }
    else
    {
      this->m_first = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i);
    }
    if ( !vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i) )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v5 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v5,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v3,
      (int)&raii);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        survarium::damage_protector *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v4; // ecx
  survarium::damage_protector *m_first; // [esp+0h] [ebp-24h]
  survarium::damage_protector *i; // [esp+1Ch] [ebp-8h]
  survarium::damage_protector *previous_i; // [esp+20h] [ebp-4h]

  v2 = this->m_first == 0;
  if ( v2 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->next = i->next;
    else
      this->m_first = i->next;
    v4 = (survarium::game_camera *)i;
    if ( !i->next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v4 = (survarium::game_camera *)m_first;
      this->m_last = m_first;
    }
    survarium::weapon_user_dead_state::finalize(v4);
    return 1;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::percept_memory_object *object)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::ai::percept_memory_object *m_first; // [esp+4h] [ebp-2Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+20h] [ebp-10h] BYREF
  vostok::ai::percept_memory_object *i; // [esp+28h] [ebp-8h]
  vostok::ai::percept_memory_object *previous_i; // [esp+2Ch] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->next = i->next;
    else
      this->m_first = i->next;
    v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i;
    if ( !i->next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i,
      (int)&raii);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::perceptors::sensors_subscriber *object)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::ai::perceptors::sensors_subscriber *m_first; // [esp+4h] [ebp-2Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+20h] [ebp-10h] BYREF
  vostok::ai::perceptors::sensors_subscriber *i; // [esp+28h] [ebp-8h]
  vostok::ai::perceptors::sensors_subscriber *previous_i; // [esp+2Ch] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->m_next = i->m_next;
    else
      this->m_first = i->m_next;
    v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i;
    if ( !i->m_next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i,
      (int)&raii);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::proxy_statistic,vostok::sound::proxy_statistic *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::proxy_statistic *object)
{
  vostok::sound::proxy_statistic *m_first; // [esp+0h] [ebp-24h]
  vostok::sound::proxy_statistic *i; // [esp+1Ch] [ebp-8h]
  vostok::sound::proxy_statistic *previous_i; // [esp+20h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i != object )
    return 0;
  --this->m_size;
  if ( previous_i )
    previous_i->next = i->next;
  else
    this->m_first = i->next;
  if ( !i->next )
  {
    if ( previous_i )
      m_first = previous_i;
    else
      m_first = this->m_first;
    this->m_last = m_first;
  }
  return 1;
}


char __thiscall vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::sensed_visual_object *object)
{
  BOOL v2; // ecx
  survarium::game_camera *v4; // ecx
  vostok::ai::sensed_visual_object *m_first; // [esp+0h] [ebp-24h]
  vostok::ai::sensed_visual_object *i; // [esp+1Ch] [ebp-8h]
  vostok::ai::sensed_visual_object *previous_i; // [esp+20h] [ebp-4h]

  v2 = this->m_first == 0;
  if ( v2 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->next = i->next;
    else
      this->m_first = i->next;
    v4 = (survarium::game_camera *)i;
    if ( !i->next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v4 = (survarium::game_camera *)m_first;
      this->m_last = m_first;
    }
    survarium::weapon_user_dead_state::finalize(v4);
    return 1;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::brain_unit,vostok::ai::brain_unit *,264,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::brain_unit *object)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::ai::brain_unit *m_first; // [esp+4h] [ebp-2Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+20h] [ebp-10h] BYREF
  vostok::ai::brain_unit *i; // [esp+28h] [ebp-8h]
  vostok::ai::brain_unit *previous_i; // [esp+2Ch] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next_for_tick )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->m_next_for_tick = i->m_next_for_tick;
    else
      this->m_first = i->m_next_for_tick;
    v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i;
    if ( !i->m_next_for_tick )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i,
      (int)&raii);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::new_sound_propagator *object)
{
  vostok::sound::new_sound_propagator *m_first; // eax
  vostok::sound::new_sound_propagator *v4; // edx
  vostok::sound::new_sound_propagator *m_next_for_proxies; // esi

  m_first = this->m_first;
  if ( !m_first )
    return 0;
  v4 = 0;
  while ( m_first != object )
  {
    v4 = m_first;
    m_first = m_first->m_next_for_proxies;
    if ( !m_first )
    {
      if ( object )
        return 0;
      break;
    }
  }
  --this->m_size;
  m_next_for_proxies = m_first->m_next_for_proxies;
  if ( v4 )
    v4->m_next_for_proxies = m_next_for_proxies;
  else
    this->m_first = m_next_for_proxies;
  if ( !m_first->m_next_for_proxies )
  {
    if ( !v4 )
      v4 = this->m_first;
    this->m_last = v4;
  }
  return 1;
}


char __thiscall vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::receiver_collision *object)
{
  vostok::sound::receiver_collision *m_first; // [esp+0h] [ebp-2Ch]
  vostok::threading::mutex *v5; // [esp+14h] [ebp-18h]
  vostok::sound::receiver_collision *i; // [esp+24h] [ebp-8h]
  vostok::sound::receiver_collision *previous_i; // [esp+28h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    v5 = &this->vostok::threading::mutex;
  else
    v5 = 0;
  vostok::threading::mutex::lock(v5);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i == object )
  {
    --this->m_size;
    if ( previous_i )
      previous_i->m_next = i->m_next;
    else
      this->m_first = i->m_next;
    if ( !i->m_next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex::unlock(v5);
    return 1;
  }
  else
  {
    vostok::threading::mutex::unlock(v5);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_buffer,vostok::sound::sound_buffer *,16,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_buffer *object)
{
  vostok::sound::sound_buffer *m_first; // [esp+0h] [ebp-24h]
  vostok::sound::sound_buffer *i; // [esp+1Ch] [ebp-8h]
  vostok::sound::sound_buffer *previous_i; // [esp+20h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i != object )
    return 0;
  --this->m_size;
  if ( previous_i )
    previous_i->m_next = i->m_next;
  else
    this->m_first = i->m_next;
  if ( !i->m_next )
  {
    if ( previous_i )
      m_first = previous_i;
    else
      m_first = this->m_first;
    this->m_last = m_first;
  }
  return 1;
}


char __thiscall vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_scene *object)
{
  vostok::sound::sound_scene *m_first; // [esp+0h] [ebp-24h]
  vostok::sound::sound_scene *i; // [esp+1Ch] [ebp-8h]
  vostok::sound::sound_scene *previous_i; // [esp+20h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next )
    previous_i = i;
  if ( i != object )
    return 0;
  --this->m_size;
  if ( previous_i )
    previous_i->m_next = i->m_next;
  else
    this->m_first = i->m_next;
  if ( !i->m_next )
  {
    if ( previous_i )
      m_first = previous_i;
    else
      m_first = this->m_first;
    this->m_last = m_first;
  }
  return 1;
}


char __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object)
{
  vostok::sound::sound_voice *m_first; // [esp+0h] [ebp-2Ch]
  vostok::threading::mutex *v5; // [esp+14h] [ebp-18h]
  vostok::sound::sound_voice *i; // [esp+24h] [ebp-8h]
  vostok::sound::sound_voice *previous_i; // [esp+28h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    v5 = &this->vostok::threading::mutex;
  else
    v5 = 0;
  vostok::threading::mutex::lock(v5);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next_for_active )
    previous_i = i;
  if ( i == object )
  {
    --this->m_size;
    if ( previous_i )
      previous_i->m_next_for_active = i->m_next_for_active;
    else
      this->m_first = i->m_next_for_active;
    if ( !i->m_next_for_active )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex::unlock(v5);
    return 1;
  }
  else
  {
    vostok::threading::mutex::unlock(v5);
    return 0;
  }
}


char __thiscall vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::sound::sound_voice *object)
{
  vostok::sound::sound_voice *m_first; // [esp+0h] [ebp-2Ch]
  vostok::threading::mutex *v5; // [esp+14h] [ebp-18h]
  vostok::sound::sound_voice *i; // [esp+24h] [ebp-8h]
  vostok::sound::sound_voice *previous_i; // [esp+28h] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    v5 = &this->vostok::threading::mutex;
  else
    v5 = 0;
  vostok::threading::mutex::lock(v5);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->m_next_for_delete )
    previous_i = i;
  if ( i == object )
  {
    --this->m_size;
    if ( previous_i )
      previous_i->m_next_for_delete = i->m_next_for_delete;
    else
      this->m_first = i->m_next_for_delete;
    if ( !i->m_next_for_delete )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex::unlock(v5);
    return 1;
  }
  else
  {
    vostok::threading::mutex::unlock(v5);
    return 0;
  }
}
